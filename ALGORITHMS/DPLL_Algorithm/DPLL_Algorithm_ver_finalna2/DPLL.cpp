#include "DPLL.hpp"

SAT::DPLL::DPLL(const std::vector<std::vector<SAT::Literal>>& my_data, const int64_t amount_of_literals):
	Data(my_data),
	Q(),
	amount_of_literals(amount_of_literals)
{
	this->Knowledge = new int64_t[this->amount_of_literals];
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		Knowledge[i] = (this->amount_of_literals + 1);//default value means that there is not a value inside
	}
	//Print_Data();
	//system("pause");
	//std::cout << "\n\n";
}

SAT::DPLL::DPLL(const DPLL& Object) :
	Data(Object.Data),
	Q(Object.Q),
	amount_of_literals(Object.amount_of_literals)
{
	this->Knowledge = new int64_t[this->amount_of_literals];
	for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	{
		Knowledge[i] = (this->amount_of_literals + 1);//default value means that there is not a value inside
	}
}

void SAT::DPLL::Print_Data() const
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			//std::cout << vec_iterator_second->Get_Value() << ' ' << std::boolalpha << vec_iterator_second->Get_Visited() << " | ";
			if (vec_iterator_second->Get_Visited() == false)
			{
				std::cout << vec_iterator_second->Get_Value() << ' ' << std::boolalpha << vec_iterator_second->Get_Visited() << " | ";
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

void SAT::DPLL::SAT_or_UNSAT()
{
	//if (Is_End() == false)
	//{
	//	if (Find_Unaries() == true)
	//	{
	//		Mark_As_Visited();
	//		if (Is_Conflict() == true)	//check this function later
	//		{
	//			//Print_Data();
	//			//system("pause");
	//			Backtrack();
	//			//std::cout << '\n' << '\n';
	//			//Print_Data();
	//			//system("pause");
	//		}
	//		SAT_or_UNSAT();
	//	}
	//	else
	//	{
	//		Take_First_Literal();
	//		Mark_As_Visited();
	//		if (Is_Conflict() == true)	//check this function later
	//		{
	//			Backtrack();
	//		}
	//		SAT_or_UNSAT();
	//	}
	//}
	//else
	//{
	//	if (Is_unsatisfiable() == true)
	//	{
	//		std::cout << "\nUNSATISFIABLE" << '\n';
	//	}
	//	else
	//	{
	//		std::cout << "SATISFIABLE" << '\n' << '\n';
	//		size_t counter{};
	//		int64_t value{};
	//		while (Q.empty() == false)
	//		{
	//			value = Q.front();
	//			if (value < 0)
	//			{
	//				counter = static_cast<size_t>((value * (-1)) - 1);
	//			}
	//			else
	//			{
	//				counter = static_cast<size_t>(value - 1);
	//			}
	//			Knowledge[counter] = value;
	//			Q.pop_front();
	//			value = {};
	//		}
	//		for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
	//		{
	//			if (Knowledge[i] == (this->amount_of_literals + 1))
	//			{
	//				std::cout << (i + 1) << ' ';
	//			}
	//			else
	//			{
	//				std::cout << Knowledge[i] << ' ';
	//			}
	//		}
	//		std::cout << "0" << '\n' << '\n';
	//	}
	//}
}

SAT::DPLL& SAT::DPLL::operator=(const DPLL& Object)
{
	if (this != std::addressof(Object))
	{
		delete[] this->Knowledge;
		this->Data.clear();
		this->Q.clear();
		this->Data = Object.Data;
		this->Q = Object.Q;
		this->amount_of_literals = Object.amount_of_literals;
		this->Knowledge = new int64_t[this->amount_of_literals];
		for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
		{
			Knowledge[i] = (this->amount_of_literals + 1);	//default value means that there is not a value inside
		}
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
	this->Q.clear();
}

/*
//Print_Data();
		//system("pause");
		//if (Is_Conflict() == false)	//check this function later
		//{
		//	//system("pause");
		//	if (Find_Unaries() == true)
		//	{
		//		Mark_As_Visited();
		//		//Print_Data();
		//		//std::cout << "\n Unary\n";
		//		//std::cout << "===========================================\n";
		//		//system("pause");
		//		//std::cout << "\n\n";
		//		SAT_or_UNSAT();
		//	}
		//	else
		//	{
		//		Take_First_Literal();
		//		Mark_As_Visited();
		//	//	Print_Data();
		//		//std::cout << "\n Took first literal\n";
		//		//std::cout << "===========================================\n";
		//		//system("pause");
		//		//std::cout << "\n\n";
		//		SAT_or_UNSAT();
		//	}
		//}
		//else
		//{
		//	//backtrack
		//	//remember to check is USATISFIABLE, if everything status == false then print unsatisfiable
		//	Backtrack();
		//	//Print_Data();
		//	//std::cout << "\n Going backwards\n";
		//	//std::cout << "===========================================\n";
		//	//system("pause");
		//	//std::cout << "\n\n";
		//	SAT_or_UNSAT();
		//}
*/