class Person(object):
    """description of class"""
    #name = "John"       #static variable name inside the class, not a typical type in class like in C++ (global)
    #surname = "Wick"
    def __init__(self, name = "John", surname = "Wick", ID = 123456789, debit = 0.0):
        #self.name = "John"
        #self.surname = "Wick"
        #self.ID = 123456789
        self.name = name
        self.surname = surname
        self.ID = ID
        self.NS = self.name + self.surname
        self.debit = 0.0


    def Add_Debit(self,amount):
        self.debit -= amount
        

    def __str__(self):
        #return self.name + " " + self.surname
        return "{0} {1} {2} Debit: {3} ".format(self.name, self.surname, self.ID,self.debit);

    def Get_Name(self):
        return self.name