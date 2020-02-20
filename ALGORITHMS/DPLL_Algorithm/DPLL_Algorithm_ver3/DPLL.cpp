#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	for (typename std::vector<std::vector<std::pair<int64_t, bool>>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2)
		{
			K[static_cast<size_t>((*vec_iterator)[0].first - 1)] = std::make_pair((*vec_iterator)[0].first, (*vec_iterator)[0].second);
			(*vec_iterator)[0].first = static_cast<int64_t>((amount_of_literals) + (*vec_iterator)[0].first);
		}
	}
}

void SAT::DPLL::Add_To_Knowledge(int64_t value)
{
	size_t position{ static_cast<size_t>(value - 1) };
	if (value < 0)
	{
		position = static_cast<size_t>(((value) * - 1) - 1);
	}
	Knowledge[position] = value;
}

const bool SAT::DPLL::Is_End() const
{
	for (typename std::vector<std::vector<std::pair<int64_t, bool>>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<std::pair<int64_t, bool>>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
		/*	if ((*vec_iterator_second) <= amount_of_literals && (*vec_iterator_second) != 0)
			{
				return false;
			}*/
		}
	}
	return true;
}

SAT::DPLL::DPLL(const std::vector<std::vector<std::pair<int64_t, bool>>> & my_data, const int64_t amount_of_literals):
	Data(my_data),
	amount_of_literals(amount_of_literals),
	K(amount_of_literals),
	Unary_Variables()
{
	this->Knowledge = new int64_t[this->amount_of_literals];
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		Knowledge[i] = (this->amount_of_literals + 1);//default value means that there is not a value inside
	}
	Print_Data();
	//Print_Knowledge();
	Print_K();
	Find_Unaries();
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
	//Print_Knowledge();
	Print_K();
	Find_Unaries();
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<std::pair<int64_t, bool>>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<std::pair<int64_t, bool>>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			//std::cout << "[ " << vec_iterator_second->first << ' ' << std::boolalpha << vec_iterator_second->second << " ]";
			if (vec_iterator_second->second == false)
			{
				std::cout << '-' << vec_iterator_second->first << ' ';
			}
			else
			{
				std::cout << vec_iterator_second->first << ' ';
			}
		}
		std::cout << '\n';
	}
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
	std::cout << '\n';
	std::cout << '\n';
}

void SAT::DPLL::Print_K() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::pair<int64_t, bool>>::const_iterator vec_iterator = this->K.begin(); vec_iterator != this->K.end(); ++vec_iterator)
	{
		std::cout << vec_iterator->first << ' ';
	}
	std::cout << '\n';
	std::cout << "|================================|" << '\n';
	std::cout << '\n';
	std::cout << '\n';
}

void SAT::DPLL::SAT_or_UNSAT()
{
	if (Is_End() == false)
	{
		Print_Data();
		//Print_Knowledge();
		Print_K();
		Find_Unaries();
		SAT_or_UNSAT();
	}
	else
	{
		//GIVE RESULT SAT or UNSAT
		//if some of literals arent in Data, you have to explicitly set their value to true
		//for example, we have 7 literals given but in data we have from 1 to 5 (6 and 7 are implicit, defaultly set up to true)
		for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
		{
			if (Knowledge[i] == (this->amount_of_literals + 1))
			{
				Knowledge[i] = (i + 1);
			}
		}
		Print_Data();
		//Print_Knowledge();
		Print_K();
		std::cout << "SATISFIABLE" << '\n';
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
	}
	return *this;
}

SAT::DPLL::~DPLL()
{
	if (this->Data.size() > 0)
	{
		this->Data.clear();
	}
	delete[] Knowledge;
	this->amount_of_literals = 0;
	this->Unary_Variables.clear();
}