from My_Class import Person

class Student(Person):
    """description of class"""
    #pass
    def __init__(self, name = "John", surname = "Wick", ID = 123456789, debit = 0.0, faculty = "WFiIS"):
        #self.name = name
        #self.surname = surname
        #self.ID = ID
        #self.NS = self.name + self.surname
        #self.debit = 0.0
        super().__init__(name,surname,ID,debit)
        self.faculty = faculty

    def __str__(self):
            return super().__str__()+" Faculty: {0}".format(self.faculty);

    def Get_Name(self): #method overriding 
        return super().Get_Name() 
