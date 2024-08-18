import React, { useState } from 'react'
import emailjs from 'emailjs-com';
export const Contact = () => {
  const [firstName, setFirstName] = useState('');
  const [phone, setPhone] = useState('');
  const [email, setEmail] = useState('');
  const [message, setMessage] = useState('');
  const [error, setError] = useState(null);

  const handleSubmit=(e)=>{
    e.preventDefault();
    if (!firstName || !phone || !email || !message) {
      setError('Please fill out all fields.');
      alert('Please fill out all fields.')
      return;
    }
    // fetch("https://vf-backend.onrender.com/sendEmail",{
    //       method:"POST",
    //       headers:{
    //         "Content-Type":"application/json"
    //       },
    //       body:JSON.stringify({
    //         Name:firstName,
    //         Phone:"+91 "+phone,
    //         Email:email,
    //         Message:message
    //       })
    //     }).then((res)=>
    //       res.json()
    //     ).then((data)=>{
    //       console.log(data);
    //     }).catch((error)=>{
    //       console.log(error);
    //     })
    const templateParams = {
      from_name: firstName,
      mobile_number: "+91 " + phone,
      email: email,
      message: message
    };
    console.log("serviceId: ",process.env.SERVICEID)
    emailjs.send(process.env.SERVICEID, process.env.TEMPLATEID , templateParams, process.env.PUBLICKEY)
      .then((response) => {
        alert('Data sent successfully!');
        console.log(response);
      })
      .catch((error) => {
        setError('Failed to send data.');
        console.log(error);
      });
  }
  return (
    <div className='mt-5 flex flex-col'>
       <div className='mb-8'>
      <h1 className='text-center font-extrabold text-5xl text-blue-900 max-md:text-2xl'> Want to Reach Our Team ?</h1>
    </div>
   <div className='mx-10'>
      <form className='mt-8' onSubmit={(e)=>{handleSubmit(e)}}>
    <div className="grid gap-6 mb-6 md:grid-cols-2">
        <div>
            <label htmlFor="first_name" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Name</label>
            <input type="text" pattern="[A-Za-z]+" id="first_name" onChange={(e)=>{setFirstName(e.target.value)}} className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Enter First Name" required/>
        </div>
       
        <div>
            <label htmlFor="phone" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Contact Number</label>
            <input type="tel" pattern='[0-9]{10}' id="phone" onChange={(e)=>{setPhone(e.target.value)}} className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder='Enter Phone Number' required/>
        </div>
       
       
    </div>
    <div className="mb-6">
        <label htmlFor="email" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Email Address</label>
        <input type="email" id="email" onChange={(e)=>{setEmail(e.target.value)}} className="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Enter Email Address" required/>
    </div> 
    <div className='mb-6'>
    <label htmlFor="message" className="block mb-2 text-sm font-medium text-gray-900 dark:text-white">Your Question</label>
<textarea id="message" rows="4" onChange={(e)=>{setMessage(e.target.value)}} className="block p-2.5 w-full text-sm text-gray-900 bg-gray-50 rounded-lg border border-gray-300 focus:ring-blue-500 focus:border-blue-500 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500" placeholder="Write your thoughts here..."></textarea>
    </div>
    
    <button type='submit' className="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-600 font-medium rounded-lg text-sm w-full sm:w-auto px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Submit</button>
</form>
</div>
      </div>
  )
}
