#include "_FACTORY.h"

using namespace std;

_FACTORY::_FACTORY():
	Factory_name("FABRIC"),
	external_info(""),
	Morse_ptr(nullptr)
{
	
}

_FACTORY::_FACTORY(const std::string & Fabric_name):
	Factory_name(Fabric_name),
	external_info(""),
	Morse_ptr(nullptr)
{

}

_FACTORY::_FACTORY(const _FACTORY & Object)
{
	this->Factory_name = Object.Factory_name;
	this->external_info = Object.external_info;
	this->Morse_ptr = &Beep;
}


void _FACTORY::setExterlnalInfo(const char chain[])
{
	this->external_info = chain;
}

void _FACTORY::setOutput(enum _FACTORY::WAJCHA ENUM_TYPE)
{
	if (ENUM_TYPE == BEEP)
	{
		Morse_ptr = &Beep;
		Morse_ptr->ExternalInfo(external_info);
	}
	else if (ENUM_TYPE == BLINK)
	{
		Morse_ptr = &Blink;
		Morse_ptr->ExternalInfo(external_info);
	}
	else if (ENUM_TYPE == CONSOLE)
	{
		Morse_ptr = &Console;
		Morse_ptr->ExternalInfo(external_info);
	}
	else if (ENUM_TYPE == DISK)
	{
		Morse_ptr = &Disk;
		Morse_ptr->ExternalInfo(external_info);
	}
}

const std::string & __fastcall _FACTORY::get_FACTORY_name(void) const
{
	return Factory_name;
}

_FACTORY & _FACTORY::operator=(const _FACTORY & Object)
{
	if (this != &Object)
	{
		this->Factory_name = Object.Factory_name;
		this->external_info = Object.external_info;
		this->Morse_ptr = &Beep;
	}
	return *this;
}

_FACTORY::~_FACTORY()
{
	Factory_name = "";
	external_info = "";
	Morse_ptr = nullptr;
}