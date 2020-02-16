#include <iostream>
#define _STD ::std::
#define NEW_LINE '\n'

#include "File_Reader.hpp"
#include "DPLL.hpp"

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	SAT_File_Reader::File_Reader Obj("16v18c.in");
	Obj.Read();

	SAT::DPLL DPLL_Object(Obj.Get_File(), Obj.Get_Max_Value());
	DPLL_Object.SAT_or_UNSAT();
	DPLL_Object.Print_Data();
	DPLL_Object.Print_Unary_Variables();

	_STD cin.get();
	return EXIT_SUCCESS;
}