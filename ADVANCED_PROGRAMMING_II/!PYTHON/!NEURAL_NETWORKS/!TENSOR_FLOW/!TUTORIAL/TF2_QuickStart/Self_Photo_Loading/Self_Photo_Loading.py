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
import random
import pickle

print(tf.__version__)

# Import your own photos

Data_dir = "E:\\!!PROJECTS_VS\\!Data_Sets\\SIGN_ALPHABET\\asl-alphabet\\asl_alphabet_train\\asl_alphabet_train"

#Class_names = [ "A", "B" , "C" , "D"]

Class_names = [ "A", "B" , "C" , "D", "del", "E", "F", "G", "H", "I" ]


#Class_names = [ "A", "B" , "C" , "D", "del", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "nothing", "O", "P", "Q", "R", "S", "space", "T", "U", "V", "W", "X", "Y", "Z"]

#for category in Class_names:
#    path = os.path.join(Data_dir)  # path to A,B,C,...,Z
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
        path = os.path.join(Data_dir,category)   # path to A,B,C,...,Z
        class_num = Class_names.index(category)
        print("{0} | {1}".format(path,class_num))
        for img in os.listdir(path):
            try:
                img_array = cv2.imread(os.path.join(path,img), cv2.IMREAD_GRAYSCALE)
                new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
                training_data.append([new_img_array,class_num])
                
            except Exception as e:
                print("Exception")

Create_Training_Data()

#print(training_data[0])
#print(len(training_data))

random.shuffle(training_data)   #shuffle the data

#for sample in training_data[:10]:
#    print(sample[1])

X = []
Y = []

for features, labels in training_data:
    X.append(features)
    Y.append(labels)


X = np.array(X).reshape(-1, IMG_SIZE,IMG_SIZE,1)
#print(X)

pickle_out = open("X.pickle","wb")
pickle.dump(X, pickle_out)
pickle_out.close()

pickle_out = open("Y.pickle","wb")
pickle.dump(Y, pickle_out)
pickle_out.close()

#Load back the data
#pickle_in = open("X.pickle", "rb")
#X = pickle.load(pickle_in)