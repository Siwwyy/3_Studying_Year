#include <iostream>
#include <vector>
#define _STD ::std::
#define NEW_LINE '\n'

#include "File_Reader.hpp"
#include "DPLL.hpp"

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	//SAT_File_Reader::File_Reader Obj("16v18c.in");
	SAT_File_Reader::File_Reader Obj("file.in");
	Obj.Read();

	SAT::DPLL DPLL_Object(Obj.Get_File(), Obj.Get_Amout_Of_Literals());
	DPLL_Object.SAT_or_UNSAT();
	//DPLL_Object.Print_Data();
	//DPLL_Object.Print_Unary_Variables();
	//DPLL_Object.Print_Knowledge();


	//std::vector<std::vector<int> > v(10); //Allocate space for 100 vectors

	//for (int i = 0; i < 10; i++)
	//{
	//	v[i].resize(10); //set the size of these 100 vectors to say 100 again
	//	for (int j = 0; j < 10; j++)
	//	{
	//		v[i][j] = i;
	//	}
	//}

	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//	{
	//		std::cout << v[i][j] << ' ';
	//	}
	//	std::cout << "\n";
	//}
	//std::cout << "\n";
	//std::cout << "\n";
	//v[1].erase(std::remove(v[1].begin(), v[1].end(), 1), v[1].end());	//removing unecessary elements
	//v.erase(v.begin() + 1, v.begin() + 2);
	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//	{
	//		std::cout << v[i][j] << ' ';
	//	}
	//	std::cout << "\n";
	//}
	_STD cin.get();
	return EXIT_SUCCESS;
}