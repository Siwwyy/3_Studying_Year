/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

/*
	OWN "STATIC" VARIABLES
*/
constexpr __int32 elevator_move_time = 10;
constexpr __int32 tape_move_time = 5;

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class _Car_Case
{
private:
	/*
		VARIABLES PUBLIC
	*/
	__int32 value;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Car_Case(void);
	_Car_Case(const __int32 value);
	_Car_Case(const _Car_Case & Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_value(const __int32 value);
	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	const __int32 get_value(void) const;
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	const bool operator<(const _Car_Case * rhs) const;
	const bool operator>(const _Car_Case * rhs) const;
	const bool operator==(const _Car_Case * rhs) const;
	//DWUARGUMENTOWE
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	///////////////////////////////////////////////
	virtual ~_Car_Case(void);
};


//CLASS OF HEAP SORT
class _Car_Elevator
{
private:
	/*
		VARIABLES PRIVATE
	*/
	std::vector<std::vector<_Car_Case*>> Parking;
	__int32 elevator_height;
	__int32 tape_size;
	///////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Car_Elevator(void);
	_Car_Elevator(const __int32 elevator_height, const __int32 tape_size);
	_Car_Elevator(const _Car_Elevator & Object);
	///////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void _fastcall push(const _Car_Case * _Ty_ptr, const __int32 i, const __int32 j);
	void take_the_car();
	///////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	///////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	const __int32 get_elevator_height(void) const;
	const __int32 get_tape_size(void) const;
	///////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	_Car_Elevator & operator=(const _Car_Elevator & Object);
	///////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Car_Elevator(void);
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
	__int64 N = 0;		//amount of test cases
	__int32 h = 0;
	__int32 l = 0;
	__int32 number_amount = 0;
	std::cin >> N;
	while (N > 0)
	{
		std::cin >> h;
		std::cin >> l;
		_Car_Elevator * Car_Elevator = new _Car_Elevator(h, l);
		for (__int32 i = 0; i < h; ++i)
		{
			for (__int32 j = 0; j < l; ++j)
			{
				std::cin >> number_amount;
				{
					Car_Elevator->push(new _Car_Case(number_amount), i, j);
				}
				number_amount = 0;
			}
		}
		Car_Elevator->take_the_car();
		delete Car_Elevator;
		N--;
		h = 0;
		l = 0;
	}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	CAR CASE CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Car_Case::_Car_Case(void)
{

}

_Car_Case::_Car_Case(const __int32 value):
	value(value)
{

}

_Car_Case::_Car_Case(const _Car_Case & Object):
	value(Object.value)
{

}

void _Car_Case::set_value(const __int32 value)
{
	this->value = value;
}

const __int32 _Car_Case::get_value(void) const
{
	return value;
}

const bool _Car_Case::operator<(const _Car_Case * rhs) const
{
	if (value < rhs->value)
	{
		return true;
	}
	return false;
}

const bool _Car_Case::operator>(const _Car_Case * rhs) const
{
	if (value > rhs->value)
	{
		return true;
	}
	return false;
}

const bool _Car_Case::operator==(const _Car_Case * rhs) const
{
	if (value == rhs->value)
	{
		return true;
	}
	return false;
}

_Car_Case::~_Car_Case(void)
{
	value = 0;
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	CAR ELEVATOR CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Car_Elevator::_Car_Elevator(void) :
	elevator_height(0),
	tape_size(0)
{
	Parking.resize(elevator_height);
	for (int i = 0; i < Parking.size(); ++i)
	{
		Parking[i].resize(tape_size);
	}
}

_Car_Elevator::_Car_Elevator(const __int32 elevator_height, const __int32 tape_size):
	elevator_height(elevator_height),
	tape_size(tape_size)
{
	Parking.resize(elevator_height);
	for (int i = 0; i < Parking.size(); ++i)
	{
		Parking[i].resize(tape_size);
	}
}

_Car_Elevator::_Car_Elevator(const _Car_Elevator & Object) :
	elevator_height(Object.elevator_height),
	tape_size(Object.tape_size)

{

}

void _fastcall _Car_Elevator::push(const _Car_Case * _Ty_ptr, const __int32 i, const __int32 j)
{
	Parking[i][j] = const_cast<_Car_Case *>(_Ty_ptr);
}

void _Car_Elevator::take_the_car()
{
	std::vector<std::pair<__int32, __int32>> flag_xy(Parking.size());
	for (__int32 i = 0; i < Parking.size(); ++i)	//set the defaults flags, each level have to be on -1 
	{
		for (__int32 j = 0; j < Parking[i].size(); ++j)
		{
			if (Parking[i][j]->get_value() < 0 && i < 1)
			{
				flag_xy[i].first = i;
				flag_xy[i].second = j;
				break;
			}
			else
			{
				flag_xy[i].first = i;
				flag_xy[i].second = j;
				break;
			}
		}
	}
	__int64 final_value = 0;
	__int32 x = 0;
	__int32 y = 0;
	for (__int32 i = 0; i < Parking.size(); ++i)	//width
	{
		for (__int32 j = 0; j < Parking[i].size(); ++j)	//height
		{
			__int32 the_smallest_element = -1;
			//seeking the smallest element case
			//seeking works
			for (__int32 k = 0; k < Parking.size(); ++k)	//seeking in width for the smallest value
			{
				for (__int32 l = 0; l < Parking[k].size(); ++l)	//seeking in height for the smallest value
				{
					if (Parking[k][l]->get_value() < 0)
					{
						continue;
					}
					else
					{
						if (the_smallest_element == -1)
						{
							the_smallest_element = Parking[k][l]->get_value();
							x = k;
							y = l;
						}
						else if(the_smallest_element >= Parking[k][l]->get_value())
						{
							the_smallest_element = Parking[k][l]->get_value();
							x = k;
							y = l;
						}
					}
				}
			}
			//look for the way down here
			__int32 tape_moves = 0;
			if (Parking[x][y]->get_value() == the_smallest_element && the_smallest_element > -1)	//works
			{
				__int32 left = 0;
				__int32 right = 0; 
				if (y <= flag_xy[x].second)
				{ 
					left = flag_xy[x].second - y;
					right = y + ((Parking[x].size() - 1) - flag_xy[x].second) + 1;
				}
				else if (flag_xy[x].second <= y)
				{
					left = flag_xy[x].second + (Parking[x].size() - 1) - y + 1;
					right = y - flag_xy[x].second;
				}
				if (left > right)
				{
					tape_moves = right;
					final_value += 2 * (elevator_move_time *(x)) + (tape_move_time * tape_moves);
				}
				else
				{
					tape_moves = left;
					final_value += 2 * (elevator_move_time *(x)) + (tape_move_time * tape_moves);
				}
				for (__int32 i = 0; i < flag_xy.size(); ++i)
				{
					if (flag_xy[i].first == x)
					{
						flag_xy[i].second = y;
					}
				}
				Parking[x][y]->set_value(-1);
			}
			the_smallest_element = 0;
		}
	}
	std::cout << final_value << '\n';
	final_value = 0;
}

const __int32 _Car_Elevator::get_elevator_height(void) const
{
	return elevator_height;
}

const __int32 _Car_Elevator::get_tape_size(void) const
{
	return tape_size;
}

_Car_Elevator & _Car_Elevator::operator=(const _Car_Elevator & Object)
{
	if (this != std::addressof(Object))
	{
		this->elevator_height = Object.elevator_height;
		this->tape_size = Object.tape_size;
	}
	return *this;
}

_Car_Elevator::~_Car_Elevator(void)
{
	elevator_height = 0;
	tape_size = 0;
	for (__int32 i = 0; i < Parking.size(); ++i)
	{
		Parking[i].erase(Parking[i].begin(), Parking[i].end());
	}
	Parking.erase(Parking.begin(), Parking.end());
}
