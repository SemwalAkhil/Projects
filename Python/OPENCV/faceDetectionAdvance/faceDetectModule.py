import cv2 as cv
import mediapipe as mp
import mediapipe.python.solutions.face_detection as mpFaceDetect
import mediapipe.python.solutions.drawing_utils as mpDraw
import time

class FaceDetector():
    """Initializes a MediaPipe Face Detection object.

    Args:
      min_detection_confidence: Minimum confidence value ([0.0, 1.0]) for face
        detection to be considered successful. See details in
        https://solutions.mediapipe.dev/face_detection#min_detection_confidence.
      model_selection: 0 or 1. 0 to select a short-range model that works
        best for faces within 2 meters from the camera, and 1 for a full-range
        model best for faces within 5 meters. See details in
        https://solutions.mediapipe.dev/face_detection#model_selection.
    """
    # initialisation of class
    def __init__(self, min_detection_confidence=0.5, model_selection=0):
        self.minDetectCon = min_detection_confidence
        self.modelSelection = model_selection

        self.faceDetect = mpFaceDetect
        self.mpDraw = mpDraw
        self.faceDetection = self.faceDetect.FaceDetection(self.minDetectCon,self.modelSelection)
    
    # face detection and drawing
    def findFaces(self,frame,draw=True):
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        results = self.faceDetection.process(imgRGB)
        # print(results)
        boxs = []
        if results.detections: # type: ignore
            for id,detection in enumerate(results.detections): # type: ignore
                box = detection.location_data.relative_bounding_box
                iHeight,iWidth,iChannel = frame.shape
                box = (int(box.xmin * iWidth),int(box.ymin * iHeight),int(box.width * iWidth),int(box.height * iHeight))
                boxs.append([id,box,detection.score[0]*100])
                if draw:
                    cv.rectangle(frame,box,(255,0,255),2)
                    cv.putText(frame,f'{int(detection.score[0] * 100)}%',(box[0],box[1]-20),cv.FONT_HERSHEY_SIMPLEX,1,(255,0,255),2)
        return frame,boxs

# frame resizing
def resize(frame,scale):
    return cv.resize(frame,(int(frame.shape[1] * scale),int(frame.shape[0] * scale)),interpolation=cv.INTER_AREA)
     
def main():
    cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\1.mp4")

    pTime = 0
    cTime = 0

    detector = FaceDetector()

    while True:
        isTrue,frame = cap.read()
        if isTrue :
            frame = resize(frame,0.3)

            frame, detectList = detector.findFaces(frame)

            # print(detectList)

            pTime = time.time()
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

if __name__ == "__main__":
    main()