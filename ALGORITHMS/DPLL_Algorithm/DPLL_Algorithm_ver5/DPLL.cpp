#include "DPLL.hpp"

void SAT::DPLL::Find_Unaries()
{
	size_t distance{};
	for (typename std::vector<std::pair<std::reference_wrapper<Literal>, bool>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		//if ((*vec_iterator).size() == 2)
		//{
		//	Add_To_Knowledge((*vec_iterator)[0]);
		//	(*vec_iterator)[0] = ((amount_of_literals)+1);
		//	(*vec_iterator)[1] = ((amount_of_literals)+1);
		//}
		if (vec_iterator->first.get().Get_Value() != 0)
		{
			++distance;
		}
		else
		{
			if (distance == 1)
			{
				vec_iterator->first.get().Set_Status(SAT::Literal::STATUS::TRUE);
			}
			distance = 0;
		}
	}
}

SAT::DPLL::DPLL(const std::vector<std::pair<std::reference_wrapper<Literal>, bool>> my_data, const std::vector< std::reference_wrapper<SAT::Literal>>& Literals,const int64_t amount_of_literals):
	Data(my_data),
	Literals(Literals),
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
	//Change_Row();
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
	//Change_Row();
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::pair<std::reference_wrapper<Literal>, bool>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if (vec_iterator->first.get().Get_Value() == 0)
		{
			std::cout << vec_iterator->first.get().Get_Value() << '\n';
		}
		else
		{
			if (vec_iterator->second == true)
			{
				std::cout << '-' << vec_iterator->first.get().Get_Value() << ' ';
			}
			else
			{
				std::cout << vec_iterator->first.get().Get_Value() << ' ';
			}
		}
	}
	//std::cout << &Data[0].first.get() << '\n';
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

void SAT::DPLL::Print_Literals()
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector< std::reference_wrapper<SAT::Literal>>::const_iterator vec_iterator = this->Literals.begin(); vec_iterator != this->Literals.end(); ++vec_iterator)
	{
		std::cout << vec_iterator->get().Get_Value() << ' ';
	}
	Literals[0].get().Set_Value(1000);
	std::cout << "\n|================================|" << '\n';
}

void SAT::DPLL::SAT_or_UNSAT()
{
	//if (Is_End() == false)
	//{
	//	Print_Data();
	//	Print_Knowledge();
	//	Create_Tree();
	//	Find_Unaries();
	//	Change_Row();
	//	SAT_or_UNSAT();
	//}
	//else
	//{
	//	//GIVE RESULT SAT or UNSAT
	//	//if some of literals arent in Data, you have to explicitly set their value to true
	//	//for example, we have 7 literals given but in data we have from 1 to 5 (6 and 7 are implicit, defaultly set up to true)
	//	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	//	{
	//		if (Knowledge[i] == (this->amount_of_literals + 1))
	//		{
	//			Knowledge[i] = (i + 1);
	//		}
	//	}
	//	Print_Data();
	//	Print_Knowledge();
	//	std::cout << "SATISFIABLE" << '\n';
	//}
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
		//Print_Data();
		//Print_Knowledge();
		//Find_Unaries();
		//Change_Row();
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