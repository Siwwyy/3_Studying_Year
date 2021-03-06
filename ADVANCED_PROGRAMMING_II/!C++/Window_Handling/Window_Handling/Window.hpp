/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							Greetings for everyone!
*/
#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_
#define NEW_LINE '\n'

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <string.h>

namespace Window
{

	class Window
	{
	private:
		//////////////////////////////////////////////////////////////////////////////
		/*
			ZMIENNE PRIVATE
		*/
		DWORD window_title_size;
		WCHAR* window_title;
		//////////////////////////////////////////////////////////////////////////////
	public:
		//////////////////////////////////////////////////////////////////////////////
		/*
			KONSTRUKTORY PUBLIC
		*/
		Window();
		Window(const WCHAR * window_title, const DWORD window_title_size);
		Window(const Window& Object);
		Window(const Window* Object);
		//////////////////////////////////////////////////////////////////////////////
		/*
			FUNKCJE PUBLIC
		*/
		const void Print() const;
		static void Deleter(Window * To_Delete);
		//////////////////////////////////////////////////////////////////////////////
		/*
			SETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			OPERATORY PUBLIC
		*/
		//JEDNOARGUMENTOWE
		Window& operator=(const Window& Object);
		Window& operator=(const Window* Object);
		//DWUARGUMENTOWE
		//////////////////////////////////////////////////////////////////////////////
		/*
			GETTERY PUBLIC
		*/
		const DWORD Get_window_title_size() const;
		const WCHAR* Get_window_title() const;
		//////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUKTOR
		*/
		virtual ~Window();
	};

}

#endif /* _WINDOW_HPP_ */