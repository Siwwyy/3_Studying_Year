/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							Greetings for everyone!
*/
#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#define NEW_LINE '\n'

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <string.h>

namespace Window
{

	template<typename _Ty>
	class Display
	{
	private:

		//////////////////////////////////////////////////////////////////////////////
		/*
			ZMIENNE PRIVATE
		*/

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
		Display();
		Display(const Display & Object);
		//////////////////////////////////////////////////////////////////////////////
		/*
			FUNKCJE PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			SETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			OPERATORY PUBLIC
		*/
		//JEDNOARGUMENTOWE
		Display& operator=(const Display& Object);
		//DWUARGUMENTOWE
		//////////////////////////////////////////////////////////////////////////////
		/*
			GETTERY PUBLIC
		*/

		//////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUKTOR
		*/
		virtual ~Display();
	};

	template<typename _Ty>
	inline Display<_Ty>::Display()
	{

	}

	template<typename _Ty>
	inline Display<_Ty>::Display(const Display& Object)
	{

	}

	template<typename _Ty>
	inline Display<_Ty>& Display<_Ty>::operator=(const Display& Object)
	{
		if (this != _STD addressof(Object))
		{
			//TO DO SOMETHING
		}
		return *this;
	}

	template<typename _Ty>
	inline Display<_Ty>::~Display()
	{

	}
}

#endif /* _DISPLAY_HPP_ */