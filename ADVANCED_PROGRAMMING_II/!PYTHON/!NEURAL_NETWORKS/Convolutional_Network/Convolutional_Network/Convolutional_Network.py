import cv2 as cv
import numpy as np
from PIL import Image

Input_Batch = [[0 for x in range(6)] for y in range(6)]
Kernel = [[0 for x in range(3)] for y in range(3)]
Output = [[0 for x in range(2)] for y in range(2)]

def Fill_Input_Batch(Param):
    value = float(0.0)
    for x in range(len(Param)):
        value = float(x)
        for y in range(len(Param[x])):
            Param[y][x] = value
            value += 0.1

#Kernel[0][0] = 0;
#Kernel[0][1] = 0;
#Kernel[0][2] = 0;

Kernel[0][1] = 0.5;
Kernel[1][1] = 1;
Kernel[2][1] = 0.5;

#Kernel[2][0] = 0;
#Kernel[2][1] = 0;
#Kernel[2][2] = 0;

def Display_Input_Batch(Param1):
    for a in range(len(Param1)):
        for b in range(len(Param1[a])):
            print('%.1f'%Param1[a][b], end =' ')
        print()



def Display_Kernel(Param1):
    for a in range(len(Param1)):
        for b in range(len(Param1[a])):
            print('%.1f'%Param1[a][b], end =' ')
        print()

def Display_Output(Param1):
    for a in range(len(Param1)):
        for b in range(len(Param1[a])):
            print('%.1f'%Param1[a][b], end =' ')
        print()

def Convolutional_Transform(Input, Kernel,Output):
    pos = int()
    pos = (6*6)/(3*3)
    output_counter = int()
    value = float()
    stride = int(3)
    #for x in range(0,int(pos)):
    print();
    for y in range(0,len(Output)):
        for z in range(0,len(Output[y])):
            value = 0.0
            for a in range(len(Kernel)):
                for b in range(len(Kernel[a])):
                    value += (Input[y*stride + a][z*stride + b] * Kernel[a][b])
                #print(value)
            Output[y][z] = value
    print()


#Fill_Input_Batch(Input_Batch)
#Display_Input_Batch(Input_Batch)
#print()
#Display_Kernel(Kernel)
#Convolutional_Transform(Input_Batch,Kernel,Output)
#print()
#Display_Output(Output)

# Load an color image in grayscale
img = cv.imread("red_eyes.jpg",1)
print(type(img))

data = np.asarray( img, dtype="int32" )
#print(data)


#cv.imshow('image',img)
#cv.waitKey(0)
#cv.destroyAllWindows()

height, width, channels = img.shape

print(width)
print(height)

data_R =  [[0 for x in range(width)] for y in range(height)]

for x in range(0,height):
    for y in range(width):
        #data_R[x][y] = data[x][y]
        #print(data[x][y])
        temp = data[x][y]
        if(temp[0] < 0):
            temp[0] = 0
        if(temp[0] > 255):
            temp[0] = 255

        if(temp[1] < 0):
            temp[1] = 0
        if(temp[1] > 255):
            temp[1] = 255


        if(temp[2] < 0):
            temp[2] = 0
        if(temp[2] > 255):
            temp[2] = 255
        #temp[0] = 0
        #temp[1] = 100
        #temp[2] = 100
        data_R[x][y] = temp[0]
        data[x][y] = temp
        #print(data_R[x][y])
        #input()

#image_2d = np.vstack(itertools.imap(numpy.uint16, data[x][y])) 

#im = Image.fromarray(data, 'RGB')
#im.save("your_file.png")
#im.show()
#w, h = 512, 512
#data = np.zeros((h, w, 3), dtype=np.uint8)
#data[0:256, 0:256] = [255, 0, 0] # red patch in upper left
img = Image.fromarray(data, 'RGB')
img.save('my.png')
img.show()

from matplotlib import pyplot as plt
plt.imshow(data)
plt.show()