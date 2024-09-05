import React from 'react'
import Image from 'next/image'

export const PAP = () => {
  return (
    <div className='flex flex-row justify-center w-full max-md:mb-6'>
    <div className=' flex flex-col justify-center items-center border-2 rounded-lg border-black w-1/2 p-10 max-md:w-full'>
      <h1 className='text-3xl font-serif font-extrabold mb-4 max-md:text-2xl max-md:text-center'>Psychometric Assessment Program</h1>
      <div className='flex flex-col justify-center items-center gap-10 max-md:flex-col'>
        <div className='max-md:flex max-md:justify-center'>
          <Image src={'/images/def.jpeg'} width={300} height={300}/>
        </div>
        <div className='w-full flex flex-col justify-start max-md:w-full max-md:text-justify'>
          <p className='text-justify'>
          This program provides comprehensive psychological assessments to understand students' cognitive abilities, emotional functioning, and personality traits. It helps identify learning disabilities, behavioral issues, and career aptitude, providing valuable insights that guide tailored educational and counseling interventions.
          </p>
        </div>
      </div>
    </div>
    </div>
  )
}
