#include <windows.h>
#include "dllaccess.h"


#pragma warning(disable:4996)


MyStaticInterface::MyStaticInterface(const CHAR * _fname)
:
XDllInstance(_fname)
, CreateMyStatic(*this, "CreateMyStatic")
{
}


MyStaticInterface::~MyStaticInterface()
{
}
