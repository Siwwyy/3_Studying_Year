'''
    Copyright 2019 by Damian Andrysiak
'''

import cv2
import numpy as np
import imutils
import math
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time
import idx2numpy

file = "../../../../../Rubbish/train-images.idx3-ubyte"
arr = idx2numpy.convert_from_file(file)

file1 = "../../../../../Rubbish/train-labels.idx1-ubyte"
arr1 = idx2numpy.convert_from_file(file1)

i = int()
for x in range(1000):
    cv2.imshow(str(arr1[x]), arr[x])
    print(arr1[x])
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    #++i



cv2.waitKey(0)
cv2.destroyAllWindows()

#from sklearn.linear_model import SGDClassifier
