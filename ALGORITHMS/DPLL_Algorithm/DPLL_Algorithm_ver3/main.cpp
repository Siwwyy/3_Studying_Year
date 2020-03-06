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
	//SAT_File_Reader::File_Reader Obj("50v80c.in");
	//SAT_File_Reader::File_Reader Obj("100v160c.in");
	//SAT_File_Reader::File_Reader Obj("1040v3668c.in");
	SAT_File_Reader::File_Reader Obj("file.in");
	//SAT_File_Reader::File_Reader Obj("file2.in");
	Obj.Read();

	SAT::DPLL DPLL_Object(Obj.Get_File(), Obj.Get_Amout_Of_Literals());
	//DPLL_Object.SAT_or_UNSAT();
	DPLL_Object.Print_Data();
	DPLL_Object.Print_K();

	_STD cin.get();
	return EXIT_SUCCESS;
}