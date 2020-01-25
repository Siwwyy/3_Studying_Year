#include "Engine.hpp"

Engine::Engine::Engine()
{

}

//Engine::Engine::Engine(const Engine& Object):
//    Detect_Window_Object(Object.Detect_Window_Object)
//{
//
//}

void Engine::Engine::Start_Monitoring()
{
    Detect_Window_Object.Clear();
    for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT))
    {
        if (!IsWindowVisible(hwnd))
        {
            continue;
        }
        else
        {
            size_t length = static_cast<size_t>(GetWindowTextLength(hwnd));
            if (length > 0)
            {
                ++length;
                //WCHAR windowTitle[TITLE_SIZE];
                WCHAR* windowTitle = new WCHAR[length];
                GetWindowTextW(hwnd, windowTitle, length);
                //std::wcout << "HWND: " << hwnd << " Title: " << windowTitle << std::endl;
                ////std::wcout << length << std::endl;

                Detect_Window_Object.Get_vec_Windows().emplace_back(std::make_unique<Window::Window>(new Window::Window(windowTitle, length)));
                delete[] windowTitle;
            }  
        }
    }

    //HWND hwnd = GetTopWindow(NULL);
    ////hw = FindWindow(NULL,NULL);
    //std::vector<std::wstring> windowTitles;
    //std::thread t1(Window::Get_Window, hwnd, reinterpret_cast<LPARAM>(&windowTitles));
    ////EnumWindows(Window::Get_Window, reinterpret_cast<LPARAM>(&windowTitles));
    //t1.join();
    //_STD cout << NEW_LINE;
    //_STD cout << NEW_LINE;
    //_STD cout << NEW_LINE;
    //Detect_Window_Object.Get_vec_Windows().resize(windowTitles.size());

    ////Insert handled windows names
    //for (typename _STD vector<std::wstring>::iterator iterator_windowTitles = windowTitles.begin(); iterator_windowTitles != windowTitles.end(); ++iterator_windowTitles)
    //{
    //    Detect_Window_Object.Get_vec_Windows()[std::distance(windowTitles.begin(), iterator_windowTitles)] = std::make_unique<Window::Window>(new Window::Window((*iterator_windowTitles).c_str(), (*iterator_windowTitles).size()));
    //}
    ////Detect_Window_Object.Print();
}

void Engine::Engine::Print() const
{
    Detect_Window_Object.Print();
}

//Engine::Engine& Engine::Engine::operator=(const Engine& Object)
//{
//    if (this != _STD addressof(Object))
//    {
//        Detect_Window_Object = Object.Detect_Window_Object;
//    }
//    return *this;
//}

Engine::Engine::~Engine()
{

}