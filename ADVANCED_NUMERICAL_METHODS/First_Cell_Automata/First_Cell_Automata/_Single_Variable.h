// __Single_Variable_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						    *** Koniec: 13/12/2018 ***
 *							Klasa ma za zadanie:
 *	1. Utworzyc obiekt ktory bedzie posiadal jego ilosc wystapien w danych podanych przez uzytkownika
 *  2. Klasa szablonowa
*/
#ifndef _SINGLE_VARIABLE_H_
#define _SINGLE_VARIABLE_H_
#include <iostream>
#include <string>
#include <set>
#include <iterator> 
#include <map> 

template<typename Type>
class _Single_Variable
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	Type variable;			//szablon zmiennej
	int occurrence;			//zmienna przechowujaca wystapienia
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
	_Single_Variable();													//konstruktor bezparametrowy
	_Single_Variable(const Type & Type_variable, int occurence);		//konstruktor dwuparametrowy
	explicit _Single_Variable(const Type & Type_variable);				//jawny konstruktor jednoparametrowy
	explicit _Single_Variable(const _Single_Variable & object);			//jawny konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	__forceinline void Show_Variable(void) const;					//funkcja wyswietlajaca nasz obiekt
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	__forceinline void Set_Type(const Type & Type_variable);			//setter Type
	__forceinline void Set_Occurrence(const int & occurrence);			//setter wystepowania
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	__forceinline const Type & Get_Type(void) const;					//getter typu
	__forceinline const int & Get_Occurrence(void) const;				//getter wystepowania
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	constexpr _Single_Variable & operator=(const _Single_Variable & object);				//staly operator przypisani
	constexpr bool operator<(const _Single_Variable & object) const;						//staly operator bool do sprawdzenia ktora zmienna/obiekt jest mniejsza/wieksza (potrzebne przy wczytywaniu do naszej mapy
	constexpr bool operator>(const _Single_Variable & object) const;						//staly operator bool (to samo co operator wyzej)
	constexpr bool operator==(const _Single_Variable & object) const;						//staly operator przyrowania
	//DWUARGUMENTOWE
	friend std::ostream& operator<<(std::ostream& lhs, const _Single_Variable& rhs);		//zaprzyjazniony operator wyswietalnia (out)
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Single_Variable();		//wirtualny destruktor
	//////////////////////////////////////////////////////////////////////////////
};

//////////////////////////////////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////////////////////////////////



#endif /* _SINGLE_VARIABLE_H_ */

template<typename Type>
inline std::ostream & operator<<(std::ostream & lhs, const _Single_Variable<Type> & rhs)
{
	lhs << rhs.variable << rhs.occurrence;
	return lhs;
}

template<typename Type>
inline std::istream & operator<<(std::istream & lhs, const _Single_Variable<Type> & rhs)
{
	lhs << rhs.variable << rhs.occurrence;
	return lhs;
}

template<typename Type>
inline _Single_Variable<Type>::_Single_Variable():
	occurrence(0)
{

}

template<typename Type>
inline _Single_Variable<Type>::_Single_Variable(const Type & Type_variable, int occurence):
	variable(Type_variable),
	occurrence(occurence)
{

}

template<typename Type>
inline _Single_Variable<Type>::_Single_Variable(const Type & Type_variable):
	variable(Type_variable),
	occurrence(0)
{

}

template<typename Type>
inline _Single_Variable<Type>::_Single_Variable(const _Single_Variable & object)
{
	this->variable = object.variable;
	this->occurrence = object.occurrence;
}

template<typename Type>
inline void _Single_Variable<Type>::Show_Variable() const
{
	std::cout << "Value: " << variable << " Wystepowanie: " << occurrence << std::endl;
}

template<typename Type>
__forceinline void _Single_Variable<Type>::Set_Type(const Type & Type_variable)
{
	this->variable = Type_variable;
}

template<typename Type>
__forceinline void _Single_Variable<Type>::Set_Occurrence(const int & occurrence)
{
	this->occurrence = occurrence;
}

template<typename Type>
__forceinline const Type & _Single_Variable<Type>::Get_Type() const
{
	return variable;
}

template<typename Type>
inline const int & _Single_Variable<Type>::Get_Occurrence() const
{
	return occurrence;
}

template<typename Type>
inline constexpr _Single_Variable<Type> & _Single_Variable<Type>::operator=(const _Single_Variable & object)
{
	if (this != &object)
	{
		this->variable = object.variable;
		this->occurrence = object.occurrence;
	}
	return *this;
}

template<typename Type>
inline constexpr bool _Single_Variable<Type>::operator<(const _Single_Variable & object) const
{
	return this->variable < object.variable;
}

template<typename Type>
inline constexpr bool _Single_Variable<Type>::operator>(const _Single_Variable & object) const
{
	return this->variable > object.variable;
}

template<typename Type>
inline constexpr bool _Single_Variable<Type>::operator==(const _Single_Variable & object) const
{
	return this->variable == object.variable;
}

template<typename Type>
inline _Single_Variable<Type>::~_Single_Variable()
{
	occurrence = 0;
}
