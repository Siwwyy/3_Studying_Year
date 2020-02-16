#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	size_t distance{};
	for (typename std::vector<int>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if (*vec_iterator != 0)
		{
			++distance;
		}
		else
		{
			if (distance == 1)
			{
				Unary_Variables.insert(*(vec_iterator - 1));
			}
			distance = 0;
		}
	}
}

void SAT::DPLL::Erase_Useful_Variables()
{
	typename std::vector<int>::iterator zero_position{};
	std::vector<int> Data_Temp(this->Data);
	for (typename std::unordered_set<int>::const_iterator set_iterator = this->Unary_Variables.begin(); set_iterator != this->Unary_Variables.end(); ++set_iterator)
	{
		for (typename std::vector<int>::iterator vec_iterator = Data_Temp.begin(); vec_iterator != Data_Temp.end(); ++vec_iterator)
		{
			if ((*vec_iterator) == 0 || std::distance(Data_Temp.begin(), vec_iterator) == 0)
			{
				zero_position = vec_iterator;
			}
			if ((*vec_iterator) == (*set_iterator))
			{
				if (std::distance(Data_Temp.begin(), vec_iterator) == 0)
				{
					for (typename std::vector<int>::iterator vec_iterator_second = (zero_position); vec_iterator_second != Data_Temp.end(); ++vec_iterator_second)
					{
						if ((*vec_iterator_second) != 0)
						{
							(*vec_iterator_second) = (this->max_value + 1);
						}
						else
						{
							(*vec_iterator_second) = (this->max_value + 1);
							break;
						}
					}
				}
				else
				{
					for (typename std::vector<int>::iterator vec_iterator_second = (zero_position + 1); vec_iterator_second != Data_Temp.end(); ++vec_iterator_second)
					{
						if ((*vec_iterator_second) != 0)
						{
							(*vec_iterator_second) = (this->max_value + 1);
						}
						else
						{
							(*vec_iterator_second) = (this->max_value + 1);
							break;
						}
					}
				}
			}
		}
	}
	Data.clear();
	for (typename std::vector<int>::iterator vec_iterator = Data_Temp.begin(); vec_iterator != Data_Temp.end(); ++vec_iterator)
	{
		if ((*vec_iterator) != (this->max_value + 1))
		{
			Data.emplace_back((*vec_iterator));
		}
	}
}

SAT::DPLL::DPLL(const std::vector<int> & my_data, const int64_t max_value):
	Data(my_data),
	max_value(max_value),
	Unary_Variables()
{
	Find_Unaries();
	Erase_Useful_Variables();
}

SAT::DPLL::DPLL(const DPLL& Object) :
	Data(Object.Data),
	max_value(Object.max_value),
	Unary_Variables(Object.Unary_Variables)
{
	Find_Unaries();
	Erase_Useful_Variables();
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<int>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		std::cout << *vec_iterator << ' ';
		if (*vec_iterator == 0)
		{
			std::cout << '\n';
		}
	}
	std::cout << "|================================|" << '\n';
}

void SAT::DPLL::Print_Unary_Variables() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::unordered_set<int>::const_iterator set_iterator = this->Unary_Variables.begin(); set_iterator != this->Unary_Variables.end(); ++set_iterator)
	{
		std::cout << *set_iterator << ' ';
	}
	std::cout << '\n';
	std::cout << "|================================|" << '\n';
}

const bool SAT::DPLL::SAT_or_UNSAT()
{
	if (this->Unary_Variables.size() == 0)
	{

	}
	else
	{

	}

	return false;
}

SAT::DPLL& SAT::DPLL::operator=(const DPLL& Object)
{
	if (this != std::addressof(Object))
	{
		this->Data.clear();
		this->Unary_Variables.clear();
		this->Data = Object.Data;
		this->max_value = Object.max_value;
		this->Unary_Variables = Object.Unary_Variables;
		Find_Unaries();
		Erase_Useful_Variables();
	}
	return *this;
}

SAT::DPLL::~DPLL()
{
	this->Data.clear();
	this->max_value = 0;
	this->Unary_Variables.clear();
}