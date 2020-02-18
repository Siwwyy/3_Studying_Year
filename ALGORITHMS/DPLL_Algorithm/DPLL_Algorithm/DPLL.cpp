#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	/*size_t distance{};
	for (typename std::vector<int32_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
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
	}*/
	size_t distance{};
	std::vector<int32_t>::const_iterator _First{};
	std::vector<int32_t>::const_iterator _Last{};
	//std::vector<int32_t> Temp_Vector(this->Data);
	for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if (*vec_iterator != 0)
		{
			//_First = static_cast<std::vector<int32_t>::const_iterator>(vec_iterator);
			++distance;
		}
		else
		{
			if (distance == 1)
			{
				/*
					REMOVE FROM DATA VECTOR UNARY VARIABLES
				*/
				size_t position{};
				if ((*(vec_iterator - 1)) < 0)
				{
					position = static_cast<size_t>(((*(vec_iterator - 1)) * -1) - 1);
				}
				Knowledge[position] = (*(vec_iterator - 1));
				for (typename std::vector<int64_t>::iterator vec_iterator_second = this->Data.begin(); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
				{
					if (((*(vec_iterator - 1)) * -1) == (*vec_iterator_second))
					{
						(*vec_iterator_second) = ((amount_of_literals)+1);
					}
				}
				(*(vec_iterator - 1)) = ((amount_of_literals)+1);
				(*(vec_iterator)) = ((amount_of_literals)+1);
				//_Last = static_cast<std::vector<int32_t>::const_iterator>(vec_iterator);
				//Temp_Vector.erase(_First, _Last);
			}
			distance = 0;
		}
	}
	//this->Data = Temp_Vector;
}

void SAT::DPLL::Erase_Useful_Variables()
{
	std::remove(this->Data.begin(), this->Data.end(), ((amount_of_literals)+1));	//removing unecessary elements





	/*typename std::vector<int32_t>::iterator zero_position{};
	std::vector<int32_t> Data_Temp(this->Data);
	for (typename std::unordered_set<int32_t>::const_iterator set_iterator = this->Unary_Variables.begin(); set_iterator != this->Unary_Variables.end(); ++set_iterator)
	{
		for (typename std::vector<int32_t>::iterator vec_iterator = Data_Temp.begin(); vec_iterator != Data_Temp.end(); ++vec_iterator)
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
							(*vec_iterator_second) = (this->amount_of_literals + 1);
						}
						else
						{
							(*vec_iterator_second) = (this->amount_of_literals + 1);
							break;
						}
					}
				}
				else
				{
					for (typename std::vector<int32_t>::iterator vec_iterator_second = (zero_position + 1); vec_iterator_second != Data_Temp.end(); ++vec_iterator_second)
					{
						if ((*vec_iterator_second) != 0)
						{
							(*vec_iterator_second) = (this->amount_of_literals + 1);
						}
						else
						{
							(*vec_iterator_second) = (this->amount_of_literals + 1);
							break;
						}
					}
				}
			}
		}
	}
	Data.clear();
	for (typename std::vector<int32_t>::iterator vec_iterator = Data_Temp.begin(); vec_iterator != Data_Temp.end(); ++vec_iterator)
	{
		if ((*vec_iterator) != (this->amount_of_literals + 1))
		{
			Data.emplace_back((*vec_iterator));
		}
	}*/
}

SAT::DPLL::DPLL(const std::vector<int64_t> & my_data, const int64_t amount_of_literals):
	Data(my_data),
	amount_of_literals(amount_of_literals),
	Unary_Variables()
{
	this->Knowledge = new int64_t[this->amount_of_literals];
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		Knowledge[i] = (this->amount_of_literals + 1);//default value means that there is not a value inside
	}
	Print_Data();
	Print_Knowledge();
	Find_Unaries();
	Erase_Useful_Variables();
}

SAT::DPLL::DPLL(const DPLL& Object) :
	Data(Object.Data),
	amount_of_literals(Object.amount_of_literals),
	Unary_Variables(Object.Unary_Variables)
{
	this->Knowledge = new int64_t[this->amount_of_literals];
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		Knowledge[i] = (this->amount_of_literals + 1);//default value means that there is not a value inside
	}
	Print_Data();
	Print_Knowledge();
	Find_Unaries();
	Erase_Useful_Variables();
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<int64_t>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
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

void SAT::DPLL::Print_Knowledge() const
{
	std::cout << "|================================|" << '\n';
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		//std::cout << *(Knowledge+i) << ' ';
		std::cout << Knowledge[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "|================================|" << '\n';
}

void SAT::DPLL::SAT_or_UNSAT()
{
	if (this->Data.size() != 0)
	{
		//SAT_or_UNSAT();
	}
	else
	{
		//GIVE RESULT SAT or UNSAT
		//if some of literals arent in Data, you have to explicitly set their value to true
		//for example, we have 7 literals given but in data we have from 1 to 5 (6 and 7 are implicit, defaultly set up to true)
	}
}

SAT::DPLL& SAT::DPLL::operator=(const DPLL& Object)
{
	if (this != std::addressof(Object))
	{
		delete[] this->Knowledge;
		this->Data.clear();
		this->Unary_Variables.clear();
		this->Data = Object.Data;
		this->amount_of_literals = Object.amount_of_literals;
		this->Unary_Variables = Object.Unary_Variables;
		this->Knowledge = new int64_t[this->amount_of_literals];
		for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
		{
			Knowledge[i] = (this->amount_of_literals + 1);	//default value means that there is not a value inside
		}
		Print_Data();
		Print_Knowledge();
		Find_Unaries();
		Erase_Useful_Variables();
	}
	return *this;
}

SAT::DPLL::~DPLL()
{
	delete[] this->Knowledge;
	this->Data.clear();
	this->amount_of_literals = 0;
	this->Unary_Variables.clear();
}