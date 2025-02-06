import React from 'react'
import { Carousel } from 'flowbite-react'
import Image from 'next/image'
export const Carousl = () => {
  return (
    <div className="h-56 w-4/5 mx-8 mt-5 sm:h-96 xl:h-96 2xl:h-96 ">
   <Carousel>
        <img src="/gallery/22.jpg" alt="..." />
        <img src="/gallery/24.jpg" alt="..." />
        <img src="/gallery/26.jpg" alt="..." />
        <img src="/gallery/27.jpg" alt="..." />
        <img src="/gallery/1.jpg" alt="..." />
        <video src="" alt="..."/>
      </Carousel>
</div>
  )
}
