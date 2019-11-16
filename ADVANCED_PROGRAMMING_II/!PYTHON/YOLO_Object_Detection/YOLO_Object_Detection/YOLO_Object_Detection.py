import cv2
import numpy as np


#Load YOLO algorithm
net = cv2.dnn.readNet("yolov3.weights", "yolov3.cfg")
