import Link from 'next/link'
import React, { useState } from 'react'

export const Navig = () => {
  const[open,setOpen]=useState(false); 
  return (
    <>
    <div className='hidden max-lg:flex max-lg:flex-col max-lg:w-full max-lg:justify-end max-lg:items-end max-lg:mt-5 max-lg:pr-5'>
      <div className="container" onClick={() => setOpen(!open)}>
      <div className={`line ${open ? 'line-1-open' : 'line-1-close'}`}></div>
      <div className={`line ${open ? 'line-2-open' : 'line-2-close'}`}></div>
      <div className={`line ${open ? 'line-3-open' : 'line-3-close'}`}></div>
    </div>
    {open&&(<div className='flex flex-col bg-white max-lg:items-end'>

        <Link href='/'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 hover:text-white rounded-full '><button>Home</button></div></Link>
        <Link href='/Aboutus'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>About Kesri Foundation</button></div></Link>
        <Link href='/Service'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Services For Institutes</button></div></Link>
        <Link href='/Service2'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Services For Professionals/Students</button></div></Link>
        <Link href='/Accredition'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Our Accredition</button></div></Link>
        <Link href='/Gallerys'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Glimpse of Our Events</button></div></Link>
        <Link href='/Testimonials'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Testimonials</button></div></Link>
        <Link href='/ContactUs'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full  hover:text-white'><button>Reach Out To Us</button></div></Link>
    </div>)}
    </div>
    <div className='flex flex-row justify-center bg-white max-lg:hidden'>

        <Link href='/'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 hover:text-white rounded-full p-5'><button>Home</button></div></Link>
        <Link href='/Aboutus'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>About Kesri Foundation</button></div></Link>
        <Link href='/Service'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Services For Institutes</button></div></Link>
        <Link href='/Service2'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Services For Professionals/Students</button></div></Link>
        <Link href='/Accredition'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Our Accredition</button></div></Link>
        <Link href='/Gallerys'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Glimpse of Our Events</button></div></Link>
        <Link href='/Testimonials'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Testimonials</button></div></Link>
        <Link href='/ContactUs'><div className='px-10 text-xl bg-transparent font-serif font-bold text-blue-900 hover:bg-blue-900 rounded-full p-5 hover:text-white'><button>Reach Out To Us</button></div></Link>
    </div>
    </>
  )
}
