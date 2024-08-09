import React from 'react'
import { Navbar } from '../components/Navbar'
import { Navig } from '../components/Navig'
import { Footer } from '../components/Footer'
import Head from 'next/head'
import { Gallery } from '../components/Gallery'

export default function Gallerys (){
  return (
    <>
    <Head>
      <title>Our Precious Moments</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>
    <div className='flex flex-col overflow-hidden'>
 
    <Navbar/>
    <Navig/>
    <div className='flex flex-row '>
    
    <div className='flex flex-col w-full mx-5'>
    <Gallery/>
   
    
    </div>

    
    </div>
    <Footer/>
  
    </div>
    </>
  )
}
