#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	//size_t distance{};
	//for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	//{
	//	if (*vec_iterator != 0)
	//	{
	//		++distance;
	//	}
	//	else
	//	{
	//		if (distance == 1)
	//		{
	//			/*
	//				REMOVE FROM DATA VECTOR UNARY VARIABLES
	//			*/
	//			Add_To_Knowledge(*(vec_iterator - 1));
	//			for (typename std::vector<int64_t>::iterator vec_iterator_second = this->Data.begin(); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
	//			{
	//				if (((*(vec_iterator - 1)) * -1) == (*vec_iterator_second))
	//				{
	//					(*vec_iterator_second) = ((amount_of_literals)+1);
	//				}
	//			}
	//			(*(vec_iterator - 1)) = ((amount_of_literals)+1);
	//			(*(vec_iterator)) = ((amount_of_literals)+1);
	//		}
	//		distance = 0;
	//	}
	//}


	for (typename std::vector<std::vector<int64_t>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2)
		{
			Add_To_Knowledge((*vec_iterator)[0]);
			(*vec_iterator)[0] = ((amount_of_literals)+1);
			(*vec_iterator)[1] = ((amount_of_literals)+1);
			//const std::vector<int64_t>::iterator & my_iterator = vec_iterator->begin();
			Erase(vec_iterator);
		}
	}
}

void SAT::DPLL::Erase(const std::vector<std::vector<int64_t>>::iterator& _Where)
{
	//Data.erase(std::remove(this->Data.begin(), this->Data.end(), ((amount_of_literals)+1)), this->Data.end());	//removing unecessary elements
	Data[std::distance(Data.begin(), _Where)].erase(std::remove(_Where->begin(), _Where->end(), ((amount_of_literals)+1)), _Where->end());	//removing unecessary elements
}



//void SAT::DPLL::Erase()
//{
//	std::cout << "PRINTING" << '\n';
//	Print_Data();
//	typename std::vector<int64_t>::iterator zero_position{};
//	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
//	{
//		if (Knowledge[i] != (this->amount_of_literals + 1))
//		{
//			for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
//			{
//				if ((*vec_iterator) == 0 || std::distance(this->Data.begin(), vec_iterator) == 0)
//				{
//					zero_position = vec_iterator;
//				}
//				if ((*vec_iterator) == Knowledge[i])
//				{
//					if (std::distance(Data.begin(), vec_iterator) == 0)
//					{
//						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
//						{
//							if ((*vec_iterator_second) != 0)
//							{
//								Add_To_Knowledge((*vec_iterator_second));
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//							}
//							else
//							{
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//								break;
//							}
//						}
//					}
//					else
//					{
//						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position + 1); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
//						{
//							if ((*vec_iterator_second) != 0)
//							{
//								Add_To_Knowledge((*vec_iterator_second));
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//							}
//							else
//							{
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//								break;
//							}
//						}
//					}
//				}
//				//else if (((*vec_iterator) * -1) == Knowledge[i])
//				//{
//				//	(*vec_iterator) = (this->amount_of_literals + 1);
//				//}
//			}
//		}
//	}
//
//	typename std::vector<int64_t>::iterator zero_position{};
//	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
//	{
//		if (Knowledge[i] != (this->amount_of_literals + 1))
//		{
//			for (typename std::vector<int64_t>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
//			{
//				if ((*vec_iterator) == 0 || std::distance(this->Data.begin(), vec_iterator) == 0)
//				{
//					zero_position = vec_iterator;
//				}
//				if (((*vec_iterator) * -1) == Knowledge[i])
//				{
//					(*vec_iterator) = (this->amount_of_literals + 1);
//				}
//				if ((*vec_iterator) == Knowledge[i])
//				{
//					if (std::distance(Data.begin(), vec_iterator) == 0)
//					{
//						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
//						{
//							if ((*vec_iterator_second) != 0 && (*vec_iterator_second) != (this->amount_of_literals + 1))
//							{
//								Add_To_Knowledge((*vec_iterator_second));
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//							}
//							else
//							{
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//								break;
//							}
//						}
//					}
//					else
//					{
//						for (typename std::vector<int64_t>::iterator vec_iterator_second = (zero_position + 1); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
//						{
//							if ((*vec_iterator_second) != 0 && (*vec_iterator_second) != (this->amount_of_literals + 1))
//							{
//								Add_To_Knowledge((*vec_iterator_second));
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//							}
//							else
//							{
//								(*vec_iterator_second) = (this->amount_of_literals + 1);
//								break;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	Data.erase(std::remove(this->Data.begin(), this->Data.end(), ((amount_of_literals)+1)),this->Data.end());	//removing unecessary elements
//
//	Print_Data();
//	Print_Knowledge();
//	system("pause");
//}

//void SAT::DPLL::Create_Tree()
//{
//	Add_To_Knowledge(Data[0]);
//}

void SAT::DPLL::Add_To_Knowledge(int64_t value)
{
	size_t position{ static_cast<size_t>(value - 1) };
	if (value < 0)
	{
		position = static_cast<size_t>(((value) * - 1) - 1);
	}
	if (position >= 0 && position < amount_of_literals)
	{
		Knowledge[position] = value;
	}
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
	//Print_Data();
	//Print_Knowledge();
	//Find_Unaries();
	//Print_Data();
	//Print_Knowledge();
	//Erase();
	//Print_Data();
	//Print_Knowledge();
	//system("pause");
	Print_Data();
	Find_Unaries();
	Print_Data();
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
	//Print_Data();
	//Print_Knowledge();
	//Find_Unaries();
	//Erase();
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
	if (this->Data.size() > 0)
	{
		//Print_Data();
		//Print_Knowledge();
		//Create_Tree();
		//Find_Unaries();
		//Erase();
		////std::cout << "SIZE " << this->Data.size() << '\n';
		//system("pause");
		//SAT_or_UNSAT();
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
	/*	Erase();*/
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