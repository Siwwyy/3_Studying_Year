#include "Detect_Window.hpp"

Window::Detect_Window::Detect_Window():
	Handle(NULL)
{

}

BOOL Window::Detect_Window::Get_Window(HWND hwnd, LPARAM substring)
{
	const DWORD TITLE_SIZE = 1024;
	WCHAR windowTitle[TITLE_SIZE];
	GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);
	

	int length = ::GetWindowTextLength(hwnd);
	_STD wstring title(&windowTitle[0]);

	//this->vec_Windows.emplace_back((&Window(windowTitle, TITLE_SIZE)));
	// List visible windows with a non-empty title
	if (IsWindowVisible(hwnd) && title != L"")
	{
		std::wcout << hwnd << ":  " << windowTitle << NEW_LINE;
	}
	return TRUE;
}

Window::Detect_Window::~Detect_Window()
{
	//vec_Windows.clear();
}
