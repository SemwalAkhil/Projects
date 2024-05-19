import cv2 as cv
import mediapipe as mp
import hand_track_module as htm
import autopy # supported on python 3.8
import time
import numpy as np

# CONSTANTS
VID_WIDTH = 720
VID_HEIGHT = 480
W_SCR , H_SCR = autopy.screen.size()
FRAME_R = 100
SMOOTHEN = 5
DELAY = 0.5

# FUNCTIONS
def changeRes(frame,height,width):
    return cv.resize(frame,(width,height),interpolation=cv.INTER_CUBIC)

# VIDEO CAPTURE
cap = cv.VideoCapture(0)

# FPS VARIABLE
cTime = 0
pTime = 0

# LOCATION VARIABLE
pLocX , pLocY = 0,0
cLocX , cLocY = 0,0

# MOUSE LOCATION
xMouse,yMouse = autopy.mouse.location()

# DETECTOR OBJECT
detector = htm.handDetector(maxHands=1,minDetectConfidence=0.2,minTrackConfidence=0.2)

while True:
    isTrue,frame = cap.read()
    frame  = changeRes(frame,VID_HEIGHT,VID_WIDTH)
    frame = cv.flip(frame,1)

    frame = detector.findHands(frame)
    lmDetect,bBox = detector.findPosition(frame)

    '''
    0 up -> move
    thumb up -> scroll
    index up -> left click
    index + middle up -> right click
    '''
    # IF HAND DETECTED
    if len(lmDetect) != 0:
        # FRAME RECTANGLE -> AVOID PLACING HANDS OUTSIDE FRAME AS IT MAY LEAD TO CRASH
        cv.rectangle(frame,(FRAME_R,FRAME_R),(VID_WIDTH-FRAME_R,VID_HEIGHT-FRAME_R),(255,0,255),2)
        # IF INDEX FINGER UP
        if detector.fingerUp(8):
            # IF INDEX + MIDDLE FINGER
            if detector.fingerUp(12):
                # RIGHT CLICK
                autopy.mouse.click(autopy.mouse.Button.RIGHT)
            # ONLY INDEX FINGER UP
            else:  
                # LEFT CLICK
                autopy.mouse.click()
            # DELAY TO AVOID CONSECUTIVE MOUSE CLICKS
            time.sleep(DELAY)
        # IF NO FINGER UP
        else:
            # POSITION OF TIP OF FOLDED INDEX
            x1,y1 = lmDetect[8][1:]
            # CONVERTING VIDEO COORDINATES TO SCREEN COORDINATES
            cLocX = np.interp(x1,(FRAME_R,VID_WIDTH-FRAME_R),(0,W_SCR))
            cLocY = np.interp(y1,(FRAME_R,VID_HEIGHT-FRAME_R),(0,H_SCR))
            # DRAWING CIRCLE ON INDEX TIP
            cv.circle(frame,(x1,y1),10,(200,0,200),cv.FILLED)
            # SMOOTHENING COORDINATES BEFORE PASSING TO MOUSE TO AVOID FLICKERS
            xMouse = pLocX + (cLocX - pLocX)/SMOOTHEN
            yMouse = pLocY + (cLocY - pLocY)/SMOOTHEN
        # MOVING MOUSE
        autopy.mouse.move(xMouse,yMouse)
        pLocX = xMouse
        pLocY = yMouse

    # FRAME CALCULATION
    pTime = time.time()
    fps = 1/(pTime-cTime)
    cTime = pTime

    # DISPLAYING FPS AND FRAME
    cv.putText(frame,f"{int(fps)}",(int(VID_WIDTH*0.01),int(VID_HEIGHT*0.1)),cv.FONT_HERSHEY_TRIPLEX,2,(0,0,255),3)
    cv.imshow("Capture",frame)

    # ENDING VIDEO
    if (cv.waitKey(10) & 0xFF== ord("q")):
        print("Closed")
        break
cap.release()
cv.destroyAllWindows()


