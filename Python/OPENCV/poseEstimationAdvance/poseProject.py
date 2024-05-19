import cv2 as cv
import time
# importing created module
import poseModule as pm

cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\poseEstimationAdvance\Dataset\2.mp4")

pTime = 0
cTime = 0
detector = pm.poseDetector()

while True:
    isTrue, frame = cap.read()
    if isTrue:
        frame = pm.changeRes(frame,0.3)

        frame = detector.findPose(frame,True)
        detector.getPos(frame,True)
        lmDict = detector.getPos(frame)
        print(lmDict[15])
        cv.circle(frame,(lmDict[15][0],lmDict[15][1]),15,(0,0,255),cv.FILLED)

        cTime = time.time()
        fps = 1/(cTime-pTime)
        pTime = cTime
        cv.putText(frame,str(int(fps)),(0,50),cv.FONT_ITALIC,1,(0,0,255),1)
        cv.imshow("Video",frame)
        if cv.waitKey(1) & 0xff==ord('q') : # increasing waitkey slows down video
            break
    else:
        break
cap.release()
cv.destroyAllWindows()