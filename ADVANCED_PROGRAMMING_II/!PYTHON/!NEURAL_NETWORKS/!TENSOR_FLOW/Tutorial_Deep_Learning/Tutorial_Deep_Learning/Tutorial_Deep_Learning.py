
import tensorflow as tf
import keras
import numpy as np
import matplotlib.pyplot as plt
from keras.models import load_model
print(tf.__version__)

mnist = tf.keras.datasets.mnist #28x28 images, images of hand written digits from 0 to 9

(x_train, y_train), (x_test, y_test) = mnist.load_data()

#print(x_train[0])
#plt.imshow(x_train[0], cmap = plt.cm.binary) #change the color of photo
#plt.show()


x_train = tf.keras.utils.normalize(x_train, axis=1)
x_test = tf.keras.utils.normalize(x_test, axis=1)

#build model
model = keras.Sequential(
    [
        keras.layers.Flatten(),
        keras.layers.Dense(128, activation = tf.nn.relu),
        keras.layers.Dense(128, activation = tf.nn.relu),
        keras.layers.Dense(10, activation = tf.nn.softmax)
    ]
)

#model.compile(keras.optimizers.SGD(0.5),keras.losses.sparse_categorical_crossentropy, metrics = ['accuracy'])
model.compile(keras.optimizers.Adam(learning_rate=0.001, beta_1=0.9, beta_2=0.999, amsgrad=False),keras.losses.sparse_categorical_crossentropy, metrics = ['accuracy'])
#train model
model.fit(x_train,y_train,epochs=3)

model.summary()

val_loss, val_acc = model.evaluate(x_test,y_test)

#print('> loaded %s %s' % (filename, img_data.shape))
print('\n > Loss: %s \n > Accuracy: %s \n' % (val_loss,val_acc))
model.save_weights("model_weights.h5")
#print("Saved model to disk")

#model.save('epic_num_reader_model')

#new_model = keras.models.load_model('epic_num_reader_model',custom_objects={'my_custom_activation': 'softmax_v2'})
new_model = model


predictions = new_model.predict([x_test])

#print(predictions)

#predict model

print(np.argmax(predictions[0]))

plt.imshow(x_test[0])
plt.show()