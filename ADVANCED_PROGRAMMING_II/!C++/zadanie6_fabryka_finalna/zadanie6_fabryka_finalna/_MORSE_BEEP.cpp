#include "_MORSE_BEEP.h"

using namespace std;

_MORSE_BEEP::_MORSE_BEEP() :
	_MORSE_BASE(),
	m__Freq(0),
	m__Pause(0),
	m__DotTime(0),
	m__DashTime(0),
	m__CharPause(0)
{

}

_MORSE_BEEP::_MORSE_BEEP(const std::string & name_morse):
	_MORSE_BASE(name_morse),
	m__Freq(1000),
	m__Pause(180),
	m__DotTime(180),
	m__DashTime(540),
	m__CharPause(250)
{

}

_MORSE_BEEP::_MORSE_BEEP(const _MORSE_BEEP & Object)
{
	this->m_name_morse = Object.m_name_morse;
	this->m__Freq = Object.m__Freq;
	this->m__Pause = Object.m__Pause;
	this->m__DotTime = Object.m__DotTime;
	this->m__DashTime = Object.m__DashTime;
	this->m__CharPause = Object.m__CharPause;
}

void _MORSE_BEEP::Morse_Feature(const std::string & from_Converter_fun)
{
	for (std::string::const_iterator it_from_Convert_fun = from_Converter_fun.begin(); it_from_Convert_fun != from_Converter_fun.end(); ++it_from_Convert_fun)
	{
		if (*it_from_Convert_fun == '.')
		{
			this->Beep_fun(this->get__DotTime());
			this->Pause_fun(this->get__Pause());
		}
		else if (*it_from_Convert_fun == '-')
		{
			this->Beep_fun(this->get__DashTime());
			this->Pause_fun(this->get__Pause());
		}
		else if (*it_from_Convert_fun == ' ')
		{
			this->Pause_fun(this->get__CharPause());
		}
	}
}

void _MORSE_BEEP::ExternalInfo(const std::string & chain)
{	
	Parser pars(chain);
	this->m__Freq = atoi(pars.Parse_String().c_str());
	this->m__Pause = atoi(pars.Parse_String().c_str());
	this->m__DotTime = atoi(pars.Parse_String().c_str());
	this->m__DashTime = atoi(pars.Parse_String().c_str());
	this->m__CharPause = atoi(pars.Parse_String().c_str());
}

void _MORSE_BEEP::Beep_fun(const int time) const noexcept
{
	Beep(get__Freq(), time);
}

void _MORSE_BEEP::Pause_fun(const int time) const noexcept
{
	Sleep(time);
}

void _MORSE_BEEP::setFrequency(int __Freq)
{
	this->m__Freq = __Freq;
}

void _MORSE_BEEP::setPause(int __Pause)
{
	this->m__Pause = __Pause;
}

void _MORSE_BEEP::setDotTime(int __DotTime)
{
	this->m__DotTime = __DotTime;
}

void _MORSE_BEEP::setDashTime(int __DashTime)
{
	this->m__DashTime = __DashTime;
}

void _MORSE_BEEP::setCharPause(int __CharPause)
{
	this->m__CharPause = __CharPause;
}

const std::string & _MORSE_BEEP::get_name_morse(void) const
{
	return _MORSE_BASE::get_name_morse();
}

const int _MORSE_BEEP::get__Freq(void) const
{
	return m__Freq;
}

const int _MORSE_BEEP::get__Pause(void) const
{
	return m__Pause;
}

const int _MORSE_BEEP::get__DotTime(void) const
{
	return m__DotTime;
}

const int _MORSE_BEEP::get__DashTime(void) const
{
	return m__DashTime;
}

const int _MORSE_BEEP::get__CharPause(void) const
{
	return m__CharPause;
}

_MORSE_BEEP& _MORSE_BEEP::operator=(const _MORSE_BEEP& Object)
{
	if (this != &Object)
	{
		//this->m_name_morse = Object.m_name_morse;
		_MORSE_BASE::operator=(Object);
		this->m__Freq = Object.m__Freq;
		this->m__Pause = Object.m__Pause;
		this->m__DotTime = Object.m__DotTime;
		this->m__DashTime = Object.m__DashTime;
		this->m__CharPause = Object.m__CharPause;
	}
	return *this;
}

_MORSE_BEEP::~_MORSE_BEEP()
{
	m_name_morse = "";
	m__Freq = NULL;
	m__Pause = NULL;
	m__DotTime = NULL;
	m__DashTime = NULL;
	m__CharPause = NULL;
}
