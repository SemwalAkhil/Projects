import Image from 'next/image'
import React from 'react'
export const Navbar = () => {
  return (
    <div >
        <div className='flex flex-row items-center pl-14 max-lg:flex max-lg:flex-row max-lg:items-center max-lg:pl-0 max-lg:justify-center max-lg:w-full md:gap-2 max-lg:gap-2'>
            <Image className='h-40 w-40 rounded-full bg-transparent max-lg:h-20 max-lg:w-20 object-cover lg:mt-9 md:mt-4' src='/images/logo.png' width={150} height={150}/>
            <div className='flex flex-col pr-40 max-lg:pr-0'>
                <h1 className='h-auto'><span className='text-blue-900 text-6xl max-lg:text-3xl' >Kesri Foundation</span></h1>
                <p className='text-blue-500 font-bold text-2xl ml-1 max-lg:text-sm max-lg:ml-0 max-lg:mr-1 max-lg:text-start'>Empowering Lives</p>
            </div>
        </div>

    </div>
  )
}
