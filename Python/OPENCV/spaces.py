import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread("D:/Codes/Python/OPENCV/Photos/wp2.jpg")
dim = (int(img.shape[1] *0.25) , int(img.shape[0] *0.25))
img = cv.resize(img,dim,interpolation=cv.INTER_AREA)
#cv.imshow("BGR",img)

#matplot follows rgb colors
'''  
plt.imshow(img)
plt.show()
'''
#gray
'''
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("GRAY",gray)
gray_rev = cv.cvtColor(gray,cv.COLOR_GRAY2BGR)
cv.imshow("GRAY_REV",gray_rev)
'''
#rgb -> inverse of bgr format
'''
rgb = cv.cvtColor(img,cv.COLOR_BGR2RGB)
cv.imshow("RGB",rgb)
rgb_rev = cv.cvtColor(rgb,cv.COLOR_RGB2BGR)
cv.imshow("RGB_REV",rgb_rev)
'''
'''
plt.imshow(rgb)
plt.show()
'''
#hsv -> hue saturation value
'''
hsv = cv.cvtColor(img,cv.COLOR_BGR2HSV)
cv.imshow("HSV",hsv)
hsv_rev = cv.cvtColor(hsv,cv.COLOR_HSV2BGR)
cv.imshow("HSV_REV",hsv_rev)
'''
#lab
'''
lab = cv.cvtColor(img,cv.COLOR_BGR2LAB)
cv.imshow("LAB",lab)
lab_rev = cv.cvtColor(lab,cv.COLOR_LAB2BGR)
cv.imshow("LAB_REV",lab_rev)
'''
cv.waitKey(0)