// _MORSE_BASE_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 04/01/2019 ***
 *							Klasa ma za zadanie:

 *	1.	Byc klasa bazowa dla reszty pochodnych morsow
 *	2.	Posiadac wspolne dla wszystkich morsow funkcjonalnosci
 *	3.	Posiada dwie funkcje czysto abstrakcyjne
 */
#ifndef _MORSE_BASE_H_
#define _MORSE_BASE_H_
/*
	OUTSIDE FILES .h / .hpp
*/

//////////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "Parser.h"

class _MORSE_BASE
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	std::string morse_value;				//zmienna przechowujaca wartosc przekonwertowanych liter/liczb na alfabet morsa
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
	std::string m_name_morse;					//nazwa morsa uzywanego aktualnie
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PROTECTED
	*/
	_MORSE_BASE();																//konstruktor bezparametrowy	
	explicit _MORSE_BASE(const std::string & name_morse);						//konstruktor z jednym parametrem
	explicit _MORSE_BASE(const _MORSE_BASE & Object) = delete;					//konstruktor kopiujacy(wylaczony z uzytkowania)
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PROTECTED
	*/
	const std::string & open_dictionary(const char param);						//funkcja ktora otwiera nasze slowniki i zwraca nam nasz wyraz zmieniony na . i -
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
	/*
		ZMIENNE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	virtual void ExternalInfo(const std::string & chain) = 0;							//Abstrakcyjna funkcja otrzymujaca "ExterlanInfo" z fabryki
	virtual void Converter(const std::string & to_Convert);								//Funkcja ktora rozdziela prace miedzy open_dictonary a morse_feature
	virtual void Morse_Feature(const std::string & it_from_Convert_fun) = 0;			//Abstrakcyjna funkcja w ktorej klasy pochodne tworza swoje produkty	
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	virtual const std::string & get_name_morse(void) const;						//getter zwracajacy czestotliwosc
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_MORSE_BASE & operator=(const _MORSE_BASE & Object);							//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MORSE_BASE() {}					//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _MORSE_BASE_H_ */