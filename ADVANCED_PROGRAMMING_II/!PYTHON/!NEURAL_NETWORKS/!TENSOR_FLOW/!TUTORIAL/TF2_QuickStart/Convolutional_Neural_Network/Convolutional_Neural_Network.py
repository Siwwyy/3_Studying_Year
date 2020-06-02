
import tensorflow as tf
from tensorflow import keras
from keras.datasets import cifar10
from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten, Conv2D, MaxPooling2D
from keras.callbacks import TensorBoard
import pickle
import time
import numpy as np
import cv2

#gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.333)
#sess = tf.Session(config=tf.ConfigProto(gpu_options=gpu_options))

#NAME = "A-vs-B-sign_alphabet-cnn-64x2-{}".format(int(time.time()))
#NAME = "what{}".format(int(time.time()))

#My_TensorBoard = TensorBoard(log_dir="logs/".format(NAME))






IMG_SIZE = 50



Class_names = [ "A", "B" , "C" , "D", "del", "E", "F", "G", "H", "I" ]


X = pickle.load(open("X.pickle", "rb"))
Y = pickle.load(open("Y.pickle", "rb"))
X = np.array(X).reshape(-1, IMG_SIZE,IMG_SIZE)
Y = np.array(Y)
X = X/255.0

cos = X.shape[1:]

model = keras.Sequential([
    keras.layers.Flatten(input_shape = (IMG_SIZE,IMG_SIZE)),
    keras.layers.Dense(256, activation='relu'),
    keras.layers.Dense(10)
])




model.compile(optimizer='adam',loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True), metrics=['accuracy'])

model.fit(X, Y, epochs=20,validation_split=0.3,verbose=1)



model.save('my_model_mnist.h5')









































#X = pickle.load(open("X.pickle", "rb"))
#Y = pickle.load(open("Y.pickle", "rb"))

#X = X/255.0

##dense_layers = [0]
##layer_sizes = [64]
##conv_layers = [3]

##counter = 0

##for dense_layer in dense_layers:
##    for layer_size in layer_sizes:
##        for conv_layer in conv_layers:
##            NAME = "{}_conv_{}_nodes_{}_dense_{}".format(conv_layer,layer_size,dense_layer, int(time.time()))

##            print(NAME)

##            # Neural network
##            model = Sequential()

##            #First Layer
##            model.add(  Conv2D(layer_size, (3,3), input_shape = X.shape[1:])    )
##            model.add(  Activation("relu")  )
##            model.add(  MaxPooling2D(pool_size=(2,2))    )

##            for l in range(conv_layer-1):
##                #Second Layer
##                model.add(  Conv2D(layer_size, (3,3))   )
##                model.add(  Activation("relu")  )
##                model.add(  MaxPooling2D(pool_size=(2,2))    )

##            #Thrid Layer
##            model.add(  Flatten()   )


##            for l in range(dense_layer):
##                #Fourth Layer
##                model.add(  Dense(512)  )
##                model.add(  Activation("relu")  )
##            #model.add(Flatten(data_format=(3,3)))

##            #Output Layer
##            model.add(  Dense(1)    )
##            model.add(  Activation("sigmoid")   )


##            tensorboard_callback = TensorBoard(log_dir=".\\logs\\{}".format(counter))
##            counter = counter + 1

##            #model.compile(loss="binary_crossentropy", optimizer="adam", metrics=['accuracy'])
##            model.compile(optimizer='adam', loss=tf.keras.losses.CategoricalCrossentropy(from_logits=True), metrics=['accuracy'])


##            model.fit(X,Y, batch_size=32, epochs=10,validation_split=0.3)

            
##            #model.fit(X,Y, batch_size=32, epochs=10,validation_split=0.3,verbose=1,callbacks=[tensorboard_callback])

##model.save('64x3-CNN.model')


##model = keras.Sequential([
##    keras.layers.Flatten(input_shape=(50, 50)),
##    keras.layers.Dense(128, activation='relu'),
##    keras.layers.Dense(10)
##])

#X = np.array(X).reshape(-1, 50, 50,1)

#Y = np.array(Y)

##model.compile(optimizer='adam', loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True), metrics=['accuracy'])


##model.fit(X,Y, batch_size=32, epochs=15,validation_split=0.3)


###probability_model = tf.keras.Sequential([model,tf.keras.layers.Softmax()])

##model.save('/mymodel.model')


#######################################################################
#######################################################################
#######################################################################
#######################################################################



#def get_model():
#    #model = tf.keras.Sequential([
#    #        tf.keras.layers.Conv2D(32, 3, activation='relu', input_shape=(50, 50,1)),
#    #        tf.keras.layers.MaxPooling2D(),
#    #        tf.keras.layers.Flatten(),
#    #        tf.keras.layers.Dense(64, activation='relu'),
#    #        tf.keras.layers.Dense(10)
#    #    ])
#    model = tf.keras.Sequential()
#    model.add(tf.keras.layers.Conv2D(32, (3,3), input_shape = X.shape[1:]))
#    model.add(tf.keras.layers.Conv2D(64, (3,3), activation='relu'))
#    model.add(tf.keras.layers.MaxPooling2D(pool_size=(2, 2)))
#    model.add(tf.keras.layers.Dropout(0.25))
#    model.add(tf.keras.layers.Flatten())
#    model.add(tf.keras.layers.Dense(128, activation='relu'))
#    model.add(tf.keras.layers.Dropout(0.5))
#    model.add(tf.keras.layers.Dense(4))

        
#    return model

#model = get_model()
#model.compile(loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True), optimizer=tf.keras.optimizers.Adam(),metrics=['accuracy'])
#model.fit(X,Y, batch_size=32, epochs=3,validation_split=0.3)

#model.summary()

##def Prepare(file_path):
##    IMG_SIZE = 50
##    img_array = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
##    new_img_array = cv2.resize(img_array, (IMG_SIZE,IMG_SIZE))
##    return new_img_array.reshape(-1, IMG_SIZE,IMG_SIZE, 1)


##Class_names = [ "A", "B" , "C" , "D"]


##predictions = model.predict([Prepare("my_a_test.jpg")])

##print("You are showing following sign: ",Class_names[int(predictions[0][0])])

##keras_model_path = "tmp\\"
#model.save('my_model.h5')   # save() should be called out of strategy scope