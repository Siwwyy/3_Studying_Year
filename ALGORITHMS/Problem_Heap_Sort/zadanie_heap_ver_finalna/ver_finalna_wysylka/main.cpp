/*											
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

class _Heap_Element
{
private:
	/*
		VARIABLES PUBLIC
	*/
	long int value;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Heap_Element(void);
	_Heap_Element(const long int value);
	_Heap_Element(const _Heap_Element & Object);
	_Heap_Element(const _Heap_Element * Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	long int get_value(void) const;
	long int get_parent(const long int i) const;
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_Heap_Element & operator=(const _Heap_Element & Object);
	_Heap_Element & operator=(const _Heap_Element * Object);
	bool operator<(const _Heap_Element & lhs) const;
	bool operator<(const _Heap_Element * lhs) const;
	bool operator>(const _Heap_Element & lhs) const;
	bool operator>(const _Heap_Element * lhs) const;
	bool operator==(const _Heap_Element & lhs) const;
	bool operator==(const _Heap_Element * lhs) const;
	//DWUARGUMENTOWE
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	///////////////////////////////////////////////
	virtual ~_Heap_Element(void);
};


//CLASS OF HEAP SORT
class _Heap_Sort
{
private:
	/*
		VARIABLES PRIVATE
	*/
	std::vector<_Heap_Element*> Heap_Array;
	std::vector<_Heap_Element*> Heap_Sorted;
	long int size;
	long int counter;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Heap_Sort(void);
	_Heap_Sort(const long int value);
	_Heap_Sort(const _Heap_Sort & Object);
	_Heap_Sort(const _Heap_Sort * Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void __fastcall push(const _Heap_Element * _Ty_ptr);
	void heap_sorting();
	void Start_Sorting();
	void End_Sorting();
	void show_sorted_heap() const;
	void show_array(void) const;
	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	long int get_size() const;
	long int get_counter() const;
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	_Heap_Sort & operator=(const _Heap_Sort & Object);
	_Heap_Sort & operator=(const _Heap_Sort * Object);
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Heap_Sort(void);
	///////////////////////////////////////////////
};

//FUNCTION FOR CREATE A LEVELS OF TEST FILES
void inserter();
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	inserter();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void inserter()
{
	long int N = 0;
	long int number_amount = 0;
	long int data_reader = 0;
	std::cin >> N;
	while (N > 0)
	{
		std::cin >> number_amount;
		_Heap_Sort * Heap = new _Heap_Sort(number_amount);
		while (number_amount > 0)
		{
			std::cin >> data_reader;
			Heap->push(new _Heap_Element(data_reader));
			data_reader = 0;
			number_amount--;
		}
		Heap->Start_Sorting();
		Heap->show_array();
		Heap->End_Sorting();
		Heap->show_sorted_heap();
		std::cout << '\n';
		delete Heap;
		N--;
		number_amount = 0;
	}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	HEAP ELEMENT CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////

_Heap_Element::_Heap_Element(void):
	value(0)
{

}

_Heap_Element::_Heap_Element(const long int value):
	value(value)
{

}

_Heap_Element::_Heap_Element(const _Heap_Element & Object):
	value(Object.value)
{

}

_Heap_Element::_Heap_Element(const _Heap_Element * Object) :
	value(Object->value)
{
}

long int _Heap_Element::get_value(void) const
{
	return value;
}

long int _Heap_Element::get_parent(const long int i) const
{
	return ((i-1) >> 1);
}

_Heap_Element & _Heap_Element::operator=(const _Heap_Element & Object)
{
	if (this != &Object)
	{
		this->value = Object.value;
	}
	return *this;
}

_Heap_Element & _Heap_Element::operator=(const _Heap_Element * Object)
{
	if (this != Object)
	{
		this->value = Object->value;
	}
	return *this;
}

bool _Heap_Element::operator<(const _Heap_Element & lhs) const
{
	if (value < lhs.value)
	{
		return true;
	}
	return false;
}

bool _Heap_Element::operator<(const _Heap_Element * lhs) const
{
	if (value < lhs->value)
	{
		return true;
	}
	return false;
}

bool _Heap_Element::operator>(const _Heap_Element & lhs) const
{
	if (value > lhs.value)
	{
		return true;
	}
	return false;
}

bool _Heap_Element::operator>(const _Heap_Element * lhs) const
{
	if (value > lhs->value)
	{
		return true;
	}
	return false;
}

bool _Heap_Element::operator==(const _Heap_Element & lhs) const
{
	if (value == lhs.value)
	{
		return true;
	}
	return false;
}

bool _Heap_Element::operator==(const _Heap_Element * lhs) const
{
	if (value == lhs->value)
	{
		return true;
	}
	return false;
}

_Heap_Element::~_Heap_Element(void)
{
	value = 0;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	HEAP SORT CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////

_Heap_Sort::_Heap_Sort(void):
	size(0),
	counter(0)
{
	Heap_Array.resize(static_cast<unsigned int>(size));
	Heap_Sorted.resize(static_cast<unsigned int>(size));
}

_Heap_Sort::_Heap_Sort(const long int size):
	size(size),
	counter(0)
{
	Heap_Array.resize(static_cast<unsigned int>(size));
	Heap_Sorted.resize(static_cast<unsigned int>(size));
}

_Heap_Sort::_Heap_Sort(const _Heap_Sort & Object):
	size(Object.size),
	counter(Object.counter)
{

}

_Heap_Sort::_Heap_Sort(const _Heap_Sort * Object):
	size(Object->size),
	counter(Object->counter)
{

}

void __fastcall _Heap_Sort::push(const _Heap_Element * _Ty_ptr)
{
	Heap_Array[static_cast<unsigned int>(counter)] = const_cast<_Heap_Element *>(_Ty_ptr);
	counter++;
}

void _Heap_Sort::heap_sorting()
{
	for (typename std::vector<_Heap_Element*>::iterator vec_iterator_first = Heap_Array.begin(); vec_iterator_first != Heap_Array.end(); ++vec_iterator_first)
	{
		if ((*vec_iterator_first) == nullptr)
		{
			continue;
		}
		else
		{
			unsigned int i = static_cast<unsigned int>(std::distance(Heap_Array.begin(), vec_iterator_first));
			while (i != 0)
			{
				if (Heap_Array[i]->get_value() >= Heap_Array[Heap_Array[i]->get_parent(i)]->get_value())
				{
					std::swap(Heap_Array[Heap_Array[i]->get_parent(i)], Heap_Array[i]);
				}
				else
				{
					break;
				}
				i = (((i - 1) >> 1));
			}
		}
	}
}

void _Heap_Sort::Start_Sorting()
{
	for (typename std::vector<_Heap_Element*>::const_iterator vec_iterator_first = Heap_Array.begin(); vec_iterator_first != Heap_Array.end(); ++vec_iterator_first)
	{
		if ((*vec_iterator_first) == nullptr)
		{
			continue;
		}
		else
		{
			heap_sorting();
		}
	}
}

void _Heap_Sort::End_Sorting()
{
	for (typename std::vector<_Heap_Element*>::reverse_iterator vec_iterator_first = Heap_Array.rbegin(); vec_iterator_first != Heap_Array.rend(); ++vec_iterator_first)
	{
		if ((*vec_iterator_first) == nullptr)
		{
			continue;
		}
		else if ((std::distance(vec_iterator_first, Heap_Array.rend()) - 1) > 1)
		{
			std::swap(Heap_Array[0], Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)]);
			Heap_Sorted[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)] = Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)];
			Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)] = nullptr;
			heap_sorting();
			show_array();
		}
		else
		{
			std::swap(Heap_Array[0], Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)]);
			Heap_Sorted[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)] = Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)];
			Heap_Array[(std::distance(vec_iterator_first, Heap_Array.rend()) - 1)] = nullptr;
			heap_sorting();
		}
	}
}

