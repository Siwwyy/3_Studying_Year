#include <iostream>
#include "Buttons_Library.hpp"


int main(int argc, char* argv[])
{
    BUTTON::CButtonsLibrary Obj(200,200, L"Beep Me");
    Obj.Show();

	return EXIT_SUCCESS;
}