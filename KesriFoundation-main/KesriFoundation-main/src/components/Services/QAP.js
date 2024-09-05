import React from 'react'
import Image from 'next/image'

export const QAP = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg max-md:w-full border-black w-1/2 p-10'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Quality Assessment Program</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/pep.jpeg'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-center'>
          <p className='text-justify'>
          The Quality Assessment Program ensures that educational processes and outcomes are continually evaluated and improved. This initiative focuses on assessing institutional effectiveness, curriculum quality, and student performance. It employs a range of evaluation tools to provide actionable insights, ensuring high standards of academic delivery.
          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
