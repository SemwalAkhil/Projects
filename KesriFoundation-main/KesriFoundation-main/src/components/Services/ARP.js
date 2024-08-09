import React from 'react'
import Image from 'next/image'

export const ARP = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg border-black w-1/2 p-10 max-md:w-full'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Scholastic Improvement Program</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/aqp.jpeg'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-center'>
          <p className='text-justify'>
          Our program focuses on nurturing the mental well-being of both mentors and learners through a skills-based approach. We aim to empower them with the tools and techniques necessary to cultivate resilience and promote mental wellness.          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
