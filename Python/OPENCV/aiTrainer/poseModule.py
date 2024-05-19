import cv2 as cv
import mediapipe as mp
import mediapipe.python.solutions.pose as pose
import mediapipe.python.solutions.drawing_utils as utils
import time
import math

# https://developers.google.com/mediapipe/solutions/vision/pose_landmarker#get_started

# position detector class
class poseDetector():
    """Initializes a MediaPipe Pose object.

    Args:
      static_image_mode: Whether to treat the input images as a batch of static
        and possibly unrelated images, or a video stream. See details in
        https://solutions.mediapipe.dev/pose#static_image_mode.
      model_complexity: Complexity of the pose landmark model: 0, 1 or 2. See
        details in https://solutions.mediapipe.dev/pose#model_complexity.
      smooth_landmarks: Whether to filter landmarks across different input
        images to reduce jitter. See details in
        https://solutions.mediapipe.dev/pose#smooth_landmarks.
      enable_segmentation: Whether to predict segmentation mask. See details in
        https://solutions.mediapipe.dev/pose#enable_segmentation.
      smooth_segmentation: Whether to filter segmentation across different input
        images to reduce jitter. See details in
        https://solutions.mediapipe.dev/pose#smooth_segmentation.
      min_detection_confidence: Minimum confidence value ([0.0, 1.0]) for person
        detection to be considered successful. See details in
        https://solutions.mediapipe.dev/pose#min_detection_confidence.
      min_tracking_confidence: Minimum confidence value ([0.0, 1.0]) for the
        pose landmarks to be considered tracked successfully. See details in
        https://solutions.mediapipe.dev/pose#min_tracking_confidence.
    """
    # class initialisation
    def __init__(self,mode=False,complexity=1,smoothLm=True,segments=False,smoothSegments=True,detectCon=0.5,trackCon=0.5):
        self.mode = mode
        self.complexity =complexity
        self.smoothLm = smoothLm
        self.segments =segments
        self.smoothSegments = smoothSegments
        self.detectCon = detectCon
        self.trackCon = trackCon 
        
        self.mpPose = pose
        self.mpDraw = utils
        self.pose = self.mpPose.Pose(self.mode,self.complexity,self.smoothLm,self.segments,self.smoothSegments,self.detectCon,self.trackCon)

    # finding and drawing position landmarks
    def findPose(self,frame,draw=True):
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        self.results = self.pose.process(imgRGB)
        # pose_landmarks -> x, y, z, visibility
        # print(results.pose_landmarks)
        if self.results.pose_landmarks: # type: ignore
            if draw:    
                self.mpDraw.draw_landmarks(frame,self.results.pose_landmarks,self.mpPose.POSE_CONNECTIONS) # type: ignore
        return frame
    
    # getting a dictionary with {id : position} pair
    def getPos(self,frame,draw=False):
        self.lmDict = {}
        if self.results.pose_landmarks: # type: ignore
          for id,lm in enumerate(self.results.pose_landmarks.landmark): # type: ignore
              height ,width ,channels = frame.shape
              cx, cy = int(lm.x * width), int(lm.y * height)
              self.lmDict[id] = (cx,cy)
              if draw:
                  cv.putText(frame,str(int(id)),(cx,cy),cv.FONT_HERSHEY_SIMPLEX,.3,(0,255,0),2)
        return self.lmDict
    
    # getting angle between three points
    def getAngle(self,frame,p1,p2,p3):
        x1,y1 = self.lmDict[p1]
        x2,y2 = self.lmDict[p2]
        x3,y3 = self.lmDict[p3]
        # print(lmDict[11],lmDict[13],lmDict[15])
        
        cv.line(frame,(x1,y1),(x2,y2),(255,0,255),5)
        cv.line(frame,(x2,y2),(x3,y3),(255,0,255),5)
        cv.circle(frame,(x1,y1),5,(0,0,255),cv.FILLED)
        cv.circle(frame,(x1,y1),15,(0,0,255),2)
        
        cv.circle(frame,(x2,y2),5,(0,0,255),cv.FILLED)
        cv.circle(frame,(x2,y2),15,(0,0,255),2)
        cv.circle(frame,(x3,y3),5,(0,0,255),cv.FILLED)
        cv.circle(frame,(x3,y3),15,(0,0,255),2)
        
        # angle
        angle = math.degrees(math.atan2(y1-y2,x1-x2) - math.atan2(y3-y2,x3-x2))
        if angle<0:
            angle+=360
        return angle
            
# changing resolution
def changeRes(frame,scale=float(-1)):
    imgR = frame.shape[1]/frame.shape[0]
    if scale==-1:
        if imgR > 1:
          return cv.resize(frame,(1280,720),interpolation=cv.INTER_AREA)
        else:
          return cv.resize(frame,(480,640),interpolation=cv.INTER_AREA)
    return cv.resize(frame,(int(frame.shape[1] * scale),int(frame.shape[0] * scale)),interpolation=cv.INTER_AREA)

# demo project
def main():
    cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\poseEstimationAdvance\Dataset\2.mp4")

    pTime = 0
    cTime = 0
    detector = poseDetector()
    while True:
        isTrue, frame = cap.read()
        if isTrue:
          frame = changeRes(frame,0.3)

          frame = detector.findPose(frame,True)
          detector.getPos(frame,True)

          lmDict = detector.getPos(frame)
          print(lmDict[15])
          cv.circle(frame,(lmDict[15][0],lmDict[15][1]),15,(0,0,255),cv.  FILLED)

          cTime = time.time()
          fps = 1/(cTime-pTime)
          pTime = cTime

          cv.putText(frame,str(int(fps)),(0,50),cv.FONT_ITALIC,1,(0,0,255), 1)
          cv.imshow("Video",frame)
          if cv.waitKey(1) & 0xff==ord('q') : # increasing waitkey slows down video
            break
        else:
            break
    cap.release()
    cv.destroyAllWindows()

# if this file is run then main is called else not
if __name__ == "__main__":
    main()
