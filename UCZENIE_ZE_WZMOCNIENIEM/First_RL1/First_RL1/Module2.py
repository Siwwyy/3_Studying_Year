import sysconfig
import math

def Fun2():
    print("Podaj znak/ciag znakow: ")
    x = input()
    print(len(x))

def Fun3():
    print("Podaj liczbe ")
    x = int(input())
    print("X is bigger than 0" if x > 0 else "X is less than 0")

def Quadratic_Equation():
    print("Podaj a")
    a = int(input())
    print("Podaj b")
    b = int(input())
    print("Podaj c")
    c = int(input())

    delta = pow(b,2) - 4*a*c

    if delta > 0:
        x1 = ((-1)*b - math.sqrt(delta))/(2*a)
        x2 = ((-1)*b + math.sqrt(delta))/(2*a)
        print("x1={0}, x2={1}",x1,x2)
    elif delta == 0:
        x1 = (-1*b)/(2*a)
        print("x={0}",x1)
    else:
        print("Brak pierwiastkow")