#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	for (typename std::vector<std::vector<int64_t>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2)
		{
			Add_To_Knowledge((*vec_iterator)[0]);
			(*vec_iterator)[0] = ((amount_of_literals)+1);
			(*vec_iterator)[1] = ((amount_of_literals)+1);
		}
	}
}

void SAT::DPLL::Change_Row()
{
	std::vector<int64_t>::iterator it{};
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		if (Knowledge[i] != (this->amount_of_literals + 1))
		{
			for (typename std::vector<std::vector<int64_t>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
			{
				it = std::find(vec_iterator->begin(), vec_iterator->end(), Knowledge[i]);
				if (it != vec_iterator->end())
				{
					for (typename std::vector<int64_t>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						(*vec_iterator_second) = ((amount_of_literals)+1);
					}
				}
				it = std::find(vec_iterator->begin(), vec_iterator->end(), (-1)*Knowledge[i]);
				if (it != vec_iterator->end())
				{
					*it = ((amount_of_literals)+1);
				}
			}
		}
	}
}


void SAT::DPLL::Create_Tree()
{
	for (typename std::vector<std::vector<int64_t>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<int64_t>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if ((*vec_iterator_second) != ((amount_of_literals)+1))
			{
				Add_To_Knowledge((*vec_iterator_second));
			}
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
	if (position >= 0 && position < amount_of_literals && Knowledge[position] == ((amount_of_literals)+1))
	{
		Knowledge[position] = value;
	}
}

const bool SAT::DPLL::Is_End()
{
	for (typename std::vector<std::vector<int64_t>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<int64_t>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if ((*vec_iterator_second) != ((amount_of_literals)+1) && (*vec_iterator_second) != 0)
			{
				return false;
			}
		}
	}
	return true;
}

SAT::DPLL::DPLL(const std::vector<std::vector<int64_t>>& my_data, const int64_t amount_of_literals):
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
	Change_Row();
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
	Change_Row();
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<int64_t>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<int64_t>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			std::cout << *vec_iterator_second << ' ';
		}
		std::cout << '\n';
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
	std::cout << '\n';
	std::cout << '\n';
}

void SAT::DPLL::SAT_or_UNSAT()
{
	if (Is_End() == false)
	{
		Print_Data();
		Print_Knowledge();
		Create_Tree();
		Find_Unaries();
		Change_Row();
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
		Print_Knowledge();
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
		Change_Row();
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