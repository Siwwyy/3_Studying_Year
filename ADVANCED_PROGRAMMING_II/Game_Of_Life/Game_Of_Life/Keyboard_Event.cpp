#include "Keyboard_Event.hpp"

bool Engine::Keyboard_Event::KeyEvent(KEY_EVENT_RECORD& krec, HANDLE _HANDLE_PARAM)
{
	DWORD cc;
	INPUT_RECORD IN_REC;

	for (;;)
	{
		ReadConsoleInput(_HANDLE_PARAM, &IN_REC, 1, &cc);
		if (IN_REC.EventType == KEY_EVENT && ((KEY_EVENT_RECORD&)IN_REC.Event).bKeyDown)
		{
			krec = (KEY_EVENT_RECORD&)IN_REC.Event;
			return true;
		}
	}
	return false;
}

Engine::Keyboard_Event::Keyboard_Event() :
	Engine(),
	m_key({})
{

}

Engine::Keyboard_Event::Keyboard_Event(const Keyboard_Event& Object) :
	Engine(Object),
	m_key(Object.m_key)
{

}

bool Engine::Keyboard_Event::Detect_Key(const enum class Keyboard_Event::Keys key)
{
	KeyEvent(this->m_key, this->m_hndl_in);
	return ((this->m_key.wVirtualKeyCode == static_cast<WORD>(key)) ? true : false);
}

Engine::Keyboard_Event& Engine::Keyboard_Event::operator=(const Keyboard_Event& rhs)
{
	if (this != std::addressof(rhs))
	{
		Engine::Engine::operator=(rhs);
		this->m_key = rhs.m_key;
	}
	return *this;
}

Engine::Keyboard_Event::~Keyboard_Event()
{
	this->m_key = {};
}