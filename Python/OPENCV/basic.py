import cv2 as cv

img = cv.imread('D:/Codes/Python/OPENCV/Photos/logo.png')
cv.imshow('Color',img)

#convert to gray
'''
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("Gray",gray)
'''
#blur
'''
blur = cv.GaussianBlur(img,(0,9),cv.BORDER_DEFAULT)
#we can adjust ksize and size ^ for various blurs
cv.imshow('Blur',blur)
'''
#edge cascade
'''
canny = cv.Canny(img,100,100)
cv.imshow('Canny',canny)
'''
#dilating
'''
#preferred for canny images
dilated = cv.dilate(img,(3,3),iterations=3) # type: ignore
cv.imshow('Dilate',dilated)
dilated2 = cv.dilate(canny,(3,3),iterations=2) # type: ignore
#increase iterations for bolder dilations
cv.imshow('Dilate2',dilated2)
'''
#erroding
'''
#used to reduce dilation
erroded = cv.erode(dilated,(3,3),iterations=3) # type: ignore
cv.imshow('Erroded',erroded)
#preferred for canny images
erroded2 = cv.erode(dilated2,(3,3),iterations=2) # type: ignore
#increase iterations for bolder dilations
cv.imshow('Erroded2',erroded2)
'''
#resize
'''
resized = cv.resize(img,(500,1000))
cv.imshow("Resized",resized)
resized2 = cv.resize(img,(500,1000),interpolation=cv.INTER_CUBIC)
#interpolation cubic slowest but best quality
cv.imshow("Resized2",resized2)
'''
#cropping
'''
cropped = img[50:200,200:400] #since image is a matrix
cv.imshow('Cropped',cropped)
'''
cv.waitKey(0)