import cv2 as cv
import time
import hand_track_module as htm
import math
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import numpy as np

# managing audio library
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = interface.QueryInterface(IAudioEndpointVolume)
# volume.GetMute()
# volume.GetMasterVolumeLevel()
volTuple = volume.GetVolumeRange()
minVol = volTuple[0]
maxVol = volTuple[1]
# default coordinate of vol set for minimum
vol = 450
volPer = 0

# fps calculation
pTime = 0
cTime = 0

wCam = 480
hCam = 480

cap = cv.VideoCapture(0)
cap.set(3,wCam)
cap.set(4,hCam)
detector = htm.handDetector(minDetectConfidence=0.8)

while True:
    isTrue, frame = cap.read()
    frame = detector.findHands(frame)
    lmDetect = detector.findPosition(frame,draw=False)
    
    # volume rect border 
    cv.rectangle(frame,(50,50),(100,450),(0,255,0),3)
    if len(lmDetect) != 0:
        coT,coF = lmDetect[4][1:],lmDetect[8][1:]
        # print(lmDetect[4],lmDetect[8]) # index denotes landmark
        # calculation of distance between points
        dist = math.hypot(coT[0]-coF[0],coT[1]-coF[1])
        min = 25
        max = 170
        # colors to show min and max volume
        if (dist<min):
            col = (255,255,255)
        elif (dist>max):
            col = (0,255,0)
        else:
            col = (255,0,0)
        # circle on thumb and index finger and line between them
        cv.circle(frame,coT,5,col,5)
        cv.circle(frame,coF,5,col,5)
        cv.line(frame,coT,coF,col,5)
        # converting distance to to equivalent volume
        vol = np.interp(dist,(25,170),(minVol,maxVol))
        # setting system volume
        volume.SetMasterVolumeLevel(vol, None)
        # converting volume to displayable coordinates
        vol = np.interp(vol,(minVol,maxVol),(450,50))
        # converting coordinates to %
        volPer = np.interp(vol,(50,450),(100,0))
        print(volPer)
    
    # volume rect inner
    cv.rectangle(frame,(50,int(vol)),(100,450),(0,255,0),cv.FILLED)
    cv.putText(frame,f'{int(volPer)} %',(50,40),1,1,(0,0,0))
    
    # fps
    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime

    # putting fps on screen
    cv.putText(frame,str(int(fps)),(10,70),cv.  FONT_HERSHEY_SIMPLEX,1.3,(255,0,0),3)
    
    # displaying image
    cv.imshow("Image",frame)
    if (cv.waitKey(10) & 0xFF == ord('q'))  :
        break
# destroying windows after release
cap.release()
cv.destroyAllWindows()