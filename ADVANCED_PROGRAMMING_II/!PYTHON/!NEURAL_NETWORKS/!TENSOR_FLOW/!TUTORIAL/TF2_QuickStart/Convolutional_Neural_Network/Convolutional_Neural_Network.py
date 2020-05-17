
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



X = pickle.load(open("X.pickle", "rb"))
Y = pickle.load(open("Y.pickle", "rb"))

X = X/255.0

dense_layers = [0]
layer_sizes = [64]
conv_layers = [3]

counter = 0

for dense_layer in dense_layers:
    for layer_size in layer_sizes:
        for conv_layer in conv_layers:
            NAME = "{}_conv_{}_nodes_{}_dense_{}".format(conv_layer,layer_size,dense_layer, int(time.time()))

            print(NAME)

            # Neural network
            model = Sequential()

            #First Layer
            model.add(  Conv2D(layer_size, (3,3), input_shape = X.shape[1:])    )
            model.add(  Activation("relu")  )
            model.add(  MaxPooling2D(pool_size=(2,2))    )

            for l in range(conv_layer-1):
                #Second Layer
                model.add(  Conv2D(layer_size, (3,3))   )
                model.add(  Activation("relu")  )
                model.add(  MaxPooling2D(pool_size=(2,2))    )

            #Thrid Layer
            model.add(  Flatten()   )


            for l in range(dense_layer):
                #Fourth Layer
                model.add(  Dense(512)  )
                model.add(  Activation("relu")  )
            #model.add(Flatten(data_format=(3,3)))

            #Output Layer
            model.add(  Dense(1)    )
            model.add(  Activation("sigmoid")   )


            tensorboard_callback = TensorBoard(log_dir=".\\logs\\{}".format(counter))
            counter = counter + 1

            model.compile(loss="binary_crossentropy", optimizer="adam", metrics=['accuracy'])


            model.fit(X,Y, batch_size=32, epochs=10,validation_split=0.3,verbose=1,callbacks=[tensorboard_callback])

model.save('64x3-CNN.model')