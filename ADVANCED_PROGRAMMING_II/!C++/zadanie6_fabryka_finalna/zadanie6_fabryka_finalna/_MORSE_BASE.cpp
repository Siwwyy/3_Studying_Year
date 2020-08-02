#include "_MORSE_BASE.h"

using namespace std;

const std::string & _MORSE_BASE::open_dictionary(const char param)
{
	int char_code = 0;
	char loaded = param;
	char_code = static_cast<int>(loaded);						//rzutowanie intem na zmienna loaded
	if ((char_code >= 65 && char_code <= 90) || (char_code >= 97 && char_code <= 122))
	{
		fstream plik_char;
		plik_char.open("char_morse_dictionary.txt", ios::in);
		if (plik_char.good() == false)
		{
			exit(0);
		}
		else
		{
			while (plik_char.eof() == false)
			{
				loaded = ' ';
				plik_char >> loaded;
				if (loaded == param)
				{
					while (loaded != '*')
					{
						plik_char >> loaded;
						if (loaded == '"' || loaded == '*')
						{
							continue;
						}
						else
						{												
							if (loaded == '.')
							{
								morse_value += loaded;
							}
							else if (loaded == '-')
							{
								morse_value += loaded;
							}
						}
						loaded = ' ';
					}
				}
			}
		}
		plik_char.close();
	}
	else if ((char_code >= 48 && char_code <= 57))
	{
		fstream plik_number;
		plik_number.open("number_morse_dictionary.txt", ios::in);

		if (plik_number.good() == false)
		{
			exit(0);
		}
		else
		{
			while (plik_number.eof() == false)
			{
				loaded = ' ';
				plik_number >> loaded;
				if (loaded == param)
				{
					while (loaded != '*')
					{
						plik_number >> loaded;									
						if (loaded == '"' || loaded == '*')
						{
							continue;
						}
						else
						{													
							if (loaded == '.')
							{
								morse_value += loaded;
							}
							else if (loaded == '-')
							{
								morse_value += loaded;
							}
						}
						loaded = ' ';
					}
				}
			}
		}
		plik_number.close();
	}
	else if ((char_code == 32))
	{
		morse_value += loaded;
	}
	return morse_value;
}

_MORSE_BASE::_MORSE_BASE():
	m_name_morse("")
{

}

_MORSE_BASE::_MORSE_BASE(const std::string & name_morse):
	m_name_morse(name_morse)
{

}

void _MORSE_BASE::Converter(const std::string & to_Convert)
{
	std::string from_Converter_fun = "";
	for (std::string::const_iterator it_to_Convert = to_Convert.begin(); it_to_Convert != to_Convert.end(); ++it_to_Convert)
	{
		from_Converter_fun = open_dictionary(*it_to_Convert);
		this->Morse_Feature(from_Converter_fun);
		morse_value = "";
	}
}

const std::string & _MORSE_BASE::get_name_morse(void) const
{
	return m_name_morse;
}

_MORSE_BASE & _MORSE_BASE::operator=(const _MORSE_BASE & Object)
{
	if (this != &Object)
	{
		this->m_name_morse = Object.m_name_morse;
	}
	return *this;
}