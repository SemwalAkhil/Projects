import faceDetectModule as fm
from faceDetectModule import cv

cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\1.mp4")

pTime = 0
cTime = 0

detector = fm.FaceDetector()

while True:
    isTrue,frame = cap.read()
    if isTrue :
        frame = fm.resize(frame,0.3)

        frame, detectList = detector.findFaces(frame)

        # print(detectList)

        pTime = fm.time.time()
        fps = 1/(pTime - cTime)
        cTime = pTime

        cv.putText(frame,str(int(fps)),(10,30),cv.FONT_HERSHEY_COMPLEX,1,(255,0,0),2)
        cv.imshow("Video",frame)
        
        if cv.waitKey(1) & 0xff==ord('q'):
            break
    else:
        break
cap.release()
cv.destroyAllWindows()
