import React, { useState } from 'react'

export const Services = () => {
  return (
    <div className='my-5 flex flex-col break-words'>
    <div className='mb-8'>
      <h1 className='text-center font-extrabold text-5xl text-blue-900 max-md:text-4xl'>Our Offerings</h1>
    </div>
    <div className='flex flex-wrap justify-around mb-8 max-md:flex-col max-md:gap-3'>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Training Based Internships</h1>
        <p className='text-justify font-serif text-white'>At Kesri Foundation, we offer comprehensive training-based internships designed to equip aspiring mental health professionals with practical skills and hands-on experience. Our internships provide participants the opportunity to work closely with seasoned counselors and psychologists, applying theoretical knowledge in real-world settings. Interns engage in case studies, psychometric assessments, and counseling sessions, gaining valuable insights into mental health practices. Our structured program ensures a well-rounded experience that enhances both personal and professional growth.</p>
      </div>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Certificate Courses</h1>
        <p className='text-justify font-serif text-white'>Kesri Foundation's certificate courses are meticulously designed to provide focused learning on key areas of psychology and counseling. These short-term programs cover various topics such as Cognitive Behavioral Therapy (CBT), Psychometric Testing, and Child Psychology. Delivered by experts in the field, our courses combine theoretical instruction with practical exercises, empowering participants with the knowledge and skills required to excel in their chosen careers. Upon successful completion, participants receive certificates recognized by leading psychological associations.</p>
      </div>
      <div className='flex flex-col w-1/5 border-4 p-4 border-white gap-2 rounded-lg max-md:w-full bg-blue-900'>
        <h1 className='text-center font-extrabold font-serif text-2xl text-white'>Workshop</h1>
        <p className='text-justify font-serif text-white'>Our dynamic workshops provide a platform for professionals, students, and educators to engage in interactive learning sessions on crucial psychological topics. Covering a wide array of subjects, from stress management to career counseling, these workshops are designed to be both informative and experiential. Led by experienced facilitators, participants gain practical tools and strategies to apply in their everyday work, fostering personal development and professional competency.</p>
      </div>
    </div>
    </div>
  )
}
