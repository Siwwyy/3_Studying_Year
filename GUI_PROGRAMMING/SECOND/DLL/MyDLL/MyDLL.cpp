// MyDLL.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "MyDLL.h"


// This is an example of an exported variable
MYDLL_API int nMyDLL=0;

// This is an example of an exported function.
MYDLL_API int fnMyDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CMyDLL::CMyDLL()
{
    return;
}
