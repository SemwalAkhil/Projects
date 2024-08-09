import React from 'react'
import { Navbar } from '../components/Navbar'
import { Navig } from '../components/Navig'
import Head from 'next/head'
import { Footer } from '../components/Footer'


import { Contact } from '../components/Contact'
export const ContactUs = () => {
  return (
    <>
    <Head>
      <title>Reach Out at Kesri Foundation</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>
    <div className='flex flex-col overflow-hidden'>
 
    <Navbar/>
    <Navig/>
   
    <div className='flex flex-row '>
    <div className='flex flex-col w-full mx-5'>
  
    <Contact/>
    
    </div>

    
    </div>
    <Footer/>
  
    </div>
    </>
  )
}
export default ContactUs;
