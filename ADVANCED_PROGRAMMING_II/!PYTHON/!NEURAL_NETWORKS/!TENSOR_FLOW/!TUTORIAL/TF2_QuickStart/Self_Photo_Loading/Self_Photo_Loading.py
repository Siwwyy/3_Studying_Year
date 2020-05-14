#classify images of clothing

import tensorflow as tf

AUTOTUNE = tf.data.experimental.AUTOTUNE

import IPython.display as display
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import os
import pathlib
import cv2

print(tf.__version__)

# Import your own photos

Data_dir = "E:\\!!PROJECTS_VS\\!Data_Sets\\SIGN_ALPHABET\\asl-alphabet\\asl_alphabet_train\\test"

Class_names = [ "A", "B" ]

#for category in Class_names:
#    path = os.path.join(Data_dir,category)  # path to A or B dir
#    for img in os.listdir(path):
#        img_array = cv2.imread(os.path.join(path,img), cv2.IMREAD_GRAYSCALE)
#        #plt.imshow(img_array, cmap="gray")
#        #plt.show()
#        #break
#    #break

##########################################################################################

#print(len(img_array))

IMG_SIZE = 50

#new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
#plt.imshow(new_img_array, cmap="gray")
#plt.show()


training_data = []

def Create_Training_Data():
    for category in Class_names:
        path = os.path.join(Data_dir,category)  # path to A or B dir
        class_num = Class_names.index(category)
        for img in os.listdir(path):
            try:
                img_array = cv2.imread(os.path.join(path,img), cv2.IMREAD_GRAYSCALE)
                new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
                training_data.append([new_array,class_num])
            except Exception as e:
                print("Exception")

Create_Training_Data()

print(len(training_data))