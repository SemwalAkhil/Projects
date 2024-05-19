import cv2 as cv
from matplotlib.transforms import Bbox
import mediapipe as mp
# mediapipe is a framework developed by google
import time

'''
                    -> Palm Detection -> provides a cropped image of hand from complete image
    HAND TRACKING -
                    -> Hand Landmarks -> applies 21 landmarks on the cropped image of hand
'''


class handDetector():
    # initialisation of class and class variables
    """Initializes a MediaPipe Hand object.

    Args:
      static_image_mode: Whether to treat the input images as a batch of static
        and possibly unrelated images, or a video stream. See details in
        https://solutions.mediapipe.dev/hands#static_image_mode.
      max_num_hands: Maximum number of hands to detect. See details in
        https://solutions.mediapipe.dev/hands#max_num_hands.
      model_complexity: Complexity of the hand landmark model: 0 or 1.
        Landmark accuracy as well as inference latency generally go up with the
        model complexity. See details in
        https://solutions.mediapipe.dev/hands#model_complexity.
      min_detection_confidence: Minimum confidence value ([0.0, 1.0]) for hand
        detection to be considered successful. See details in
        https://solutions.mediapipe.dev/hands#min_detection_confidence.
      min_tracking_confidence: Minimum confidence value ([0.0, 1.0]) for the
        hand landmarks to be considered tracked successfully. See details in
        https://solutions.mediapipe.dev/hands#min_tracking_confidence.
    """
    def __init__(self,mode=False,maxHands=2,complexity=1,minDetectConfidence=0.5,minTrackConfidence=0.5):
        self.mode = mode
        self.maxHands = maxHands
        self.detectionCon = minDetectConfidence
        self.trackCon = minTrackConfidence
        self.complexity = complexity

        self.mpHands = mp.solutions.hands # type: ignore
        self.mpDraw = mp.solutions.drawing_utils # type: ignore
        self.hands = self.mpHands.Hands(self.mode,self.maxHands,self.complexity,self.detectionCon,self.trackCon)
    # detection of hands and landmarks
    def findHands(self,frame,draw=True):
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        self.results = self.hands.process(imgRGB)
        if self.results.multi_hand_landmarks:
            for handLms in self.results.multi_hand_landmarks:
                if draw:
                    self.mpDraw.draw_landmarks(frame, handLms, self.mpHands.HAND_CONNECTIONS)
        # returning modified frame
        return frame

    def findPosition(self,frame,handNo=0,draw=True,drawBox=True):
        self.lmList = []
        xList = []
        yList = []
        bBox = []
        if self.results.multi_hand_landmarks:
            handLms = self.results.multi_hand_landmarks[handNo]
            # drawing landmark on image
            for id,lm in enumerate(handLms.landmark):    
                self.mpDraw.draw_landmarks(frame, handLms, self.mpHands.HAND_CONNECTIONS)
                height ,width ,channels = frame.shape
                cx ,cy = int(lm.x * width), int(lm.y * height)
                # print(id,cx,cy)
                self.lmList.append([id,cx,cy])
                xList.append(cx)
                yList.append(cy)
                
                if draw:
                    cv.putText(frame,str(int(id)),(cx,cy),cv.FONT_HERSHEY_SIMPLEX,.6,(0,255,0),2)
            bBox = [min(xList)-10,min(yList)-10,max(xList)+10,max(yList)+10]
            if drawBox:
                cv.rectangle(frame,(bBox[0],bBox[1]),(bBox[2],bBox[3]),(0,255,0),2)
        return self.lmList,bBox
    
    def fingerUp(self,tipIndex:int):
        if tipIndex == 4:
          if self.lmList[4][1] < self.lmList[20][1]:
              if self.lmList[4][1] < self.lmList[3][1]:
                  return True
              else :
                  return False
          else:
              if self.lmList[4][1] > self.lmList[3][1]:
                  return True
              else :
                  return False
        else :
            if self.lmList[tipIndex][2] < self.lmList[tipIndex-3][2]:
                return True
            else :
                return False
            
            
        
# main function
def main():
    # fps calculation
    pTime = 0
    cTime = 0
    # video capture
    cap = cv.VideoCapture(0)
    # detector object
    detector = handDetector()
    # performing detection on video frame by frame
    while True:
        isTrue, frame = cap.read()
        frame = detector.findHands(frame)
        lmDetect = detector.findPosition(frame)
        # if len(lmDetect) != 0:
        #     print(lmDetect[4]) # index denotes landmark
        
          # if detector.fingerUp(4):
          #   print("Thumb Up")
          # if detector.fingerUp(8):
          #   print("Index Up")
          # if detector.fingerUp(12):
          #   print("Mid Up")
          # if detector.fingerUp(16):
          #   print("Third Up")
          # if detector.fingerUp(20):
          #   print("Last Up")
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


# if script run then automatically calls main function
if __name__ == "__main__":
    main()