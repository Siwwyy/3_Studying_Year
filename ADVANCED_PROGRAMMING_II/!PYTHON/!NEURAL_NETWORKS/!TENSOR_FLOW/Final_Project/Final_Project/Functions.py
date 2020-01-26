## TensorFlow and tf.keras
import tensorflow as tf
import keras

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt
import pickle
from PIL import Image
from matplotlib import image
from matplotlib import pyplot
from numpy import asarray
import os, sys


#File reader
def Load_Data(file_name):
    loaded_images = list()
    for filename in os.listdir(file_name):
        #load image
        img_data = image.imread(file_name+'/' + filename)
        loaded_images.append(img_data)
        #print('> loaded %s %s' % (filename, img_data.shape))
	    #store loaded image
    return loaded_images

