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
            //1 — Notatnik
            //1 - Notatnik
            start = FindWindow(NULL, wtxt);
            //start = FindWindow(NULL, L"1 — Notatnik");
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
            char title[1024];
            GetWindowTextA(start, (LPSTR)title, 1024);
            if ((title[0] == 'U' && title[1] == 'n') || (title[0] == '*' && title[1] == 'U'))
            {
                PostMessage(start, WM_COMMAND, 4, 0);
                Sleep(1000);

                wchar_t file_path[1024];
                HWND SaveAs = 0;
                HWND View = 0;
                HWND Direct = 0;
                HWND FloatNotifySink = 0;
                HWND ComboBox = 0;
                HWND file_path_field = 0;

                SaveAs = FindWindow(NULL, L"Save As");
                View = FindWindowEx(SaveAs, NULL, L"DUIViewWndClassName", NULL);
                Direct = FindWindowEx(View, NULL, L"DirectUIHWND", NULL);
                FloatNotifySink = FindWindowEx(Direct, NULL, L"FloatNotifySink", NULL);
                ComboBox = FindWindowEx(FloatNotifySink, NULL, L"ComboBox", NULL);
                file_path_field = FindWindowEx(ComboBox, NULL, L"Edit", NULL);
                cout << "Set file name: ";
                wcin.getline(file_path, 1024);
                std::cout << '\n';
                SendMessage(file_path_field, WM_SETTEXT, 0, (LPARAM)file_path);
                HWND child = ::FindWindowEx(SaveAs,NULL,TEXT("Button"), NULL);

                if (child)
                {
                    ::SendMessage(child, BM_CLICK, NULL, NULL);
                }
            }
            else
            {
                SendMessage(start, WM_COMMAND, 3, 0);
                Sleep(1000);

            }
            break;

        case 10:    //Save as
            PostMessage(start, WM_COMMAND, 4, 0);
            Sleep(1000);

            wchar_t file_path[1024];
            HWND SaveAs = 0;
            HWND View = 0;
            HWND Direct = 0;
            HWND FloatNotifySink = 0;
            HWND ComboBox = 0;
            HWND file_path_field = 0;

            SaveAs = FindWindow(NULL, L"Save As");
            View = FindWindowEx(SaveAs, NULL, L"DUIViewWndClassName", NULL);
            Direct = FindWindowEx(View, NULL, L"DirectUIHWND", NULL);
            FloatNotifySink = FindWindowEx(Direct, NULL, L"FloatNotifySink", NULL);
            ComboBox = FindWindowEx(FloatNotifySink, NULL, L"ComboBox", NULL);
            file_path_field = FindWindowEx(ComboBox, NULL, L"Edit", NULL);
            cout << "Set file name: ";
            wcin.getline(file_path, 1024);
            std::cout << '\n';
            SendMessage(file_path_field, WM_SETTEXT, 0, (LPARAM)file_path);
            HWND child = ::FindWindowEx(SaveAs, NULL, TEXT("Button"), NULL);
            if (child)
            {
                ::SendMessage(child, BM_CLICK, NULL, NULL);
            }
            break;
        }
    }

    ShowWindow(start, SW_HIDE);
    system("pause");
    ShowWindow(start, SW_SHOW);
    system("pause");
    return 0;
}
