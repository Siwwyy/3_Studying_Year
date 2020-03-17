#if !defined(dllfilter_h)
#define dllfilter_h
//#include <atlbase.h>
#include <windows.h>
#include <string>
//#include "filterhandling/FilterCurve_d.h"


class XDllInstance
{
public:
	XDllInstance(LPCSTR _name);
	HINSTANCE hDll_;

	const char* GetDllName();
private:
	std::string dllName_;
};


class XDllProc {
  public:
    XDllProc(const XDllInstance& _dll, LPCSTR _id);

  protected:
    FARPROC Proc_;
};


class XDllProcV0 : public XDllProc {
  public:
    XDllProcV0(const XDllInstance& _dll, LPCSTR _id) : XDllProc(_dll, _id) {}

    typedef void (far WINAPI* XProc_)();
    void operator ()() {
      ((XProc_)Proc_)();
    }
};

template <class R>
class XDllProc0 : public XDllProc {
  public:
    XDllProc0(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)();
    R operator ()() {
      return ((XProc_)Proc_)();
    }
};

template <class P1>
class XDllProcV1 : public XDllProc {
  public:
    XDllProcV1(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1);
    void operator ()(P1 p1) {
      ((XProc_)Proc_)(p1);
    }
};

//
template <class R, class P1>
class XDllProc1 : public XDllProc {
  public:
    XDllProc1(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1);
    R operator ()(P1 p1) {
      return ((XProc_)Proc_)(p1);
      // przy tym returnie dostaje blad:
      /*Run-Time Check Failure #0 - The value of ESP was not properly saved 
      across a function call.  This is usually a result of calling a function 
      declared with one calling convention with a function pointer declared 
      with a different calling convention.*/
    }
};

//
template <class P1, class P2>
class XDllProcV2 : public XDllProc {
  public:
    XDllProcV2(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 a2);
    void operator ()(P1 p1, P2 a2) {
      ((XProc_)Proc_)(p1, a2);
    }
};

//
template <class R, class P1, class P2>
class XDllProc2 : public XDllProc {
  public:
    XDllProc2(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2);
    R operator ()(P1 p1, P2 p2) {
      return ((XProc_)Proc_)(p1, p2);
    }
};

//
template <class P1, class P2, class P3>
class XDllProcV3 : public XDllProc {
  public:
    XDllProcV3(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3);
    void operator ()(P1 p1, P2 p2, P3 p3) {
      ((XProc_)Proc_)(p1, p2, p3);
    }
};

//
template <class R, class P1, class P2, class P3>
class XDllProc3 : public XDllProc {
  public:
    XDllProc3(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3);
    R operator ()(P1 p1, P2 p2, P3 p3) {
      return ((XProc_)Proc_)(p1, p2, p3);
    }
};

//
template <class P1, class P2, class P3, class P4>
class XDllProcV4 : public XDllProc {
  public:
    XDllProcV4(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4) {
      ((XProc_)Proc_)(p1, p2, p3, p4);
    }
};

