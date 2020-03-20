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

BUTTONSLIBRARY_API LRESULT Window_Process(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return LRESULT();
}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::CreateButton(void)
{
    this->hWnd = CreateWindow(TEXT("button"), TEXT("Close Notepad"), WS_VISIBLE | WS_POPUP, this->x_pos, this->y_pos, 80, 25, NULL, NULL, NULL, NULL);
}

//BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const int32_t x_pos, const int32_t y_pos, const std::wstring& button_name):
//    x_pos(x_pos),
//    y_pos(y_pos),
//    button_name(button_name),
//    msg({}),
//    hWnd(NULL)
//{
//    CreateButton();
//}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const int32_t x_pos, const int32_t y_pos) :
    x_pos(x_pos),
    y_pos(y_pos),
    msg({}),
    hWnd(NULL)
{
    CreateButton();
}

BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::CButtonsLibrary(const CButtonsLibrary& Object) :
    x_pos(Object.x_pos),
    y_pos(Object.y_pos),
    //button_name(Object.button_name),
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

//BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Set_Button_Name(const EXPIMP_TEMPLATE std::wstring& button_name)
//{
//    this->button_name = button_name;
//    DestroyWindow(this->hWnd);
//    CreateButton();
//}

BUTTONSLIBRARY_API void BUTTON::CButtonsLibrary::Show()
{
    char txt[64];
    wchar_t wtxt[1024];
    //string s;

//    system("pause");


    HWND start = 0;
    HWND edit = 0;
    start = FindWindow(NULL, L"Untilted - Notepad");

    if (start == NULL)
    {
        std::cout << "Notepad not found\n";
        //return 0;
    }
    std::cout << "Window handle: " << std::hex << start << std::endl;

    int n;
    bool exit{ true };
    while (exit)
    {
        std::cout << "********************************************" << std::endl
            << "* options:" << std::endl
            << "* 1. end" << std::endl
            << "* 2. Find notepad using name" << std::endl
            << "* 3. Find notepad using class" << std::endl
            << "********************************************" << std::endl
            << "selection: ";
        std::cin >> n;
        //std::cin.getline(txt, 64);

        //cout << endl << endl << "wprowadz:";
        //cin.getline(txt, 64);
        //cout << txt << endl;


        switch (n)
        {
            case 0:
            case 1:
                exit = false;

            case 2:
        
                std::cout << "enter name: ";
                std::wcin.getline(wtxt, 64);
                std::wcout << wtxt << std::endl;
                //1 — Notatnik
                //1 - Notatnik
                start = FindWindow(NULL, wtxt);
                //start = FindWindow(NULL, L"1 — Notatnik");
                std::cout << (start ? "sukcess!" : "failure") << std::endl;
                break;
        
            case 3:
                start = FindWindowEx(NULL, NULL, L"Notepad", NULL);
                std::cout << (start ? "sukcess!" : "failure") << std::endl;
                edit = FindWindowEx(start, NULL, L"Edit", NULL);
                std::cout << (edit ? "sukcess!" : "failure") << std::endl;
                std::cout << "Window handle: " << std::hex << start << std::endl;
                std::cout << "Edit handle: " << std::hex << edit << std::endl;
                break;

        }

     
    }
    SendMessage(start, WM_CLOSE, NULL, NULL);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.hwnd == this->hWnd)
        {
            switch (msg.message)
            {
                case WM_LBUTTONDOWN:
                    std::cout << "WM_LBUTTONDOWN" << '\n';
                    break;
                case WM_LBUTTONUP:
                    std::cout << "WM_LBUTTONUP" << '\n';
                    //add destroing window here
                    SendMessage(start, WM_CLOSE, NULL, NULL);
                    break;

                //default: std::cout << "| " << msg.message << " |"<< '\n';
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
        //this->button_name = Object.button_name;
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

//BUTTONSLIBRARY_API const EXPIMP_TEMPLATE std::wstring BUTTON::CButtonsLibrary::Get_Button_Name(void) const
//{
//    return this->button_name;
//}

// This is the constructor of a class that has been exported.
BUTTONSLIBRARY_API BUTTON::CButtonsLibrary::~CButtonsLibrary(void)
{
    DestroyWindow(this->hWnd);
    this->x_pos = NULL;
    this->y_pos = NULL;
    this->hWnd = NULL;
}