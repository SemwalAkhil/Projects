// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import type { NextApiRequest, NextApiResponse } from 'next';

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

export default function handler(
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
  } else {
    // Handle any other HTTP methods
    res.status(405).json({
      success: false,
      message: 'Method Not Allowed',
    });
  }
}

