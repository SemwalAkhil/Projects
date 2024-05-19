import cv2 as cv

#frame resizing function -> we prefer downscaling of frames to reduce strain on system
def rescaleFrame(frame,scale=0.75): #works for everything
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    #frame.shape[1] -> width , frame.shape[0] -> height 
    dimensions = (width,height)
    return cv.resize(frame,dimensions,interpolation=cv.INTER_AREA)
# when scale is increased we prefer INTER_LINEAR , INTER_CUBIC for better quality when we downscale we prefer default INTER_AREA as it takes less time

def changeRes(vid,width,height): #works for live video only
    vid.set(3,width) # 3 -> width
    vid.set(4,height) # 4 -> height


'''
img = cv.imread('D:/Codes/Python/OPENCV/Photos/iphone.jpg')
if img is None:
    print("Image Not Found")
else:
    cv.imshow('Image',img)
    cv.imshow('Image_resized',rescaleFrame(img,2)) #passing rescaled frame to imshow   
cv.waitKey(0)
cv.destroyAllWindows()
'''
'''
vid = cv.VideoCapture("C:/Users/Akhil Semwal/My project/Library/PackageCache/com.unity.timeline@1.7.5/Samples~/Customization/Demo/Videos/M09-1317.mp4")
while True:
    isTrue, frame = vid.read()
    cv.imshow('Video',frame)
    cv.imshow('Video_resized',rescaleFrame(frame)) #passing rescaled frame to imshow   
    if cv.waitKey(20) & 0xFF==ord('d'):
        break
vid.release()
cv.destroyAllWindows()
'''
'''
vid = cv.VideoCapture(0)
while True:
    isTrue, frame = vid.read()
    cv.imshow('Video',frame)
    changeRes(vid,100,100)  #rescaling frame before rendering resized video
    cv.imshow('Video1',frame)
    if cv.waitKey(20) & 0xFF==ord('d'):
        break
vid.release()
cv.destroyAllWindows()
'''