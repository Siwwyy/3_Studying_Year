
import tensorflow as tf
from tensorflow import keras
from keras.datasets import cifar10
from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten, Conv2D, MaxPooling2D
from keras.callbacks import TensorBoard
import pickle
import time

#gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.333)
#sess = tf.Session(config=tf.ConfigProto(gpu_options=gpu_options))

#NAME = "A-vs-B-sign_alphabet-cnn-64x2-{}".format(int(time.time()))
#NAME = "what{}".format(int(time.time()))

#My_TensorBoard = TensorBoard(log_dir="logs/".format(NAME))
tensorboard_callback = TensorBoard(log_dir=".\\logs")


X = pickle.load(open("X.pickle", "rb"))
Y = pickle.load(open("Y.pickle", "rb"))

X = X/255.0


# Neural network
model = Sequential()

#First Layer
model.add(  Conv2D(64, (3,3), input_shape = X.shape[1:])    )
model.add(  Activation("relu")  )
model.add(  MaxPooling2D(pool_size=(2,2))    )

#Second Layer
model.add(  Conv2D(64, (3,3))   )
model.add(  Activation("relu")  )
model.add(  MaxPooling2D(pool_size=(2,2))    )

#Thrid Layer
#model.add(Flatten(data_format=(3,3)))
model.add(  Flatten()   )

#Output Layer
model.add(  Dense(1)    )
model.add(  Activation("sigmoid")   )


model.compile(loss="binary_crossentropy", optimizer="adam", metrics=['accuracy'])


model.fit(X,Y, batch_size=32, epochs=20,validation_split=0.3,verbose=1,callbacks=[tensorboard_callback])