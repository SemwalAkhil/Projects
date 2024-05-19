
import cv2 as cv
import time
import os
import hand_track_module as htm
import numpy as np

# CONSTANTS
FRAME_WIDTH = 1080
FRAME_HEIGHT = 720
COLOR = ((255,0,0),(0,255,0),(0,0,255),(255,255,0),(0,255,255),(255,0,255),(255,255,255))
BLACK = (0,0,0)
PEN_SIZE = 10
ERASER_SIZE = 80
# 

# RESOLUTION CHANGE 
def changeRes(frame,width=FRAME_WIDTH,height=FRAME_HEIGHT):
    return cv.resize(frame,(int(width),int(height)),interpolation=cv.INTER_AREA)
#

# FPS CALCULATION
pTime = 0
cTime = 0

# VIDEO CAPTURE
cap = cv.VideoCapture(0)
# DETECTOR OBJECT
detector = htm.handDetector(minDetectConfidence=0.2,minTrackConfidence=0.2)

# INDEX TO ITERATE THROUGH COLORS
colorInd = 0

# PREVIOUS X AND Y
px , py = 0,0

# BLANK CANVAS
imgCanvas = np.zeros((FRAME_HEIGHT,FRAME_WIDTH,3),np.uint8)

# CHECK THUMBDOWN
thumbDown = True

while True:
    isTrue, frame = cap.read()
    frame = changeRes(frame)
    # HORIZONTALLY FLIP IMAGE
    frame = cv.flip(frame,1)
    # FINDING AND DRAWING HAND LANDMARKS
    frame = detector.findHands(frame,draw=True)
    # FIND POSITIONS
    lmDetect = detector.findPosition(frame,draw=True)
    # IF HAND DETECTED
    if len(lmDetect) != 0:
        # POSITION OF TIP OF THUMB
        thumX,thumY = lmDetect[4][1],lmDetect[4][2]
        # IF RIGHT HAND
        if thumX < lmDetect[20][1]: 
            # POSITION OF TIP OF INDEX AND MID 
            indeX,indeY = lmDetect[8][1],lmDetect[8][2]
            midX,midY = lmDetect[12][1],lmDetect[12][2]
            # IF INDEX FINGER UP I.E. Y OF TIP < Y OF BASE
            if indeY < lmDetect[5][2]:
                # IF MIDDLE FINGER UP
                if midY < lmDetect[9][2]:
                    # IF BOTH UP ERASE
                    cv.line(imgCanvas,(px,py),(int(indeX),int(indeY)),BLACK,ERASER_SIZE)
                else:
                    # IF ONLY INDEX UP DRAW
                    cv.circle(frame,(int(indeX),int(indeY)),10,(COLOR[colorInd]),cv.FILLED)
                    if px != 0 and py != 0:
                        # IF PREVIOUS VALUE OF px py NOT EQUAL TO DEFAULT
                        cv.line(imgCanvas,(px,py),(int(indeX),int(indeY)),(COLOR[colorInd]),PEN_SIZE)
            # IF THUMB UP
            elif (thumX < lmDetect[3][1]) and thumbDown:
                # INDEXING IN ROTATION
                if colorInd < 6:
                    colorInd +=1
                else:
                    colorInd = 0
                # DRAW CIRCLE OF CURRENT PEN COLOR
                cv.circle(frame,(lmDetect[0][1],lmDetect[0][2]),50,COLOR[colorInd],cv.FILLED)
                thumbDown = False
            # IF THUMB DOWN
            elif (thumX > lmDetect[3][1]):
                thumbDown = True
            # STORES VALUE OF LAST POSITION OF INDEX
            px,py = int(indeX),int(indeY)

        # DRAW ON FRAME -> FOR GOOD LIGHTNING 
        '''
        imgGray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
        _,imgInv = cv.threshold(imgGray,50,255,cv.THRESH_BINARY_INV)
        imgInv = cv.cvtColor(imgInv,cv.COLOR_GRAY2BGR)
        print(imgInv.shape)
        frame = cv.bitwise_and(frame,imgInv)
        frame = cv.bitwise_or(frame,imgCanvas)
        '''
    
    # FPS CALCULATION
    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime

    # OVERLAPPING IMAGE CANVAS ON FRAME -> WORKS EVEN IN POOR LIGHT
    frame = cv.addWeighted(frame,0.8,imgCanvas,0.8,0)
    
    # PUTTING FPS ON SCREEN
    cv.putText(frame,str(int(fps)),(10,70),cv.  FONT_HERSHEY_SIMPLEX,1.3,(255,0,0),3)
    # INSTRUCTIONS
    cv.putText(frame,"THUMB -> COLOR CHANGE, INDEX -> DRAW, INDEX + MID -> ERASE",(int(frame.shape[1]//2 - 10),20),1,1,(0,0,255),1)
    # DISPLAYING IMAGE
    cv.imshow("Image",frame)
    # cv.imshow("Canvas",imgCanvas)
    if (cv.waitKey(10) & 0xFF == ord('q')):
        break
# DESTROYING WINDOWS
cap.release()
cv.destroyAllWindows()