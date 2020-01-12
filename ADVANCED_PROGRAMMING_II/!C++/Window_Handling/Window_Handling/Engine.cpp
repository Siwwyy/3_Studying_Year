#include "Engine.hpp"

Engine::Engine::Engine()
{

}

void Engine::Engine::Start_Monitoring()
{
	std::vector<std::wstring> titles;
	//WNDENUMPROC proc = Detect_Window_Object.Get_Window;
	//Detect_Window_Object
	//WNDENUMPROC proc = &Window::Detect_Window::Get_Window;
	WNDENUMPROC proc = &Detect_Window_Object.Get_Window;
    EnumWindows(Window::Detect_Window::Get_Window, reinterpret_cast<LPARAM>(&titles));
}

Engine::Engine::~Engine()
{
}
