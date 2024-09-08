import React from 'react'
import { Navbar } from '../components/Navbar'
import { Navig } from '../components/Navig'
import Head from 'next/head'
import { Footer } from '../components/Footer'

import Testimonial from '../components/Testimonial'

export default function Testimonials () {
  return (
    <>
    <Head>
      <title>Testimonial | Kesri Foundation</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>
    <div>
 
    <Navbar/>
    <Navig/>
    <div className='flex flex-row '>
    <div className='flex flex-col w-full mx-5'>
   
    <Testimonial/>
   
    
    </div>

    
    </div>
    <Footer/>
  
    </div>
    </>
  )
}
