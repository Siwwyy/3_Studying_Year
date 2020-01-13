#include "Engine.hpp"

Engine::Engine::Engine():
	Handle(NULL)
{

}

void Engine::Engine::Start_Monitoring()
{
	std::vector<std::wstring> titles;
	//WNDENUMPROC proc = &Detect_Window_Object.Get_Window;
    EnumWindows(Window::Detect_Window::Get_Window, reinterpret_cast<LPARAM>(&titles));

	//for (size_t i = 0; i < Detect_Window_Object.Get_vec_Windows().size(); ++i)
	//{
	//	_STD cout << Detect_Window_Object.Get_vec_Windows()[i].get()->Get_window_title() << NEW_LINE;
	//}
}

Engine::Engine::~Engine()
{

}