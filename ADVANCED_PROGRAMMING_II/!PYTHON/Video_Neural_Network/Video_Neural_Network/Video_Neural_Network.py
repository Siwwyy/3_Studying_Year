'''
    Copyright 2019 by Damian Andrysiak
'''

import cv2
import numpy as np
import imutils
import math
import Functions as fun
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

def draw_foo1(my_capture, my_x, my_y):
    #ax1.plot(xar,yar)
    #plt.show()
    cv2.line(my_capture,(my_x,int(800* math.sin(60*1) + my_x)),(my_y,my_x),(255,0,0),5)
    #cv2.line(my_capture,(my_x,int(800* math.sin(60*1) + my_x)),(my_y,my_x),(255,0,0),5)


#cap = cv2.VideoCapture('steel_balls.mp4')
#cap = cv2.VideoCapture('people_moving.mp4')
#cap = cv2.VideoCapture('People.mp4')
#cap = cv2.VideoCapture('cars_highway.mp4')
cap = cv2.VideoCapture('in1.mp4')

#cap.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
#cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)

#print(cap.get(cv2.CAP_PROP_FPS))
#print(cap.get(cv2.CAP_PROP_FRAME_WIDTH))

ret, frame1 = cap.read()
ret, frame2 = cap.read()

xar = []
yar = []


while cap.isOpened():
    #ret, frame = cap.read()
        
    diff = cv2.absdiff(frame1,frame2)   #looking for difference between first and second frame 
    gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5), 0)
    _, thresh = cv2.threshold(blur,20,255,cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh,None,iterations=3)
    contours, _ = cv2.findContours(dilated,cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        (x,y,w,h) = cv2.boundingRect(contour)
        if cv2.contourArea(contour) < 2000 : #if area of the countour, dont draw anything
            continue
        #xar.append(int(x))
        #yar.append(int(y))
    draw_foo1(frame1,x,y)
        #draw_foo1(frame1,y,x)
        #cv2.rectangle(frame1,(x,y), (x+w,y+h),(0,255,0), 2)

    cv2.putText(frame1, "Status: {}".format("Movement"), (10,20), cv2.FONT_HERSHEY_SIMPLEX, 1,(0,0,255),3)
    #cv2.drawContours(frame1,contours, -1, (0,255,0), 2)
    cv2.imshow("Cars",frame1)

    frame1 = frame2
    ret, frame2 = cap.read()


    #cv2.imshow("Inter",frame)


    frame1 = imutils.resize(frame1, width=800, height = 800)
    frame2 = imutils.resize(frame2, width=800, height = 800)

    if cv2.waitKey(40) == 27:   #press ESC
        break

cv2.destroyAllWindows()
cap.release()