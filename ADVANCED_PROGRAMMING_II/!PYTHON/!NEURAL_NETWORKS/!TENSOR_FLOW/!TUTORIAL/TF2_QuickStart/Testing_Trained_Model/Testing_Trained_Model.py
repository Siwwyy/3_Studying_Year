
import tensorflow as tf

#AUTOTUNE = tf.data.experimental.AUTOTUNE

import IPython.display as display
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import os
import pathlib
import cv2
import random
import pickle
import keras
from pathlib import Path
import os, os.path


#print(tf.__version__)


Class_names = [ "A", "B" ]


def Prepare(file_path):
    IMG_SIZE = 50
    img_array = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
    new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
    return new_img_array.reshape(-1, IMG_SIZE,IMG_SIZE, 1)


model = keras.models.load_model("64x3-CNN.model")

#predictions = model.predict([Prepare("A_test.jpg")])

#print(Class_names[int(predictions[0][0])])

#predictions = model.predict([Prepare("B_test.jpg")])

#print(Class_names[int(predictions[0][0])])

#predictions = model.predict([Prepare("my_b_test.jpg")])

#print("You are showing following sign: ",Class_names[int(predictions[0][0])])


#bgr_img = cv2.imread('my_b_test.jpg')

#b,g,r = cv2.split(bgr_img)       # get b,g,r
#rgb_img = cv2.merge([r,g,b])     # switch it to rgb


##plt.figure(figsize=(25,25))
##plt.subplot(10,10)
#plt.xticks([])
#plt.yticks([])
#plt.grid(False)
#plt.imshow(rgb_img)
#plt.xlabel(Class_names[int(predictions[0][0])])
#plt.show()



#predictions = model.predict([Prepare("my_b_test.jpg")])

#print("You are showing following sign: ",Class_names[int(predictions[0][0])])


#bgr_img = cv2.imread('my_b_test.jpg')

#b,g,r = cv2.split(bgr_img)       # get b,g,r
#rgb_img = cv2.merge([r,g,b])     # switch it to rgb


#plt.figure(figsize=(25,25))
##plt.subplot(10,10)
#plt.xticks([])
#plt.yticks([])
#plt.grid(False)
#plt.imshow(rgb_img)
#plt.xlabel(Class_names[int(predictions[0][0])])
#plt.show()











################################################################################################################################################################################
################################################################################################################################################################################
################################################################################################################################################################################
################################################################################################################################################################################


#print ("OpenCV version: " + cv2.__version__)

images_list = []
 
#image path and valid extensions
imageDir = "/" #specify your path here
image_path_list = []
valid_image_extensions = [".jpg", ".jpeg", ".png", ".tif", ".tiff"] #specify your vald extensions here
valid_image_extensions = [item.lower() for item in valid_image_extensions]
 
#create a list all files in directory and
#append files with a vaild extention to image_path_list
for file in os.listdir(os.curdir):  #list photos only in current directory
    extension = os.path.splitext(file)[1]
    if extension.lower() not in valid_image_extensions:
        continue
    #image_path_list.append(os.path.join(imageDir, file)) #if photos are in different directory
    image_path_list.append(os.path.join(file))
 
#loop through image_path_list to open each image
for imagePath in image_path_list:
    image = cv2.imread(imagePath)
    
    # display the image on screen with imshow()
    # after checking that it loaded
    if image is not None:
        #cv2.imshow(imagePath, image)
        images_list.append(image)
    elif image is None:
        print ("Error loading: " + imagePath)
        #end this loop iteration and move on to next image
        continue
    
    # wait time in milliseconds
    # this is required to show the image
    # 0 = wait indefinitely
    # exit when escape key is pressed
    key = cv2.waitKey(0)
    if key == 27: # escape
        break



w=11
h=11
fig=plt.figure(figsize=(10, 10))
columns = 2
rows = 2
i = 1
counter = 0
for image in images_list:
    fig.add_subplot(rows, columns, i)
    predictions = model.predict([Prepare(image_path_list[counter])])
    #print("You are showing following sign: ",Class_names[int(predictions[0][0])])
    plt.xlabel(Class_names[int(predictions[0][0])])
    bgr_img = image
    b,g,r = cv2.split(bgr_img)       # get b,g,r
    rgb_img = cv2.merge([r,g,b])     # switch it to rgb
    plt.imshow(rgb_img)
    i = i + 1
    counter = counter + 1
plt.show()