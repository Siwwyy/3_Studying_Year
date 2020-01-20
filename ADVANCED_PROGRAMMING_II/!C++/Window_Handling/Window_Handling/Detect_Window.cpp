#include "Detect_Window.hpp"

Window::Detect_Window::Detect_Window():
	vec_Windows()
{
	
}

const void Window::Detect_Window::Print() const
{
	for (typename _STD vector<_STD unique_ptr<Window>>::const_iterator iterator_vec_Windows = vec_Windows.begin(); iterator_vec_Windows != vec_Windows.end(); ++iterator_vec_Windows)
	{
		const WCHAR* window_title = (*iterator_vec_Windows)->Get_window_title();
		_STD wcout << window_title << NEW_LINE;
		//system("pause");
		//system("cls");
		//_STD wcout <<  << NEW_LINE;
	}
}

::std::vector<::std::unique_ptr<Window::Window>>& Window::Detect_Window::Get_vec_Windows()
{
	return this->vec_Windows;
}

Window::Detect_Window::~Detect_Window()
{
	vec_Windows.clear();
}