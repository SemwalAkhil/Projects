import cv2 as cv
import numpy as np

img = cv.imread("D:/Codes/Python/OPENCV/Photos/wp2.jpg")

#resizing
(width,height) = (img.shape[1],img.shape[0])
dimensions = ( int(width * 0.4) , int(height * 0.4) )
img = cv.resize(img,dimensions,interpolation=cv.INTER_AREA)
#cv.imshow("Img",img)

blank = np.zeros(img.shape,dtype='uint8')
blank2 = np.zeros(img.shape,dtype='uint8')


#gray
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
#cv.imshow("gray",gray)

ret,thres = cv.threshold(gray,125,255,cv.THRESH_BINARY)
                             #thresh #max_val
#threshold attempts to binarise the image >=125 -> 1 else 0
cv.imshow("Threshold",thres)
contours,heirarchy = cv.findContours(thres,cv.RETR_LIST,cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} gray contours found!')
cv.drawContours(blank,contours,-1,(0,255,0),1)
cv.imshow('Gray Drawn',blank)

#blur -> reduces contour
blur = cv.blur(img,(5,5))
#cv.imshow("blur",blur)


#canny 
canny = cv.Canny(img,125,175)
cv.imshow("canny",canny)
contours,heirarchy = cv.findContours(canny,cv.RETR_LIST,cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} canny contours found!')

canny = cv.Canny(blur,125,175)
cv.imshow("canny",canny)
contours,heirarchy = cv.findContours(canny,cv.RETR_LIST,cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} blur contours found!')
cv.drawContours(blank2,contours,-1,(0,255,0),1)
cv.imshow('Canny Drawn',blank2)
#contours -> list of all coordinates of contour
#heirarchy -> heirarchical representation of contours
'''
modes of finding contour
cv.RETR_LIST    -> all contours
cv.RETR_EXTERNAL    -> only external contours
cv.RETR_TREE    -> all heirarchical contours
'''
'''
approximation method
cv.CHAIN_APPROX_NONE    ->  all points of contour
cv.CHAIN_APPROX_SIMPLE -> first and last point of contour
'''



cv.waitKey(0)