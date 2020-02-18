#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	size_t distance{};
	for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if (*vec_iterator != 0)
		{
			++distance;
		}
		else
		{
			if (distance == 1)
			{
				/*
					REMOVE FROM DATA VECTOR UNARY VARIABLES
				*/
				//size_t position{};
				//if ((*(vec_iterator - 1)) < 0)
				//{
				//	position = static_cast<size_t>(((*(vec_iterator - 1)) * -1) - 1);
				//}
				//Knowledge[position] = (*(vec_iterator - 1));
				Add_To_Knowledge(*(vec_iterator - 1));
				for (typename std::vector<int64_t>::iterator vec_iterator_second = this->Data.begin(); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
				{
					if (((*(vec_iterator - 1)) * -1) == (*vec_iterator_second))
					{
						(*vec_iterator_second) = ((amount_of_literals)+1);
					}
				}
				(*(vec_iterator - 1)) = ((amount_of_literals)+1);
				(*(vec_iterator)) = ((amount_of_literals)+1);
			}
			distance = 0;
		}
	}
}

void SAT::DPLL::Erase_Useful_Variables()
{
	typename std::vector<int64_t>::iterator zero_position{};
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		if (Knowledge[i] != (this->amount_of_literals + 1))
		{
			for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
			{
				if ((*vec_iterator) == 0 || std::distance(this->Data.begin(), vec_iterator) == 0)
				{
					zero_position = vec_iterator;
				}
				if ((*vec_iterator) == Knowledge[i])
				{
					if (std::distance(Data.begin(), vec_iterator) == 0)
					{
						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
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
						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position + 1); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
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
	}
	Data.erase(std::remove(this->Data.begin(), this->Data.end(), ((amount_of_literals)+1)),this->Data.end());	//removing unecessary elements
}

void SAT::DPLL::Create_Tree()
{
	//Add_To_Knowledge(std::move(Data[0] - 1), Data[0]);
	Add_To_Knowledge(Data[0]);
	Data[0] = (this->amount_of_literals + 1);
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
	//Find_Unaries();
	//Erase_Useful_Variables();
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
	std::cout << '\n';
	std::cout << '\n';
}

void SAT::DPLL::SAT_or_UNSAT()
{
	if (this->Data.size() > 0)
	{
		Print_Data();
		Print_Knowledge();
		Create_Tree();
		Find_Unaries();
		Erase_Useful_Variables();
		//std::cout << "SIZE " << this->Data.size() << '\n';
		//system("pause");
		SAT_or_UNSAT();
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
	if (this->Data.size() > 0)
	{
		this->Data.clear();
	}
	//delete[] Knowledge;
	this->amount_of_literals = 0;
	this->Unary_Variables.clear();
}