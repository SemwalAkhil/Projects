import Image from 'next/image'
import { Navbar } from '@/components/Navbar'
import { Navig } from '@/components/Navig'

import { Carousl } from '@/components/Carousl'
import { Side } from '@/components/Side'
import { Footer } from '@/components/Footer'
import Head from 'next/head'
import React from 'react'
import Marquee from 'react-fast-marquee'
export default function Home() {
  return (
    <>
    <Head>
      <title>Welcome to Kesri Foundation</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>

    <div className='flex flex-col justify-between w-full overflow-hidden'>
 
    <Navbar/>
    <Navig/>
    <div className='flex flex-col justify-center items-center pr-2 bg-blue-900 w-full p-3 mt-5 font-serif font-extrabold text-white'>
      Places We Have Visited
    </div>
    <Marquee className='mt-2 mb-5' pauseOnHover={true}>
      <h1 className='text-blue-900 font-extrabold font-serif text-xl mr-20'>Jawahar Navodaya Vidyalaya, Rakoli, Mohali, Punjab</h1>
      <h1 className='text-blue-900 font-extrabold font-serif text-xl mr-20'>Government Model Sr Sec School, Sector 33, Chandigarh</h1>
      <h1 className='text-blue-900 font-extrabold font-serif text-xl mr-20'>Jawahar Navodaya Vidyalaya, Surankote, Jammu and Kashmir</h1>
      <h1 className='text-blue-900 font-extrabold font-serif text-xl mr-20'>Government Higher Secondary School, Mendhar, Jammu and Kashmir</h1>
      
    </Marquee>

    <div className='flex flex-row overflow-hidden justify-center max-md:flex max-md:flex-col max-md:justify-center max-md:items-center  '>
    <Carousl/>
    <Side/>
    </div>
    <div className='mb-8 mt-8'>
      <h1 className='text-center font-extrabold text-5xl text-blue-900 max-md:text-4xl'>Milestone Accomplished</h1>
    </div>
    <div className='flex flex-wrap justify-around mb-8 max-md:flex-col max-md:gap-3  max-md:mx-3'>
      <div className='h-fit flex flex-col w-1/5 border-4 p-4 border-blue-900 gap-2 rounded-lg max-md:w-full bg-white'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-blue-900'>3000+</h1>
        <p className='text-center font-serif text-blue-900'>Psychometric Assessment Students</p>
      </div>
      <div className='h-fit flex flex-col w-1/5 border-4 p-4 border-blue-900 gap-2 rounded-lg max-md:w-full bg-white'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-blue-900'>1500+</h1>
        <p className='text-center font-serif text-blue-900'>Teachers Trained</p>
      </div>
      <div className='h-fit flex flex-col w-1/5 border-4 p-4 border-blue-900 gap-2 rounded-lg max-md:w-full bg-white'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-blue-900'>5000+</h1>
        <p className='text-center font-serif text-blue-900'>Individual Counselling Sessions</p>
      </div>
      <div className='h-fit flex flex-col w-1/5 border-4 p-4 border-blue-900 gap-2 rounded-lg max-md:w-full bg-white'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-blue-900'>1500+</h1>
        <p className='text-center font-serif text-blue-900'>Webinar and Seminars Conducted</p>
      </div>
    </div>
    <Footer/>
  
    </div>
    </>

  )
}
