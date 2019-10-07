import Functions
import time

print("-------------------------------");
print("     Matrix Multiplication")
print("-------------------------------");
print("\n")
print("Set the width of the both matrices:")
Width = int(input())
print("Set the height of the both matrices:")
Height = int(input())

print("Set the basic values of the both matrices:")
Basic_Value = int(input())

Matrix1 = [[0 for x in range(Width)] for y in range(Height)]
Matrix2 = [[0 for x in range(Width)] for y in range(Height)]
Matrix3 = [[0 for x in range(Width)] for y in range(Height)]
print("\n")

Functions.Fill_Matrix(Matrix1, Basic_Value)
Functions.Fill_Matrix(Matrix2, Basic_Value)
Functions.Fill_Matrix(Matrix3, Initial_Value = 0)

print("Would you like to display all of matrices you have created? Y or N:")
Choice = str(input())
print("\n")
if Choice == "Y":
    Functions.Display_Matrix(Matrix1)
    print("-------------------------------");
    Functions.Display_Matrix(Matrix2)
else: 
    pass    #empty statement, the code is skipping
print("\n")
print("I am multiplicating these matrices...:")
Functions.Multiply_Matrices(Matrix1,Matrix2,Matrix3)
time.sleep(1)
print("\n")
print("Result is following:")
Functions.Display_Matrix(Matrix3)