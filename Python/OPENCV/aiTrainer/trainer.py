import cv2 as cv
import time
import numpy as np
# importing created module
import poseModule as pm

cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\aiTrainer\dataset\2.mp4")
# cap = cv.VideoCapture(0)

# fps generation
pTime = 0
cTime = 0

# counter
per = 0
dir = 0
count = 0

# detector
detector = pm.poseDetector(detectCon=0.8,trackCon=0.8)

while True:
    isTrue, frame = cap.read()
    if isTrue:
        # resizing (preferred for better display)
        frame = pm.changeRes(frame)
        # applying detector on image
        frame = detector.findPose(frame,True)
        # getting landmark positions
        lmDict = detector.getPos(frame)
        if lmDict != {}:
            # left arm
            angle = detector.getAngle(frame,11,13,15)
            cv.putText(frame,str(int(angle)),(lmDict[13][0]-20,lmDict[13][1]-20),cv.FONT_HERSHEY_SIMPLEX,1,(255,0,0),3)
            # right arm
            # cv.putText(frame,str(int(detector.getAngle(frame,16,14,12))),(lmDict[14][0]-20,lmDict[14][1]-20),cv.FONT_HERSHEY_SIMPLEX,1,(255,0,0),3)
            
            # converting angle to %
            per = np.interp(angle,(60,150),(0,100))
            ''' 
            assuming relaxed at starting point

            dir = 0, per = 100 -> dir = 1, per < 100 -> dir = 1, per 0 -> dir = 0, per > 0

            '''
            if per==100:
                if dir == 0:
                    count+= 0.5
                    dir = 1
            if per==0:
                if dir == 1:
                    count+= 0.5
                    dir = 0

        # putting count and other details on screen
        cv.putText(frame,f"{int(count)}",(int(frame.shape[1]-(frame.shape[1]/2)),int(frame.shape[0]-100)),cv.FONT_HERSHEY_SIMPLEX,2,(255,255,0),5)
        # cv.putText(frame,f"{int(dir)}",(150,650),cv.FONT_HERSHEY_SIMPLEX,2,(255,255,0),5)
        # cv.putText(frame,f"{int(per)}",(150,700),cv.FONT_HERSHEY_SIMPLEX,2,(255,255,0),5)

        # percent to rect coordinates
        val = np.interp(per,(0,100),(300,10))
        cv.putText(frame,f"{int(per):03d}%",(int(frame.shape[1]-150),350),cv.FONT_HERSHEY_SIMPLEX,2,(255,255,0),5)
        cv.rectangle(frame,(int(frame.shape[1]-100),10),(int(frame.shape[1]-50),300),(255,255,255),2)
        cv.rectangle(frame,(int(frame.shape[1]-100),int(val)),(int(frame.shape[1]-50),300),(0,255,0),cv.FILLED)

        # frame calculation
        cTime = time.time()
        fps = 1/(cTime-pTime)
        pTime = cTime

        # displaying frame and fps
        cv.putText(frame,"fps:"+str(int(fps)),(0,50),cv.FONT_ITALIC,2,(0,0,255),5)
        cv.imshow("Video",frame)
        if cv.waitKey(1) & 0xff==ord('q') : # increasing waitkey slows down video
            break
    else:
        break
# releasing frame
cap.release()
cv.destroyAllWindows()