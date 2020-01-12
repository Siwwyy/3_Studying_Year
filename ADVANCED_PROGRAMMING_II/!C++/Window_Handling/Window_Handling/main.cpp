#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <tchar.h>
#include <windows.h>

#define NEW_LINE '\n'

_STD vector<_STD string> vec{};

BOOL CALLBACK speichereFenster(HWND hwnd, LPARAM substring) 
{
	const DWORD TITLE_SIZE = 1024;
	WCHAR windowTitle[TITLE_SIZE];

	GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

	int length = ::GetWindowTextLength(hwnd);
	_STD wstring title(&windowTitle[0]);
	if (!IsWindowVisible(hwnd) || length == 0 || title == L"Program Manager")
	{
		return TRUE;
	}

	// Retrieve the pointer passed into this callback, and re-'type' it.
	// The only way for a C API to pass arbitrary data is by means of a void*.

	std::vector<std::wstring>& titles = *reinterpret_cast<std::vector<std::wstring>*>(substring);
	titles.push_back(title);

	return TRUE;
}

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	LPCSTR app_name = "";

	std::vector<std::wstring> titles;
	EnumWindows(speichereFenster, reinterpret_cast<LPARAM>(&titles));
	// At this point, titles if fully populated and could be displayed, e.g.:
	for (const auto& title : titles)
	{
		std::wcout << L"Title: " << title << std::endl;
	}


	system("pause");
	return 0;
}