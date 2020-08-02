#include "_MORSE_CONSOLE.h"

using namespace std;

//typedef int(*name) (float a, int a);

_MORSE_CONSOLE::_MORSE_CONSOLE() :
	_MORSE_BASE()
{

}

_MORSE_CONSOLE::_MORSE_CONSOLE(const std::string & name_morse) :
	_MORSE_BASE(name_morse)
{

}

_MORSE_CONSOLE::_MORSE_CONSOLE(const _MORSE_CONSOLE & Object)
{
	this->m_name_morse = Object.m_name_morse;
}

void _MORSE_CONSOLE::ExternalInfo(const std::string & chain)
{
	/*
		NOTHING HERE
	*/
}

void _MORSE_CONSOLE::Morse_Feature(const std::string & from_Converter_fun)
{
	cerr << '|';
	for (std::string::const_iterator it_from_Convert_fun = from_Converter_fun.begin(); it_from_Convert_fun != from_Converter_fun.end(); ++it_from_Convert_fun)
	{
		if (*it_from_Convert_fun == '.')
		{
			cerr << '.';
		}
		else if (*it_from_Convert_fun == '-')
		{
			cerr << '-';
		}
		else if (*it_from_Convert_fun == ' ')
		{
			cerr << ' ';
		}
	}
	cerr << '|';
}

const std::string & _MORSE_CONSOLE::get_name_morse(void) const
{
	return _MORSE_BASE::get_name_morse();
}


_MORSE_CONSOLE & _MORSE_CONSOLE::operator=(const _MORSE_CONSOLE & Object)
{
	if (this != &Object)
	{
		this->m_name_morse = Object.m_name_morse;
	}
	return *this;
}

_MORSE_CONSOLE::~_MORSE_CONSOLE()
{
	m_name_morse = "";
}
