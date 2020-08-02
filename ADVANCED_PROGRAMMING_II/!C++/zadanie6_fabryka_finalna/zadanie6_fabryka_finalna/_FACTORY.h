// _FACTORY_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 04/01/2019 ***
 *							Klasa ma za zadanie:

 *	1. Klasa _FACTORY jest miejscem ktore udostepnia dzialanosc
	   pomiedzy klasami Morse (udostepnia dzialanosci oferujace przez klasy Morsa)

 *	2. Ma za zadanie przelaczac linie produkcyjne wedle zyczenia uzytkownika, 
	   ustawiac parametry ExterlanInfo oraz co dany Morse ma przekonwertowac(produkt finalny)
*/
#ifndef _FACTORY_H_
#define _FACTORY_H_
/*
	OUTSIDE FILES .h / .hpp
*/
#include "_MORSE_BASE.h"
#include "_MORSE_BEEP.h"
#include "_MORSE_BLINK.h"
#include "_MORSE_CONSOLE.h"
#include "_MORSE_DISK.h"
//////////////////////////////////////

class _FACTORY
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PRIVATE
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PRIVATE
	*/
	
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PRIVATE
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PRIVATE
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PRIVATE
	*/
	//JEDNOARGUMENTOWE

	//////////////////////////////////////////////////////////////////////////////
protected:
	/*
		ZMIENNE PROTECTED
	*/
	std::string Factory_name;				//zmienna przechowujaca nazwe Fabryki
	std::string external_info;				//zmienna przechowujaca dane zewnetrzne
	_MORSE_BASE * Morse_ptr;				//wskaznik na nasze morsy
	_MORSE_BEEP	Beep;						//obiekt klasy Morse Beep
	_MORSE_BLINK Blink;						//obiekt klasy Morse Blink
	_MORSE_CONSOLE Console;					//obiekt klasy Morse Console
	_MORSE_DISK	Disk;						//obiekt klasy Morse Disk
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PROTECTED
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC PROTECTED
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PROTECTED
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PROTECTED
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PROTECTED
	*/
	//JEDNOARGUMENTOWE

	//////////////////////////////////////////////////////////////////////////////
public:
	enum WAJCHA					//enumerator sluzacy do przelaczania linii produkcyjnej
	{
		BLINK = 0,
		BEEP = 1,
		CONSOLE = 2,
		DISK = 3
	};
	/*
		ZMIENNE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_FACTORY();															//konstruktor bezparametrowy
	explicit _FACTORY(const std::string & Fabric_name);					//konstruktor z jednym parametrem
	explicit _FACTORY(const _FACTORY & Object);							//konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void setExterlnalInfo(const char chain[]);								//funkcja ustawiajca zewnetrzne informacje
	void setOutput(enum _FACTORY::WAJCHA ENUM_TYPE);						//funkcja przelaczajaca linie produkcyjne
	template<typename Type>
	__forceinline void Convert(const Type & Type_variable);					//funkcja ktora otrzymuje dane do konwertowania
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	const std::string & __fastcall get_FACTORY_name(void) const;			//getter nazwy fabryki
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_FACTORY & operator=(const _FACTORY & Object);							//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_FACTORY();							//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

template<typename Type>
__forceinline void _FACTORY::Convert(const Type & Type_variable)
{
	auto itos = [](const Type & Type_variable) { std::stringstream s; s << Type_variable; return s.str(); };
	std::string chain = itos(Type_variable);
	Morse_ptr->Converter(chain);
}

#endif /* _FACTORY_H_ */