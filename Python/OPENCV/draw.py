import cv2 as cv
import numpy as np

blank = np.zeros((500,500,3),dtype='uint8')
                #height width color_channel

#creating a blank image
'''
cv.imshow('Blank',blank)
'''

#paint blank image to color
'''
blank[:] = 0,255,0 #green
#blank[:] = 255,0,0 #blue
#blank[:] = 0,0,255 #red
#blank[200:300,300:400] = 0,0,255 #colors a specific range red
cv.imshow('Color',blank)
'''

#draw a rectangle
'''
#cv.rectangle(blank,(0,0),(250,250),(0,255,0),thickness=2)
#cv.rectangle(blank,(0,0),(250,500),(0,255,0),thickness=cv.FILLED)
#cv.rectangle(blank,(0,0),(250,500),(0,255,0),thickness=-1)
cv.rectangle(blank,(0,0),(blank.shape[1]//2,blank.shape[0]//2),(0,255,0),thickness=1)
cv.imshow('Rectangle',blank)
#(img,pt1,pt2,color,thickness=None,lineType=None,shift=None,/)
'''
#draw a circle
'''
cv.circle(blank,(blank.shape[1]//2,blank.shape[0]//2),40,(0,0,255),thickness=-11)
cv.imshow('Circle',blank)
#(img,ctr_pt,radius,color,thickness=None,lineType=None,shift=None,/)
'''
#draw a line
'''
cv.line(blank,(0,0),(blank.shape[1]//2,blank.shape[0]//2),(255,255,255),thickness=5)
cv.imshow('Line',blank)
#(img,pt1,pt2,color,thickness=None,lineType=None,shift=None,/)
'''
#write text
'''
cv.putText(blank,'Hello',(225,225),cv.FONT_HERSHEY_TRIPLEX,1.0,(0,255,0),2)
cv.imshow('Text',blank)
#(img,text,pt,font,font_scale,color,thickness=None,lineType=None,bottomLeftOrigin=None,/)
'''
cv.waitKey(0)