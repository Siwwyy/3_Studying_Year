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

	Engine::Engine Engine_Object;
	Engine_Object.Start_Monitoring();

	_STD cout << NEW_LINE;
	system("pause");
	return 0;
}