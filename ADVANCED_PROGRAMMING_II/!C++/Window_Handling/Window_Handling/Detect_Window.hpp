/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							Greetings for everyone!
*/
#ifndef _DETECT_WINDOW_HPP_
#define _DETECT_WINDOW_HPP_

#define NEW_LINE '\n'

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <string.h>

#include "Window.hpp"

namespace Window
{

	class Detect_Window
	{
	private:

		//////////////////////////////////////////////////////////////////////////////
		/*
			ZMIENNE PRIVATE
		*/
		_STD vector<_STD unique_ptr<Window>> vec_Windows;
		//////////////////////////////////////////////////////////////////////////////		//////////////////////////////////////////////////////////////////////////////
		/*
			FUNKCJE PRIVATE
		*/

		//////////////////////////////////////////////////////////////////////////////
	public:
		//////////////////////////////////////////////////////////////////////////////
		/*
			KONSTRUKTORY PUBLIC
		*/
		Detect_Window();
		Detect_Window(const Detect_Window & Object);
		//////////////////////////////////////////////////////////////////////////////
		/*
			FUNKCJE PUBLIC
		*/
		const void Print() const;
		//////////////////////////////////////////////////////////////////////////////
		/*
			SETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			OPERATORY PUBLIC
		*/
		//JEDNOARGUMENTOWE
		Detect_Window& operator=(const Detect_Window& Object);
		//DWUARGUMENTOWE
		//////////////////////////////////////////////////////////////////////////////
		/*
			GETTERY PUBLIC
		*/
		_STD vector<_STD unique_ptr<Window>>& Get_vec_Windows();
		//////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUKTOR
		*/
		virtual ~Detect_Window();
	};


	/*
		OTHER FUNCTIONS
	*/
	static BOOL Get_Window(HWND hwnd, LPARAM substring)
	{
		const DWORD TITLE_SIZE = 1024;
		WCHAR windowTitle[TITLE_SIZE];
		GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

		int length = ::GetWindowTextLength(hwnd);
		_STD wstring title(&windowTitle[0]);

		std::vector<std::wstring>& windowTitles = *(reinterpret_cast<std::vector<std::wstring>*>(substring));
		
		// List visible windows with a non-empty title
		if (IsWindowVisible(hwnd) && title != L"")
		{
			windowTitles.emplace_back(title);
			//std::wcout << hwnd << ":  " << windowTitle << NEW_LINE;
		}
		return TRUE;
	}
}

#endif /* _DETECT_WINDOW_HPP_ */