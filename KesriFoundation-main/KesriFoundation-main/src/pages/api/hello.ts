// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import type { NextApiRequest, NextApiResponse } from 'next';
import clientPromise from '../../..//lib/mongodb';

type Data = {
  success: boolean;
  message: string;
  submittedData?: {
    Name: string;
    Phone: string;
    Email: string;
    Message: string;
  };
};

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<Data>
) {
  if (req.method === 'POST') {
    const { Name, Phone, Email, Message } = req.body;

    // Basic validation
    if (!Name || !Phone || !Email || !Message) {
      return res.status(400).json({
        success: false,
        message: 'All fields are required.',
      });
    }

    // Here you can process the data, save it to a database, or send an email.
    try {
      // Connect to the database
      const client = await clientPromise;
      const db = client.db('myDatabase'); // Replace with your database name

      // Insert the form data into the "contacts" collection
      const result = await db.collection('contacts').insertOne({
        Name,
        Phone,
        Email,
        Message,
        createdAt: new Date(),
      });

    // Respond with success and the submitted data
    res.status(200).json({
      success: true,
      message: 'Form submitted successfully!',
      submittedData: {
        Name,
        Phone,
        Email,
        Message,
      },
    });
  } catch (error) {
      console.error('Error connecting to the database:', error);
      res.status(500).json({
        success: false,
        message: 'Internal Server Error',
      });
    }
  } else {
    // Handle any other HTTP methods
    res.status(405).json({
      success: false,
      message: 'Method Not Allowed',
    });
  }
}

