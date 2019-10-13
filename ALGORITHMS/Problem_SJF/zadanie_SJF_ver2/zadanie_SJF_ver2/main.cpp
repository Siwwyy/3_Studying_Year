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
#include <iomanip>
#include <set>
#include <stack>
#include <algorithm>

//Struct _Single_Point

struct _Single_Point
{
	//////////////////////////////////////////////////////////////////////////////
	long long X;
	long long Y;
	double angle;	//angle between this point and point P0
	//////////////////////////////////////////////////////////////////////////////
	_Single_Point() :
		X(0),
		Y(0)
	{

	}
	//////////////////////////////////////////////////////////////////////////////
	_Single_Point(const long long X, const long long Y) :
		X(X),
		Y(Y)
	{

	}
	//////////////////////////////////////////////////////////////////////////////
	void show_object() const
	{
		std::cout << X << ' ' << Y << '\n';
	}
	//////////////////////////////////////////////////////////////////////////////
	void set_X(const long long X)
	{
		this->X = X;
	}
	//////////////////////////////////////////////////////////////////////////////
	void set_Y(const long long Y)
	{
		this->Y = Y;
	}
	//////////////////////////////////////////////////////////////////////////////
	bool operator<(const _Single_Point & _Ty_Right) const
	{
		if (this->angle < _Ty_Right.angle)
		{
			return true;
		}
		return false;
	}
	bool operator==(const _Single_Point & _Ty_Right) const
	{
		if (this->angle == _Ty_Right.angle)
		{
			return true;
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////////////
	long long get_X() const
	{
		return X;
	}
	//////////////////////////////////////////////////////////////////////////////
	long long get_Y() const
	{
		return Y;
	}
	//////////////////////////////////////////////////////////////////////////////
	~_Single_Point() { X = 0; Y = 0; }
	//////////////////////////////////////////////////////////////////////////////
};

//COMPARATOR
int porownaj(const _Single_Point & _Ty_Left, const _Single_Point & _Ty_Right)
{
	if (_Ty_Left.angle < _Ty_Right.angle)
	{
		return 1;
	}
	return 0;
}


//CLASS _SJF

class _SJF
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	_Single_Point * array_big_lanterns;
	int _big_counter;
	size_t size_array_big_lanterns;
	////////////////////////////////////////////
	std::multiset<_Single_Point> sorted_by_angle;
	////////////////////////////////////////////
	_Single_Point * array_small_lanterns;
	int _small_counter;
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
	void show_Cartesian_system(_Single_Point * Array, const size_t size);
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
		while (L > 0)
		{
			file_in >> X;
			file_in >> Y;
			Object.push_array_big_lanterns(X, Y);
			X = 0;
			Y = 0;
			--L;
		}
		file_in >> S;
		Object.set_size_array_small_lanterns(S);
		while (S > 0)
		{
			file_in >> X;
			file_in >> Y;
			Object.push_array_small_lanterns(X, Y);
			X = 0;
			Y = 0;
			--S;
		}
		Object.show_array_big_lanterns();
		Object.show_array_small_lanterns();
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
	size_array_small_lanterns(0)
{
	this->array_big_lanterns = new _Single_Point[size_array_big_lanterns];
	this->array_small_lanterns = new _Single_Point[size_array_small_lanterns];
}

_SJF::_SJF(const _SJF & Object):
	_big_counter(0),
	_small_counter(0)
{
	this->size_array_big_lanterns = Object.size_array_big_lanterns;
	this->array_big_lanterns = new _Single_Point[this->size_array_big_lanterns];
	for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	{
		array_big_lanterns[i].X = 0;
		array_big_lanterns[i].Y = 0;
	}

	this->size_array_small_lanterns = Object.size_array_small_lanterns;
	this->array_small_lanterns = new _Single_Point[this->size_array_small_lanterns];
	for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
	{
		array_small_lanterns[i].X = 0;
		array_small_lanterns[i].Y = 0;
	}
}

void _SJF::push_array_big_lanterns(const long long X, const long long Y)
{
	this->array_big_lanterns[_big_counter].X = X;
	this->array_big_lanterns[_big_counter].Y = Y;
	++_big_counter;
}

void _SJF::push_array_small_lanterns(const long long X, const long long Y)
{
	this->array_small_lanterns[_small_counter].X = X;
	this->array_small_lanterns[_small_counter].Y = Y;
	++_small_counter;
}

void _SJF::show_array_big_lanterns() const
{
	for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	{
		std::cout << array_big_lanterns[i].get_X() << ' ' << array_big_lanterns[i].get_Y() << '\n';
	}
	std::cout << '\n';
}

void _SJF::show_array_small_lanterns() const
{
	for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
	{
		std::cout << array_small_lanterns[i].get_X() << ' ' << array_small_lanterns[i].get_Y() << '\n';
	}
	std::cout << '\n';
}

void _SJF::__Make_Convex_Hull()
{
	////////////////////////////////////////////////////////////////////////////////////////////
	//seeking for the point with smalles Y and X
	_Single_Point * P;
	
	long long the_smallest_y = 0;
	long long the_smallest_x = 0;

	the_smallest_y = array_big_lanterns[0].Y;
	the_smallest_x = array_big_lanterns[0].X;
	for (size_t i = 1; i < size_array_big_lanterns; ++i)
	{
		if (the_smallest_y >= array_big_lanterns[i].Y)
		{
			if (the_smallest_y == array_big_lanterns[i].Y)
			{
				if (the_smallest_x > array_big_lanterns[i].X)
				{
					the_smallest_y = array_big_lanterns[i].Y;
					the_smallest_x = array_big_lanterns[i].X;
				}
			}
			else
			{
				the_smallest_y = array_big_lanterns[i].Y;
				the_smallest_x = array_big_lanterns[i].X;
			}
		}
	}

	P = new _Single_Point(the_smallest_x, the_smallest_y);	//move the cartezian system and set the smalles point (X and Y) as a beginning the cartezian system
	/*std::cout << P->get_X() << ' ' << P->get_Y() << std::endl;
	std::cin.get();*/

	////////////////////////////////////////////////////////////////////////////////////////////
	//Count the angles between the points
	double segment_length = 0;
	double angle = 0.0;
	//for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	//{
	//	array_big_lanterns[i].show_object();
	//}
	//std::cin.get();
	//funny key shortcut CTRL + K + S
	//int counter_cos = 0;
	//_Single_Point * temp_tab = new _Single_Point[(size_array_big_lanterns - 1)];
	for (size_t i = 0; i < size_array_big_lanterns; ++i)
	{
		if (array_big_lanterns[i].X != P->X && array_big_lanterns[i].Y != P->Y)
		{
			array_big_lanterns[i].X -= the_smallest_x;
			if (P->get_Y() < 0)
			{
				array_big_lanterns[i].Y += the_smallest_y;
			}
			else
			{
				array_big_lanterns[i].Y -= the_smallest_y;
			}
			segment_length = sqrt(pow((array_big_lanterns[i].X),2)  +  pow((array_big_lanterns[i].Y),2));
			angle = (((double)array_big_lanterns[i].Y) / ((double)segment_length));
			array_big_lanterns[i].angle = angle;
			sorted_by_angle.insert(array_big_lanterns[i]);
		}
		segment_length = 0;
		angle = 0.0;
	}
	std::stack< _Single_Point> stos;
	std::vector<_Single_Point> vec;
	std::vector<_Single_Point> temporary_vec;
	stos.push((*P));
	//vec.emplace_back((*P));
	temporary_vec.emplace_back((*P));
	bool if_first = false;
	long long result = 0;
	auto orientation = [&](const _Single_Point & p, const _Single_Point & q, const _Single_Point & r) -> const int
	{
		long long value = 0;
		value = ( (  (q.X - p.X) * (r.Y - p.Y)   ) - ( (q.Y - p.Y)* (r.X- p.X) )  );

		if (value < 0)
		{
			return -1;
		}
		else if (value == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	};

	for (auto set_iterator = sorted_by_angle.begin(); set_iterator != sorted_by_angle.end(); ++set_iterator) //-> to sortuje
	{
		temporary_vec.emplace_back(*set_iterator);
	}
	for (size_t i = 0; i < temporary_vec.size(); ++i)
	{
		temporary_vec[i].show_object();
	}



	for (size_t i = 0; i < temporary_vec.size() - 2; ++i)
	{
		vec.emplace_back(temporary_vec[i]);
		if (orientation(temporary_vec[i], temporary_vec[i + 1], temporary_vec[i + 2]) != -1)
		{
			continue;
		}
		else
		{
			int counter = vec.size() - 2;
			while (orientation(vec[counter], vec[counter + 1], temporary_vec[i + 2]) == -1)
			{
				--counter;
				vec.pop_back();
			}
		}
	}

	std::cin.get();
	for (size_t i = 0; i < vec.size(); ++i)
	{
		vec[i].show_object();
	}

	std::cin.get();
	delete P;
}

void _SJF::show_Cartesian_system(_Single_Point * Array, const size_t size)
{
	long long the_biggest_X_big = 0;
	long long the_biggest_X_small = 0;
	long long the_biggest_Y_big = 0;
	long long the_biggest_Y_small = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (Array[i].X >= the_biggest_X_big)
		{
			the_biggest_X_big = Array[i].X;
		}
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (Array[i].Y >= the_biggest_Y_big)
		{
			the_biggest_Y_big = Array[i].Y;
		}
	}
	std::cout << the_biggest_X_big << ' ' << the_biggest_Y_big << std::endl;

	bool found = false;
	size_t cos = 0;
	for (size_t i = 0; i < the_biggest_Y_big; ++i)
	{
		for (size_t j = 0; j < the_biggest_X_big; ++j)
		{
			for (size_t k = 0; k < size; ++k)
			{
				if (Array[k].get_X() == (j + 1) && Array[k].get_Y() == (the_biggest_Y_big - (i)))
				{
					found = true;
					Array[k].set_X(-22);
					Array[k].set_Y(-22);
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
}

void _SJF::set_size_array_big_lanterns(const size_t size)
{
	delete[] array_big_lanterns;
	this->size_array_big_lanterns = size;
	this->array_big_lanterns = new _Single_Point[this->size_array_big_lanterns];
	for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
	{
		array_big_lanterns[i].X = 0;
		array_big_lanterns[i].Y = 0;
	}
}

void _SJF::set_size_array_small_lanterns(const size_t size)
{
	delete[] array_small_lanterns;
	this->size_array_small_lanterns = size;
	this->array_small_lanterns = new _Single_Point[this->size_array_small_lanterns];
	for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
	{
		array_small_lanterns[i].X = 0;
		array_small_lanterns[i].Y = 0;
	}
}

_SJF & _SJF::operator=(const _SJF & Object)
{
	if(this != &Object)
	{
		delete[] array_big_lanterns;
		this->size_array_big_lanterns = Object.size_array_big_lanterns;
		this->array_big_lanterns = new _Single_Point[this->size_array_big_lanterns];
		for (size_t i = 0; i < this->size_array_big_lanterns; ++i)
		{
			array_big_lanterns[i].X = 0;
			array_big_lanterns[i].Y = 0;
		}

		delete[] array_small_lanterns;
		this->size_array_small_lanterns = Object.size_array_small_lanterns;
		this->array_small_lanterns = new _Single_Point[this->size_array_small_lanterns];
		for (size_t i = 0; i < this->size_array_small_lanterns; ++i)
		{
			array_small_lanterns[i].X = 0;
			array_small_lanterns[i].Y = 0;
		}
	}
	return *this;
}

_SJF::~_SJF()
{
	if (this->size_array_big_lanterns != 0)
	{
		delete[] array_big_lanterns;
	}
	if (this->size_array_small_lanterns != 0)
	{
		delete[] array_small_lanterns;
	}
	_big_counter = 0;
	_small_counter = 0;
}