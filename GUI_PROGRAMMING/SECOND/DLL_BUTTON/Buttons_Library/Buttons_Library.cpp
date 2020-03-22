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
    this->hWnd = CreateWindow(TEXT("button"), this->button_name, WS_VISIBLE | WS_POPUP, this->x_pos, this->y_pos, 80, 25, NULL, NULL, NULL, NULL);
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const int32_t x_pos, const int32_t y_pos, const wchar_t* const _ptr) :
    x_pos(x_pos),
    y_pos(y_pos),
    button_name(),
    msg({}),
    hWnd(NULL)
{
    size_t i{};
    while(_ptr[i] != '\0')
    {
        this->button_name[i] = _ptr[i];
        ++i;
    }
    CreateButton();
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const CButtonsLibrary& Object) :
    x_pos(Object.x_pos),
    y_pos(Object.y_pos),
    msg(Object.msg),
    hWnd(Object.hWnd)
{
    for (size_t i = 0; i < static_cast<size_t>(1024); ++i)
    {
        this->button_name[i] = Object.button_name[i];
    }
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

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Set_Button_Name(const wchar_t* const _ptr)
{
    size_t i{};
    while (_ptr[i] != '\0')
    {
        this->button_name[i] = _ptr[i];
        ++i;
    }
    while (button_name[i] != '\0')
    {
        this->button_name[i] = '\0';
        ++i;
    }
    DestroyWindow(this->hWnd);
    CreateButton();
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Show()
{
    HWND quit_hwnd = CreateWindow(TEXT("button"), TEXT("Quit") , WS_VISIBLE | WS_POPUP, this->x_pos, this->y_pos+50, 80, 25, NULL, NULL, NULL, NULL);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.hwnd == this->hWnd)
        {
            switch (msg.message)
            {
                case WM_LBUTTONDOWN:
                    break;
                case WM_LBUTTONUP:
                    Beep(2000, 500);
                    break;
            }
        }
        if (msg.hwnd == quit_hwnd)
        {
            switch (msg.message)
            {
                case WM_LBUTTONUP:
                    DestroyWindow(quit_hwnd);
                    DestroyWindow(this->hWnd);
                    PostQuitMessage(0);
                    break;
            }
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary& BUTTON::CButtonsLibrary::operator=(const CButtonsLibrary& Object)
{
    if (this != std::addressof(Object))
    {
        DestroyWindow(this->hWnd);
        this->x_pos = Object.x_pos;
        this->y_pos = Object.y_pos;
        for (size_t i = 0; i < static_cast<size_t>(1024); ++i)
        {
            this->button_name[i] = Object.button_name[i];
        }
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

const wchar_t* const BUTTON::CButtonsLibrary::Get_Button_Name(void) const
{
    return this->button_name;
}

// This is the constructor of a class that has been exported.
BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::~CButtonsLibrary(void)
{
    DestroyWindow(this->hWnd);
    this->x_pos = NULL;
    this->y_pos = NULL;
    this->hWnd = NULL;
    for (size_t i = 0; i < static_cast<size_t>(1024); ++i)
    {
        this->button_name[i] = NULL;
    }
}