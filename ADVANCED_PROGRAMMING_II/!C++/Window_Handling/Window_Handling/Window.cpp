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

Window::Window::Window(const Window& Object):
	title_size(Object.title_size)
{
	this->window_title = new WCHAR[title_size];
	for (size_t i = 0; i < this->title_size; ++i)
	{
		this->window_title[i] = Object.window_title[i];
	}
}

Window::Window::Window(const Window* Object) :
	title_size(Object->title_size)
{
	this->window_title = new WCHAR[title_size];
	for (size_t i = 0; i < this->title_size; ++i)
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

const DWORD Window::Window::Get_title_size() const
{
	return this->title_size;
}

const WCHAR* Window::Window::Get_window_title() const
{
	return this->window_title;
}

Window::Window::~Window()
{
	this->title_size = NULL;
	delete[] this->window_title;
	_STD cout << "DESTRUKTOR WINDOW" << NEW_LINE;
}
