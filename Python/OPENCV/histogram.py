import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np

img = cv.imread('D:/Codes/Python/OPENCV/Photos/wp2.jpg')
scale = 0.4
dim = (int(img.shape[1]*scale),int(img.shape[0]*scale))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
cv.imshow("ORG",img)

#mask
blank = np.zeros((dim[1],dim[0]),'uint8')
circle = cv.circle(blank,(int(dim[0]//2) - 20,int(dim[1]//2) - 20),100,255,-1) # type: ignore

#grayscale histogram
'''
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
#cv.imshow("GRAY",gray)

#masking (optional)
masked = cv.bitwise_and(gray,gray,mask=circle)
cv.imshow("MASKED",masked)

gray_hist = cv.calcHist([gray],[0],circle,[256],[0,256])
    #list of images #channels #channels #mask #bins #range of possible pixel value

plt.figure()
plt.title('Gray Histogram')
plt.xlabel('Bins')
plt.ylabel('No. of pixel')
plt.plot(gray_hist)
plt.xlim([0,256])
plt.show()
'''
#color histogram
'''
masked = cv.bitwise_and(img,img,mask=circle)
cv.imshow("MASKED",masked)

plt.figure()
plt.title('Color Histogram')
plt.xlabel('Bins')
plt.ylabel('No. of pixel')
color = ('b','g','r')
for i,col in enumerate(color):
    hist = cv.calcHist([img],[i],circle,[256],[0,256])
    plt.plot(hist,color=col)
plt.xlim([0,256])
plt.show()
'''
cv.waitKey(0)