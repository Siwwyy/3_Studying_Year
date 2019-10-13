/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

class _SJF
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	long long ** array_big_lanterns;
	int _big_counter_width;
	int _big_counter_height;
	size_t size_array_big_lanterns;
	////////////////////////////////////////////
	long long ** array_small_lanterns;
	int _small_counter_width;
	int _small_counter_height;
	size_t size_array_small_lanterns;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_SJF();
	_SJF(const _SJF & Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push_array_big_lanterns(const long long X, const long long Y);
	void push_array_small_lanterns(const long long X, const long long Y);
	void show_array_big_lanterns() const;
	void show_array_small_lanterns() const;
	void __Make_Convex_Hull();
	void show_Cartesian_system(long long ** Array, const size_t size);
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_size_array_big_lanterns(const size_t size);
	void set_size_array_small_lanterns(const size_t size);
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_SJF & operator=(const _SJF & Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_SJF();
};

//FUNCTION FOR INSERTING VALUES FROM file_in
void inserter(const std::string & file_path);
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	inserter("file.in");
	system("pause");
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void inserter(const std::string & file_path)
{
	std::fstream file_in;
	int L = 0;
	int S = 0;
	long long X = 0;
	long long Y = 0;
	file_in.open(file_path, std::ios_base::in);
	if (file_in.good() == false)
	{
		exit(0);
	}
	else
	{
		_SJF Object;
		file_in >> L;
		Object.set_size_array_big_lanterns(L);
		//std::cout << L << std::endl;
		while (L > 0)
		{
			file_in >> X;
			file_in >> Y;
			Object.push_array_big_lanterns(X, Y);
			//std::cout << X << ' ' << Y << std::endl;
			X = 0;
			Y = 0;
			--L;
		}
		file_in >> S;
		Object.set_size_array_small_lanterns(S);
		//std::cout << S << std::endl;
		while (S > 0)
		{
			file_in >> X;
			file_in >> Y;
			Object.push_array_small_lanterns(X, Y);
			//std::cout << X << ' ' << Y << std::endl;
			X = 0;
			Y = 0;
			--S;
		}
		Object.show_array_big_lanterns();
		Object.show_array_small_lanterns();
		//Object.show_Cartesian_system();
		Object.__Make_Convex_Hull();
	}
	file_in.close();
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_MST_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_SJF::_SJF():
	size_array_big_lanterns(0),
	_small_counter_height(0),
	_small_counter_width(0),
	_big_counter_height(0),
	_big_counter_width(0),
	size_array_small_lanterns(0)
{
	this->array_big_lanterns = new long long*[size_array_big_lanterns];
	this->array_small_lanterns = new long long*[size_array_small_lanterns];
}

_SJF::_SJF(const _SJF & Object)
{

}

void _SJF::push_array_big_lanterns(const long long X, const long long Y)
{
	//this->array_big_lanterns[(X - 1)][(Y - 1)] = 1;
	this->array_big_lanterns[_big_counter_width][_big_counter_height] = X;
	++_big_counter_height;
	this->array_big_lanterns[_big_counter_width][_big_counter_height] = Y;
	++_big_counter_width;
	_big_counter_height = 0;
	/*show_array_big_lanterns();
	std::cin.get();*/
}

void _SJF::push_array_small_lanterns(const long long X, const long long Y)
{
	//this->array_small_lanterns[(X - 1)][(Y - 1)] = 1;
	this->array_small_lanterns[_small_counter_width][_small_counter_height] = X;
	++_small_counter_height;
	this->array_small_lanterns[_small_counter_width][_small_counter_height] = Y;
	++_small_counter_width;
	_small_counter_height = 0;
}

void _SJF::show_array_big_lanterns() const
{
	/*std::cout << size_array_big_lanterns << std::endl;
	std::cin.get();*/
	for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			std::cout << this->array_big_lanterns[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void _SJF::show_array_small_lanterns() const
{
	for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			std::cout << this->array_small_lanterns[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void _SJF::__Make_Convex_Hull()
{
	show_Cartesian_system(array_big_lanterns, size_array_big_lanterns);
}

void _SJF::show_Cartesian_system(long long ** Array, const size_t size)
{
	long long the_biggest_X_big = 0;
	long long the_biggest_X_small = 0;
	long long the_biggest_Y_big = 0;
	long long the_biggest_Y_small = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (Array[i][0] >= the_biggest_X_big)
		{
			the_biggest_X_big = Array[i][0];
		}
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (Array[i][1] >= the_biggest_Y_big)
		{
			the_biggest_Y_big = Array[i][1];
		}
	}
	std::cout << the_biggest_X_big << ' ' << the_biggest_Y_big << std::endl;



	_big_counter_height = 0;
	_big_counter_width = 0;
	bool found = false;
	size_t cos = 0;
	for (size_t i = 0; i < the_biggest_Y_big; ++i)
	{
		for (size_t j = 0; j < the_biggest_X_big; ++j)
		{
			for (size_t k = 0; k < size; ++k)
			{
				if (Array[k][0] == (j + 1) && Array[k][1] == (the_biggest_Y_big - (i)))
				{
					found = true;
					Array[k][0] = -22;
					Array[k][1] = -22;
				}
			}
			if (found == true)
			{
				std::cout << " * ";
			}
			else
			{
				std::cout << "  ";
			}
			found = false;
		}
		std::cout << '\n';
	}
	show_array_big_lanterns();
	std::cin.get();
}

void _SJF::set_size_array_big_lanterns(const size_t size)
{
	delete[] array_big_lanterns;
	this->size_array_big_lanterns = size;
	this->array_big_lanterns = new long long*[this->size_array_big_lanterns];
	for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	{
		array_big_lanterns[i] = new long long[2];
		for (size_t j = 0; j < 2; ++j)
		{
			array_big_lanterns[i][j] = 0;
		}
	}
}

void _SJF::set_size_array_small_lanterns(const size_t size)
{
	delete[] array_small_lanterns;
	this->size_array_small_lanterns = size;
	this->array_small_lanterns = new long long*[this->size_array_small_lanterns];
	for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
	{
		array_small_lanterns[i] = new long long[2];
		for (size_t j = 0; j < 2; ++j)
		{
			array_small_lanterns[i][j] = 0;
		}
	}
}

_SJF & _SJF::operator=(const _SJF & Object)
{
	if(this != &Object)
	{
		if (this->size_array_big_lanterns == 0)
		{
			delete[] array_big_lanterns;
		}
		else
		{
			for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
			{
				delete[] array_big_lanterns[i];
			}
			delete[] array_big_lanterns;
		}
		if (this->size_array_small_lanterns == 0)
		{
			delete[] array_small_lanterns;
		}
		else
		{
			for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
			{
				delete[] array_small_lanterns[i];
			}
			delete[] array_small_lanterns;
		}

		this->size_array_big_lanterns = Object.size_array_big_lanterns;
		this->array_big_lanterns = new long long*[this->size_array_big_lanterns];
		for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
		{
			array_big_lanterns[i] = new long long[2];
		}

		this->size_array_small_lanterns = Object.size_array_small_lanterns;
		this->array_big_lanterns = new long long*[this->size_array_small_lanterns];
		for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
		{
			array_small_lanterns[i] = new long long[2];
		}
	}
	return *this;
}

_SJF::~_SJF()
{
	if (this->size_array_big_lanterns == 0)
	{
		delete[] array_big_lanterns;
	}
	else
	{
		for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
		{
			delete[] array_big_lanterns[i];
		}
		delete[] array_big_lanterns;
	}
	if (this->size_array_small_lanterns == 0)
	{
		delete[] array_small_lanterns;
	}
	else
	{
		for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
		{
			delete[] array_small_lanterns[i];
		}
		delete[] array_small_lanterns;
	}
	_big_counter_height = 0;
	_big_counter_width = 0;
	_small_counter_height = 0;
	_small_counter_width = 0;
}