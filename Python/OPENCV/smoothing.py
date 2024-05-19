import cv2 as cv 

img = cv.imread('D:/Codes/Python/OPENCV/Photos/iphone.jpg')
scale = 2
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_CUBIC)
cv.imshow("ORG",img)

#averaging
avg = cv.blur(img,(3,3))
'''
kernel size 3 x 3
     _ _ _
    |_|_|_|  this kernel of 3px x 3px is passed throughout the image  
    |_|_|_|  the blur of center pixle is adjusted by average of 
    |_|_|_|  surrounding 8px
'''
cv.imshow("AVG",avg)

#gaussian
gauss = cv.GaussianBlur(img,(3,3),sigmaX=0)
#sigma x -> deviation in x
cv.imshow("GAUSS",gauss)

#medaian
median = cv.medianBlur(img,3)
#assumes 3 x 3 kernel
cv.imshow("MEDIAN",median)

#bilateral -> retains edges
bilateral = cv.bilateralFilter(img,10,30,30)
    # src #diameter of kernel #colorSigma -> colors of surrounding considered #spaceSigma -> distance of surrounding considered
    #large sigma values lead to higher blur
cv.imshow("BILATERAL",bilateral)

cv.waitKey(0)
