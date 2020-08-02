// _MORSE_BLINK_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 04/01/2019 ***
 *							Klasa ma za zadanie:

 *	1.	Klasa pochodna po klasie Morse Base
 *	2.	Produktem klasy jest swiecaca lampka led klawisza CapsLocka
 */
#ifndef _MORSE_BLINK_H_
#define _MORSE_BLINK_H_
/*
	OUTSIDE FILES .h / .hpp
*/
#include "_MORSE_BASE.h"
//////////////////////////////////////

class _MORSE_BLINK final :
	public _MORSE_BASE
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	INPUT buffer;					//struktura ktora sluzy do uruchomienia lampki klawisza CapsLock
	int m__Pause;					//Pause
	int m__DotTime;					//DotTime
	int m__DashTime;				//DashTime
	int m__CharPause;				//CharPause
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
	_MORSE_BLINK();															//konstruktor bezparametrowy	
	explicit _MORSE_BLINK(const std::string & name_morse);					//konstruktor z jednym parametrem
	explicit _MORSE_BLINK(const _MORSE_BLINK & Object);						//konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	virtual void ExternalInfo(const std::string & chain) override;							//Funkcja otrzymujaca "ExterlanInfo" z fabryki i ustawiajaca nasze zmienne
	virtual void Morse_Feature(const std::string & from_Converter_fun) override;			//Funkcja ktora tworzy nasz chciany produkt(tutaj migajaca lampka CapsLocka)
	void Key_Up(const char key) noexcept;													//funkcja uruchamiajaca lampke Capslocka
	void Key_Down(const char key) noexcept;													//funkcja gaszaca lampke Capslocka
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	virtual void setPause(int __Pause);										 //setter pauzy miedzy . lub -
	virtual void setDotTime(int __DotTime);									 //setter dlugosci .
	virtual void setDashTime(int __DashTime);								 //setter dlugosci -
	virtual void setCharPause(int __CharPause);								 //setter pauzy miedzy znakami np. S (charpause) O (charpause) S
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	virtual const std::string & get_name_morse(void) const;				//getter nazwy morsa
	const int get__Pause(void) const;									//getter zwracajacy pauze
	const int get__DotTime(void) const;									//getter zwracajacy dlugosc .
	const int get__DashTime(void) const;									//getter zwracajacy dlugosc -
	const int get__CharPause(void) const;								//getter zwracajacy dlugosc pauzy miedzy znakam
	const INPUT & get_input(void) const;									//getter naszego buffera
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_MORSE_BLINK & operator=(const _MORSE_BLINK & Object);						//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MORSE_BLINK();						//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _MORSE_BLINK_H_ */