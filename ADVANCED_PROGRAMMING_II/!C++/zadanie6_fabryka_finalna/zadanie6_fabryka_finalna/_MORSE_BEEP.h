// _MORSE_BEEP_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						   *** Koniec: 04/01/2019 ***
 *							Klasa ma za zadanie:

 *	1.	Klasa pochodna po klasie Morse Base
 *	2.	Produktem klasy jest mors dzwiekowy
 */
#ifndef _MORSE_BEEP_H_
#define _MORSE_BEEP_H_
/*
	OUTSIDE FILES .h / .hpp
*/
#include "_MORSE_BASE.h"
//////////////////////////////////////

class _MORSE_BEEP final :
	public _MORSE_BASE
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	int m__Freq;					//Frequency
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
	_MORSE_BEEP();																//konstruktor bezparametrowy
	explicit _MORSE_BEEP(const std::string & name_morse);						//konstruktor z jednym parametrem
	explicit _MORSE_BEEP(const _MORSE_BEEP & Object);							//konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	virtual void ExternalInfo(const std::string & chain) override;							//Funkcja otrzymujaca "ExterlanInfo" z fabryki i ustawiajaca nasze zmienne
	virtual void Morse_Feature(const std::string & from_Converter_fun) override;			//Funkcja ktora tworzy nasz chciany produkt(tutaj sygnaly dzwiekowe)
	void Beep_fun(const int time) const noexcept;											//funkcja "Beepania"
	void Pause_fun(const int time) const noexcept;											//funkcja pauzy
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void setFrequency(int __Freq);					 //setter czestotliwosci
	void setPause(int __Pause);					     //setter pauzy miedzy . lub -
	void setDotTime(int __DotTime);					 //setter dlugosci .
	void setDashTime(int __DashTime);				 //setter dlugosci -
	void setCharPause(int __CharPause);				 //setter pauzy miedzy znakami np. S (charpause) O (charpause) S
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	virtual const std::string & get_name_morse(void) const;				//getter nazwy morsa
	const int get__Freq(void) const;										//getter zwracajacy czestotliwosc
	const int get__Pause(void) const;									//getter zwracajacy pauze
	const int get__DotTime(void) const;									//getter zwracajacy dlugosc .
	const int get__DashTime(void) const;									//getter zwracajacy dlugosc -
	const int get__CharPause(void) const;								//getter zwracajacy dlugosc pauzy miedzy znakami
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_MORSE_BEEP & operator=(const _MORSE_BEEP & Object);						//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MORSE_BEEP();							//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _MORSE_BEEP_H_ */