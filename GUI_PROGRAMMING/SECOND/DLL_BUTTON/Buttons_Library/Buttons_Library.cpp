// Buttons_Library.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Buttons_Library.hpp"


// This is an example of an exported variable
BUTTONSLIBRARY_API int nButtonsLibrary=0;

// This is an example of an exported function.
BUTTONSLIBRARY_API int fnButtonsLibrary(void)
{
    return 0;
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::CreateButton(void)
{
    this->hWnd = CreateWindow(TEXT("button"), (LPCTSTR)this->button_name.c_str(), WS_VISIBLE | WS_POPUP, this->x_pos, this->y_pos, 80, 25, NULL, NULL, NULL, NULL);
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const int32_t x_pos, const int32_t y_pos, const std::wstring& button_name):
    x_pos(x_pos),
    y_pos(y_pos),
    button_name(button_name),
    msg({}),
    hWnd(NULL)
{
    CreateButton();
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const CButtonsLibrary& Object) :
    x_pos(Object.x_pos),
    y_pos(Object.y_pos),
    button_name(Object.button_name),
    msg(Object.msg),
    hWnd(Object.hWnd)
{
    CreateButton();
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Set_X_Pos(const int32_t x_pos)
{
    this->x_pos = x_pos;
    DestroyWindow(this->hWnd);
    CreateButton();
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Set_Y_Pos(const int32_t y_pos)
{
    this->y_pos = y_pos;
    DestroyWindow(this->hWnd);
    CreateButton();
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Set_Button_Name(const EXPIMP_TEMPLATE std::wstring& button_name)
{
    this->button_name = button_name;
    DestroyWindow(this->hWnd);
    CreateButton();
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary& BUTTON::CButtonsLibrary::operator=(const CButtonsLibrary& Object)
{
    if (this != std::addressof(Object))
    {
        DestroyWindow(this->hWnd);
        this->x_pos = Object.x_pos;
        this->y_pos = Object.y_pos;
        this->button_name = Object.button_name;
        this->hWnd = Object.hWnd;
    }
    return *this;
}

BUTTONSLIBRARY_API const int32_t BUTTON::CButtonsLibrary::Get_X_Pos(void) const
{
    return this->x_pos;
}

BUTTONSLIBRARY_API const int32_t BUTTON::CButtonsLibrary::Get_Y_Pos(void) const
{
    return this->y_pos;
}

BUTTONSLIBRARY_API const EXPIMP_TEMPLATE std::wstring BUTTON::CButtonsLibrary::Get_Button_Name(void) const
{
    return this->button_name;
}

// This is the constructor of a class that has been exported.
BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::~CButtonsLibrary(void)
{
    DestroyWindow(this->hWnd);
}