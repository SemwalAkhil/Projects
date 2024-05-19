import cv2 as cv
import numpy as np

blank = np.zeros((400,400),'uint8')

rect = cv.rectangle(blank.copy(),(100,100),(300,300),255,-1)
cv.imshow("RECTANGLE",rect)

cir = cv.circle(blank.copy(),(200,200),125,255,-1) # type: ignore
cv.imshow("CIRCLE",cir)

#and -> intersection
andIm = cv.bitwise_and(rect,cir)
cv.imshow("AND",andIm)

#or -> union
orIm = cv.bitwise_or(rect,cir)
cv.imshow("OR",orIm)

#xor -> not intersection
xorIm = cv.bitwise_xor(rect,cir)
cv.imshow("XOR",xorIm)

#not -> inverse
notIm = cv.bitwise_not(rect)
cv.imshow("NOT RECT",notIm)

notIm = cv.bitwise_not(cir)
cv.imshow("NOT CIR",notIm)



cv.waitKey(0)