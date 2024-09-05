import React from 'react'
import Image from 'next/image'

export const ARP = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg border-black w-1/2 p-10 max-md:w-full'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Academic Reinforcement Program</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/aqp.jpeg'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-center'>
          <p className='text-justify'>
          This program focuses on strengthening core academic skills across various subjects. It is designed to support students in achieving higher performance through personalized learning strategies, remedial education, and continuous academic guidance. The program tailors instruction to meet the unique learning needs of each student, ensuring they reach their full potential.          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
