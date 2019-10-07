class Complex(object):
    """description of class"""
    re = float()
    im = float()

    my_vector = []  #only string may looks like this!

    def __init__(self, real_part, imagined_part):
        self.re = real_part
        self.im = imagined_part

####################################################
    def Print_Array(self):
        #for x in range(self.my_vector.count()): #count() function returns length of string
        for x in range(len(self.my_vector)): #count() function returns length of string
            print(self.my_vector[x])
####################################################
    def Get_Real_Part(self):
        return self.re
####################################################
    def Get_Imagined_Part(self):
        return self.im
####################################################
    def Add_To_Array(self, value):
        return self.my_vector.append(value)
####################################################
    def foo(self):
        return "Hello Classes!!"
####################################################