//
template <class R, class P1, class P2, class P3, class P4>
class XDllProc4 : public XDllProc {
  public:
    XDllProc4(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4) {
      return ((XProc_)Proc_)(p1, p2, p3, p4);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5>
class XDllProcV5 : public XDllProc {
  public:
    XDllProcV5(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5>
class XDllProc5 : public XDllProc {
  public:
    XDllProc5(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6>
class XDllProcV6 : public XDllProc {
  public:
    XDllProcV6(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6>
class XDllProc6 : public XDllProc {
  public:
    XDllProc6(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6, class P7>
class XDllProcV7 : public XDllProc {
  public:
    XDllProcV7(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                     P7 p7);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7) {
      ((XProc_)Proc_) (p1, p2, p3, p4, p5, p6, p7);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7>
class XDllProc7 : public XDllProc {
  public:
    XDllProc7(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8>
class XDllProcV8 : public XDllProc {
  public:
    XDllProcV8(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                     P7 p7, P8 p8);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8>
class XDllProc8 : public XDllProc {
  public:
    XDllProc8(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7, P8 p8);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9>
class XDllProcV9 : public XDllProc {
  public:
    XDllProcV9(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9>
class XDllProc9 : public XDllProc {
  public:
    XDllProc9(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7, P8 p8, P9 p9);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10>
class XDllProcV10 : public XDllProc {
  public:
    XDllProcV10(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                     P7 p7, P8 p8, P9 p9, P10 p10);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10>
class XDllProc10 : public XDllProc {
  public:
    XDllProc10(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7, P8 p8, P9 p9, P10 p10);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11>
class XDllProcV11 : public XDllProc {
  public:
    XDllProcV11(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                     P7 p7, P8 p8, P9 p9, P10 p10, P11 p11);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11>
class XDllProc11 : public XDllProc {
  public:
    XDllProc11(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7, P8 p8, P9 p9, P10 p10, P11 p11);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12>
class XDllProcV12 : public XDllProc {
  public:
    XDllProcV12(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                     P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12>
class XDllProc12 : public XDllProc {
  public:
    XDllProc12(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                  P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13>
class XDllProcV13 : public XDllProc {
  public:
    XDllProcV13(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,
                                    P12 p12, P13 p13);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12, P13 p13) {
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13>
class XDllProc13 : public XDllProc {
  public:
    XDllProc13(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,
                                    P12 p12, P13 p13);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12, P13 p13) {
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,class P14>
class XDllProcV14 : public XDllProc {
  public:
    XDllProcV14(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12,p13,p14);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14>
class XDllProc14 : public XDllProc {
  public:
    XDllProc14(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12,p13,p14);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,class P14, 
          class P15>
class XDllProcV15 : public XDllProc {
  public:
    XDllProcV15(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,p15);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15>
class XDllProc15 : public XDllProc {
  public:
    XDllProc15(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16>
class XDllProcV16 : public XDllProc {
  public:
    XDllProcV16(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,
                    p15,p16);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16>
class XDllProc16 : public XDllProc {
  public:
    XDllProc16(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15,p16);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17>
class XDllProcV17 : public XDllProc {
  public:
    XDllProcV17(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,
                    p15,p16,p17);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17>
class XDllProc17 : public XDllProc {
  public:
    XDllProc17(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15,p16,p17);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18>
class XDllProcV18 : public XDllProc {
  public:
    XDllProcV18(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, P18 p18){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,
                    p15,p16,p17,p18);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18>
class XDllProc18 : public XDllProc {
  public:
    XDllProc18(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, P18 p18){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15,p16,p17,p18);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18, class P19>
class XDllProcV19 : public XDllProc {
  public:
    XDllProcV19(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18, P19 p19);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, 
         P18 p18, P19 p19){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,
                    p15,p16,p17,p18,p19);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18, class P19>
class XDllProc19 : public XDllProc {
  public:
    XDllProc19(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18, P19 p19);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, 
         P18 p18, P19 p19){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15,p16,p17,p18,p19);
    }
};
//
template <class P1, class P2, class P3, class P4, class P5, class P6,class P7, 
          class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18, class P19, 
          class P20>
class XDllProcV20 : public XDllProc {
  public:
    XDllProcV20(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef void (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18, P19 p19, P20 p20);
    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, 
         P18 p18, P19 p19, P20 p20){
      ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,p14,
                    p15,p16,p17,p18,p19,p20);
    }
};
//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13,
          class P14, class P15, class P16, class P17, class P18, class P19, 
          class P20>
class XDllProc20 : public XDllProc {
  public:
    XDllProc20(const XDllInstance& module, LPCSTR id) : XDllProc(module, id) {}

    typedef R (far WINAPI* XProc_)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
         P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,P12 p12, P13 p13, P14 p14,
         P15 p15, P16 p16, P17 p17, P18 p18, P19 p19, P20 p20);
    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
         P10 p10, P11 p11, P12 p12, P13 p13, P14 p14,P15 p15, P16 p16, P17 p17, 
         P18 p18, P19 p19, P20 p20){
      return ((XProc_)Proc_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, 
                           p13,p14,p15,p16,p17,p18,p19,p20);
    }
};

/*class XDllLoader : public XDllInstance
{
public:
	XDllLoader(const char * _dllname);

	XDllProc0<const char*> GetModuleIdText;
	XDllProc0<const char*> Version;
	XDllProc0<const char*> About;
	XDllProc0<unsigned> GetNumOfFilters;
	XDllProc1<const char*, unsigned> GetFilterGroup;

};*/

#endif
