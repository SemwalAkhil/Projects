# imports
import cv2 as cv
import mediapipe as mp
import mediapipe.python.solutions.drawing_utils as mpDraw
import mediapipe.python.solutions.face_mesh as mpFaceMesh
import mediapipe.python.solutions.drawing_styles as mpStyles
import mediapipe.python.solutions.face_mesh_connections as connections
import time

class FaceMeshModule():
    def __init__(self,static_image_mode: bool = False, max_num_faces: int = 2, refine_landmarks: bool = False, min_detection_confidence: float = 0.5, min_tracking_confidence: float = 0.5):
        
        self.static_image_mode = static_image_mode 
        self.max_num_faces = max_num_faces
        self.refine_landmarks = refine_landmarks
        self.min_detection_confidence = min_detection_confidence
        self.min_tracking_confidence = min_tracking_confidence
        
        self.conDrawSpec = mpDraw.DrawingSpec((0,255,0),1,1)
        self.lmDrawSpec = mpDraw.DrawingSpec((0,0,255),2,2)
        self.faceMesh = mpFaceMesh.FaceMesh(self.static_image_mode,self.max_num_faces,self.refine_landmarks,self.min_detection_confidence,self.min_tracking_confidence)
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
    def createMesh(self,img,displayLms: bool = True,displayCount: bool = False):
        imgRGB = cv.cvtColor(img,cv.COLOR_BGR2RGB)
        # process RGB image using mp's facemesh module
        results = self.faceMesh.process(imgRGB)
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
        faces = []
        if results.multi_face_landmarks:  # type: ignore
            for faceLms in results.multi_face_landmarks: # type: ignore
                if displayLms == True:
                    mpDraw.draw_landmarks(img,faceLms,mpFaceMesh.FACEMESH_CONTOURS,self.lmDrawSpec,self.conDrawSpec) # type: ignore
                face = []
                for id,lms in enumerate(faceLms.landmark):
                    cx,cy = int(lms.x*img.shape[1]),int(lms.y*img.shape[0])
                    # display coordinates on screen
                    if displayCount == True:
                        cv.putText(img,str(id),(cx,cy),1,1,(255,0,0),1)
                    face.append((cx,cy))
                faces.append(face)
        return img,faces
    def resize(self,img,scale):
        return cv.resize(img,(int(img.shape[1]*scale),int(img.shape[0]*scale)),interpolation=cv.INTER_AREA)

def main():
    cap = cv.VideoCapture(r"D:\Codes\Python\OPENCV\faceDetectionAdvance\Dataset\7.mp4")
    fmm = FaceMeshModule()
    cTime = 0
    pTime = 0
    while True:
        isTrue,img = cap.read()
        if isTrue:
            img = fmm.resize(img,0.3) # optional
            img,faceLm = fmm.createMesh(img)
            print(len(faceLm))

            pTime = time.time()
            fps = 1/(pTime - cTime)
            cTime = pTime

            cv.putText(img,str(int(fps)),(10,30),cv.FONT_HERSHEY_COMPLEX,1,(255,0,0),2)
            cv.imshow("Video",img)
        
            if cv.waitKey(1) & 0xff==ord('q'):
                break
        else:
            break
    cap.release()
    cv.destroyAllWindows()

if __name__ == "__main__":
    main()