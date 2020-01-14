#include "Detect_Window.hpp"

Window::Detect_Window::Detect_Window():
	Handle(NULL)
{
	/*vec_Windows.emplace_back(new Window[10]{});*/
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
		//Window A(windowTitle, TITLE_SIZE);
		//vec_Windows.emplace_back(_STD move(_STD make_unique<Window>((new Window(windowTitle, TITLE_SIZE)))));
		//std::wcout << hwnd << ":  " << windowTitle << NEW_LINE;
	}
	return TRUE;
}

::std::vector<::std::unique_ptr<int>>& Window::Detect_Window::Get_vec_Windows()
{
	return vec_Windows;
}

Window::Detect_Window::~Detect_Window()
{
	//vec_Windows.clear();
	//vec_Windows.erase(vec_Windows.begin(), vec_Windows.end());
	//vec_Windows.clear();
	
}
