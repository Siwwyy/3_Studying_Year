
#include <windows.h>
#include "dllloader.h"



//#include <xlib/dg_error.h>
#define START_ERROR
#define THROW_ERROR
#define RETHROW_ERROR

#pragma warning(disable:4996)

XDllInstance::XDllInstance(LPCSTR _name)
:
hDll_(0)
{
   START_ERROR
      dllName_ = _name;
      hDll_ = ::LoadLibraryA(_name);
   if(hDll_ == NULL)
   {
      char txt[1000];
      sprintf(txt, "Error opening library: %s", _name);
      THROW_ERROR(txt, "XDllInstance");
   }
   RETHROW_ERROR("XDllInstance");
}

const char* XDllInstance::GetDllName()
{
   return dllName_.c_str();
}

XDllProc::XDllProc(const XDllInstance& _dll, LPCSTR _id)
:
Proc_(0)
{
   START_ERROR
      Proc_ = ::GetProcAddress(_dll.hDll_, _id);
   if(Proc_ == NULL)
   {
      char txt[1000];
      sprintf(txt, "Error accessing function: %s", _id);
      THROW_ERROR(txt, "XDllProc");
   }
   RETHROW_ERROR("XDllProc");
}


