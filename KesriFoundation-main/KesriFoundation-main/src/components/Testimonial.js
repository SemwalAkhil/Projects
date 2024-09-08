import React from 'react';
import Image from 'next/image';

const testimonials = [
  {
    id: 1,
    name: 'John Doe',
    image: '/team/neeraj.jpg', 
    quote: 'This service changed my life! The team was amazing and very professional.',
    role: 'CEO, ExampleCorp'
  },
  {
    id: 2,
    name: 'Jane Smith',
    image: '/team/dwarka.jpg',
    quote: 'I had a fantastic experience. The support and quality exceeded my expectations.',
    role: 'Marketing Head, AnotherCorp'
  },
  {
    id: 3,
    name: 'Samuel Green',
    image: '/team/khyati.jpeg',
    quote: 'Highly recommend! The process was smooth, and the results were outstanding.',
    role: 'Entrepreneur'
  }
];

export default function Testimonial () {
  return (
    <div className='my-5 flex flex-col break-word'>
      <div className='text-center'>
        <h1 className='font-serif text-5xl mb-5 text-blue-900 font-extrabold max-md:text-4xl'>
          Testimonial
        </h1>
      </div>
      <div className='flex flex-wrap justify-around gap-6'>
        {testimonials.map((testimonial) => (
          <div key={testimonial.id} className='bg-white shadow-md rounded-lg p-6 max-w-xs text-center'>
            <Image
              src={testimonial.image}
              alt={testimonial.name}
              width={100}
              height={100}
              className='rounded-full mx-auto'
            />
            <p className='italic text-lg my-4'>"{testimonial.quote}"</p>
            <h3 className='font-semibold text-blue-900'>{testimonial.name}</h3>
            <p className='text-gray-600'>{testimonial.role}</p>
          </div>
        ))}
      </div>
    </div>
  );
};
