import Image from 'next/image'
import React from 'react'
import { Button, Modal } from 'flowbite-react';
import { useState } from 'react';

export const About = () => {
  const [openFounder, setOpenFounder] = useState(false);
  const [openMember1, setOpenMember1 ] =useState(false);
  const [openMember2, setOpenMember2 ] =useState(false);
  const [openMember3, setOpenMember3 ] =useState(false);
  const [openMember4, setOpenMember4 ] =useState(false);
  const [openMember5, setOpenMember5 ] =useState(false);
  const [openMember6, setOpenMember6 ] =useState(false);
  const [openMember7, setOpenMember7 ] =useState(false);
  const [openMember8, setOpenMember8 ] =useState(false);
  const [openMember9, setOpenMember9 ] =useState(false);
  return (
    <div className='mt-5 flex flex-col'>
       <div className='mb-8'>
      <h1 className='text-center font-extrabold text-5xl text-blue-900 max-md:text-3xl'>About Kesari Foundation</h1>
    </div>
      <p className='  font-serif font-bold text-blue-600 text-xl mx-8 text-justify'>
      
Kesri Foundation, standing for "<span className='font-extrabold text-blue-900'>K</span>nowing Yourself and <span className='font-extrabold text-blue-900'>E</span>mpowering Lives for <span className='font-extrabold text-blue-900'>S</span>uccessful Aspirations, <span className='font-extrabold text-blue-900'>R</span>ehabilitation, and <span className='font-extrabold text-blue-900'>I</span>nformed career Strategies," embodies a profound commitment to enhancing mental health awareness and educational guidance. With a primary focus on school children, the foundation recognizes the critical need for informed career choices, utilizing psychological tools and testing to illuminate pathways for students. Recognizing the prevalent lack of awareness in this domain, Kesri Foundation passionately addresses stress management during exams, acknowledging its pivotal role in fostering the overall well-being of students. Furthermore, the foundation's holistic approach extends to adolescent education, emphasizing the significance of combating drug and substance abuse in India. By seamlessly integrating these essential elements, Kesri Foundation strives to make a meaningful impact on individuals' lives, advocating for psychological well-being and providing informed career strategies that empower and uplift communities.
      </p>
      
      <div className='my-8'>
      <h1 className='text-center font-extrabold font-serif text-5xl text-blue-900'>Our Group</h1>
    </div>
      <div className='flex flex-col justify-center items-center w-full'>
        <h1 className='py-5 text-center font-serif font-extrabold text-4xl'>The Founder's Team</h1>
        <div className='flex flex-wrap justify-between max-md:justify-center  max-md:items-center max-md:flex-col'>
          <div className='flex flex-row mt-4 '>
          <div className='rounded-full h-28 w-28  mr-5  overflow-hidden  '>
             <Image className=' object-cover'   src='/team/neeraj.jpg' height={160} width={160} />
             </div>
            <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Mr. Neeraj Kumar</strong>
                <strong className='h-auto text-lg'>Founder(Psychologist)</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenFounder(true)}>View More</Button>
              </div>
              <Modal show={openFounder} onClose={() => setOpenFounder(false)}>
                <Modal.Header>Founder's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/neeraj.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Neeraj Kumar is a highly skilled counselling psychologist with a robust background spanning over 8 years, specializing in career counselling and adolescent education, notably within school settings. His extensive experience includes collaborations with four rehabilitation centers across India, showcasing his commitment to diverse environments. With over 5 years dedicated to addiction counselling, particularly in combating drug addiction and substance abuse, Neeraj brings invaluable expertise to the realm of mental health support. He obtained his master's degree in 2015, further enhancing his qualifications with a diploma in guidance and counselling in 2020. Neeraj has been an active advocate for mental health, conducting workshops and contributing over 4 years to Jawahar Navodaya Vidyalaya, significantly impacting educational support initiatives.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
          
        </div>
      </div>
      <div className='flex flex-col justify-center items-center w-full mt-5'>
      <h1 className='py-5 text-center font-serif font-extrabold text-4xl'>The Strategic Psychological Advisors Team</h1>
        <div className='flex flex-wrap justify-center max-md:justify-center max-md:flex-col'>
        <div className='flex flex-row  mt-4'>
            <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className=' object-cover' src='/team/t4.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Dr. Jaismeen Kaur</strong>
                <strong className='h-auto text-lg'>Consultant Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember2(true)}>View More</Button>
              </div>
              <Modal show={openMember2} onClose={() => setOpenMember2(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t4.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Jaismeen Kaur is an accomplished psychologist with a diverse background in research, publications, internships, and professional experience. Her research has centered on the efficacy of Reality Therapy in addressing Empty Nest Syndrome, leading to published works in esteemed journals focusing on topics like Empty Nest Syndrome and mindfulness-based interventions for older adults. Jaismeen's hands-on experience includes internships in Neuropsychiatry & Drug Rehab at reputable institutions, contributing to her comprehensive understanding of mental health.
                      </p>
                      <br></br>
                      <p className='text-justify'>
                      In her professional capacity, Jaismeen currently serves as a Counselor at Rajiv Gandhi National University of Law, Patiala, building upon her prior role as a school counselor at Holy Angels School, Rajpura. She has conducted impactful workshops addressing a range of mental health concerns, including Anger Management and Suicide Prevention. Jaismeen's commitment to the field is underscored by her participation in workshops covering diverse topics such as Child Sexual Abuse and Choice Theory. Her contributions have been recognized through awards, including the First Prize in a Mental Health Poster Competition and a Best Presenter accolade at a prominent psychology conference.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
          <div className='flex flex-row  mt-4'>
            <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className=' object-cover' src='/team/t7.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Khushpreet Kaur</strong>
                <strong className='h-auto text-lg'>Consultant Clinical Psychologist</strong>
                <strong className='h-auto text-lg'>RCI License Approved</strong>
                <strong className='h-auto text-lg'>CRR Number: A90748</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember6(true)}>View More</Button>
              </div>
              <Modal show={openMember6} onClose={() => setOpenMember6(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t7.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Khushpreet Kaur is a dedicated and qualified psychologist based in Patiala, India, with expertise in mental health assessment and the measurement of individuals' mental capabilities. She possesses the necessary qualifications to contract, administer, score, and interpret psychometric tests related to personality, psychopathology, and intelligence. Khushpreet is highly proficient in leveraging test results and assessments to objectively evaluate the specific proficiencies and needs of her patients.

In her current role as a Psychologist at the National Health Mission since June 2019, Khushpreet has demonstrated her skills by conducting patient observations, monitoring behavior, and documenting crucial information such as physical health, family history, and medications in mental health assessment reports. She has actively engaged in psychological testing for various patients and holds the knowledge to interpret testing and observation results effectively. Managing a diverse caseload, Khushpreet conducts individual, couples, children, and family therapy sessions.

Khushpreet's educational background is extensive, having earned a Bachelor of Arts (Honours) in Psychology from H.M.V. College in Jalandhar in July 2016. Subsequently, she pursued a Master of Arts in Psychology from Punjabi University in Patiala, completing her studies in July 2018. She furthered her education with a PG Diploma in Counselling and Behaviour Modification from G.J.U. of Science and Technology in Hisar, which she obtained in August 2021. Khushpreet also completed a P.G.D.R.P. at Adarsh Rehabilitation Centre for Mentally Handicap in Bhiwani in July 2022.

With a comprehensive education and diverse work experience, Khushpreet Kaur is a seasoned professional who excels in mental health assessment, psychological testing, and counseling across various age groups. Her commitment to understanding and addressing the unique needs of her clients reflects her dedication to the field of psychology and mental health.
                      </p>
                      
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
          <div className='flex flex-row  mt-4'>
            <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className=' object-cover' src='/team/t6.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Dr. Nayanika Singh</strong>
                <strong className='h-auto text-lg'>Consultant Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember4(true)}>View More</Button>
              </div>
              <Modal show={openMember4} onClose={() => setOpenMember4(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t6.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Dr. Nayanika Singh has done her schooling from The Lawrence School Sanawar following which she did her graduation with honours in psychology from gcg-11, Chandigarh, Post Graduation in Psychology from Panjab University with specialization in Clinical and Counselling Psychology and PhD in Jungian Psychology from Punjabi University Patiala.
She has also done a Post Graduate Diploma in Guidance and Counselling. Dr. Singh, has a passion for research and has 70 papers published in National and International Journals of repute. She has presented more than 35 papers across the country for National and International Conferences and is on the board of studies of academic institutions and member of many National associations.
She has a passion for writing and has authored a book in Sports Psychology and Edited a book on Mental Disorders. She has the acclaim of correlating Psychology with Art as part of the National Mobile Exposition in 2009 sponsored by the Govt. Museum and Art Gallery, Chandigarh.
Dr. Nayanika, is certified for Emotional Freedom Therapy (EFT), Internationally Certified as Mindfulness Meditation Practitioner (IAPCCT Certified), Certified Parent Coach form CCI and a Certified Career Counselling Coach. She has also done a Certificate course in Art Therapy from Asha, The Hope Foundation in collaboration with ICPEM, Govt. of India, content approved by United Nations, Geneva.
She is also a Grandmaster in Reiki Therapy and trained for basic modalities of Hypnotherapy, Expressive Arts Therapy, Neuro-Linguistic Programming (NLP), Life Skills and Mandala Art. Dr. Singh, has a passion for training and has conducted over 500 behavioural trainings and a number of webinars.
Dr. Singh has done a Ten Days Online Course on Casestudy writing from Stanford University, Georgetown, U.S.A in collaboration with MGSIPA under the able guidance of Prof. Kent Weaver and Mr. Blair Cameroon.
She has also done a training module on Purpose & Motivation and Leadership from Chandler Institute of Governance, Singapore in collaboration with MGSIPA.
Some of her core areas for trainings include: Stress Management, Mindfulness, Life Skills, NLP, Team Building, Motivation, Drug Awareness, Office Etiquettes, Research Methodology, Emotional Intelligence & Regulation and Leadership.
She is also a reviewer for and on the editorial board of many National Journals and International Journals such as MOJABB, Medcrave publishing house, CA, USA.
Presently she is working as an Assistant professor in Psychology at Mahatma Gandhi State Institute of Public Administration (MGSIPA) , Chandigarh, Govt of Punjab and conducting behavioural trainings for IAS/PCS officers and officers of boards and corporations of the Punjab Government.
                      </p>
                     
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
  

          
          <div className='flex flex-col justify-center items-center w-full mt-5'>
      <h1 className='py-5 text-center font-serif font-extrabold text-4xl'>The Support Team</h1>
        <div className='flex flex-wrap justify-center max-md:justify-center max-md:flex-col'>
          
        <div className='flex flex-row mt-4'>
        <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className=' object-fill' src='/team/t1.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Manju Duggal</strong>
                <strong className='h-auto text-lg'>Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember1(true)}>View More</Button>
              </div>
              <Modal show={openMember1} onClose={() => setOpenMember1(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t1.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Manju Duggal is an accomplished Educational Counselor with a strong academic foundation and extensive practical experience. Her qualifications include a PG Diploma in Child Guidance and Family Counseling, completed at Punjab University's Gov. Home-Science College in Chandigarh during 2018-2019. Complementing this, she pursued an M.A. in Psychology at Govt. P.G. College in Panchkula, affiliated with Kurukshetra University, between 2019 and 2022.

Professionally, Ms. Duggal has excelled in various educational roles, notably at institutions like SDM School and K.V.S OCF Sector 29b in Chandigarh. Her career journey reflects her commitment to fostering student development, offering guidance, and supporting their educational and personal growth. With a solid educational background and extensive experience in educational settings, Ms. Manju Duggal continues to be an asset in providing comprehensive counseling services and ensuring the holistic well-being of students.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
      
          <div className='flex flex-row  mt-4'>
            <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className=' object-cover' src='/team/t5.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Isha Khangwal</strong>
                <strong className='h-auto text-lg'>Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember3(true)}>View More</Button>
              </div>
              <Modal show={openMember3} onClose={() => setOpenMember3(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t5.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                     
Isha Khangwal is an experienced Psychological Counsellor with six years of comprehensive expertise in private and government sectors. Her roles at JNV Rakoli, Punjab, and JNV Gandhi Nagar, Gujarat, focused on daily counselling sessions to enhance students' learning abilities and ensure their mental well-being, accompanied by holistic counselling for parents. At Sahyog Charitable Trust, she conducted individual and family counselling, generating detailed reports based on her sessions.
                      </p>
                      <br></br>
                      <p className='text-justify'>
                      She has extensive experience in various therapeutic modalities like Cognitive Behaviour Therapy (CBT), trauma and grief therapy, and relaxation techniques. Isha actively engages in professional development, participating in workshops and conferences covering neurological assessments, inkblot tests, personality assessments, Positive Psychology, Art in Therapy, and trauma psychology. She has presented her research on anxiety management through meditational music at an International Conference of Applied Psychology in Chandigarh.
                      </p>
                      <br></br>
                      <p className='text-justify'>
                      Isha Khangwal's career showcases a dedicated commitment to psychological counselling, continuous skill enhancement, and the application of diverse therapeutic approaches to benefit her clients' mental health and well-being.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>
          

          <div className='flex flex-row  mt-4'>
          <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className='object-cover'  src='/team/t3.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Pawandeep Kaur</strong>
                <strong className='h-auto text-lg'>Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember5(true)}>View More</Button>
              </div>
              <Modal show={openMember5} onClose={() => setOpenMember5(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t3.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Pawandeep Kaur's academic journey embodies a passion for mental health, fortified by a Master's in Psychology and a Diploma in Counseling Psychology. Her academic prowess encompasses a profound understanding of psychological theories, coupled with ethical counseling practices rooted in real-world applications. Complementing her academic achievements, Pawandeep's six months' hands-on involvement in a drug rehabilitation center reveals her compassionate approach and adeptness in providing personalized support. Her role involved implementing tailored therapeutic strategies, fostering hope, and aiding individuals grappling with substance abuse challenges. Pawandeep's amalgamation of theoretical expertise and practical engagement underscores her unwavering commitment to fostering mental well-being. She remains dedicated to offering invaluable guidance within counseling spheres and substance abuse rehabilitation contexts, driven by a heartfelt dedication to each individual's mental health journey.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>

          <div className='flex flex-row  mt-4'>
          <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className='object-cover'  src='/team/t8.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Sheetal Mehta</strong>
                <strong className='h-auto text-lg'>Psychologist</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember7(true)}>View More</Button>
              </div>
              <Modal show={openMember7} onClose={() => setOpenMember7(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t8.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Sheetal Mehta, a 25-year-old Indian professional, is actively pursuing a challenging position where she can apply her skills effectively and contribute to the success of leading services. With a keen focus on continuous learning and development, Sheetal brings a robust educational background and diverse experiences to the table.

Having completed her X (Metric) and XII (+2) from G.M.S.S.S in Sec. 39 C and Sec. 23 C, Chd., respectively, under the CBSE board, Sheetal demonstrated consistent academic performance with 56% in both examinations in 2013 and 2015. She furthered her education by obtaining a BA with honors from 6 Phase College under Patiala University in 2018, achieving an impressive 70%. Continuing her academic journey, Sheetal earned an M.A. in Psychology from SUS Tangori, Patiala University, in 2020, maintaining a high standard with a 70% score.

Sheetal's commitment to professional development is underscored by her pursuit of a Postgraduate Diploma in Guidance & Counselling from Dev Samaj College in Sec 36, Chd., under Punjab University, where she excelled with a remarkable 77% and gained valuable practical experience through an internship. Additionally, she completed a 7-month Basic Computer Knowledge course from a government institute, enhancing her technical skills.

Her proactive approach to learning extends beyond the classroom, as evidenced by her participation in Red Cross Camps and attendance at various workshops and seminars related to counseling. She further enriched her practical experience through a one-month career counseling internship at Aadi Career Center in Sec 8, Chandigarh.

With a solid foundation in education and a well-rounded skill set, Sheetal is also equipped with five years of experience in home tutoring. Her commitment to excellence is evident in her consistent academic achievements, diverse experiences, and ongoing pursuit of knowledge.

In addition to her academic and professional accomplishments, Sheetal is characterized by her hardworking, sincere, dedicated, responsible, adaptable, and disciplined nature. She is poised to bring a wealth of knowledge, innovative ideas, and a strong work ethic to any team or organization she joins, making her a valuable asset in any challenging professional setting.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>

          <div className='flex flex-row  mt-4'>
          <div className='rounded-full h-28 w-28  mr-4  overflow-hidden'>
             <Image className='object-cover'  src='/team/t10.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Mr. Vishal</strong>
                <strong className='h-auto text-lg'>Academic Advisor</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember8(true)}>View More</Button>
              </div>
              <Modal show={openMember8} onClose={() => setOpenMember8(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t10.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Vishal is a dynamic professional with a unique blend of technical and managerial expertise. Holding a B.Tech in Electronics and Communication, he has a solid foundation in engineering principles and technology. Complementing his technical background, Vishal has pursued an MBA in Marketing, showcasing a strategic mindset and an understanding of business dynamics.

Currently serving in a Human Resources role, Vishal's diverse educational background positions him as a versatile asset within the organization. His technical acumen allows him to comprehend the intricacies of various functions, while his marketing qualifications provide him with a strategic perspective on talent acquisition, employee engagement, and organizational development.

Vishal's ability to bridge the gap between technology and business, coupled with his insights into marketing strategies, enables him to contribute uniquely to the HR domain. His multifaceted skill set allows him to approach HR challenges with a holistic perspective, fostering a well-rounded and effective approach to talent management.

In summary, Vishal is a forward-thinking professional with a B.Tech in Electronics and Communication, an MBA in Marketing, and a current role in Human Resources. His diverse background positions him as an invaluable asset, capable of bringing a unique and comprehensive skill set to any organization's HR functions.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>

          <div className='flex flex-row  mt-4'>
          <div className='rounded-full h-28 w-28  mr-5  overflow-hidden'>
             <Image className='object-cover'  src='/team/t9.jpg' height={160} width={160} />
             </div>
             <div className='flex flex-col pr-8 gap-2'>
              <div className='flex flex-col'>
                <strong className='h-auto text-xl text-blue-700'>Ms. Chanchal Sehra</strong>
                <strong className='h-auto text-lg'>Academic Advisor</strong>
              </div>
              <div>
              <Button className='w-fit' color='blue' onClick={() => setOpenMember9(true)}>View More</Button>
              </div>
              <Modal show={openMember9} onClose={() => setOpenMember9(false)}>
                <Modal.Header>Member's Details</Modal.Header>
                <Modal.Body>
                  <div className='flex flex-col justify-center items-center'>
                    <div className='rounded-full h-40 w-40 overflow-hidden  '>
                    <Image className=' object-cover'   src='/team/t9.jpg' height={160} width={160} />
                    </div>
                    <div className='details'>
                      <p className='text-justify'>
                      Chanchal Sehra is a results-driven professional who holds an MBA in Human Resource from Panjab University, earned in 2019, and a B.Com degree from the same university obtained in 2017. Complementing her academic achievements, Chanchal holds certifications from the C.B.S.E. Board for 12th grade in 2014 and 10th grade in 2012, demonstrating her commitment to continuous education.

As a recent graduate entering the professional arena, Chanchal brings a set of valuable attributes to the table. Her academic journey underscores her strong leadership qualities and quick learning abilities, making her well-suited for adapting to dynamic work environments. Additionally, she possesses a foundational understanding of computer systems, contributing to her versatility in modern workplaces.

Chanchal is characterized by her hardworking nature and positive attitude, two qualities that she aims to leverage to contribute effectively to organizational success. With a keen desire for professional development, she is committed to continuous learning, keeping pace with industry trends and best practices.

In summary, Chanchal Sehra is an ambitious and capable professional, equipped with a strong educational foundation and relevant skills. Her positive mindset, coupled with a diligent work ethic, positions her as a promising candidate ready to make meaningful contributions to any organization she joins, while actively seeking opportunities for continuous personal and professional growth.
                      </p>
                    </div>
                  </div>
                </Modal.Body>
              </Modal>
            </div>

          </div>


          </div></div>
        </div>
      </div>
    </div>
  )
}
