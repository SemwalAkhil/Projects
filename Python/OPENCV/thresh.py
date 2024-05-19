import cv2 as cv

img = cv.imread('D:/Codes/Python/OPENCV/Photos/wp2.jpg')
scale = 0.3
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
#cv.imshow("ORG",img)

gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

#simple
threshold,thresh = cv.threshold(gray,150,255,cv.THRESH_BINARY)
                        #img #threshold_value #max_value 
'''
checks each pixel if 
                     value > 150 -> sets to 255 
                            else -> sets to 0
'''
cv.imshow('SIMPLE',thresh)

#simple inverse
threshold,thresh_inv = cv.threshold(gray,150,255,cv.THRESH_BINARY_INV)
cv.imshow('SIMPLE_INVERSE',thresh_inv)

#adaptive mean
adaptive_thresh = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_MEAN_C,cv.THRESH_BINARY,15,3)
#img #max_value # #adaptive_method #thresh_method #kernel_size #c_value to fine_tune
cv.imshow('ADAPTIVE',adaptive_thresh)

#adaptive inverse mean
adaptive_thresh_inv = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_MEAN_C,cv.THRESH_BINARY_INV,11,3)
cv.imshow('ADAPTIVE_INVERSE',adaptive_thresh_inv)

#adaptive gauss
adaptive_thresh = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,cv.THRESH_BINARY,15,3)
#img #max_value # #adaptive_method #thresh_method #kernel_size #c_value to fine_tune
cv.imshow('ADAPTIVE_GAUSS',adaptive_thresh)

#adaptive gauss inverse
adaptive_thresh_inv = cv.adaptiveThreshold(gray,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,cv.THRESH_BINARY_INV,11,3)
cv.imshow('ADAPTIVE_GAUSS_INVERSE',adaptive_thresh_inv)
cv.waitKey(0)