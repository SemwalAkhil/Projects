import cv2 as cv
import numpy as np

#gradients are similar to edges in image

img = cv.imread('D:/Codes/Python/OPENCV/Photos/wp2.jpg')
scale = 0.3
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
cv.imshow("ORG",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

#laplacian
lap = cv.Laplacian(gray,cv.CV_64F) # type: ignore
#img #data_depth
lap = np.uint8(np.absolute(lap))
'''
lap gives slope which can occasionaly be negative so we take absolute value which is then converted to uint8 
'''
cv.imshow('LAPLACIAN',lap) # type: ignore

#sobel -> calculates gradient in x and y direction
sobelx = cv.Sobel(gray,cv.CV_64F,1,0) # type: ignore
sobely = cv.Sobel(gray,cv.CV_64F,0,1) # type: ignore
sobelxy = cv.Sobel(gray,cv.CV_64F,1,1) # type: ignore

cv.imshow("SOBELX",sobelx)
cv.imshow("SOBELY",sobely)
cv.imshow("SOBELXY",sobelxy)

#canny
canny = cv.Canny(gray,150,175)
cv.imshow("CANNY",canny)
cv.waitKey(0)