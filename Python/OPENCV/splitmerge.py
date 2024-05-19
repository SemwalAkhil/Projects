import cv2 as cv
import numpy as np

img = cv.imread('D:/Codes/Python/OPENCV/Photos/logo.png')
dim = (int(img.shape[1]*0.25),int(img.shape[0]*0.25))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
cv.imshow('ORG',img)
print(f'{img.shape} : original')
        # x , y , color_channels(bgr)

blank = np.zeros(img.shape[:2],'uint8')

#color split
b,g,r = cv.split(img)


cv.imshow("BLUE",b)
print(f'{b.shape} : blue')
cv.imshow("GREEN",g)
print(f'{g.shape} : green')
cv.imshow("RED",r)
print(f'{r.shape} : red')

#merge
merged = cv.merge([b,g,r])
cv.imshow("MERGED",merged)
blue = cv.merge([b,blank,blank])
cv.imshow("BLUE_MERGE",blue)
green = cv.merge([blank,g,blank])
cv.imshow("GREEN_MERGE",green)
red = cv.merge([blank,blank,r])
cv.imshow("RED_MERGE",red)

cv.waitKey(0)