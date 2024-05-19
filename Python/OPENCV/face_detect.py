import cv2 as cv

#on image
'''
img = cv.imread("D:/Codes/Python/OPENCV/Photos/download.jpeg")
scale = 0.6
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
#cv.imshow("ORG",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
#cv.imshow("GRAY",gray)
#haar_cascade works on gray images

haar_cascade = cv.CascadeClassifier('D:/Codes/Python/OPENCV/haar_face.xml')
#haar_cascade are very sensitive to noise hence can possibly give different numbers

faces_rect = haar_cascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=7)
#img #scale_factors #no._of_neighbour_to_classify_face
#rectangle coordinates of faces are returned as list

print(f"No. of faces : {len(faces_rect)}")
#one element -> one face

for (x,y,w,h) in faces_rect:
    cv.rectangle(img,(x,y),(x+w,y+h),(0,255,0),thickness=2)

cv.imshow("DETECED FACES",img)
'''
#on video
'''
vid = cv.VideoCapture(0)
haar_cascade = cv.CascadeClassifier('D:/Codes/Python/OPENCV/haar_face.xml')
while True:
    isTrue,frame = vid.read()
    cv.imshow("CAM",frame)
    gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    cv.imshow("GRAY",gray)
    faces_rect = haar_cascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=7)
    for (x,y,w,h) in faces_rect:
        cv.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),thickness=2)
    cv.imshow("DETECTED",frame)
    if cv.waitKey(20) & 0xFF==ord('d'):
        break
vid.release()
cv.destroyAllWindows()
'''