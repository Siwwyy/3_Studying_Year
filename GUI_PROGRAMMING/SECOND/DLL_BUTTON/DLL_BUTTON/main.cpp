#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "Buttons_Library.hpp"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main(int argc, char* argv[])
{
    //BUTTON::CButtonsLibrary Obj(200,200,L"Buttonek");
    BUTTON::CButtonsLibrary Obj(200,200);
    Obj.Show();
//int WINAPI main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
    //MSG msg;
    ////if you add WS_CHILD flag,CreateWindow will fail because there is no parent window.
    //HWND hWnd = CreateWindow(TEXT("button"), TEXT("Button"), WS_VISIBLE | WS_POPUP, 200, 200, 80, 25, NULL, NULL, NULL, NULL);

    //ShowWindow(hWnd, SW_SHOW);
    //UpdateWindow(hWnd);
    //int cos = 200;
    //while (GetMessage(&msg, NULL, 0, 0) && GetAsyncKeyState(VK_ESCAPE) == false)
    //{
    //    DestroyWindow(hWnd);
    //    Sleep(1000);
    //    hWnd = CreateWindow(TEXT("button"), TEXT("Button"), WS_VISIBLE | WS_POPUP, 200, cos, 80, 25, NULL, NULL, NULL, NULL);
    //    ShowWindow(hWnd, SW_SHOW);
    //    UpdateWindow(hWnd);
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //    if (cos == 200)
    //    {
    //        cos = 1000;
    //    }
    //    else if (cos == 1000)
    //    {
    //        cos = 200;
    //    }
    //    Sleep(1000);
    //    //DestroyWindow(hWnd);
    //}

  /*  MSG  msg;
    WNDCLASS wc = { 0 };
    wc.lpszClassName = TEXT("Menu");
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DDKSHADOW);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_HAND);


    RegisterClass(&wc);
    CreateWindow(wc.lpszClassName, TEXT("Menu"), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 230, 150, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }*/
    //MSG  msg;
    //HWND hwndButton = CreateWindow(TEXT("button"), TEXT("Button"), WS_VISIBLE | WS_POPUP, 200, 200, 80, 25, NULL, NULL, NULL, NULL);
    //while (GetMessage(&msg, NULL, 0, 0))
    //{
    //    if (msg.hwnd == hwndButton)
    //    {
    //        switch (msg.message)
    //        {
    //        case WM_LBUTTONDOWN:
    //            // start sound
    //            std::cout << "WM_LBUTTONDOWN" << '\n';
    //            continue;
    //        case WM_LBUTTONUP:
    //            // stop sound
    //            std::cout << "WM_LBUTTONUP" << '\n';
    //            continue;
    //        }
    //        // Allow other messages to fall through
    //    }
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //}

	system("pause");
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            CreateWindow(TEXT("button"), TEXT("Beep"), WS_VISIBLE | WS_CHILD, 20, 50, 80, 25, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow(TEXT("button"), TEXT("Quit"), WS_VISIBLE | WS_CHILD, 120, 50, 80, 25, hwnd, (HMENU)2, NULL, NULL);
            break;
        }

        case WM_COMMAND:
        {
            if (LOWORD(wParam) == 1) 
            {
                Beep(40, 50);
            }

            if (LOWORD(wParam) == 2) 
            {
                PostQuitMessage(0);
            }

            break;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}