void _Heap_Sort::show_sorted_heap() const	//if > 1 remember !! display only when heap has more than 1 element
{
	for (typename std::vector<_Heap_Element*>::const_iterator vec_iterator_first = Heap_Sorted.begin(); vec_iterator_first != Heap_Sorted.end(); ++vec_iterator_first)
	{
		if ((*vec_iterator_first) == nullptr)
		{
			continue;
		}
		else
		{
			std::cout << (*vec_iterator_first)->get_value() << ' ';
		}
	}
	std::cout << '\n';
}

void _Heap_Sort::show_array(void) const
{
	if (size > 1)
	{
		for (typename std::vector<_Heap_Element*>::const_iterator vec_iterator_first = Heap_Array.begin(); vec_iterator_first != Heap_Array.end(); ++vec_iterator_first)
		{
			if ((*vec_iterator_first) == nullptr)
			{
				continue;
			}
			else
			{
				std::cout << (*vec_iterator_first)->get_value() << ' ';
			}
		}
		std::cout << '\n';
	}
}

long int _Heap_Sort::get_size() const
{
	return size;
}

long int _Heap_Sort::get_counter() const
{
	return counter;
}

_Heap_Sort & _Heap_Sort::operator=(const _Heap_Sort & Object)
{
	if (this != &Object)
	{
		this->size = Object.size;
		this->counter = Object.counter;
		Heap_Array.resize(static_cast<unsigned int>(size));
		Heap_Sorted.resize(static_cast<unsigned int>(size));
	}
	return *this;
}

_Heap_Sort & _Heap_Sort::operator=(const _Heap_Sort * Object)
{
	if (this != Object)
	{
		this->size = Object->size;
		this->counter = Object->counter;
		Heap_Array.resize(static_cast<unsigned int>(size));
		Heap_Sorted.resize(static_cast<unsigned int>(size));
	}
	return *this;
}

_Heap_Sort::~_Heap_Sort()
{
	Heap_Array.erase(Heap_Array.begin(), Heap_Array.end());
	Heap_Sorted.erase(Heap_Sorted.begin(), Heap_Sorted.end());
	size = 0;
	counter = 0;
}