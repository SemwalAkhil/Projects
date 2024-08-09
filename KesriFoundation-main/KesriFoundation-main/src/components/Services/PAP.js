import React from 'react'
import Image from 'next/image'

export const PAP = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg border-black w-1/2 p-10 max-md:w-full'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Behavioral Assessment Initiative</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/def.jpeg'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-justify'>
          <p className='text-justify'>
          Behavioral Assessment Initiative aims to evaluate individuals through a comprehensive assessment process. This program employs various tools and techniques to gauge cognitive abilities, personality traits, and emotional well-being.

By utilizing a range of assessments, this initiative provides valuable insights into individuals' strengths, weaknesses, and areas for development. It serves as a valuable resource for making informed decisions in education, career planning, and personal development.

Overall, the program offers a holistic approach to understanding individuals' psychological profiles and supporting their growth and success.
          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
