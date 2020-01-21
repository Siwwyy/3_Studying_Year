#include "Detect_Window.hpp"

Window::Detect_Window::Detect_Window():
	vec_Windows()
{
	
}

//Window::Detect_Window::Detect_Window(const Detect_Window& Object):
//	vec_Windows(Object.vec_Windows)
//{
//
//}

const void Window::Detect_Window::Print() const
{
	HWND Find{};
	_STD wstring temp{};
	for (typename _STD vector<_STD unique_ptr<Window>>::const_iterator iterator_vec_Windows = vec_Windows.begin(); iterator_vec_Windows != vec_Windows.end(); ++iterator_vec_Windows)
	{
		for (size_t i = 0; i < static_cast<size_t>((*iterator_vec_Windows)->Get_window_title_size()); ++i)
		{
			temp += (*iterator_vec_Windows)->Get_window_title()[i];
			_STD wcout << (*iterator_vec_Windows)->Get_window_title()[i];
		}
		//Find = FindWindow(0, reinterpret_cast<LPCWSTR>(&temp));
		Find = FindWindow(0, temp.c_str());
		if (Find)
		{
			_STD cout << " -> Window has been found" << NEW_LINE;
			//int choice{};
			//_STD cin >> choice;
			//if (choice == 1)
			//{
			//	SendMessage(Find, WM_CLOSE, 0, NULL);
			//}
			//_STD cout << NEW_LINE;
			//Sleep(500);
			//SendMessage(Find, WM_CLOSE, 0, NULL);
		}
		temp.clear();
		_STD wcout << NEW_LINE;
	}
}

//Window::Detect_Window& Window::Detect_Window::operator=(const Detect_Window& Object)
//{
//	if (this != _STD addressof(Object))
//	{
//		vec_Windows.clear();
//		vec_Windows = Object.vec_Windows;
//	}
//	return *this;
//}

::std::vector<::std::unique_ptr<Window::Window>>& Window::Detect_Window::Get_vec_Windows()
{
	return this->vec_Windows;
}

Window::Detect_Window::~Detect_Window()
{
	vec_Windows.clear();
}