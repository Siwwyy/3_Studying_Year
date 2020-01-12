#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tchar.h>
#include <windows.h>

#define NEW_LINE '\n'


BOOL CALLBACK Get_Window(HWND hwnd, LPARAM substring) 
{
	const DWORD TITLE_SIZE = 1024;
	WCHAR windowTitle[TITLE_SIZE];
	GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

	int length = ::GetWindowTextLength(hwnd);
	_STD wstring title(&windowTitle[0]);

	// List visible windows with a non-empty title
	if (IsWindowVisible(hwnd) && title != L"")
	{
		std::wcout << hwnd << ":  " << windowTitle << NEW_LINE;
	}
	return TRUE;
}

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	LPCSTR app_name = "";
	//f5 to refresh monitor , if user type a name for instance
	/*
		Notepad -> Seek in vector of wstring for title which will match it
		OPENED APPS MONITOR
	*/
	std::vector<std::wstring> titles;
	EnumWindows(Get_Window, reinterpret_cast<LPARAM>(&titles));

	HWND Find = FindWindow(0, L"Calculator");
	if (Find)
	{
		cout << "znaleziono";
		Sleep(500);
		SendMessage(Find, WM_CLOSE, 0, NULL);
	}

	else 
	{
		cout << "Nie znaleziono";
	}

	_STD cout << NEW_LINE;
	system("pause");
	return 0;
}