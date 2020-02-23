#include "DPLL.hpp"

const bool SAT::DPLL::Find_Unaries()
{
	/*
	FINDING UNARIES
	Here we have a bunch of cases
	1. If is just a for example 1 0 row. Algorithm will find it immediately
	2. If row is larger but we visited some of values from row for example 1->visited 2->visited 3 ->visitied 4->unvisitied 0 ->unvisited. Algorithm will return a true cause it is a unary
*/
	auto Amount_Of_Unvisited = [&](const std::vector<std::vector<SAT::Literal>>::iterator& _Where) -> size_t	//this case is looking for row where are 2 unvisited values, 0 and other literal for example 1,2,3,4,5 etc. 1 0, 2 0 etc.
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
		if ((*vec_iterator).size() == 2 && (*vec_iterator)[0].Get_Visited() == false)	//case nr1.
		{
			Q.push_back((*vec_iterator)[0].Get_Value());	//add to queue
			(*vec_iterator)[0].Set_Who_Visited((*vec_iterator)[0].Get_Value());
			(*vec_iterator)[0].Set_Visited(true);
			if ((*vec_iterator)[0].Get_Value() < 0)
			{
				(*vec_iterator)[0].Set_Status(SAT::Literal::STATUS::FALSE);
			}
			else
			{
				(*vec_iterator)[0].Set_Status(SAT::Literal::STATUS::TRUE);
			}
			(*vec_iterator)[1].Set_Who_Visited((*vec_iterator)[0].Get_Value());
			(*vec_iterator)[1].Set_Visited(true);
			Mark_Visited(vec_iterator->begin());
			return true;
		}
		else if (Amount_Of_Unvisited(vec_iterator) == 2)	//case nr2.
		{

		}
	}
	return false;
}

const bool SAT::DPLL::Is_End() const
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

void SAT::DPLL::Take_First_Literal()
{
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if (vec_iterator_second->Get_Visited() == false && vec_iterator_second->Get_Value() != 0)
			{
				Q.push_back(vec_iterator_second->Get_Value());
				//think about setting up the status
				Mark_Visited(vec_iterator_second);
			}
		}
	}
}

void SAT::DPLL::Mark_Visited(const std::vector<SAT::Literal>::iterator& _Where)
{
	std::vector<SAT::Literal>::iterator it{};
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		it = std::find(vec_iterator->begin(), vec_iterator->end(), _Where->Get_Value());
		if (it != vec_iterator->end() && it->Get_Visited() == false)
		{
			if (it->Get_Value() > 0)
			{
				if (_Where->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						if (vec_iterator_second->Get_Visited() == false)
						{
							vec_iterator_second->Set_Visited(true);
							vec_iterator_second->Set_Who_Visited(_Where->Get_Value());
						}
					}
				}
				else if (_Where->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					if (it->Get_Visited() == false)
					{
						it->Set_Visited(true);
						it->Set_Who_Visited(_Where->Get_Value());
					}
				}
			}
			else
			{
				if (_Where->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					if (it->Get_Visited() == false)
					{
						it->Set_Visited(true);
						it->Set_Who_Visited(_Where->Get_Value());
					}
				}
				else if (_Where->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						if (vec_iterator_second->Get_Visited() == false)
						{
							vec_iterator_second->Set_Visited(true);
							vec_iterator_second->Set_Who_Visited(_Where->Get_Value());
						}
					}
				}
			}
		}
	}
}

void SAT::DPLL::Set_Status(const std::vector<SAT::Literal>::iterator& _Where)
{
	if (_Where->Get_Status() == SAT::Literal::STATUS::UNTAGGED)
	{
		_Where->status = SAT::Literal::STATUS::TRUE;
	}
	else if (_Where->Get_Status() == SAT::Literal::STATUS::TRUE)
	{
		_Where->status = SAT::Literal::STATUS::FALSE;
	}
	else if (_Where->Get_Status() == SAT::Literal::STATUS::FALSE)
	{
		_Where->status = SAT::Literal::STATUS::TRUE;
	}
}

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
	if (Is_End() == false)
	{
		if (Find_Unaries() == true)
		{
			SAT_or_UNSAT();
		}
		else
		{
			Take_First_Literal();
			SAT_or_UNSAT();
		}
		//{
		//	Mark_As_Visited();
		//	if (Is_Conflict() == true)	//check this function later
		//	{
		//		//Print_Data();
		//		//system("pause");
		//		Backtrack();
		//		//std::cout << '\n' << '\n';
		//		//Print_Data();
		//		//system("pause");
		//	}
		//	SAT_or_UNSAT();
		//}
		//else
		//{
		//	Take_First_Literal();
		//	Mark_As_Visited();
		//	if (Is_Conflict() == true)	//check this function later
		//	{
		//		Backtrack();
		//	}
		//	SAT_or_UNSAT();
		//}
	}
	else
	{
		if (/*Is_unsatisfiable() == */true)
		{
			std::cout << "\nUNSATISFIABLE" << '\n';
		}
		else
		{
			std::cout << "SATISFIABLE" << '\n' << '\n';
			size_t counter{};
			int64_t value{};
			while (Q.empty() == false)
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
				Q.pop_front();
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
			std::cout << "0" << '\n' << '\n';
		}
	}
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