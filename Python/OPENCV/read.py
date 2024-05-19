import cv2 as cv
#imports opencv

#reading and displaying image
'''
img = cv.imread('D:/Codes/Python/OPENCV/Photos/iphone.jpg')
#imports image
if img is None:
    print("Image Not Found")
else:
    cv.imshow('Iphone',img)
    #displays image imshow("windows_name",image_handle)
cv.waitKey(0)
#wait for key press until closing screen waitKey(time)  time=0 => infinite
'''


#reading and displaying video
'''
vid = cv.VideoCapture("C:/Users/Akhil Semwal/My project/Library/PackageCache/com.unity.timeline@1.7.5/Samples~/Customization/Demo/Videos/M09-1317.mp4")
#imports video if VideoCapture("vid_location") and turns on camera if VideoCaptur(0,1 or 2) => 0,1,2... represents camera number 0 for webcam

while True:
    isTrue, frame = vid.read()
    #vid.read() => bool value if reading is true/false and the frame it is reading
    cv.imshow('Video',frame)
    #the frame that is read is rendered
    if cv.waitKey(20) & 0xFF==ord('d'):
        #0xff==ord('d') checksif key d is pressed
        break
vid.release()
cv.destroyAllWindows()
#destroys window after termination or completion of video
#on end of complete video the video terminates with error because next frame not found hence abrupt termination
'''
