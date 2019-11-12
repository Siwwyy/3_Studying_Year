'''
    Copyright 2019 by Damian Andrysiak
'''

import cv2
import numpy as np
import imutils

#cap = cv2.VideoCapture('steel_balls.mp4')
cap = cv2.VideoCapture('people_moving.mp4')

#cap.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
#cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)

#print(cap.get(cv2.CAP_PROP_FPS))
#print(cap.get(cv2.CAP_PROP_FRAME_WIDTH))

ret, frame1 = cap.read()
ret, frame2 = cap.read()

while cap.isOpened():
    #ret, frame = cap.read()
        
    diff = cv2.absdiff(frame1,frame2)   #looking for difference between first and second frame 
    gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5), 0)
    _, thresh = cv2.threshold(blur,20,255,cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh,None,iterations=3)
    contours, _ = cv2.findContours(dilated,cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    cv2.drawContours(frame1,contours, -1, (0,255,0), 2)
    cv2.imshow("feed",frame1)

    frame1 = frame2

    ret, frame2 = cap.read()


    #cv2.imshow("Inter",frame)
    frame1 = imutils.resize(frame1, width=1920, height = 1080)
    frame2 = imutils.resize(frame2, width=1920, height = 1080)
    if cv2.waitKey(40) == 27:
        break

cv2.destroyAllWindows()
cap.release()