import React from 'react'
import { Navbar } from '../components/Navbar'
import { Navig } from '../components/Navig'
import Head from 'next/head'
import { Footer } from '../components/Footer'

import {Services} from '../components/Services2'

const Service = () => {
  return (
    <>
    <Head>
      <title>Psychological Support | Kesri Foundation</title>
      <link rel="shortcut icon" type="image/x-icon" href="/favicon.ico"/>
    </Head>
    <div>
 
    <Navbar/>
    <Navig/>
    <div className='flex flex-row '>
    <div className='flex flex-col w-full mx-5'>
   
    <Services/>
   
    
    </div>

    
    </div>
    <Footer/>
  
    </div>
    </>
  )
}
export default Service;
