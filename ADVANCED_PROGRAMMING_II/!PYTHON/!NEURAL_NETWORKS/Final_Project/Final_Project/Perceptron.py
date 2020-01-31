import numpy as np
import pygame, sys
import random

class Perceptron(object):
    """description of class"""
    def __init__(self):
        self.training_inputs = np.array([[1,0,0,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0],[0,0,0,1,0,0,0,0,0,0],[0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,1,0,0,0,0],[0,0,0,0,0,0,1,0,0,0],[0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,0,1,0],[0,0,0,0,0,0,0,0,0,1]])
        self.training_outputs = np.array([[1,0,1,1,0,0,1,0,1,0]]).T
        self.output = 0
        # seed random numbers to make calculation
        np.random.seed(1)

        # initialize weights randomly with mean 0 to create weight matrix, synaptic weights
        self.synaptic_weights = 2 * np.random.random((10,1)) - 1

        print('Random starting synaptic weights: ')
        print(self.synaptic_weights)

        np.random.seed(1)

        # initialize weights randomly with mean 0 to create weight matrix, synaptic weights
        synaptic_weights = 2 * np.random.random((10,1)) - 1

        print('Random starting synaptic weights: ')
        print(synaptic_weights)

        # Iterate 10,000 times
        for iteration in range(10000):

            # Define input layer
            input_layer = training_inputs
            # Normalize the product of the input layer with the synaptic weights
            outputs = sigmoid(np.dot(input_layer, synaptic_weights))

            # how much did we miss?
            error = training_outputs - outputs

            # multiply how much we missed by the
            # slope of the sigmoid at the values in outputs
            adjustments = error * sigmoid_derivative(outputs)

            # update weights
            synaptic_weights += np.dot(input_layer.T, adjustments)

        print('Synaptic weights after training: ')
        print(synaptic_weights)

        print("Output After Training:")
        print(outputs)

    def sigmoid(self,x):
        return 1/(1+np.exp(-x))

    def sigmoid_derivative(self,x):
        return x * (1 - x)

    #def Learn(self):
    #    for iterations in range(1):
    #        input_layers = self.training_inputs

    #        outputs = self.sigmoid(np.dot(input_layers, self.synaptic_weights))

    #    print('Synaptic weights after training: ')
    #    print(self.synaptic_weights)


#import numpy as np

# sigmoid function to normalize inputs
#def sigmoid(x):
#    return 1 / (1 + np.exp(-x))

# sigmoid derivatives to adjust synaptic weights
#def sigmoid_derivative(x):
#    return x * (1 - x)

## input dataset
#training_inputs = np.array
#(
#    [
#        [0,0,1,0,0,0,1,0,1,0],
#        [1,1,1,0,1,0,1,1,1,0],
#        [0,0,1,0,0,0,1,0,1,0],
#        [0,0,0,0,0,0,0,0,1,0]
#    ]
#)

## output dataset
#training_outputs = np.array
#(
#    [
#        [1,0,1,1,0,0,1,0,1,0]
#    ]
#)

## seed random numbers to make calculation
#np.random.seed(1)

## initialize weights randomly with mean 0 to create weight matrix, synaptic weights
#synaptic_weights = 2 * np.random.random((10,1)) - 1

#print('Random starting synaptic weights: ')
#print(synaptic_weights)

## Iterate 10,000 times
#for iteration in range(10000):

#    # Define input layer
#    input_layer = training_inputs
#    # Normalize the product of the input layer with the synaptic weights
#    outputs = sigmoid(np.dot(input_layer, synaptic_weights))

#    # how much did we miss?
#    error = training_outputs - outputs

#    # multiply how much we missed by the
#    # slope of the sigmoid at the values in outputs
#    adjustments = error * sigmoid_derivative(outputs)

#    # update weights
#    synaptic_weights += np.dot(input_layer.T, adjustments)

#print('Synaptic weights after training: ')
#print(synaptic_weights)

#print("Output After Training:")
##print(outputs)

#import numpy as np
#import random

## sigmoid function to normalize inputs
#def sigmoid(x):
#    return 1 / (1 + np.exp(-x))

## sigmoid derivatives to adjust synaptic weights
#def sigmoid_derivative(x):
#    return x * (1 - x)

## input dataset
##training_inputs = np.array([[0,0,1,0,0,0,1,0,1,0],[1,1,1,0,1,0,1,1,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,0,0,0,0,0,0,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,0,1,0],[0,0,1,0,0,0,1,0,1,0]])
#training_inputs = np.array([[1,0,0,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0],[0,0,0,1,0,0,0,0,0,0],[0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,1,0,0,0,0],[0,0,0,0,0,0,1,0,0,0],[0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,0,1,0],[0,0,0,0,0,0,0,0,0,1]])
##training_inputs = np.array([[0,0,0,0,1,0,0,0,0,0]])
##training_inputs = np.array([[0,0,1,0,0,0,1,0,1,0]])
## output dataset
##training_outputs = np.array([[1,0,1,1,0,0,1,0,1,0]]).T
#training_outputs = np.array([[1,0,1,1,0,0,1,0,1,0]]).T
##training_outputs = np.array([[0,1,1,0]]).T
## seed random numbers to make calculation
#np.random.seed(1)

## initialize weights randomly with mean 0 to create weight matrix, synaptic weights
#synaptic_weights = 2 * np.random.random((10,1)) - 1

#print('Random starting synaptic weights: ')
#print(synaptic_weights)

## Iterate 10,000 times
#for iteration in range(10000):

#    # Define input layer
#    input_layer = training_inputs
#    # Normalize the product of the input layer with the synaptic weights
#    outputs = sigmoid(np.dot(input_layer, synaptic_weights))

#    # how much did we miss?
#    error = training_outputs - outputs

#    # multiply how much we missed by the
#    # slope of the sigmoid at the values in outputs
#    adjustments = error * sigmoid_derivative(outputs)

#    # update weights
#    synaptic_weights += np.dot(input_layer.T, adjustments)

#print('Synaptic weights after training: ')
#print(synaptic_weights)

#print("Output After Training:")
#print(outputs)