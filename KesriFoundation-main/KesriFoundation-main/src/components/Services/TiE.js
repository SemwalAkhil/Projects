import React from 'react'
import Image from 'next/image'
export const TiE = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6 max-md:justify-center max-md:items-center'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg max-md:w-full border-black w-1/2 p-10'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Theatre In Education</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/tie.webp'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-center'>
          <p className='text-justify'>
          Theatre in Education integrates drama and performance arts into the educational curriculum. It is a dynamic tool for fostering creativity, communication skills, and emotional expression among students. The program aims to make learning more engaging and interactive, while also promoting critical thinking, teamwork, and social awareness.
          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
