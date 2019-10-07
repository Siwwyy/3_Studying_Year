#HERE IS A MODULE FOR FUNCTIONS (DEFINITIONS KNOWN AS DEF)


############################################################

def Fill_Matrix(Param,Initial_Value):
    for x in range(len(Param)):
            for y in range(len(Param[x])):
                Param[x][y] = Initial_Value

############################################################

def Display_Matrix(Param1):
    for a in range(len(Param1)):
        for b in range(len(Param1[a])):
            print(Param1[a][b], end =' ')
        print()

############################################################

def Multiply_Matrices(Mat1,Mat2,Mat3):
    for i in range(len(Mat1)):
        for j in range(len(Mat1[i])):
            for k in range(len(Mat1[j])):
                Mat3[i][j] += Mat1[i][k] * Mat2[k][j]

############################################################