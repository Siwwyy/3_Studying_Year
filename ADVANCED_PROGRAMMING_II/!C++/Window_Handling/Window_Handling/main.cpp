#include <iostream>
#include <windows.h>
#include <string>

#define INCLUDE_FORBID
#include "Engine.hpp"

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	//LPCSTR app_name = "";
	////
	//APPLICATION APPROACH 
	//f5 to refresh monitor , if user type a name for instance
	///*
	//	Notepad -> Seek in vector of wstring for title which will match it
	//	OPENED APPS MONITOR
	//*/
	//std::vector<std::wstring> titles;
	//EnumWindows(Get_Window, reinterpret_cast<LPARAM>(&titles));

	//HWND Find = FindWindow(0, L"Calculator");
	//if (Find)
	//{
	//	cout << "znaleziono";
	//	Sleep(500);
	//	SendMessage(Find, WM_CLOSE, 0, NULL);
	//}

	//else 
	//{
	//	cout << "Nie znaleziono";
	//}
	HWND consoleWindowHandle = GetConsoleWindow();
	::SetWindowPos(consoleWindowHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	::ShowWindow(consoleWindowHandle, SW_NORMAL);
	Engine::Engine Engine_Object;
	for (size_t i = 0; i < 1000; ++i)
	{
		Engine_Object.Start_Monitoring();
		Engine_Object.Print();
		std::cin.get();
		system("cls");
	}


	_STD cout << NEW_LINE;
	system("pause");
	return 0;
}