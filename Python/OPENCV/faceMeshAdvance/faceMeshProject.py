from faceMeshModule import FaceMeshModule
import time
import cv2 as cv

cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\7.mp4")
fmm = FaceMeshModule()
cTime = 0
pTime = 0
while True:
    isTrue,img = cap.read()
    if isTrue:
        img = fmm.resize(img,0.3) # optional
        img,faceLm = fmm.createMesh(img)
        print(len(faceLm))
        print(faceLm[0])
        pTime = time.time()
        fps = 1/(pTime - cTime)
        cTime = pTime
        cv.putText(img,str(int(fps)),(10,30),cv.FONT_HERSHEY_COMPLEX,1,(255,0,0),2)
        cv.imshow("Video",img)
    
        if cv.waitKey(1) & 0xff==ord('q'):
            break
    else:
        break
cap.release()
cv.destroyAllWindows()