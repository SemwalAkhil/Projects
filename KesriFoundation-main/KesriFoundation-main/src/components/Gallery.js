import React from 'react'
import Image from 'next/image'

export const Gallery = () => {
  return (
    <div className='my-5 flex flex-col break-word'>
    <div className='text-center '>
      <h1 className='font-serif text-5xl mb-5 text-blue-900 font-extrabold max-md:text-4xl'>Our Precious Moments</h1>
    </div>
    <div className='flex flex-wrap justify-around gap-6'>

      <Image src={'/gallery/25.jpg'} width={400} height={400} className='border-2 border-blue-900' />
  

    
      <Image src={'/gallery/28.jpg'} width={400} height={400} className='border-2 border-blue-900' />

    

    
      <Image src={'/gallery/33.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/31.jpg'} width={400} height={400} className='border-2 border-blue-900' />
    

      <Image src={'/gallery/7.jpg'} width={400} height={400} className='border-2 border-blue-900' />
    
      <Image src={'/gallery/2.jpg'} width={400} height={400} className='border-2 border-blue-900' />

      <Image src={'/gallery/5.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/32.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/34.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/4.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/19.jpg'} width={400} height={400} className='border-2 border-blue-900' />
 

      <Image src={'/gallery/9.jpg'} width={400} height={400} className='border-2 border-blue-900' />


      <Image src={'/gallery/10.jpg'} width={400} height={400} className='border-2 border-blue-900' /> 

      <Image src={'/gallery/20.jpg'} width={400} height={400} className='border-2 border-blue-900' />
  

      <Image src={'/gallery/13.jpg'} width={400} height={400} className='border-2 border-blue-900' />
   
    
      <Image src={'/gallery/6.jpg'} width={400} height={400} className='border-2 border-blue-900' />

  

    
      <Image src={'/gallery/11.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/12.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/18.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/8.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/14.jpg'} width={400} height={400} className='border-2 border-blue-900' />
      <Image src={'/gallery/30.jpg'} width={400} height={400} className='border-2 border-blue-900' />
    
    </div>
   
    </div>
  )
}
