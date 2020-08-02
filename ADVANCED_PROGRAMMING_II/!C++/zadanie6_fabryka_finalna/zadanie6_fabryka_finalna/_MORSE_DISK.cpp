#include "_MORSE_DISK.h"

using namespace std;

_MORSE_DISK::_MORSE_DISK() :
	_MORSE_BASE(),
	m_save_file_path("morse_disk.txt")
{
	//m_file_out.open(m_save_file_path, std::ios_base::out);
	//m_file_out.close();
}

_MORSE_DISK::_MORSE_DISK(const std::string & name_morse) :
	_MORSE_BASE(name_morse),
	m_save_file_path("morse_disk.txt")
{
	/*m_file_out.open(m_save_file_path, std::ios_base::out);
	m_file_out.close();*/
}

_MORSE_DISK::_MORSE_DISK(const _MORSE_DISK & Object)
{
	this->m_name_morse = Object.m_name_morse;
	this->m_save_file_path = Object.m_save_file_path;
}

void _MORSE_DISK::ExternalInfo(const std::string & chain)
{
	Parser pars(chain);
	m_save_file_path = pars.Parse_String();
	m_file_out.open(m_save_file_path, std::ios_base::out);
	m_file_out.close();
}

void _MORSE_DISK::Morse_Feature(const std::string & from_Converter_fun)
{
	m_file_out.open(m_save_file_path, std::ios_base::app);
	for (std::string::const_iterator it_from_Convert_fun = from_Converter_fun.begin(); it_from_Convert_fun != from_Converter_fun.end(); ++it_from_Convert_fun)
	{
		if (*it_from_Convert_fun == '.')
		{
			m_file_out << '.';
		}
		else if (*it_from_Convert_fun == '-')
		{
			m_file_out << '-';
		}
		else if (*it_from_Convert_fun == ' ')
		{
			m_file_out << ' ';
		}
	}
	m_file_out << '|';
	m_file_out.close();
}

const std::string & _MORSE_DISK::get_name_morse(void) const
{
	return _MORSE_BASE::get_name_morse();
}

const std::string & _MORSE_DISK::get_save_file_path(void) const
{
	return m_save_file_path;
}

_MORSE_DISK & _MORSE_DISK::operator=(const _MORSE_DISK & Object)
{
	if (this != &Object)
	{
		this->m_name_morse = Object.m_name_morse;
		this->m_save_file_path = Object.m_save_file_path;
	}
	return *this;
}

_MORSE_DISK::~_MORSE_DISK()
{
	m_name_morse = "";
	m_save_file_path = "";
}
