#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "Buttons_Library.hpp"


int main(int argc, char* argv[])
{
    BUTTON::CButtonsLibrary Obj(200,200);
    Obj.Show();

	system("pause");
	return 0;
}