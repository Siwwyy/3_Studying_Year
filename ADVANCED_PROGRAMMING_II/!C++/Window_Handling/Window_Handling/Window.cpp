#include "Window.hpp"

Window::Window::Window():
	title_size(NULL)
{
	this->window_title = new WCHAR[title_size];
}

Window::Window::Window(const WCHAR * window_title, const DWORD title_size) :
	title_size(title_size)
{
	this->window_title = new WCHAR[title_size];
	for (size_t i = 0; i < this->title_size; ++i)
	{
		this->window_title[i] = window_title[i];
	}
}

Window::Window::~Window()
{
	this->title_size = NULL;
	delete[] this->window_title;
	_STD cout << "DESTRUKTOR WINDOW" << NEW_LINE;
}
