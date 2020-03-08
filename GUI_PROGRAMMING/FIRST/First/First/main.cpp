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
            SendMessage(start, WM_COMMAND, 3, 0);
            break;
        case 10:    //Save as
            PostMessage(start, WM_COMMAND, 4, 0);
            Sleep(1000);

            HWND savedlg;
            savedlg = FindWindow(NULL, L"Save As");
            //HWND hwnd_edit = FindWindow("Edit"
            cout << (savedlg ? "sukcess!" : "failure") << endl;
            cout << "Save dialog handle: " << hex << savedlg << endl;


            ///////////////////////////////////////////////////////////////

            HWND savedlg1;
            //savedlg1 = FindWindowEx(savedlg, NULL, L"(Dialog)", NULL);
            //savedlg1 = FindWindow(NULL, L"#32770");
            savedlg1 = FindWindowEx(savedlg, NULL, L"ToolbarWindow32", NULL);


            //HWND saving_title;
            ////savedlg1 = FindWindowEx(savedlg, NULL, L"(Dialog)", NULL);
            ////savedlg1 = FindWindow(NULL, L"#32770");
            //saving_title = FindWindowEx(savedlg1, NULL, L"DirectUIHWND", NULL);
            //saving_title = FindWindow(NULL, L"*.txt");
           // FindWindowEx()
            cout << (savedlg1 ? "sukcess!" : "failure") << endl;
           // cout << (saving_title ? "sukcess!" : "failure") << endl;
            cout << "Save dialog handle: " << hex << savedlg1 << endl;
            //cout << "Save dialog handle: " << hex << saving_title << endl;
          /*  cout << "enter text: ";
            wcin.getline(wtxt, 1024);*/
            //wchar_t disk_name[] = { 'C',':','/' };
            wchar_t disk_name[] = L"Address: Cddd";
            //std::cin.get();
            //SetFileInformationByHandle(savedlg,)
            //OPENFILENAMEA file{};
            //GetOpenFileNameA(&file);
            //TCHAR tab[1024]{};
            //GetCurrentDirectory(sizeof(tab), tab);
            //ShowWindow(savedlg, SW_HIDE);
            //SendMessage(savedlg1, WM_SETTEXT,0, (LPARAM)L"Address: C:\\Users\\andry\\Desktop\\Dora");
            ///SetWindowTextA(savedlg1, (LPCSTR)disk_name);
            //SetWindowText(savedlg1, disk_name);




            //OPENFILENAME ofn;
            //wchar_t szFileName[MAX_PATH]{};

            //ZeroMemory(&ofn, sizeof(ofn));

            //ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
            //ofn.hwndOwner = savedlg;
            //ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
            //ofn.lpstrFile = szFileName;
            //ofn.nMaxFile = MAX_PATH;
            //ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
            //ofn.lpstrDefExt = L"txt";

            //if (GetOpenFileName(&ofn))
            //{
            //    // Do something usefull with the filename stored in szFileName 
            //}
            //HANDLE hFile;
            //BOOL bSuccess = FALSE;

            //hFile = CreateFile(L"text.txt", GENERIC_WRITE, 0, NULL,
            //    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            //if (hFile != INVALID_HANDLE_VALUE)
            //{
            //    DWORD dwTextLength;

            //    dwTextLength = GetWindowTextLength(savedlg);
            //    // No need to bother if there's no text.
            //    if (dwTextLength > 0)
            //    {
            //        LPSTR pszText;
            //        DWORD dwBufferSize = dwTextLength + 1;

            //        pszText = (LPSTR)GlobalAlloc(GPTR, dwBufferSize);
            //        if (pszText != NULL)
            //        {
            //            if (GetWindowText(savedlg,LPWSTR(pszText), dwBufferSize))
            //            {
            //                DWORD dwWritten;

            //                if (WriteFile(hFile, pszText, dwTextLength, &dwWritten, NULL))
            //                    bSuccess = TRUE;
            //            }
            //            GlobalFree(pszText);
            //        }
            //    }
            //    CloseHandle(hFile);
            //}

            //OPENFILENAME ofn{};
            //char file_name[100]{};

            //ZeroMemory(&ofn, sizeof(OPENFILENAME));

            //ofn.lStructSize = sizeof(OPENFILENAME);
            //ofn.hwndOwner = savedlg1;
            //ofn.lpstrFile = (LPWSTR)file_name;
            //ofn.lpstrFile[0] = '\0';
            //ofn.nMaxFile = 100;
            //ofn.lpstrFilter = L"C:\\Users\\andry\\Desktop\\Dora";
            //ofn.nFilterIndex = 1;

            //GetSaveFileName(&ofn);
            //GetWindowText(savedlg1, (LPWSTR)file_name, 100);

 /*           DWORD dwTextLength = GetWindowTextLength(savedlg1) + 1;

            if (dwTextLength > 0)

            {

                DWORD dwBufferSize = dwTextLength + 1;

                LPWSTR pszText = (LPWSTR)GlobalAlloc(GPTR, dwBufferSize * sizeof(LPWSTR));

                if (pszText != NULL)

                {

                    GetWindowText(savedlg1, pszText, dwTextLength);

                    SetWindowText(savedlg1, L"DDDDDD");

                    GlobalFree(pszText);

                }

            }*/
            SendMessage(edit, WM_GETTEXT, 0, (LPARAM)wtxt);
            std::cin.get();
            //ShowWindow(savedlg, SW_SHOW);

            //SetWindowText(edit, wtxt);
            //SendMessage(edit, WM_SETTEXT, 0, (LPARAM)disk_name+(LPARAM)wtxt);
            break;
        }
    }

    ShowWindow(start, SW_HIDE);
    system("pause");
    ShowWindow(start, SW_SHOW);
    system("pause");
    return 0;
}
