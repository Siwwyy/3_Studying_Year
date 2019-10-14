// _FREQCOUNTER_H_ standard header
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *							*** WERSJA FINALNA ***
 *						    *** Koniec: 13/12/2018 ***
 *							Klasa ma za zadanie:
 *	1. Stworzyc obiekt w ktorym podamy jaki typ zmiennych przyjmiemy do wczytywania
 *  2. Dodac do naszej mapy dane oraz wyliczyc ich ilosc wystepowan
 *  3. Klasa szablonowa
*/
#ifndef _FREQCOUNTER_H_
#define _FREQCOUNTER_H_
/*
	OUTSIDE FILES
*/
#include "_Single_Variable.h"
////////////////////////////
#include <iostream>
#include <string>
#include <set>
#include <iterator> 
#include <fstream> 
#include <chrono>

template<typename Type> 
class FreqCounter
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	Type variable;													//zmienna przechowujaca nasze dane (typnename Type) przyjmie taki typ zmiennej jaki zadeklarujemy przy tworzeniu obiektu typu FreqCounter
	_Single_Variable<Type> _Single_Variable_Object;					//obiekt przechowujacy nasze dane ktore potem dodajemy do mapy
	//std::set<_Single_Variable<Type>> _array_set;					//kontener typu set przechowuajcy tylko unikalne wystapienia
	std::vector<_Single_Variable<Type>> _array_vector;			//kontener typu multiset do przechowywania wszystkie co dostanie klasa
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
	FreqCounter();												//konstruktor bezparametrowy
	FreqCounter(const Type & Type_variable);					//konstruktor z jednym parametrem
	explicit FreqCounter(const FreqCounter & object);			//jawny konstruktor kopiujacy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	__forceinline void Push_Data(const Type & Type_variable);		//funkcja do dodawania elementow do std::multiset
	__forceinline void Push_Data(const Type & Type_variable, const __int32 magnetization);		//funkcja do dodawania elementow do std::multiset
	__forceinline void Unique_Results(void);						//funkcja do liczenia ilosci wystapien
	__forceinline void Pop_Data(void) const;						//funkcja do wyswietlenia wczytanej danej
	__forceinline void Save_Results_To_File(void) const;			//funkcja do zapisu wynikow
	__forceinline void Create_Chart(void);							//funkcja do tworzenia wykresu
	//__forceinline void Excel_Chart(void);							//funkcja do tworzenia wykresu w excelu
	__forceinline int Decrease_Width(const int width);				//funkcja do zmniejszania szerokosci (po to by wykres nie mial np. 750k pixeli szerokosci)
	__forceinline int Increase_Width(const int width);				//funkcja do zwiekszania szerokosci (po to by wykres nie mial np. 100 pixeli szerokosci)
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	__forceinline const Type & Get_Type(void) const;						//getter typu
	__forceinline const int & Get_The_Biggest_Occurence(void);				//getter najwiekszego wystepowania
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	constexpr FreqCounter & operator=(const FreqCounter & object);			//operator przypisania
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	~FreqCounter();		//niewirtualny destruktor						//destruktor niewirtualny
	//////////////////////////////////////////////////////////////////////////////
};

//////////////////////////////////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////////////////////////////////

template<typename Type>
inline FreqCounter<Type>::FreqCounter()
{

}

template<typename Type>
inline FreqCounter<Type>::FreqCounter(const Type & Type_variable):
	variable(Type_variable)
{

}

template<typename Type>
inline FreqCounter<Type>::FreqCounter(const FreqCounter & object)
{
	this->variable = object.variable;
}

template<typename Type>
__forceinline void FreqCounter<Type>::Push_Data(const Type & Type_variable)
{
	this->variable = Type_variable;
	_Single_Variable_Object.Set_Type(variable);
	_Single_Variable_Object.Set_Occurrence(1);
	_array_vector.emplace_back(_Single_Variable_Object);
}

template<typename Type>
__forceinline void FreqCounter<Type>::Push_Data(const Type& Type_variable, const __int32 magnetization)
{
	this->variable = Type_variable;
	_Single_Variable_Object.Set_Type(variable);
	_Single_Variable_Object.Set_Occurrence(magnetization);
	_array_vector.emplace_back(_Single_Variable_Object);

}

template<typename Type>
__forceinline void FreqCounter<Type>::Unique_Results()
{
	//try
	//{
	//	auto start = std::chrono::system_clock::now();
	//	int occurence = 0;
	//	std::set<_Single_Variable<Type>> _array_set_second(_array_multiset.begin(), _array_multiset.end());
	//	for (typename std::set<_Single_Variable<Type>>::const_iterator iter_set = _array_set_second.begin(); iter_set != _array_set_second.end(); ++iter_set) //SPROBUJ set.size() i multiset.size()
	//	{
	//		for (typename std::multiset<_Single_Variable<Type>>::const_iterator iter_multiset = _array_multiset.begin(); iter_multiset != _array_multiset.end(); iter_multiset++)
	//		{
	//			if (iter_set->Get_Type() == iter_multiset->Get_Type())
	//			{
	//				for (typename std::multiset<_Single_Variable<Type>>::const_iterator iter_multiset_second = iter_multiset; iter_multiset_second != _array_multiset.end(); iter_multiset_second++)
	//				{
	//					if (iter_set->Get_Type() == iter_multiset_second->Get_Type())
	//					{
	//						occurence++;
	//					}
	//					else
	//					{
	//						break;
	//					}
	//				}
	//				break;
	//			}
	//		}
	//		_Single_Variable<Type> _Single_Variable_Object_cos(iter_set->Get_Type(), occurence);
	//		_array_set.insert(_Single_Variable_Object_cos);
	//		occurence = 0;
	//	}
	//	auto stop = std::chrono::system_clock::now();
	//	std::chrono::duration<double, std::milli> time = stop - start;
	//	std::cout << time.count() << " ms for counting a unique occurrences" << '\n';
	//}
	//catch (const std::string & Message)
	//{
	//	throw Message;
	//}
}

