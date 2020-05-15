
import tensorflow as tf
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten, Conv2D, MaxPooling2D
import pickle

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
model.add(  Dense(64)   )

#Output Layer
model.add(  Dense(1)    )
model.add(  Activation("sigmoid")   )


model.compile(loss="binary_crossentropy", optimizer="adam", metrics=['accuracy'])

model.fit(X,Y, batch_size=32, epochs=3,validation_split=0.1,verbose=1)