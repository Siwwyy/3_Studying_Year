
#from __future__ import absolute_import, division, print_function, unicode_literals

## TensorFlow and tf.keras
#import tensorflow as tf
#from tensorflow import keras

## Helper libraries
#import numpy as np
#import matplotlib.pyplot as plt

#print(tf.__version__)

#fashion_mnist = keras.datasets.fashion_mnist

#(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

#class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
#               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']


#print(train_images.shape)
#print(len(train_labels))
#print(train_labels)
#print(test_images.shape)
#print(len(test_labels))

##plt.figure()
##plt.imshow(train_images[0])
##plt.colorbar()
##plt.grid(False)
##plt.show()

##plt.figure()
##plt.imshow(train_images[0])
##plt.colorbar()
##plt.grid(False)
##plt.show()

#train_images = train_images / 255.0

#test_images = test_images / 255.0

##chaning pixel rate from 0 - 255 to 0 - 1
##plt.figure()
##plt.imshow(train_images[0])
##plt.colorbar()
##plt.grid(False)
##plt.show()

##plt.figure(figsize=(10,10))
##for i in range(25):
##    plt.subplot(5,5,i+1)
##    plt.xticks([])
##    plt.yticks([])
##    plt.grid(False)
##    plt.imshow(train_images[i], cmap=plt.cm.binary)
##    plt.xlabel(class_names[train_labels[i]])
##plt.show()

#model = keras.Sequential([
#    keras.layers.Flatten(input_shape=(28, 28)), #making array from 2 dimensional to one dimensional (flat, 28*28)
#    keras.layers.Dense(128, activation='relu'),
#    keras.layers.Dense(10, activation='softmax')
#])



#model.compile(optimizer='adam',
#              loss='sparse_categorical_crossentropy',
#              metrics=['accuracy'])

#model.fit(train_images, train_labels, epochs=10) #train model

#test_loss, test_acc = model.evaluate(test_images,  test_labels, verbose=2)

#print('\nTest accuracy:', test_acc)

#predictions = model.predict(test_images)

#print(predictions[0])

#print(np.argmax(predictions[0]))
#print(test_labels[0])


#def plot_image(i, predictions_array, true_label, img):
#  predictions_array, true_label, img = predictions_array, true_label[i], img[i]
#  plt.grid(False)
#  plt.xticks([])
#  plt.yticks([])

#  plt.imshow(img, cmap=plt.cm.binary)

#  predicted_label = np.argmax(predictions_array)
#  if predicted_label == true_label:
#    color = 'blue'
#  else:
#    color = 'red'

#  plt.xlabel("{} {:2.0f}% ({})".format(class_names[predicted_label],
#                                100*np.max(predictions_array),
#                                class_names[true_label]),
#                                color=color)

#def plot_value_array(i, predictions_array, true_label):
#  predictions_array, true_label = predictions_array, true_label[i]
#  plt.grid(False)
#  plt.xticks(range(10))
#  plt.yticks([])
#  thisplot = plt.bar(range(10), predictions_array, color="#777777")
#  plt.ylim([0, 1])
#  predicted_label = np.argmax(predictions_array)

#  thisplot[predicted_label].set_color('red')
#  thisplot[true_label].set_color('blue')


#i = 0
#plt.figure(figsize=(6,3))
#plt.subplot(1,2,1)
#plot_image(i, predictions[i], test_labels, test_images)
#plt.subplot(1,2,2)
#plot_value_array(i, predictions[i],  test_labels)
#plt.show()


#i = 12
#plt.figure(figsize=(6,3))
#plt.subplot(1,2,1)
#plot_image(i, predictions[i], test_labels, test_images)
#plt.subplot(1,2,2)
#plot_value_array(i, predictions[i],  test_labels)
#plt.show()

## Plot the first X test images, their predicted labels, and the true labels.
## Color correct predictions in blue and incorrect predictions in red.
#num_rows = 5
#num_cols = 3
#num_images = num_rows*num_cols
#plt.figure(figsize=(2*2*num_cols, 2*num_rows))
#for i in range(num_images):
#  plt.subplot(num_rows, 2*num_cols, 2*i+1)
#  plot_image(i, predictions[i], test_labels, test_images)
#  plt.subplot(num_rows, 2*num_cols, 2*i+2)
#  plot_value_array(i, predictions[i], test_labels)
#plt.tight_layout()
#plt.show()


## Grab an image from the test dataset.
#img = test_images[1]

#print(img.shape)

#img = (np.expand_dims(img,0))

#print(img.shape)

#predictions_single = model.predict(img)

#print(predictions_single)

#plot_value_array(1, predictions_single[0], test_labels)
#_1 = plt.xticks(range(10), class_names, rotation=45)

#print(np.argmax(predictions_single[0]))


## TensorFlow and tf.keras
import tensorflow as tf
import keras

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt

print(tf.__version__)


model_a = keras.Sequential(
    [
        keras.layers.Flatten(input_shape=(28, 28)), #making array from 2 dimensional to one dimensional (flat, 28*28)
        keras.layers.Dense(20, activation= 'sigmoid'),
        keras.layers.Dense(10, activation= 'sigmoid'),
        keras.layers.Dense(10, activation= 'softmax')
    ]
)


model = keras.Sequential(
    [ #LENET 5
        #keras.layers.Flatten(input_shape=(28, 28)), #making array from 2 dimensional to one dimensional (flat, 28*28)
        keras.layers.Conv2D(6, kernel_size=(5,5),strides=(1,1),input_shape=(28,28,1)),
        keras.layers.AvgPool2D(pool_size = (2,2), strides = (2,2)),
        keras.layers.Conv2D(16, kernel_size=(5,5),strides=(1,1)),
        keras.layers.AvgPool2D(pool_size = (2,2), strides = (2,2)),
        keras.layers.Conv2D(120, kernel_size=(2,2),strides=(1,1)),
        keras.layers.Flatten(),
        keras.layers.Dense(86, activation= 'sigmoid'),
        keras.layers.Dense(10, activation= 'softmax')
    ]
) 

model.compile(keras.optimizers.SGD(0.5), keras.losses.sparse_categorical_crossentropy, metrics = ['accuracy'])
model.summary()

mnist = keras.datasets.mnist
#mnist = keras.datasets.cifar10

(train_inputs, train_labels), (test_inputs, test_labels) = mnist.load_data()

train_inputs, test_inputs = train_inputs/255, test_inputs/255




print("Test labels ",test_labels.shape)
print("Test inputs ",test_inputs.shape)

print("Train labels ",train_labels.shape)
print("Train inputs ",train_inputs.shape)

train_inputs = train_inputs.reshape(60000,28,28,1)
test_inputs = test_inputs.reshape(10000,28,28,1)
#train_labels = train_labels.reshape(60000,1)

model.fit(train_inputs,train_labels, epochs = 10, batch_size = 100)
test_loss,test_acc = model.evaluate(test_inputs,test_labels)

print("Test accuracy: ",test_acc)
print("Test loss", test_loss)

#print("Test labels ",test_labels.shape)
#print("Test inputs ",test_inputs.shape)


predictions = model.predict(test_inputs)

#print(predictions[0])

#np.argmax(predictions[0])

#test_labels[0]

img = test_inputs[1]

print(img.shape)


img = (np.expand_dims(img,0))

print(img.shape)

predictions_single = model.predict(img)

print(predictions_single)

#plot_value_array(1, predictions_single[0], test_labels)
#_ = plt.xticks(range(10), rotation=45)
