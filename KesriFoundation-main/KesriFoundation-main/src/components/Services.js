import React, { useState } from 'react'
import Image from 'next/image'
import { ARP } from './Services/ARP'
import { QAP } from './Services/QAP';
import { PAP } from './Services/PAP';
import { TiE } from './Services/TiE';

export const Services = () => {
  const[arp,setARP]=useState(false);
  const[qap,setQAP]=useState(false);
  const[pap,setPAP]=useState(false);
  const[tie,setTiE]=useState(false);
  return (
    <div className='my-5 flex flex-col break-words'>
   

    <div className='mb-8'>
      <h1 className='text-center max-md:text-4xl font-extrabold text-5xl text-blue-900'>Psychological Support</h1>
    </div>
    <div className='my-5 flex flex-wrap justify-around max-md:flex-col max-md:gap-3 max-md:mt-1'>
      <button onClick={()=>{
        setARP(!arp);
        setPAP(false);
        setQAP(false);
        setTiE(false);
      }} className={!arp?('p-8 bg-blue-900 w-1/5 rounded-lg max-md:w-full'):('p-8 bg-white w-1/5 max-md:w-full  border-blue-900 rounded-lg border-2')}>
      <h1 className={!arp?('font-extrabold text-white text-center max-md:w-full'):('font-extrabold text-blue-900 text-center max-md:w-full')}>Academic Reinforcement Program</h1>
      </button>
      <button onClick={()=>{
        setARP(false);
        setPAP(false);
        setQAP(!qap);
        setTiE(false);
      }} className={!qap?('p-8 bg-blue-900 w-1/5 rounded-lg max-md:w-full'):('p-8 bg-white  max-md:w-full w-1/5  border-blue-900 rounded-lg border-2')}>
      <h1 className={!qap?('font-extrabold max-md:w-full text-white text-center'):('font-extrabold max-md:w-full  text-blue-900 text-center')}>Quality Assessment Program</h1>
      </button>
      <button onClick={()=>{
        setARP(false);
        setPAP(!pap);
        setQAP(false);
        setTiE(false);
      }} className={!pap?('p-8 bg-blue-900 w-1/5 max-md:w-full rounded-lg'):('p-8 bg-white max-md:w-full w-1/5  border-blue-900 rounded-lg border-2')}>
      <h1 className={!pap?('font-extrabold text-white max-md:w-full text-center'):('font-extrabold text-blue-900 max-md:w-full text-center')}>Psychometric Assessment Program</h1>
      </button>
      <button onClick={()=>{
        setARP(false);
        setPAP(false);
        setQAP(false);
        setTiE(!tie);
      }} className={!tie?('p-8 bg-blue-900 w-1/5 max-md:w-full rounded-lg'):('p-8 bg-white max-md:w-full w-1/5  border-blue-900 rounded-lg border-2')}>
      <h1 className={!tie?('font-extrabold text-white max-md:w-full text-center'):('font-extrabold text-blue-900 max-md:w-full text-center')}>Theatre in Education</h1>
      </button>
    </div>
    {arp&&<ARP/>}
    {qap&&<QAP/>}
    {pap&&<PAP/>}
    {tie&&<TiE/>}
    <div className='mb-8'>
      <h1 className='text-center font-extrabold text-5xl text-blue-900 max-md:text-4xl'>Our Offerings</h1>
    </div>
    <div className='flex flex-wrap justify-around mb-8 max-md:flex-col max-md:gap-3'>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Data-Driven Approaches</h1>
        <p className='text-justify font-serif text-white'>Drawing from forefront research and proven methodologies, our interventions are meticulously tailored to ensure the utmost quality and effectiveness in the services we provide.</p>
      </div>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Accomplished Specialists</h1>
        <p className='text-justify font-serif text-white'>Within our team, you'll find accredited mental health experts, encompassing psychologists, therapists, and social advocates. With rich backgrounds in supporting varied communities within educational environments, they bring invaluable experience to the table.</p>
      </div>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Individualized Strategies</h1>
        <p className='text-justify font-serif text-white'>Recognizing the distinct requirements of each educational establishment, we personalize our offerings to align seamlessly with the unique demands of every school. This tailored approach guarantees impactful interventions and favorable results.</p>
      </div>
    </div>
    </div>
  )
}
