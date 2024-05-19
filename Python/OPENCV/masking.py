import cv2 as cv
import numpy as np

img = cv.imread('D:/Codes/Python/OPENCV/Photos/wp.png')
scale = 0.4
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
cv.imshow("ORG",img)

blank = np.zeros(img.shape[:2],'uint8')
#cv.imshow("BLANK",blank)

mask = cv.circle(blank,(img.shape[1]//2 - 20,img.shape[0]//2 - 20),100,255,-1)  # type: ignore
cv.imshow("MASK",mask)

masked = cv.bitwise_and(img,img,mask=mask) #applies mask to img then performs and
cv.imshow("MASKED",masked)

cv.waitKey(0)