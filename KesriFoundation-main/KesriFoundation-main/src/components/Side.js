import Link from 'next/link'
import React from 'react'

export const Side = () => {
  return (
    <div className='flex flex-col mt-5 w-fit mr-5 max-md:justify-center max-md:items-center max-md:px-10'>
        <div>
        <h1 className='text-extrabold font-serif text-4xl text-blue-900 max-md:text-3xl max-md:text-center max-md:text-extrabold max-md:font-serif'> Welcome to Kesri Foundation</h1>
        </div>
        <br></br>
        <div className='flex flex-col gap-2 text-justify'>
        <p className='font-serif text-blue-900'>The inception of Kesri Foundation marks a pivotal moment in the realm of mental health and education advocacy. Born from a profound understanding of the critical need to address these fundamental aspects of human well-being, Kesri Foundation stands as a commendable initiative aimed at fostering resilience and strength within communities. The very essence of the name "Kesri" encapsulates a unique blend of fortitude and endurance, perfectly mirroring the foundation's overarching mission. This initiative symbolizes a beacon of hope, striving to champion mental health awareness and educational empowerment in a world where these facets are integral to individual growth and societal progress.</p>
        </div>
        <div className='mt-8'>
            <Link href='/ContactUs'><button className='w-40 h-10 rounded-xl bg-blue-900 text-white font-serif max-md:text-center '>Reach Us</button></Link>
        </div>
    </div>
  )
}
