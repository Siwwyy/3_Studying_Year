#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>

#include "MyStatic.h"



MyStatic::MyStatic()
    :
    hwnd_(0)
, hfont_(0)
, fcolor_(0)
, bcolor_(0)
, OldWndProc(0)
{
}


MyStatic::~MyStatic()
{
    if (hfont_)
    {
        DeleteObject(hfont_);
    }
}

void MyStatic::Create(HWND _parent, DWORD _styles, int _x, int _y, int _width, int _height)
{
    _styles |= WS_CHILD | SS_OWNERDRAW;
    hwnd_ = CreateWindow(
        L"Static",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        _styles, //WS_TABSTOP | WS_VISIBLE | WS_CHILD,  // Styles 
        _x,         // x position 
        _y,         // y position 
        _width,        // Button width
        _height,        // Button height
        _parent,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLong(_parent, GWL_HINSTANCE),
        NULL);      // Pointer not needed.

    //okno utworzone
    //bierzemy wskaznik this i umieszczamy go w userdata
    //potrzebny bedzie pozniej przy procedurze okna
    SetWindowLong(*this, GWL_USERDATA, (LONG)this); 

    //pobierz stary adres procedury okna
    OldWndProc = (LRESULT(*CALLBACK)(HWND, UINT, WPARAM, LPARAM)) GetWindowLong(*this, GWL_WNDPROC);
    SetWindowLong(*this, GWL_WNDPROC, (LONG)staticWndProc);
     
}

void MyStatic::SetText(const wchar_t * _txt)
{
    SetWindowTextW(*this, _txt);
}

void MyStatic::SetText(const char * _txt)
{
    SetWindowTextA(*this, _txt);
    //SendMessageA(*this, WM_SETTEXT, NULL, (LPARAM)_txt);
}

void MyStatic::SetText(std::string& _s)
{
    SetText(_s.c_str());
}

wchar_t* MyStatic::GetText(wchar_t* _buf, int _size)
{
    GetWindowTextW(*this, _buf, _size);
    return _buf;
}

char* MyStatic::GetText(char* _buf, int _size)
{
    GetWindowTextA(*this, _buf, _size);
    return _buf;

}

std::string& MyStatic::GetText(std::string &_s)
{
    char txt[1024];
    GetText(txt, 1024);
    _s = txt;
    return _s;
}


void MyStatic::SetFont(const TCHAR* _name, LONG _height, LONG _weight, BYTE _italic, BYTE _underline, BYTE _strikeOut, BYTE _charSet)
{
    if (hfont_)
        DeleteObject(hfont_);
    LOGFONT f = { 0 };
    _tcscpy_s(f.lfFaceName, _name);   //uzywamy tcscpy aby byc niezlaeznym od wide i char
    f.lfHeight = _height;
    f.lfWeight = _weight;
    f.lfItalic = _italic;
    f.lfUnderline = _underline;
    f.lfStrikeOut = _strikeOut;
    f.lfCharSet = _charSet;
    hfont_ = CreateFontIndirect(&f);

    SendMessage(*this, WM_SETFONT, (WPARAM)hfont_, MAKELPARAM(0, TRUE));
}

void MyStatic::SetFont(LONG _height, LONG _weight, BYTE _italic, BYTE _charSet, BYTE _underline, BYTE _strikeOut)
{
    SetFont(L"", _height, _weight, _italic, _underline, _strikeOut, _charSet);
}


void MyStatic::SetTextColor(int _r, int _g, int _b)
{
    fcolor_ = RGB(_r, _g, _b);
    
}

void MyStatic::SetBckColor(int _r, int _g, int _b)
{
    bcolor_ = RGB(_r, _g, _b);

}


void MyStatic::UpdateWindow()
{
    //::UpdateWindow(*this);
    InvalidateRect(*this, NULL, TRUE);

}



LRESULT CALLBACK MyStatic::WindowProc(UINT _msg, WPARAM _wparam, LPARAM _lparam)
{

    switch (_msg) {
    case WM_DESTROY:
        //przywracamy stara wartosc procedury okna i konczymy
        SetWindowLong(*this, GWL_WNDPROC, (LPARAM)OldWndProc); //v2
        PostQuitMessage(0);
        break;
    case WM_PAINT:
    {
        RECT rc;
        PAINTSTRUCT ps;
        HFONT oldfont = 0;
        TCHAR buf[1024];
        GetWindowText(*this, buf, 1024);

        HDC hdc = BeginPaint(*this, &ps);
        GetClientRect(*this, &rc);
        //SetBkMode(hdc, TRANSPARENT);
        COLORREF oldcolor = ::SetTextColor(hdc, fcolor_);
        if(hfont_)
            oldfont = (HFONT)::SelectObject(hdc, hfont_);
        DrawText(hdc, buf, -1, &rc, DT_LEFT | DT_VCENTER);

        if (oldfont)
            ::SelectObject(hdc, oldfont);
        ::SetTextColor(hdc, oldcolor);
        EndPaint(*this, &ps);
        //break;
        return CallWindowProc((WNDPROC)OldWndProc, *this, _msg, _wparam, _lparam);

    }
    case WM_MYSTATIC_SETCOLOR:
    {
        fcolor_ = _lparam;
        UpdateWindow();
        break;
    }
    //niestety ponizszy kod dziala tylko dla rodzica
    //case WM_CTLCOLORSTATIC:
    //case WM_CTLCOLOREDIT:
    //{
    //    HDC hdcStatic = (HDC)_wparam;
    //    ::SetTextColor(hdcStatic, fcolor_);
    //    ::SetBkColor(hdcStatic, bcolor_);

    //    if (hbrush_ == NULL)
    //    {
    //        hbrush_ = CreateSolidBrush(bcolor_);
    //    }

    //    return (INT_PTR)hbrush_;
    //}
    default:
    //    return DefWindowProc(*this, _msg, _wparam, _lparam);
        return CallWindowProc((WNDPROC)OldWndProc, *this, _msg, _wparam, _lparam);

    }
    return 0;
}







LRESULT CALLBACK MyStatic::staticWndProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
    MyStatic *wnd;
    wnd = (MyStatic *)GetWindowLong(_hwnd, GWL_USERDATA);
    if (wnd)
        return wnd->WindowProc(_msg, _wparam, _lparam);
    
    return DefWindowProc(_hwnd, _msg, _wparam, _lparam);
}


HWND WINAPI CreateMyStatic(
    LPCTSTR lpWindowName			// pointer to window name
    , DWORD dwStyle						// window style
    , int x								// horizontal position of window
    , int y								// vertical position of window
    , int nWidth							// window width
    , int nHeight						// window height
    , HWND hWndParent 					//rodzic dla okna
)
{
#pragma comment(linker, "/EXPORT:" __FUNCTION__"=" __FUNCDNAME__)
    MyStatic *ms = new MyStatic;
    ms->Create(hWndParent, dwStyle, x, y, nWidth, nHeight);
    return *ms;
}
