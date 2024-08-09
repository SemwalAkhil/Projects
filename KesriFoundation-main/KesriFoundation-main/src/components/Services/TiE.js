import React from 'react'
import Image from 'next/image'
export const TiE = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6 max-md:justify-center max-md:items-center'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg max-md:w-full border-black w-1/2 p-10'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Theatre In Education</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/service.jpg'} width={500} height={500}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-center'>
          <p className='text-justify'>
          Its a conceptual artist who moulds knowledge, feelings, thoughts, sensations, and experience into an active and stimulating educational Process. 

To use drama as a toolbox to empower children, young adults, teachers, community workers to be more confident, expressive, imaginative, creative and serve society as a whole.

This create space, both mental and physical, among the participants to open up and become an efficient individual. It fulfills all types of learning and enhances the development process.
          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
