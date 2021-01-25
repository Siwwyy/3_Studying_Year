
import math
import matplotlib.pyplot as plt


def Rownanie(x, t):
    if x == 1.0:
        return 1
    else:
        rownanie = [ math.cos(x), math.sin((t/4)) ]
        return rownanie[0] * rownanie[1]



def Foo():
    iteracji = 50

    h = 0.5
    x = 0.0
    x_star = 0.0
    y = 1
    y_star = 0.0
    m_star = 0.0
    i = 0

    wartosc_rownania = []
    wartosc_x = []

    for i in range(1,iteracji):
        wartosc_x.append( x )
        wartosc_rownania.append( y )
        x_star = x + h
        y_star = y + h * Rownanie(x,y)
        m_star = Rownanie(x,y)
        y = y + 0.5 * h * (Rownanie(x,y) + m_star)
        x = x + h

    plt.figure(figsize=(10, 10))
    plt.plot(wartosc_x, wartosc_rownania)
    plt.title('Metoda Eulera-Cauchego')
    plt.xlabel('Wartosc x')
    plt.ylabel('Wartosc y')

    plt.show()


Foo()