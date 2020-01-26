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
    #image = Image.open(file_name)
    ## summarize some details about the image
    #print(image.format)
    #print(image.mode)
    #print(image.size)
    #image.show()
    ## show the image
    #data = image.imread(file_name)
    ## summarize shape of the pixel array
    #print(data.dtype)
    #print(data.shape)
    ## display the array of pixels as an image
    #pyplot.imshow(data)
    #pyplot.show()
    #image = Image.open(file_name)
    ## convert image to numpy array
    #data = asarray(image)
    ## summarize shape
    #print(data.shape)
    ## create Pillow image
    #image2 = Image.fromarray(data)
    ## summarize image details
    #print(image2.format)
    #print(image2.mode)
    #print(image2.size)
    # load all images in a directory
    loaded_images = list()
    for filename in os.listdir(file_name):
        # load image
        img_data = image.imread(file_name+'/' + filename)
        loaded_images.append(img_data)
        print('> loaded %s %s' % (filename, img_data.shape))
	    # store loaded image

