// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BUTTONSLIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BUTTONSLIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once

#ifdef BUTTONSLIBRARY_EXPORTS
	#define BUTTONSLIBRARY_API __declspec(dllexport)
#else
	#define BUTTONSLIBRARY_API __declspec(dllimport)
#endif

#include <iostream>
#include <windows.h>
#include <cstdint>
#include <memory>
#include <string>

namespace BUTTON
{
	// This class is exported from the dll
	class BUTTONSLIBRARY_API CButtonsLibrary
	{
	private:
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PRIVATE VARIABLES
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		HWND hWnd;
		MSG msg;
		int32_t x_pos;
		int32_t y_pos;
		wchar_t button_name[1024];
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PRIVATE FUNCTIONS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		void CreateButton(void);
		/////////////////////////////////////////////////////////////////////////////////////////////
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC CONSTRUCTORS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		CButtonsLibrary(void) = delete;
		CButtonsLibrary(const int32_t x_pos, const int32_t y_pos, const wchar_t * const _ptr);
		CButtonsLibrary(const CButtonsLibrary& Object);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC SETTERS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		void Set_X_Pos(const int32_t x_pos);
		void Set_Y_Pos(const int32_t y_pos);
		void Set_Button_Name(const wchar_t* const _ptr);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		void Show();
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC OPERATORS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		//UNARY
		CButtonsLibrary& operator=(const CButtonsLibrary& Object);
		//BINARY

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC GETTERS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		const int32_t Get_X_Pos(void) const;
		const int32_t Get_Y_Pos(void) const;
		const wchar_t *const Get_Button_Name(void) const;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUCTOR
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		virtual ~CButtonsLibrary(void);
		/////////////////////////////////////////////////////////////////////////////////////////////
	};
}

extern "C" BUTTONSLIBRARY_API int nButtonsLibrary;

BUTTONSLIBRARY_API int fnButtonsLibrary(void);