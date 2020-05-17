
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


#print(tf.__version__)


Class_names = [ "A", "B" ]


def Prepare(file_path):
    IMG_SIZE = 50
    img_array = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
    new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
    return new_img_array.reshape(-1, IMG_SIZE,IMG_SIZE, 1)


model = keras.models.load_model("64x3-CNN.model")

predictions = model.predict([Prepare("A_test.jpg")])

print(predictions)