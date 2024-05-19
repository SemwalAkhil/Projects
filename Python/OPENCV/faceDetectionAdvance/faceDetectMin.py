import cv2 as cv
import mediapipe as mp
import mediapipe.python.solutions.face_detection as mpFaceDetect
import mediapipe.python.solutions.drawing_utils as mpDraw
import time

# resizing frame
def resize(frame,scale):
    return cv.resize(frame,(int(frame.shape[1] * scale),int(frame.shape[0] * scale)),interpolation=cv.INTER_AREA)

# video input
cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\1.mp4")
# webcam input
# cap = cv.VideoCapture(0)

# variable initialisation - to be used in fps calculation
pTime = 0
cTime = 0

# Face detection module
faceDetection = mpFaceDetect.FaceDetection()

while True:
    # capturing frame by frame
    isTrue,frame = cap.read()
    '''
    isTrue (bool) -> next frame exist
    frame (frame) -> frame of video
    '''
    if isTrue :
        # resizing to suitable screen size (optional)
        frame = resize(frame,0.2)
        # converting BGR(default) image to RGB
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        # processing frame through face detection module
        results = faceDetection.process(imgRGB)
        # print(results)

        # if their are detection in results
        if results.detections: # type: ignore
            # assigning ids to detection
            for id,detection in enumerate(results.detections): # type: ignore
                '''
                print(id,detection)

                # prints the confidence of detection(0-1)
                print(detection.score)
                
                # prints details of the box enclosing the face 
                print(detection.location_data.relative_bounding_box)
                
                # drawing detections
                mpDraw.draw_detection(frame,detection)
                '''
                # getting details of the box enclosing face
                box = detection.location_data.relative_bounding_box
                # frame size
                iHeight,iWidth,iChannel = frame.shape
                # converting box details from screen ratio to coordinates
                box = (int(box.xmin * iWidth),int(box.ymin * iHeight),int(box.width * iWidth),int(box.height * iHeight))
                # making box through coordinates
                cv.rectangle(frame,box,(255,0,255),2)
                # putting detection confidence on frame
                cv.putText(frame,f'{int(detection.score[0] * 100)}%',(box[0],box[1]-20),cv.FONT_HERSHEY_SIMPLEX,1,(255,0,255),2)
                
        # calculation of fps
        pTime = time.time()
        fps = 1/(pTime - cTime)
        cTime = pTime

        # putting fps and displaying frame on screen
        cv.putText(frame,str(int(fps)),(10,30),cv.FONT_HERSHEY_COMPLEX,1,(255,0,0),2)
        cv.imshow("Video",frame)
        
        # breaking loop on key press
        if cv.waitKey(1) & 0xff==ord('q'):
            break
    # breaking loop on video end
    else:
        break
# releaing video and destroying frames 
cap.release()
cv.destroyAllWindows()