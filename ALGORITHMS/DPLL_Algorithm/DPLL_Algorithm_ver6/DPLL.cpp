#include "DPLL.hpp"

const bool SAT::DPLL::Find_Unaries()
{
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2 && (*vec_iterator)[0].Get_Visited() == false)
		{
			Q.push((*vec_iterator)[0].Get_Value());
			(*vec_iterator)[0].Set_Visited(true);
			(*vec_iterator)[0].Set_Status(SAT::Literal::STATUS::TRUE);
			(*vec_iterator)[1].Set_Visited(true);
			return true;
		}
	}
	return false;
}

const bool SAT::DPLL::Is_Conflict()
{
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2 && (*vec_iterator)[0].Get_Visited() == false)
		{
			for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator_second = this->Data.begin(); vec_iterator_second != this->Data.end(); ++vec_iterator_second)
			{
				//if ((*vec_iterator)[0].Get_Value() == (-1)*(*vec_iterator_second)[0].Get_Value() && (*vec_iterator_second)[0].Get_Visited() == false)
				//{
				//	return true;
				//}
				if ((*vec_iterator_second).size() == 2 && (*vec_iterator_second)[0].Get_Visited() == false)
				{
					if ((*vec_iterator)[0].Get_Value() == (-1) * (*vec_iterator_second)[0].Get_Value())
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

const bool SAT::DPLL::Is_End()
{
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if (vec_iterator_second->Get_Visited() == false)
			{
				return false;
			}
		}
	}
	return true;
}

void SAT::DPLL::Mark_As_Visited()
{
	std::vector<SAT::Literal>::iterator it{};
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		it = std::find(vec_iterator->begin(), vec_iterator->end(), Q.front());
		if (it != vec_iterator->end() && it->Get_Visited() == false)
		{
			if (it->Get_Value() > 0)
			{
				for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
				{
					vec_iterator_second->Set_Visited(true);
				}
			}
			else
			{
				it->Set_Visited(true);
			}
		}
	}
}

SAT::DPLL::DPLL(const std::vector<std::vector<SAT::Literal>>& my_data, const int64_t amount_of_literals):
	Data(my_data),
	Q(),
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
}

SAT::DPLL::DPLL(const DPLL& Object) :
	Data(Object.Data),
	Q(Object.Q),
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
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			std::cout << vec_iterator_second->Get_Value() << ' ' << std::boolalpha << vec_iterator_second->Get_Visited() << " | ";
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
		if (Is_Conflict() == false)
		{
			if (Find_Unaries() == true)
			{
				Mark_As_Visited();
				Print_Data();
			}
			else
			{

			}
		}
		else
		{
			//backtrack
		}
	}
	else
	{
		//Give the result
	}
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
		this->Q.empty();
		this->Unary_Variables.clear();
		this->Data = Object.Data;
		this->Q = Object.Q;
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
	this->Q.empty();
}