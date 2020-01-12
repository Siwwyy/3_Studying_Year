/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							Greetings for everyone!
*/
#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_
#define NEW_LINE '\n'

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <string.h>

#include "Detect_Window.hpp"


namespace Engine
{

	class Engine
	{
	private:
		//////////////////////////////////////////////////////////////////////////////
		/*
			ZMIENNE PRIVATE
		*/
		HWND Handle;
		Window::Detect_Window Detect_Window_Object;
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
		Engine();
		//////////////////////////////////////////////////////////////////////////////
		/*
			FUNKCJE PUBLIC
		*/
		void Start_Monitoring();
		//////////////////////////////////////////////////////////////////////////////
		/*
			SETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			OPERATORY PUBLIC
		*/
		//JEDNOARGUMENTOWE

		//DWUARGUMENTOWE
		//////////////////////////////////////////////////////////////////////////////
		/*
			GETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUKTOR
		*/
		virtual ~Engine();
	};

}

#endif /* _ENGINE_HPP_ */