import React from 'react';
import Image from 'next/image';

const testimonials = [
  {
    id: 1,
    name: 'Sadaf Safeer',
    quote: `Dear Neeraj Sir !!

I want to take a moment to express my deepest gratitude for the incredible impact you've had on my life.Your Guidance in career counseling has helped me discover my true path and your support in mental health has provided me with the strength to overcome challenges. I am feeling blessed for having a mentor like you.
Neeraj sir really you are such a gem for many peoples and thankyou for your compassion,wisdom, and unwavering belief in my potential I truly appreciate all that you do once again thanks a lot sir for guiding me in every step of my life.

#Your student Sadaf Safeer from J&K.`,
    role: 'Student'
  },
  {
    id: 2,
    name: 'Shareen',
    quote: 'You taught us how to deal with overthinking and cope with unnecessary stress and tensions. Thank you sir !!!',
    role: 'Student'
  },
  {
    id: 3,
    name: 'Samuel Green',
    quote: `You taught us how to interact with people's.`,
    role: 'Student'
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
            <p className='italic text-lg my-4'>"{testimonial.quote}"</p>
            <h3 className='font-semibold text-blue-900'>{testimonial.name}</h3>
            <p className='text-gray-600'>{testimonial.role}</p>
          </div>
        ))}
      </div>
    </div>
  );
};
