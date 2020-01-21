#include "Engine.hpp"

Engine::Engine::Engine()
{

}
//
//Engine::Engine::Engine(const Engine& Object):
//    Detect_Window_Object(Object.Detect_Window_Object)
//{
//
//}

void Engine::Engine::Start_Monitoring()
{
    std::vector<std::wstring> windowTitles;
    EnumWindows(Window::Get_Window, reinterpret_cast<LPARAM>(&windowTitles));

    Detect_Window_Object.Get_vec_Windows().resize(windowTitles.size());

    //Insert handled windows names
    for (typename _STD vector<std::wstring>::iterator iterator_windowTitles = windowTitles.begin(); iterator_windowTitles != windowTitles.end(); ++iterator_windowTitles)
    {
        Detect_Window_Object.Get_vec_Windows()[std::distance(windowTitles.begin(), iterator_windowTitles)] = std::make_unique<Window::Window>(new Window::Window((*iterator_windowTitles).c_str(), (*iterator_windowTitles).size()));
    }
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