template<typename Type>
__forceinline void FreqCounter<Type>::Pop_Data() const
{
	_Single_Variable_Object.Show_Variable();
}

template<typename Type>
__forceinline void FreqCounter<Type>::Save_Results_To_File() const
{
	//try
	//{
	//	std::fstream file;
	//	file.open("RESULTS.csv", std::ios_base::out);
	//	if (file.good() == false)
	//	{
	//		exit(0);
	//	}
	//	else
	//	{
	//		file << " Wartosc  " << " " << " Ilosc wystapien" << '\n';
	//		for (auto iter = _array_set.begin(); iter != _array_set.end(); ++iter)
	//		{
	//			file << " " << iter->Get_Type() << " ";
	//			file << "         ";
	//			file << "" << iter->Get_Occurrence() << " ";
	//			file << '\n';
	//		}
	//	}
	//	file.close();
	//	std::cout << "Results have been saved to file" << '\n';
	//}
	//catch (const std::string & Message)
	//{
	//	throw Message;
	//}
}

template<typename Type>
__forceinline void FreqCounter<Type>::Create_Chart()
{
	try
	{
		std::fstream file;
		file.open("CHART_OF_RESULTS3.ppm", std::ios_base::out);
		if (file.good() == false)
		{
			exit(0);
		}
		else
		{
			int occurrence = 0;
			int width = Get_The_Biggest_Occurence();
			int height = _array_vector.size() * 2;
			int i = 0;
			int decreaser = 1;		//always must be equal to 1 !! otherwise will be a dividing by 0 !!
			int increaser = 1;		//always must be equal to 1 !! otherwise will be multiplicating by 0 !!
			bool which = true;		//true means the program will decrease width if will be too huge;
			if (height > 20000)
			{
				std::cout << "Unfortunately, we got too many parameters. Chart does not exist" << '\n';
			}
			else
			{
				if (width > 4000)
				{
					decreaser = Decrease_Width(width);
					width /= decreaser;
				}
				else if (width < 400)
				{
					increaser = Increase_Width(width);
					width *= increaser;
					which = false;		//time to decreasing
				}
				file << "P3";
				file << '\n';
				file << "# Created by Damian Andrysiak";
				file << '\n';
				file << width;
				file << ' ';
				file << height;
				file << '\n';
				file << 255;
				file << '\n';
				int R = 255, G = 0, B = 0;   //for own colors
				for (auto iter = _array_vector.begin(); iter != _array_vector.end(); ++iter)
				{
					if (which == false)
					{
						occurrence = (iter->Get_Occurrence() * increaser);
					}
					else
					{
						occurrence = (iter->Get_Occurrence() / decreaser);
					}
					while (occurrence > 0)
					{
						file << R;
						file << ' ';
						file << G;
						file << ' ';
						file << B;
						file << ' ';
						occurrence--;
						i++;
					}
					for (int j = 0; j < 2; j++)
					{
						while (i < width)
						{
							file << 255;
							file << ' ';
							file << 255;
							file << ' ';
							file << 255;
							file << ' ';
							i++;
						}
						occurrence = 0;
						i = 0;
						file << '\n';
					}
					file << '\n';
					occurrence = 0;
					i = 0;
				}
				std::cout << "Chart has been created" << '\n';
			}
		}
		file.close();
	}
	catch (const std::string & Message)
	{
		throw Message;
	}
}

//template<typename Type>
//__forceinline void FreqCounter<Type>::Excel_Chart(void)
//{
//
//}

template<typename Type>
__forceinline int FreqCounter<Type>::Decrease_Width(const int width)
{
	int temporary_width = width;
	int decreaser = 1;
	while (temporary_width > 4000)
	{
		temporary_width /= 10;
		decreaser *= 5;
	}
	return decreaser;
}

template<typename Type>
__forceinline int FreqCounter<Type>::Increase_Width(const int width)
{
	int temporary_width = width;
	int decreaser = 1;
	while (temporary_width < 4000)
	{
		temporary_width *= 10;
		decreaser *= 5;
	}
	return decreaser;
}

template<typename Type>
__forceinline const Type & FreqCounter<Type>::Get_Type() const
{
	return variable;
}

template<typename Type>
inline const int & FreqCounter<Type>::Get_The_Biggest_Occurence(void)
{
	int the_biggest_occurence = 0;
	for (typename std::vector<_Single_Variable<Type>>::iterator iter_set = _array_vector.begin(); iter_set != _array_vector.end(); ++iter_set)
	{
		if (iter_set->Get_Occurrence() > the_biggest_occurence)
		{
			the_biggest_occurence = iter_set->Get_Occurrence();
		}
	}
	return the_biggest_occurence;
}

template<typename Type>
inline constexpr FreqCounter<Type> & FreqCounter<Type>::operator=(const FreqCounter & object)
{
	if (this != &object)
	{
		this->variable = object.variable;
	}
	return *this;
}

template<typename Type>
inline FreqCounter<Type>::~FreqCounter()
{
	//_array_multiset.clear();
	//_array_set.clear();
}

#endif /* _FREQCOUNTER_H_ */