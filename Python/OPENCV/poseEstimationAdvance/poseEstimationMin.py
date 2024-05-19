import cv2 as cv
import mediapipe as mp
import time

# https://developers.google.com/mediapipe/solutions/vision/pose_landmarker#get_started

# function to change resolution
def changeRes(frame,scale):
    return cv.resize(frame,(int(frame.shape[1] * scale),int(frame.shape[0] * scale)),interpolation=cv.INTER_AREA)

# video to be viewed , 0 for camera
cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\poseEstimationAdvance\Dataset\3.mp4")

# initializing pTime cTime for frame calculation
pTime = 0
cTime = 0

# mp modules for pose and drawing utilities
mpPose = mp.solutions.pose # type: ignore
mpDraw = mp.solutions.drawing_utils # type: ignore


"""
Initializes a MediaPipe Pose object.
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
pose = mpPose.Pose()

while True:
    isTrue, frame = cap.read()
    if isTrue:
        # resizing
        frame = changeRes(frame,0.3) 

        # conversion to rgb
        imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
        # processing pose through module 
        results = pose.process(imgRGB) 

        # pose_landmarks -> x, y, z, visibility
        # print(results.pose_landmarks)

        # checking landmarks in processed image
        if results.pose_landmarks:
            # drawing landmarks
            mpDraw.draw_landmarks(frame,results.pose_landmarks,mpPose.  POSE_CONNECTIONS)
            # id and landmark in list of landmarks
            for id,lm in enumerate(results.pose_landmarks.landmark):
                height ,width ,channels = frame.shape
                # position of landmarks are in ratio to screen size to extract coordinates
                cx ,cy = int(lm.x * width), int(lm.y * height)
                # putting position id on screen at respective position
                cv.putText(frame,str(int(id)),(cx,cy),cv.   FONT_HERSHEY_SIMPLEX,.3,(0,255,0),2)
                # printing id with coordinates
                print(id,cx,cy)

        # calculation of fps
        cTime = time.time()
        fps = 1/(cTime-pTime)
        pTime = cTime

        # putting fps on screen 
        cv.putText(frame,str(int(fps)),(0,50),cv.FONT_ITALIC,1,(0,0,255),1)
        # diplaying video frame by frame 
        cv.imshow("Video",frame)
        # video termination by clicking key after 1 millisecond
        if cv.waitKey(1) & 0xff==ord('q') : # increasing waitkey slows down     video
            break
    # video termination at end of video
    else:
        break
# releasing video and destroying windows
cap.release()
cv.destroyAllWindows()