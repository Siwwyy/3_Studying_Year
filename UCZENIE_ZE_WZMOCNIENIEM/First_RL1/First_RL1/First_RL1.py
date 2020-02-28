#import Module1
#import Module2
import Lists

import numpy as np
import sys
import random

#Module1.Fun1()
#Module2.Fun2()
#Module2.Fun3()
#Module2.Quadratic_Equation()
#Lists.Fun4()
#Lists.Fun5()
#Lists.Fun6()
#Lists.Fun7()
#print(Lists.Fun8(2,3))
#print("Max:{0}, Sum:{1}".format(Lists.info_list([1,2,3,4,5,6])[0],Lists.info_list([1,2,3,4,5,6])[1]))


#RL2

#a = np.array([1,2,3,4,5])
#b = np.array((0.4, 1.6, 2.1, -3.7, 2.9))
#b = b.astype(int)
#c = np.array([[1, 9, 3],[4, 5, 6]])
#d = np.array([[1, 9, 3.14],[-4, 5, 6]])
#e = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])

#print(a.shape,b.shape)
#print(e.ndim,e.shape,e.size,e.dtype,e.itemsize,e.nbytes)

#X1 = np.zeros((2, 3, 4))
##print(X1.shape)

#X2 = np.zeros((2, 3))
##print(X2)

#X3 = np.full((6,2,1,2),7)
##print(X3)

##X4 = np.full((5,7),np.random.rand(2,20))
#X4 = np.random.randint(2,20, size=(5,6))
##print(X4)
#X5 = np.full((5,5),1)
##print(X5)


#print(X4[3][2])
#print(X4[3])
##print(X5[2][:len(X5)])
#print(X5[:len(X5)][2])

#A = np.full((5,5),1)
##B = A[:5][1:3]
#B = A[:5,1:3]
#C = A[1:3,1:]
#B[0][0] = 10
#print(A)
#print("\n")
#print(B)
#print("\n")
#print(C)
#print("\n")
#print(A.shape,B.shape,C.shape)

#A1 = np.array([[1,2,3],[4,5,6]])
#B1 = A1.copy();
#C1 = A1.copy();

D = np.ndarray(shape=(12,), dtype=int)
D1 = D.reshape(6,2)
D2 = D.reshape(3,2,2)
D3 = D.reshape(6,2,1)
D4 = D.reshape(6,2,1,1)
print(D.shape,D1.shape,D2.shape,D3.shape,D4.shape)