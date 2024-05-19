import cv2 as cv
import numpy as np

haar_cascade = cv.CascadeClassifier('D:/Codes/Python/OPENCV/haar_face.xml')

people = ['Elon Musk','K L Rahul','Narendra Modi','Rahul Gandhi','Virat Kohli']
#features = np.load('D:/Codes/Python/OPENCV/features.npy',allow_pickle=True)
#labels = np.load('D:/Codes/Python/OPENCV/labels.npy')

face_recogniser = cv.face.LBPHFaceRecognizer_create() # type: ignore
face_recogniser.read('D:/Codes/Python/OPENCV/face_trained.yml')
img = cv.imread('D:/Codes/Python/OPENCV/Photos/kl1.jpg')
scale = 0.4
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
#cv.imshow('Person',gray)

#detect face in rect
faces_rect = haar_cascade.detectMultiScale(gray,1.1,3)
for (x,y,w,h) in faces_rect:
    faces_roi = gray[y:y+h,x:x+h]

    label,confidence = face_recogniser.predict(faces_roi)
    print(f'Label = {people[label]} with confidence of {confidence}')

    cv.putText(img, str(people[label]),(20,20),cv.FONT_HERSHEY_COMPLEX,1,(0,255,0),thickness=2)
    cv.putText(img, str(round((confidence),2))+'%',(img.shape[1] - (img.shape[1]//2),img.shape[0] - 10),cv.FONT_HERSHEY_COMPLEX,1,(0,0,255),thickness=2)
    cv.rectangle(img,(x,y),(x+w,w+h),(0,255,0),thickness=2)

cv.imshow("IMG",img)
cv.waitKey(0)

