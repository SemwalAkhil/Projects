import cv2 as cv
import mediapipe as mp
# mediapipe is a framework developed by google
import time

'''
                    -> Palm Detection -> provides a cropped image of hand from complete image
    HAND TRACKING -
                    -> Hand Landmarks -> applies 21 landmarks on the cropped image of hand
'''

cap = cv.VideoCapture(0)
mpHands = mp.solutions.hands # type: ignore
mpDraw = mp.solutions.drawing_utils # type: ignore

# static_image_mode -> True/False -> if true then always detect and track
#                   -> if false then it detects and if good detecting confidence then it tracks if poor tracking confidence then returns to detectio -> default(False)
# max number of hands -> default(2)
# min detection confidence -> default(0.5)
# min tracking confidence -> default(0.5)
hands = mpHands.Hands()

pTime = 0
cTime = 0


while True:
    isTrue, frame = cap.read()

    # mpHands uses rgb images so we need to convert
    imgRGB = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
    
    # process image
    results = hands.process(imgRGB)

    # print coordinates of hand landmarks
    # print(results.multi_hand_landmarks)

    # hand is detected
    if results.multi_hand_landmarks:
        # hand landmarks in results
        for handLms in results.multi_hand_landmarks:
            #                     <src> <handlandmark> <connection>            
            mpDraw.draw_landmarks(frame, handLms, mpHands.HAND_CONNECTIONS)
            # mpHands.HAND_CONNECTIONS is optional which makes lines between the points tracked by draw_landmarks function

            # id -> id label(number) of landmark
            # lm -> position ratio(i.e. ratio to complete image) of landmarks
            for id,lm in enumerate(handLms.landmark):    
                mpDraw.draw_landmarks(frame, handLms, mpHands.HAND_CONNECTIONS)

                # displaying landmarks
                height ,width ,channels = frame.shape
                cx ,cy = int(lm.x * width), int(lm.y * height)
                cv.putText(frame,str(int(id)),(cx,cy),cv.FONT_HERSHEY_SIMPLEX,.6,(0,255,0),2)

    # measuring frames
    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime

    # putting frames on screen
    cv.putText(frame,str(int(fps)),(10,70),cv.FONT_HERSHEY_SIMPLEX,1.3,(255,0,0),3)

    # showing images
    cv.imshow("Image",frame)
    if (cv.waitKey(10) & 0xFF == ord('q'))  :
        break

cap.release()
cv.destroyAllWindows()
