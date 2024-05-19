import cv2 as cv
import mediapipe as mp
import time

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
        
        self.mpPose = mp.solutions.pose # type: ignore
        self.mpDraw = mp.solutions.drawing_utils # type: ignore
        self.pose = self.mpPose.Pose(self.mode,self.complexity,self.smoothLm,self.segments,self.smoothSegments,self.detectCon,self.trackCon)

    # finding and drawing position landmarks
    def findPose(self,frame,draw=True):
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        self.results = self.pose.process(imgRGB)
        # pose_landmarks -> x, y, z, visibility
        # print(results.pose_landmarks)
        if self.results.pose_landmarks:
            if draw:    
                self.mpDraw.draw_landmarks(frame,self.results.pose_landmarks,self.mpPose.POSE_CONNECTIONS)
        return frame
    
    # getting a dictionary with {id : position} pair
    def getPos(self,frame,draw=True):
        lmDict = {}
        for id,lm in enumerate(self.results.pose_landmarks.landmark):
            height ,width ,channels = frame.shape
            cx, cy = int(lm.x * width), int(lm.y * height)
            lmDict[id] = (cx,cy)
            if draw:
                cv.putText(frame,str(int(id)),(cx,cy),cv.FONT_HERSHEY_SIMPLEX,.3,(0,255,0),2)
        return lmDict
            
# changing resolution
def changeRes(frame,scale):
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
