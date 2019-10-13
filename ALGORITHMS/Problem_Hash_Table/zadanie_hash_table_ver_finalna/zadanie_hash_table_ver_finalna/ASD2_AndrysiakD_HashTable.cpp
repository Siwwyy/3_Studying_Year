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

//CLASS OF HASH_ELEMENET, for inserting

class _Hash_Element
{
private:
	/*
		PRIVATE VARIABLES
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	unsigned int _Key;
	std::string Value;
	/////////////////////////////////////////////////////////////////////////////////////////////
public:
	/*
		CONSTRUCTORS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Hash_Element() :
		_Key(NULL),
		Value("")
	{
		//to do something
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Hash_Element(const unsigned int _Key, const std::string & Value) :
		_Key(_Key),
		Value(Value)
	{
		//to do something
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	_Hash_Element(const _Hash_Element & Object) :
		_Key(Object._Key),
		Value(Object.Value)
	{
		//to do something
	}

	/*
		SETTERS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	void set_key(const unsigned int _Key)
	{
		if (_Key < 0)
		{
			this->_Key = ((-1) * _Key);
		}
		else
		{
			this->_Key = _Key;
		}
	}
	void set_value(const std::string & Value)
	{
		this->Value = Value;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		GETTERS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	const unsigned int get_index(const unsigned int __array_lenght)
	{
		return (_Key % __array_lenght);
	}	//index to put there the hash element
	const unsigned int get_key() const
	{
		return _Key;
	}	//return the key of hash element
	const std::string & get_value() const
	{
		return Value;
	}	//return the string of hash element
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		OPERATORS
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	constexpr _Hash_Element & operator=(const _Hash_Element & Object) //staly operator przypisani
	{
		if (this != &Object)
		{
			this->_Key = Object._Key;
			this->Value = Object.Value;
		}
		return *this;
	} //operator of assignment
	constexpr bool operator<(const _Hash_Element & Object) const
	{
		if (_Key < Object._Key)
		{
			return true;
		}
		return false;
	} // to compare(if the key is smaller)
	constexpr bool operator>(const _Hash_Element & Object) const
	{
		if (_Key > Object._Key)
		{
			return true;
		}
		return false;
	}	//to compare (if the key is bigger)
	constexpr bool operator==(const _Hash_Element & Object) const
	{
		if (_Key == Object._Key)
		{
			return true;
		}
		return false;
	}	
	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
		DESTRUCTOR
	*/
	virtual ~_Hash_Element()
	{
		_Key = NULL;
		Value = "";
	}
	///////////////////////////////////////////////////////////////////////////
};

//CLASS OF HASHTABLE

class _Hash_Table
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	std::vector<_Hash_Element *> __Array;	
	unsigned int __array_lenght;
	unsigned int __array_counter;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Hash_Table();
	_Hash_Table(const unsigned int __array_lenght);
	_Hash_Table(const _Hash_Table & Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void __fastcall push(const _Hash_Element * ptr);
	void show_elements();
	void hash_table_organizer();
	bool __fastcall if_same_key(const _Hash_Element * ptr);
	void delete_elemenet(const unsigned int _Key);
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set__array_lenght(const unsigned int __array_lenght);
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	//////////////////////////////////////////////////////////////////////////////

	/*
		DESTRUKTOR
	*/
	virtual ~_Hash_Table();
};

//////////////////////////////////////////////////////////////////////////////

//FUNCTION FOR INSERTING VALUES FROM file_in
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
_Hash_Table::_Hash_Table() :
	__array_lenght(0),
	__array_counter(0)
{
	__Array.resize(__array_lenght);
}

_Hash_Table::_Hash_Table(const unsigned int __array_lenght) :
	__array_lenght(__array_lenght),
	__array_counter(0)
{
	__Array.resize(__array_lenght);
}

_Hash_Table::_Hash_Table(const _Hash_Table & Object) :
	__array_lenght(Object.__array_lenght),
	__array_counter(Object.__array_counter)
{
	__Array.resize(__array_lenght);
}

void __fastcall _Hash_Table::push(const _Hash_Element * ptr)
{
	__array_counter = 0;
	if (if_same_key(ptr) == true)
	{
		__Array[__array_counter] = const_cast<_Hash_Element *>(ptr);
		__array_counter = 0;
	}
	else if (__Array[(const_cast<_Hash_Element *>(ptr)->get_index(__array_lenght))] == nullptr)
	{
		__Array[(const_cast<_Hash_Element *>(ptr)->get_index(__array_lenght))] = const_cast<_Hash_Element *>(ptr);
	}
	else 
	{
		bool found_slot = false;
		for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin() + (const_cast<_Hash_Element *>(ptr)->get_index(__array_lenght)); vector_iterator != __Array.end(); ++vector_iterator)
		{
			if ((*vector_iterator) == nullptr)
			{
				__Array[(std::distance(__Array.begin(), vector_iterator))] = const_cast<_Hash_Element *>(ptr);
				found_slot = true;
				break;
			}
		}
		if (found_slot == false)
		{
			for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin(); vector_iterator != __Array.end(); ++vector_iterator)
			{
				if ((*vector_iterator) == nullptr)
				{
					__Array[(std::distance(__Array.begin(), vector_iterator))] = const_cast<_Hash_Element *>(ptr);
					break;
				}
			}
		}
	}
}

