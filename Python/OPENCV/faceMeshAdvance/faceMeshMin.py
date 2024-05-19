# imports
import cv2 as cv
import mediapipe as mp
import mediapipe.python.solutions.drawing_utils as mpDraw
import mediapipe.python.solutions.face_mesh as mpFaceMesh
import mediapipe.python.solutions.drawing_styles as mpStyles
import mediapipe.python.solutions.face_mesh_connections as connections
import time

# video input
cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\3.mp4")

# resize function
def resize(img,scale):
    return cv.resize(img,(int(img.shape[1]*scale),int(img.shape[0]*scale)),interpolation=cv.INTER_AREA)

# cTime and pTime for fps calculation
cTime = 0
pTime = 0

# mp class initialisations
conDrawSpec = mpDraw.DrawingSpec((0,255,0),1,1)
lmDrawSpec = mpDraw.DrawingSpec((0,0,255),2,2)
faceMesh = mpFaceMesh.FaceMesh(max_num_faces=2)
"""
(static_image_mode: bool = False, max_num_faces: int = 1, refine_landmarks: bool = False, min_detection_confidence: float = 0.5, min_tracking_confidence: float = 0.5) -> None
static_image_mode: Whether to treat the input images as a batch of static

Initializes a MediaPipe Face Mesh object.

Args:
  static_image_mode: Whether to treat the input images as a batch of static
    and possibly unrelated images, or a video stream. See details in
    https://solutions.mediapipe.dev/face_mesh#static_image_mode.
  max_num_faces: Maximum number of faces to detect. See details in
    https://solutions.mediapipe.dev/face_mesh#max_num_faces.
  refine_landmarks: Whether to further refine the landmark coordinates
    around the eyes and lips, and output additional landmarks around the irises. Default to False. See details in
    https://solutions.mediapipe.dev/face_mesh#refine_landmarks.
  min_detection_confidence: Minimum confidence value ([0.0, 1.0]) for face
    detection to be considered successful. See details in
    https://solutions.mediapipe.dev/face_mesh#min_detection_confidence.
  min_tracking_confidence: Minimum confidence value ([0.0, 1.0]) for the
    face landmarks to be considered tracked successfully. See details in
    https://solutions.mediapipe.dev/face_mesh#min_tracking_confidence.
"""
# reading and processing video frame by frame
while True:
    isTrue,img = cap.read()
    # if next frame exists
    if isTrue:
        # (optional) resizing depending on size
        img = resize(img,0.4)
        # BGR(opencv default) to RGB
        imgRGB = cv.cvtColor(img,cv.COLOR_BGR2RGB)
        # process RGB image using mp's facemesh module
        results = faceMesh.process(imgRGB)
        """Processes an RGB image and returns the face landmarks on each detected face.

        Args:
          image: An RGB image represented as a numpy ndarray.

        Raises:
          RuntimeError: If the underlying graph throws any error.
          ValueError: If the input image is not three channel RGB.

        Returns:
          A NamedTuple object with a "multi_face_landmarks" field that  contains the
          face landmarks on each detected face.
        """
        # if landmarks exist
        if results.multi_face_landmarks:  # type: ignore
            # print(results.multi_face_landmarks)
            # draw landmarks for each face
            for faceLms in results.multi_face_landmarks: # type: ignore
                mpDraw.draw_landmarks(img,faceLms,mpFaceMesh.FACEMESH_CONTOURS,lmDrawSpec,conDrawSpec) # type: ignore
                
                # other posiible styles
                
                # mpDraw.draw_landmarks(img,faceLms,mpFaceMesh.FACEMESH_FACE_OVAL,mpDraw.DrawingSpec(),mpStyles.get_default_face_mesh_tesselation_style(color=[0,255,0]))
                
                # mpDraw.draw_landmarks(img,faceLms,mpFaceMesh.FACEMESH_CONTOURS,mpStyles.get_default_face_mesh_tesselation_style(color=[0,0,255],thickness=1))
                
                # mpDraw.draw_landmarks(img,faceLms,mpFaceMesh.FACEMESH_TESSELATION,None,mpStyles.get_default_face_mesh_tesselation_style(color=[0,255,0],thickness=1))
                for id,lms in enumerate(faceLms.landmark):
                    # print(lms)
                    # screen ratio to coordinates
                    cx,cy = int(lms.x*img.shape[1]),int(lms.y*img.shape[0])
                    # display coordinates on screen
                    cv.putText(img,str(id),(cx,cy),1,1,(255,0,0),1) 
        # fps
        pTime = time.time()
        fps = 1/(pTime-cTime)
        cTime = pTime
        # put fps on screen
        cv.putText(img,str(int(fps)),(20,20),1,1,(255,0,0),1)        
        
        cv.imshow("Video",img)
        if cv.waitKey(1) & 0xff==ord("q"):
            break
    else:
        break
cap.release()
cv.destroyAllWindows()

