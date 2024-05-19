import cv2 as cv
import os
import numpy as np

#list of models of label
#M1 to create people list
'''
people = ['Elon Musk','K L Rahul','Narendra Modi','Rahul Gandhi','Virat Kohli']
'''
#M2 to create people list
people = []
for i in os.listdir('D:/Codes/Python/OPENCV/Photos/dataset'):
    people.append(i)
#print(people)
''''''
DIR = 'D:/Codes/Python/OPENCV/Photos/dataset'
#training set
features = [] #image array
labels = [] #label of image
haar_cascade = cv.CascadeClassifier('D:/Codes/Python/OPENCV/haar_face.xml') #face detector

def create_train():
    for person in people:
        path = os.path.join(DIR,person) #joins individual folder to path
        label = people.index(person) #label iterates through each folder
        for img in os.listdir(path): #img iterates through images in folder
            img_path = os.path.join(path,img) #joins individual image to path
            img_array = cv.imread(img_path)
            
            #improving quality of dataset by resizing and reducing noise
            #increases time of training
            scale = 2
            dim = (int(img_array.shape[1]*scale),int(img_array.shape[0]*scale))
            img_array = cv.resize(img_array,dim,interpolation=cv.INTER_CUBIC)
            img_array = cv.bilateralFilter(img_array,10,30,30)

            gray = cv.cvtColor(img_array,cv.COLOR_BGR2GRAY) #gray
            faces_rect = haar_cascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=3) #rectangle
            for (x,y,w,h) in faces_rect:
                faces_roi = gray[y:y+h,x:x+w] #range_of_interest
                features.append(faces_roi) # type: ignore #appending face to feature
                labels.append(label) # type: ignore #appending corresponding label(index to folder) to labels

create_train()
print("TRAINING COMPLETE!!!")

#print(f"Length of features = {len(features)}") # -> no. of faces detected
#print(f"Length of labels = {len(labels)}") # -> no. of corresponding labels

features = np.array(features,dtype='object') #conversion to np arrays
labels = np.array(labels) #conversion to np arrays

face_recognizer = cv.face.LBPHFaceRecognizer_create() # type: ignore #instantiate face recogniser 

#train the recognizer on the features and the labels list
face_recognizer.train(features,labels)

#in case we do not save to yml file, we have to train the recognizer each time before using it
face_recognizer.save('D:/Codes/Python/OPENCV/face_trained.yml')
np.save('D:/Codes/Python/OPENCV/features.npy',features)
np.save('D:/Codes/Python/OPENCV/labels.npy',features)
''''''
