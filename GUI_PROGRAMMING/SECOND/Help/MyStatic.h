//**************************************
//
// MyStatic
//
// Klasa wrapper wokol static control z WinAPI
// -------------------------
//
// Autor
// P.Kowalczyk	marzec 2017
// 
//
// Historia zmian:
//
// Autor			Co zmienil												data
// P.K.             dodane export/import z pliku DLL                        03/2017
// P.Kowalczyk		wersja oryginalana										03/2017
//
//****************************************


#ifndef MyStatic_h
#define MyStatic_h

#ifdef PGUI_API_EXPORTS
#define PGUI_API __declspec(dllexport)
#else
#define PGUI_API __declspec(dllimport)
#endif



#include <string>

class PGUI_API MyStatic
{
public:
    MyStatic();
    virtual ~MyStatic();

    //funkcja tworzy obiekt static
    void Create(HWND _parent, DWORD _styles, int _x = 0, int _y = 0, int _width = 120, int _height = 20);


    //ustaw tekst w oknie
    void SetText(const wchar_t * _txt);
    void SetText(const char * _txt);
    void SetText(std::string& s);

    //pobierz tekst z okna
    wchar_t* GetText(wchar_t* _buf, int _size);
    char* GetText(char* _buf, int _size);
    std::string& GetText(std::string &_s);

    //funkcje zmieniajace font w polu static
    void SetFont(const TCHAR* _name, LONG _height = 12, LONG _weight = FW_NORMAL, BYTE _italic = FALSE, BYTE _underline = FALSE, BYTE _strikeOut = FALSE, BYTE _charSet = ANSI_CHARSET);
    void SetFont(LONG _height = 12, LONG _weight = FW_NORMAL, BYTE _italic = FALSE, BYTE _charSet = ANSI_CHARSET, BYTE _underline = FALSE, BYTE _strikeOut = FALSE);

    //ustawienie koloru tekstu
    void SetTextColor(int _r, int _g, int _b);

    //ustawienie koloru tla (nie dziala)
    void SetBckColor(int _r, int _g, int _b);


    //odswierzenie zawartosci okna
    void UpdateWindow();


    //operator rzutowania na HWND
    operator HWND();

protected:
    //wirtualna procedura okna
    virtual LRESULT CALLBACK WindowProc(UINT _msg, WPARAM _wparam, LPARAM _lparam);



protected:
    HWND hwnd_;         //uchwyt na okno
    HFONT hfont_;       //uchwyt na font, jesli nie zero to trzeba kasowac
    HBRUSH hbrush_;
    COLORREF fcolor_;   //foreground color
    COLORREF bcolor_;   //background color
    LRESULT (*CALLBACK OldWndProc)(HWND, UINT, WPARAM, LPARAM);        //wskaznik na stara procedure okna


private:
    //
    // konstruktor kopiujacy. Na razie nie pozwalamy na uzycie
    MyStatic(const MyStatic&);

    //
    // operator=. Na razie nie pozwalamy na uzycie
    MyStatic& operator=(const MyStatic&);

    //procedura okna statyczna
    //statyczna nie posiada wskaznika this jako pierwszego parametru i jest kompatybilna z WINAPI
    static LRESULT CALLBACK staticWndProc(HWND, UINT, WPARAM, LPARAM);

};



/////////////////////////////////////////////////////////////////////////////////
//inlines

inline
MyStatic::operator HWND()
{
    return hwnd_;
}

/////////////////////////////////////////////////////////////////////////////////
//Sekcja potrzebna do obslugi dll w sposob niezalezny od kompilatora

//Ustawia kolor znakow, LPARAM zawiera kolor w formacie COLORREF
#define WM_MYSTATIC_SETCOLOR WM_USER+1

HWND PGUI_API WINAPI CreateMyStatic(
     LPCTSTR lpWindowName			// pointer to window name
    , DWORD dwStyle						// window style
    , int x								// horizontal position of window
    , int y								// vertical position of window
    , int nWidth							// window width
    , int nHeight						// window height
    , HWND hWndParent 					//rodzic dla okna
);


#endif