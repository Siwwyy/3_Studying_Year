#include <iostream>
#include <vector>
#define _STD ::std::
#define NEW_LINE '\n'

#include "File_Reader.hpp"
#include "DPLL.hpp"


//#include<functional>
//
//class MyClass {
//public:
//	void func() 
//	{
//		std::cout << "I am func \n";
//	}
//
//	MyClass(int y) : x(y) {}
//
//	int getval()
//	{
//		return x;
//	}
//
//	void setval(const int x)
//	{
//		this->x = x;
//	}
//
//private:
//	int x;
//};

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	//SAT_File_Reader::File_Reader Obj("16v18c.in");
	//SAT_File_Reader::File_Reader Obj("50v80c.in");
	//SAT_File_Reader::File_Reader Obj("100v160c.in");
	//SAT_File_Reader::File_Reader Obj("1040v3668c.in");
	SAT_File_Reader::File_Reader Obj("file.in");
	//SAT_File_Reader::File_Reader Obj("file2.in");
	Obj.Read();
	//Obj.Print();
	Obj.Print_Literals();

	//SAT::DPLL DPLL_Object(Obj.Get_File(), Obj.Get_Amout_Of_Literals());


	//std::vector<std::reference_wrapper<MyClass>> vec;

	//MyClass obj1(2);
	//MyClass obj2(3);

	////MyClass& obj_ref1 = std::ref(obj1);
	////MyClass& obj_ref2 = obj2;

	//vec.push_back(obj1);
	//vec.push_back(obj2);

	//for (auto i : vec)
	//{
	//	//std::remove_reference<MyClass&>::type(obj3).func();
	//	std::cout << std::remove_reference<MyClass&>::type(i).getval() << "\n";
	//}

	//for (auto i : vec)
	//{
	//	//std::remove_reference<MyClass&>::type(obj3).func();
	//	i.get().setval(10);
	//}

	//for (auto i : vec)
	//{
	//	//std::remove_reference<MyClass&>::type(obj3).func();
	//	std::cout << std::remove_reference<MyClass&>::type(i).getval() << "\n";
	//}

	//std::cout << obj1.getval();

	_STD cin.get();
	return EXIT_SUCCESS;
}