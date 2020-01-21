#include "Window.hpp"

Window::Window::Window():
	window_title_size(NULL)
{
	this->window_title = new WCHAR[window_title_size];
}

Window::Window::Window(const WCHAR * window_title, const DWORD window_title_size) :
	window_title_size(window_title_size)
{
	this->window_title = new WCHAR[window_title_size];
	for (size_t i = 0; i < this->window_title_size; ++i)
	{
		this->window_title[i] = window_title[i];
	}
}

Window::Window::Window(const Window& Object):
	window_title_size(Object.window_title_size)
{
	this->window_title = new WCHAR[window_title_size];
	for (size_t i = 0; i < this->window_title_size; ++i)
	{
		this->window_title[i] = Object.window_title[i];
	}
}

Window::Window::Window(const Window* Object) :
	window_title_size(Object->window_title_size)
{
	this->window_title = new WCHAR[window_title_size];
	for (size_t i = 0; i < this->window_title_size; ++i)
	{
		this->window_title[i] = Object->window_title[i];
	}
}

const void Window::Window::Print() const
{
	
}

void Window::Window::Deleter(Window* To_Delete)
{
	delete To_Delete;
}

const DWORD Window::Window::Get_window_title_size() const
{
	return this->window_title_size;
}

const WCHAR* Window::Window::Get_window_title() const
{
	return this->window_title;
}

Window::Window::~Window()
{
	this->window_title_size = NULL;
	delete[] this->window_title;
	_STD cout << "DESTRUKTOR WINDOW" << NEW_LINE;
}
