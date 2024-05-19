import cv2 as cv
import time
import hand_track_module as htm

# fps calculation
pTime = 0
cTime = 0
# video capture
cap = cv.VideoCapture(0)
# detector object
detector = htm.handDetector()
# performing detection on video frame by frame
while True:
    isTrue, frame = cap.read()
    frame = detector.findHands(frame)
    lmDetect = detector.findPosition(frame,draw=False)
    if len(lmDetect) != 0:
        print(lmDetect[4]) # index denotes landmark

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