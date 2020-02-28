import sys

def Fun4():
    test = [11.0, "Ala ma koty", 12, 4, "5"]
    print(len(test),test[0],test[1],test[3:6],test[3:],test[:6],test[-2])
    test.append(121)
    print(test)
    test2 = test + [1,2,3]
    print(test2)
    #11.0 → "Lodz", 1 → 77.
    for index,value in enumerate(test2,start=0):
        if value == 11.0:
            test2[index] = "Lodz"
        if value == 1:
            test2[index] = 77
    print(test2)
    print(12 in test2)
    print(100 in test2)

def Fun5():
    for i in range(0,9):
        print(i)
    print("-------------------")
    for i in range(0,13,3):
        print(i)
    print("-------------------")
    for i in range(-9,0,2):
        print(i)

def Fun6():
    pass
