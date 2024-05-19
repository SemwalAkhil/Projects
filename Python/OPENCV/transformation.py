import cv2 as cv
import numpy as np

img = cv.imread('D:/Codes/Python/OPENCV/Photos/iphone.jpg')
cv.imshow("Iphone",img)

#translation
# -x -> left
# x -> right
# -y -> up
# y -> down
def translate(img,x,y):
    transMat = np.float32([[1,0,x],[0,1,y]]) # type: ignore
    '''
    1. Defining the translation matrix:

    transMat: This variable stores the transformation matrix that defines   the translation.
    np.float32: This specifies that the matrix elements will be stored in   the 32-bit floating-point format for efficient memory usage.
    [[1,0,x],[0,1,y]]: This is the actual translation matrix. It looks like     this:
    | 1 0 x |
    | 0 1 y |
    | 0 0 1 |
    The diagonal elements (1, 1) represent no scaling, while the    off-diagonal elements (0, 0) are for shearing (not used here).
    x and y define the horizontal and vertical shifts, respectively.
    '''
    dimensions = (img.shape[1],img.shape[0])
                  #width       #height
    '''
    2. Getting image dimensions:

    dimensions: This variable stores the image dimensions as a tuple    ((width, height)) using img.shape. This information is needed for the  next step.
    '''
    return cv.warpAffine(img,transMat,dimensions)  # type: ignore
    '''
    3. Applying the translation:

    cv.warpAffine(img, transMat, dimensions): This line uses the OpenCV     warpAffine function to apply the transformation defined by transMat to  the image (img). dimensions specifies the output image size.
    '''

def rotate(img,angle,rotPoint=None):
    (height,width) = img.shape[:2]
    if rotPoint is None :
        rotPoint = (width//2,height//2)
    rotMat = cv.getRotationMatrix2D(rotPoint,angle,1)
                                                   #scale
    dimensions = (width,height)
    return cv.warpAffine(img,rotMat,dimensions) 

#trans = translate(img,50,50)
#cv.imshow("Translated",trans)
#trans2 = translate(trans,-100,-100) #blackened pixel will also be #translated
#cv.imshow("Translated2",trans2)

#rotated = rotate(img,45)
#cv.imshow("Rotated",rotated)
#rotated2 = rotate(rotated,20) #blackened pixel will also be roatated
#cv.imshow("Rotated2",rotated2)

#flipping
#vertical
#flip0 = cv.flip(img,0)
#cv.imshow('Flip(0)',flip0)
#horizontal
#flip1 = cv.flip(img,1)
#cv.imshow('Flip(1)',flip1)
#both
#flip2 = cv.flip(img,-1)
#cv.imshow('Flip(-1)',flip2)

cv.waitKey(0)