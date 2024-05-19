import cv2 as cv
import time
import hand_track_module as htm
import os


def changeRes(frame,scale):
    return cv.resize(frame,(int(frame.shape[1] * scale),int(frame.shape[0] * scale)),interpolation=cv.INTER_AREA)

# finger count
count = 0
# fps calculation
pTime = 0
cTime = 0
# video capture
cap = cv.VideoCapture(0)
# detector object
detector = htm.handDetector(minDetectConfidence=0.8,maxHands=1)
# folder of images
folderPath = r"D:\Codes\Python\OPENCV\fingerCounter\dataset"
myList = os.listdir(folderPath)
# print(myList)
# list of overlay images
overlayList = []
# check for images in directory
for imPath in myList:
    # appending resized images to overlay list
    image = cv.imread(f'{folderPath}/{imPath}')
    image = changeRes(image,0.3)
    # print(f'{folderPath}/{imPath}')
    overlayList.append(image)
# performing detection on video frame by frame
while True:
    isTrue, frame = cap.read()
    
    frame = detector.findHands(frame)
    lmDetect = detector.findPosition(frame,draw=True)
    
    # if hands detected
    if len(lmDetect) != 0:
        # check for 1st finger
        if lmDetect[8][2] < lmDetect[6][2]:
            # check for 2nd finger
            if lmDetect[12][2] < lmDetect[10][2]:
                # check for 3rd finger
                if lmDetect[16][2] < lmDetect[14][2]:
                    # check for 4th finger
                    if lmDetect[20][2] < lmDetect[18][2]:
                        # check for thumb
                        # check hand type(left/right)
                            # thumb on left of 4th finger -> right
                        if lmDetect[4][1] > lmDetect[20][1]:
                            if lmDetect[4][1] > lmDetect[2][1]:
                                count = 5
                            # if thumb not included -> 4 fingers
                            else:
                                count = 4
                        else:
                            if lmDetect[4][1] < lmDetect[2][1]:
                                count = 5
                            # if thumb not included -> 4 fingers
                            else:
                                count = 4
                    # if 4th not included -> 3 fingers
                    else:
                        count = 3
                # if 3rd not included -> 2 fingers
                else:
                    count = 2
            # if 2nd not included -> 1 fingers
            else:
                count = 1
        # if 1st not included -> 0 fingers
        else:
            count = 0

    # get height,width,channels of overlay image
    h,w,c = overlayList[count].shape
    # overlay the image on already existing image
    frame[0:h,0:w] = overlayList[count] 
    
    # frame calculation
    cTime = time.time()
    fps = 1/(cTime-pTime)
    pTime = cTime

    # putting fps on screen
    cv.putText(frame,"fps: "+str(int(fps)),(480,70),cv.  FONT_HERSHEY_SIMPLEX,1.3,(255,0,0),3)
    
    # displaying image
    cv.imshow("Image",frame)
    if (cv.waitKey(10) & 0xFF == ord('q'))  :
        break

# destroying windows after release
cap.release()
cv.destroyAllWindows()