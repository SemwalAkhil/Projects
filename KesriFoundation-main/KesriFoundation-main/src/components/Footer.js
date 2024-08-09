import Link from 'next/link'
import React from 'react'

export const Footer = () => {
  return (
    <footer className="bg-white rounded-lg w-full mt-4 dark:bg-gray-800 flex flex-col justify-center items-center ">
    <div className="w-full max-lg:mx-5 flex flex-col justify-between items-center max-w-screen-xl p-4 max-lg:flex max-lg:flex-col max-lg:items-center max-lg:justify-between ">
    <ul className="flex flex-wrap items-center mt-3 text-sm font-medium max-lg:justify-center max-lg:items-center text-gray-500 dark:text-gray-400 sm:mt-0">
        <li>
            <Link href="/" className="mr-4 hover:underline lg:mr-6 font-serif text-green-900">Home</Link>
        </li>
        <li>
            <Link href="/Aboutus" className="mr-4 hover:underline lg:mr-6 font-serif text-green-900 ">About Kesari Foundation</Link>
        </li>
        <li>
            <Link href="/Service" className="mr-4 hover:underline lg:mr-6 font-serif text-green-900">What We Provide</Link>
        </li>
        <li>
            <Link href="/Gallerys" className="mr-4 hover:underline lg:mr-6 font-serif text-green-900">Glimpse of Our Events</Link>
        </li>
        <li>
            <Link href="/ContactUs" className="hover:underline font-serif text-green-900">Reach Out To Us</Link>
        </li>
        
    </ul>
    </div>
</footer>
  )
}
