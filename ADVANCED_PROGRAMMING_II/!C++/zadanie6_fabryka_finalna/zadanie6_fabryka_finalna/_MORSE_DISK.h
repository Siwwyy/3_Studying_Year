// _MORSE_DISK_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 04/01/2019 ***
 *							Klasa ma za zadanie:

 *	1.	Klasa pochodna po klasie Morse Base
 *	2.	Produktem klasy jest przekonwertowane slowo 
		zapisane w pliku tekstowym itp.
 */
#ifndef _MORSE_DISK_H_
#define _MORSE_DISK_H_
/*
	OUTSIDE FILES .h / .hpp
*/
#include "_MORSE_BASE.h"
//////////////////////////////////////
#include <fstream>

class _MORSE_DISK final :
	public _MORSE_BASE
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	std::string m_save_file_path;					//zmienna przechowujaca sciezke pliku
	std::fstream m_file_out;						//obiekt klasy do odczytu/zapisu pliku
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
	/*
		ZMIENNE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_MORSE_DISK();															//konstruktor bezparametrowy
	explicit _MORSE_DISK(const std::string & name_morse);					//konstruktor z jednym parametrem
	explicit _MORSE_DISK(const _MORSE_DISK & Object);						//konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	virtual void ExternalInfo(const std::string & chain) override;							//Funkcja otrzymujaca "ExterlanInfo" z fabryki i ustawiajaca nasze zmienne
	virtual void Morse_Feature(const std::string & from_Converter_fun) override;			//Funkcja ktora tworzy nasz chciany produkt(tutaj zapis do pliku)
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	virtual const std::string & get_name_morse(void) const;				//getter nazwy morsa
	const std::string & get_save_file_path(void) const;					//getter nazwy sciezki pliku
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE	
	_MORSE_DISK & operator=(const _MORSE_DISK & Object);						//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MORSE_DISK();						//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _MORSE_DISK_H_ */