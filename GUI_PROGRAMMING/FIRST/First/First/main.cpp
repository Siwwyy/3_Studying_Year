#include <iostream>
#include <Windows.h>

using namespace std;

int main()
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
        cout << "Notepad not found\n";
        //return 0;
    }
    cout << "Window handle: " << hex << start << endl;

    int n;
    while (1) 
    {
        cout << "********************************************" << endl
            << "* options:" << endl
            << "* 1. end" << endl
            << "* 2. Find notepad using name" << endl
            << "* 3. Find notepad using class" << endl
            << "* 4. Hide notepad" << endl
            << "* 5. Show notepad" << endl
            << "* 6. Hide notepad window" << endl
            << "* 7. Show notepad window" << endl
            << "* 8. Send text to notepad" << endl
            << "* 9. Save" << endl
            << "* 10. Save As..." << endl
            << "********************************************" << endl
            << "selection: ";
        cin >> n;
        cin.getline(txt, 64);

        //cout << endl << endl << "wprowadz:";
        //cin.getline(txt, 64);
        //cout << txt << endl;


        switch (n)
        {
        case 0:
        case 1:
            return 0;

        case 2:
        {
            cout << "enter name: ";
            wcin.getline(wtxt, 64);
            wcout << wtxt << endl;
            //1 � Notatnik
            //1 - Notatnik
            start = FindWindow(NULL, wtxt);
            //start = FindWindow(NULL, L"1 � Notatnik");
            cout << (start ? "sukcess!" : "failure") << endl;
            break;
        }
        case 3:
            start = FindWindowEx(NULL, NULL, L"Notepad", NULL);
            cout << (start ? "sukcess!" : "failure") << endl;
            edit = FindWindowEx(start, NULL, L"Edit", NULL);
            cout << (edit ? "sukcess!" : "failure") << endl;
            cout << "Window handle: " << hex << start << endl;
            cout << "Edit handle: " << hex << edit << endl;

            break;

        case 4:
            ShowWindow(edit, SW_HIDE);
            break;

        case 5:
            ShowWindow(edit, SW_SHOW);
            break;

        case 6:
            ShowWindow(start, SW_HIDE);
            break;

        case 7:
            ShowWindow(start, SW_SHOW);
            break;

        case 8:
            if (!edit)
                break;
            cout << "enter text: ";
            wcin.getline(wtxt, 1024);
            //SetWindowText(edit, wtxt);
            SendMessage(edit, WM_SETTEXT, 0, (LPARAM)wtxt);

            break;

        case 9:     //Save
            SendMessage(start, WM_COMMAND, 3, 0);
            break;
        case 10:    //Save as
            PostMessage(start, WM_COMMAND, 4, 0);
            Sleep(1000);

            HWND savedlg;
            savedlg = FindWindow(NULL, L"Save As");
            cout << (savedlg ? "sukcess!" : "failure") << endl;
            cout << "Save dialog handle: " << hex << savedlg << endl;


            ///////////////////////////////////////////////////////////////

            HWND savedlg1;
            savedlg1 = FindWindowEx(NULL, savedlg, L"DirectUIHWND");
            cout << (savedlg1 ? "sukcess!" : "failure") << endl;
            cout << "Save dialog handle: " << hex << savedlg << endl;
          /*  cout << "enter text: ";
            wcin.getline(wtxt, 1024);*/
            wchar_t disk_name[] = { 'C',':','/' };
            //SetWindowText(edit, wtxt);
           // SendMessage(edit, WM_SETTEXT, 0, (LPARAM)disk_name+(LPARAM)wtxt);
            break;
        }
    }

    ShowWindow(start, SW_HIDE);
    system("pause");
    ShowWindow(start, SW_SHOW);
    system("pause");
    return 0;
}
