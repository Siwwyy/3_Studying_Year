
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
from tensorflow import keras
from pathlib import Path
import os, os.path


#print(tf.__version__)


#Class_names = [ "A", "B" , "C" , "D", "del", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "nothing", "O", "P", "Q", "R", "S", "space", "T", "U", "V", "W", "X", "Y", "Z"]
#Class_names = [ "A", "B" , "C" , "D"]

Class_names = [ "A", "B" , "C" , "D", "del", "E", "F", "G", "H", "I" ]

def Prepare(file_path):
    IMG_SIZE = 50
    img_array = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
    new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
    return new_img_array.reshape(-1,IMG_SIZE,IMG_SIZE,1)


#model = keras.models.load_model("64x3-CNN.model")
#model = keras.models.load_model("my_model.h5")
model = keras.models.load_model("my_model_mnist_epochs20.h5")

#predictions = model.predict([Prepare("F_test.jpg")])

#print(Class_names[int(predictions[0][0])])

#predictions = model.predict([Prepare("B_test.jpg")])

#print(Class_names[int(predictions[0][0])])

#predictions = model.predict([Prepare("my_b_test.jpg")])

#print(np.argmax(predictions[0]))

#print("You are showing following sign: ",Class_names[int(predictions[0][0])])




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
valid_image_extensions = [item.lower() for item in valid_image_extensions]  #lower means every Capital letter goes to be small D -> d
 
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

def scale(image):
    return tf.cast(image, tf.float32)



fig=plt.figure(figsize=(30, 30))
columns = int(len(image_path_list)/2)
rows = int(len(image_path_list)/3)
i = 1
counter = 0
for image in images_list:
    fig.add_subplot(rows, columns, i)
    #img = scale(Prepare(image_path_list[counter]));
    #predictions = model.predict([scale(Prepare(image_path_list[counter]))])
    #predictions = model.predict([Prepare(image_path_list[counter])])
    #predictions = model.predict(img)
    #probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])
    #predictions = probability_model.predict(img)
    #print("You are showing following sign: ",Class_names[int(predictions[0][0])])


    predictions = model.predict([scale(Prepare(image_path_list[counter]))])
    plt.xlabel(Class_names[np.argmax(predictions[0])])



    bgr_img = image
    b,g,r = cv2.split(bgr_img)       # get b,g,r
    rgb_img = cv2.merge([r,g,b])     # switch it to rgb
    plt.imshow(rgb_img)
    i = i + 1
    counter = counter + 1
plt.show()