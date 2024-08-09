import React from 'react'
import { Navbar } from '../components/Navbar'
import { Navig } from '../components/Navig'
import Head from 'next/head'
import { Footer } from '../components/Footer'

import { About } from '../components/About'
 const Aboutus = () => {
  return (
    <>
    <Head>
      <title>About Kesri Foundation</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>
    <div className='flex flex-col overflow-hidden'>
 
    <Navbar/>
    <Navig/>
    <div className='flex flex-col w-full mx-5 max-md:mx-0 '>
    <About/>
   
    
    
    </div>

    
    
    <Footer/>
  
    </div>
    </>
  )
}
export default Aboutus;
