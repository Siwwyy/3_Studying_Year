from My_Class import Person
from Student import Student
from math import *


print("-------------------------------");
print("     Python Class, 10/10/2019")
print("-------------------------------");
print("\n")

Person_One = Person("Piotr","Nowak", "97030474388")

Person_One.Add_Debit(13.43)
print(Person_One)

Person_Two = Student("Marcin","Pawlak", "96110243895", 12.23)
#Person_Two = Student.Student()

print(Person_Two)
print("{0} {1}",Person_One.Get_Name(), Person_Two.Get_Name())

print("\n")
print("\n")
##################################################################################
print("Usage of lambdas")
my_first_lambda = lambda a : a + 10

print(my_first_lambda(1))

my_second_lambda = lambda value: float(sin(value))
print(my_second_lambda(1))

class_lambda1 = lambda : print(Person_Two)
class_lambda1()

#def main():
#    Person_One = My_Class.Person("Piotr","Nowak", "97030474388")

#    Person_One.Add_Debit(13.43)
#    print(Person_One)

#    Person_Two = Student.Student("Marcin","Pawlak", "96110243895")

#    Person_Two.Add_Debit(13.43)
#    print(Person_Two)

