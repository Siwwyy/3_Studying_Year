import MyClass

print("-------------------------------");
print("     My First Class")
print("-------------------------------");
print("\n")

x = float()
y = float()
print("Set the real and imagined parts!");
print("Real part: ");
x = input()
print("Imagined part: ");
y = input()
print("\n")
#Object = MyClass.Complex()
#Object = MyClass.Complex(-3.1, 2.5)
Object = MyClass.Complex(x, y)
#print(Object.re)
#print(Object.im)
################################
Object_Function = Object.foo();
print(Object_Function);
################################
Object_Function = Object.Get_Real_Part();
print("Real part: ",Object_Function);
################################
Object_Function = Object.Get_Imagined_Part();
print("Imagined part: ",Object_Function);
################################
print("\n")

#Add_To_Array = Object.Add_To_Array()

print("Now, Let's add something to array inside the class object!")
print("\n")
for i in range(10):
    Object.Add_To_Array("a")

Object_Function = Object.Print_Array();