void _Hash_Table::show_elements()
{
	for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin(); vector_iterator != __Array.end(); ++vector_iterator)
	{
		if ((*vector_iterator) != nullptr)
		{
			__int64 index = std::distance(__Array.begin(), vector_iterator);
			std::cout << index << ' ' << (*vector_iterator)->get_key() << ' ' << (*vector_iterator)->get_value() << '\n';
		}
	}
	std::cout << '\n';
}

void _Hash_Table::hash_table_organizer()
{
	__array_counter = 0;
	for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin(); vector_iterator != __Array.end(); ++vector_iterator)
	{
		if ((*vector_iterator) == nullptr)
		{
			continue;
		}
		else if ((*vector_iterator)->get_index(__array_lenght) != std::distance(__Array.begin(), vector_iterator))
		{
			if (static_cast<unsigned int>(std::distance(__Array.begin(), vector_iterator)) < (*vector_iterator)->get_index(__array_lenght))
			{
				__array_counter = 0;
				for (unsigned int i = 0; i < __array_lenght; ++i)
				{
					if (std::distance(__Array.begin(), (vector_iterator)) == 0)
					{
						if ((__Array[i] == nullptr && i >= (*vector_iterator)->get_index(__array_lenght)))
						{
							std::swap(__Array[std::distance(__Array.begin(), (vector_iterator))], __Array[i]);
							break;
						}
					}
					else
					{
						if ((__Array[i] == nullptr && i <= (*vector_iterator)->get_index(__array_lenght)))
						{
							std::swap(__Array[std::distance(__Array.begin(), (vector_iterator))], __Array[i]);
							break;
						}
					}
				}
				__array_counter = 0;
			}
			else if (__Array[std::distance(__Array.begin(), (vector_iterator - 1))] == nullptr)
			{
				__array_counter = static_cast<unsigned int>(std::distance(__Array.begin(), vector_iterator));
				std::swap(__Array[__array_counter - 1], __Array[__array_counter]);
				__array_counter = 0;
			}
			else if (static_cast<unsigned int>(std::distance(__Array.begin(), vector_iterator)) > (*vector_iterator)->get_index(__array_lenght))
			{
				__array_counter = 0;
				for (unsigned int i = static_cast<unsigned int>(std::distance(__Array.begin(), (vector_iterator))); i >= (*vector_iterator)->get_index(__array_lenght); --i)
				{
					if (__Array[i] == nullptr && i >= (*vector_iterator)->get_index(__array_lenght))
					{
						std::swap(__Array[std::distance(__Array.begin(), (vector_iterator))],__Array[i]);
						break;
					}
					__array_counter++;
				}
				__array_counter = 0;
			}
		}
	}
	__array_counter = 0;
}

bool __fastcall _Hash_Table::if_same_key(const _Hash_Element * ptr)
{
	for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin(); vector_iterator != __Array.end(); ++vector_iterator)
	{
		if ((*vector_iterator) == nullptr)
		{
			continue;
		}
		else if (ptr->get_key() == (*vector_iterator)->get_key())		//overloaded oeprator ==
		{
			__array_counter = std::distance(__Array.begin(), vector_iterator);
			return true;
		}
	}
	return false;
}

void _Hash_Table::set__array_lenght(const unsigned int __array_lenght)
{
	if (__array_lenght < 0)
	{
		this->__array_lenght = ((-1) * __array_lenght);
	}
	else
	{
		this->__array_lenght = __array_lenght;
	}
}

void _Hash_Table::delete_elemenet(const unsigned int _Key)
{
	for (typename std::vector<_Hash_Element *>::iterator vector_iterator = __Array.begin(); vector_iterator != __Array.end(); ++vector_iterator)
	{
		if ((*vector_iterator) == nullptr)
		{
			continue;
		}
		else if ((*vector_iterator)->get_key() == _Key)
		{
			(*vector_iterator) = nullptr;
			hash_table_organizer();
			break;
		}
	}
}

_Hash_Table::~_Hash_Table()
{
	__array_lenght = NULL;
	__array_counter = NULL;
	__Array.erase(__Array.begin(), __Array.end());
}

void inserter()
{
	std::string data_reader = "";		//czyta dane z pliku
	std::string Value = "";
	unsigned int Element_Key = 0;
	long int Element_Key_Delete = 0;

	//reading
	std::cin >> data_reader;
	unsigned int loop_range = static_cast<unsigned int>(stoi(data_reader));
	for (unsigned int i = 0; i < loop_range; ++i)
	{
		std::cin >> data_reader;
		if (data_reader == "size")
		{
			std::cin >> data_reader;
			unsigned int object_array_size = static_cast<unsigned int>(stoi(data_reader));
			_Hash_Table Object(object_array_size);
			while (true)
			{
				std::cin >> data_reader;
				if (data_reader == "add")
				{
					std::cin >> Element_Key;
					std::cin >> Value;
					Object.push(new _Hash_Element(Element_Key, Value));
				}
				else if (data_reader == "print")	//print
				{
					Object.show_elements(); //uncomment
				}
				else if (data_reader == "delete")	//delete
				{
					std::cin >> Element_Key_Delete;
					Object.delete_elemenet(Element_Key_Delete);
				}
				else if (data_reader == "stop")		//stop
				{
					break;
				}
				data_reader = "";
				Value = "";
				Element_Key = 0;
			}
		}
		data_reader = "";
		Value = "";
		Element_Key = 0;
	}
}