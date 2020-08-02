#include "_MORSE_BLINK.h"

using namespace std;

_MORSE_BLINK::_MORSE_BLINK() :
	_MORSE_BASE(),
	buffer(),
	m__Pause(0),
	m__DotTime(0),
	m__DashTime(0),
	m__CharPause(0)
{
	buffer.type = INPUT_KEYBOARD;
	buffer.ki.wScan = 0;
	buffer.ki.time = 0;
	buffer.ki.dwExtraInfo = 0;
}

_MORSE_BLINK::_MORSE_BLINK(const std::string & name_morse) :
	_MORSE_BASE(name_morse),
	buffer(),
	m__Pause(180),
	m__DotTime(180),
	m__DashTime(540),
	m__CharPause(250)
{
	buffer.type = INPUT_KEYBOARD;
	buffer.ki.wScan = 0;
	buffer.ki.time = 0;
	buffer.ki.dwExtraInfo = 0;
}

_MORSE_BLINK::_MORSE_BLINK(const _MORSE_BLINK & Object)
{
	this->m_name_morse = Object.m_name_morse;
	this->buffer = Object.buffer;
	this->m__Pause = Object.m__Pause;
	this->m__DotTime = Object.m__DotTime;
	this->m__DashTime = Object.m__DashTime;
	this->m__CharPause = Object.m__CharPause;
}

void _MORSE_BLINK::Morse_Feature(const std::string & from_Converter_fun)
{
	for (std::string::const_iterator it_from_Convert_fun = from_Converter_fun.begin(); it_from_Convert_fun != from_Converter_fun.end(); ++it_from_Convert_fun)
	{
		if (*it_from_Convert_fun == '.')
		{
			Key_Up(0x14);
			Sleep(this->get__DotTime());
			Key_Down(0x14);
		}
		else if (*it_from_Convert_fun == '-')
		{
			Key_Up(0x14);
			Sleep(this->get__DashTime());
			Key_Down(0x14);
		}
		else if (*it_from_Convert_fun == ' ')
		{
			Key_Up(0x14);
			Sleep(this->get__CharPause());
			Key_Down(0x14);
		}
	}
}

void _MORSE_BLINK::Key_Up(const char key) noexcept
{
	buffer.ki.wVk = key;
	buffer.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, static_cast<LPINPUT>(&buffer), sizeof(INPUT));
}

void _MORSE_BLINK::Key_Down(const char key) noexcept
{
	buffer.ki.wVk = key;
	buffer.ki.dwFlags = 0;
	SendInput(1, static_cast<LPINPUT>(&buffer), sizeof(INPUT));
}

void _MORSE_BLINK::ExternalInfo(const std::string & chain)
{
	Parser pars(chain);
	this->m__Pause = atoi(pars.Parse_String().c_str());
	this->m__DotTime = atoi(pars.Parse_String().c_str());
	this->m__DashTime = atoi(pars.Parse_String().c_str());
	this->m__CharPause = atoi(pars.Parse_String().c_str());
}

void _MORSE_BLINK::setPause(int __Pause)
{
	this->m__Pause = __Pause;
}

void _MORSE_BLINK::setDotTime(int __DotTime)
{
	this->m__DotTime = __DotTime;
}

void _MORSE_BLINK::setDashTime(int __DashTime)
{
	this->m__DashTime = __DashTime;
}

void _MORSE_BLINK::setCharPause(int __CharPause)
{
	this->m__CharPause = __CharPause;
}

const std::string & _MORSE_BLINK::get_name_morse(void) const
{
	return _MORSE_BASE::get_name_morse();
}

const INPUT & _MORSE_BLINK::get_input(void) const
{
	return buffer;
}

const int _MORSE_BLINK::get__Pause(void) const
{
	return m__Pause;
}

const int _MORSE_BLINK::get__DotTime(void) const
{
	return m__DotTime;
}

const int _MORSE_BLINK::get__DashTime(void) const
{
	return m__DashTime;
}

const int _MORSE_BLINK::get__CharPause(void) const
{
	return m__CharPause;
}

_MORSE_BLINK & _MORSE_BLINK::operator=(const _MORSE_BLINK & Object)
{
	if (this != &Object)
	{
		this->m_name_morse = Object.m_name_morse;
		this->buffer = Object.buffer;
		this->m__Pause = Object.m__Pause;
		this->m__DotTime = Object.m__DotTime;
		this->m__DashTime = Object.m__DashTime;
		this->m__CharPause = Object.m__CharPause;
	}
	return *this;
}

_MORSE_BLINK::~_MORSE_BLINK()
{
	m_name_morse = "";
	m__Pause = NULL;
	m__DotTime = NULL;
	m__DashTime = NULL;
	m__CharPause = NULL;
}
