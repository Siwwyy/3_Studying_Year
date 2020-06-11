def Fun1():
    b = 11.0
    B = "ala ma koty"
    zm1 = 12
    zm2 = 4
    Zm3 = "5"
    print("------------------------")
    print(type(b))
    print(b)
    print(type(B))
    print(B)
    print(type(zm1))
    print(zm1)
    print(type(zm2))
    print(zm2)
    print(type(Zm3))
    print(Zm3)
    print("------------------------")

    a,ca,cb = 11,12,"cos"
    print(a,ca,cb)
    print("------------------------")

    print(zm1+zm2)
    print(B+ " i psa")
    print(b%zm2)
    print(b*zm1)
    print(b**zm1)
    print(B*zm1)
    #print(B*Zm3)
    print("------------------------")

    print(len(B))
    print(B[0])
    print(B[1])
    print(B[3:6])
    print(B[3:])
    print(B[:6])
    print(B[-2])

    print("------------------------")
    print(B*int(Zm3))
    print(type(str(3)))

    print("------------------------")
    Bnew = "Ala ma " + str(3) + " koty"
    print(Bnew)
    print(Bnew[0:2])
    print(Bnew[0:8:2])
    print(Bnew[-3:len(Bnew):2])

    print("------------------------")
    x = Bnew.replace("koty", "psy")
    print(x)
    print("------------------------")
