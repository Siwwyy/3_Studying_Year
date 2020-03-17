#if !defined(dllreader_h)
#define dllreader_h
#include "dllloader.h"


class MyStaticInterface : public XDllInstance
{
public:
    MyStaticInterface(const CHAR * _dllname);
	~MyStaticInterface();

	XDllProc7<HWND          //returns HWND
        , LPCTSTR 			// pointer to window name
        , DWORD 			// window style
        , int 				// horizontal position of window
        , int 				// vertical position of window
        , int 				// window width
        , int 				// window height
        , HWND> CreateMyStatic;

};

#endif