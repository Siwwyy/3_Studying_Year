#include "DPLL.hpp"

const bool SAT::DPLL::Find_Unaries()
{
	auto Amount_Of_Unvisited = [&](const std::vector<std::vector<SAT::Literal>>::iterator & _Where) -> size_t
	{
		size_t size{};
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator = _Where->begin(); vec_iterator != _Where->end(); ++vec_iterator)
		{
			if (vec_iterator->Get_Visited() == false)
			{
				++size;
			}
		}
		return size;
	};

	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if ((*vec_iterator).size() == 2 && (*vec_iterator)[0].Get_Visited() == false)
		{
			Q.push((*vec_iterator)[0].Get_Value());
			Set_Literal_Status((*vec_iterator)[0].Get_Value());
			(*vec_iterator)[0].Set_Visited(true);
			(*vec_iterator)[1].Set_Visited(true);
			return true;
		}
		else if (Amount_Of_Unvisited(vec_iterator) == 2)
		{
			for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
			{
				if (vec_iterator_second->Get_Value() != 0 && vec_iterator_second->Get_Visited() == false)
				{
					Q.push(vec_iterator_second->Get_Value());
					Set_Literal_Status(vec_iterator_second->Get_Value());					
				}
				vec_iterator_second->Set_Visited(true);
			}
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

const bool SAT::DPLL::Is_Unsatisfiable() const
{
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if (vec_iterator_second->Get_Status() != SAT::Literal::STATUS::FALSE && vec_iterator_second->Get_Value() != 0)
			{
				//std::cout << "Algos sie jebnal\n";
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
		it = std::find(vec_iterator->begin(), vec_iterator->end(), Q.back());
		if (it != vec_iterator->end() && it->Get_Visited() == false)
		{
			if (it->Get_Value() > 0)
			{
				if (it->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						vec_iterator_second->Set_Visited(true);
					}
				}
				else if (it->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					it->Set_Visited(true);
				}
			}
			else
			{
				if (it->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					it->Set_Visited(true);
				}
				else if (it->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						vec_iterator_second->Set_Visited(true);
					}
				}
			}
		}
	}
}

void SAT::DPLL::Take_First_Literal()
{
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if (vec_iterator_second->Get_Visited() == false && vec_iterator_second->Get_Value() != 0)
			{
				Q.push(vec_iterator_second->Get_Value());
				Set_Literal_Status(vec_iterator_second->Get_Value());
				return;
			}
		}
	}
}

void SAT::DPLL::Set_Literal_Status(const int64_t value)
{
	std::vector<SAT::Literal>::iterator it{};
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		it = std::find(vec_iterator->begin(), vec_iterator->end(), value);
		if (it != vec_iterator->end() && it->Get_Visited() == false)
		{
			if (it->Get_Status() == SAT::Literal::STATUS::UNTAGGED)
			{
				it->status = SAT::Literal::STATUS::TRUE;
			}
			else if (it->Get_Status() == SAT::Literal::STATUS::TRUE)
			{
				it->status = SAT::Literal::STATUS::FALSE;
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
			//std::cout << vec_iterator_second->Get_Value() << ' ' << static_cast<int32_t>(vec_iterator_second->Get_Status()) << ' ' << std::boolalpha << vec_iterator_second->Get_Visited() << " | ";
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
				//Print_Data();
				//system("pause");
				SAT_or_UNSAT();
			}
			else
			{
				Take_First_Literal();
				Mark_As_Visited();
				//Print_Data();
				//system("pause");
				//system("pause");
				SAT_or_UNSAT();
			}
		}
		else
		{
			//backtrack
			//remember to check is USATISFIABLE, if everything status == false then print unsatisfiable
		}
	}
	else if (Is_Unsatisfiable() == true)
	{
		std::cout << "\nUNSATISFIABLE" << '\n';
	}
	else
	{
		size_t counter{};
		int64_t value{};
		while(Q.empty() == false)
		{
			value = Q.front();
			if (value < 0)
			{
				counter = static_cast<size_t>((value * (-1)) - 1);
			}
			else
			{
				counter = static_cast<size_t>(value - 1);
			}
			Knowledge[counter] = value;
			Q.pop();
			value = {};
		}
		for (size_t i = 0; i < static_cast<size_t>(this->amount_of_literals); ++i)
		{
			if (Knowledge[i] == (this->amount_of_literals + 1))
			{
				std::cout << (i + 1) << ' ';
			}
			else
			{
				std::cout << Knowledge[i] << ' ';
			}
		}
		std::cout << "\nSATISFIABLE" << '\n';
	}
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