#include "DPLL.hpp"

const bool SAT::DPLL::Find_Unaries()
{
	/*
		FINDING UNARIES
		Here we have a bunch of cases
		1. If is just a for example 1 0 row. Algorithm will find it immediately
		2. If row is larger but we visited some of values from row for example 1->visited 2->visited 3 ->visitied 4->unvisitied 0 ->unvisited. Algorithm will return a true cause it is a unary
	*/
	auto Amount_Of_Unvisited = [&](const std::vector<std::vector<SAT::Literal>>::iterator & _Where) -> size_t	//this case is looking for row where are 2 unvisited values, 0 and other literal for example 1,2,3,4,5 etc. 1 0, 2 0 etc.
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
			Set_Literal_Status((*vec_iterator)[0].Get_Value());
			(*vec_iterator)[0].Set_Visited(true);	//mark as a visited
			(*vec_iterator)[1].Set_Visited(true);	//mark as a visited
			return true;
		}
		else if (Amount_Of_Unvisited(vec_iterator) == 2)	//case nr2.
		{
			for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
			{
				if (vec_iterator_second->Get_Value() != 0 && vec_iterator_second->Get_Visited() == false)
				{
					Q.push_back(vec_iterator_second->Get_Value());
					Set_Literal_Status(vec_iterator_second->Get_Value());					
				}
				vec_iterator_second->Set_Visited(true);	//mark rest of values as a visitied
			}
			return true;
		}
	}
	return false;
}

const bool SAT::DPLL::Is_Conflict()
{
	/*
		Here we are looking for a conflicts. For example: when we have a 4 0 row and -4 0 row => true != false, two unaries with same literal but with different value
	*/
	auto Amount_Of_Unvisited = [&](const std::vector<std::vector<SAT::Literal>>::const_iterator& _Where) -> size_t
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

	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		if (Amount_Of_Unvisited(vec_iterator) == 2 && (*vec_iterator)[1].Get_Value() != 0)	//if we have 2 unvisited values in a row but different from unary row (it cannot be a unary, unary is a special)
		{
			for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
			{
				if (vec_iterator_second->Get_Value() != 0 && vec_iterator_second->Get_Visited() == false)
				{
					std::vector<SAT::Literal>::const_iterator it{};
					for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator_third = (vec_iterator+1); vec_iterator_third != this->Data.end(); ++vec_iterator_third)
					{
						it = std::find(vec_iterator_third->begin(), vec_iterator_third->end(), *vec_iterator_second);
						if (it != vec_iterator_third->end() && it->Get_Visited() == false && Amount_Of_Unvisited(vec_iterator_third) == 2)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

const bool SAT::DPLL::Is_End()
{
	//Seeking for end, if all of literals are visitied then we have end and result
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

const bool SAT::DPLL::Is_satisfiable()
{
	//If all of literals are visitied and with false status
	for (typename std::vector<std::vector<SAT::Literal>>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			/*
				vec_iterator_second->Get_Status() != SAT::Literal::STATUS::FALSE
				This means that we estimated with both states (true of false) each value. If is still unsatisfiable, we will receive information about it
			*/
			if (vec_iterator_second->Get_Status() != SAT::Literal::STATUS::FALSE && vec_iterator_second->Get_Value() != 0)
			{
				return false;
			}
		}
	}
	return true;
}

void SAT::DPLL::Mark_As_Visited()
{
	/*
		Marking as visitied
		Ealier, We added a literal to queue, now we are forced to mark literals as a visitied for example. We added to queue literal 1 and set up status to True.
		In rows where is a 1 we have to mark whole row as a visited, in rows where is -1 we mark only -1 as a visited
	*/
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
	//If unary variable isint exist, we have to take first possible literal and push it into queue
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			if (vec_iterator_second->Get_Visited() == false && vec_iterator_second->Get_Value() != 0)
			{
				Set_Literal_Status(vec_iterator_second->Get_Value());
				if (vec_iterator_second->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					if (vec_iterator_second->Get_Value() < 0)
					{
						Q.push_back((-1) * vec_iterator_second->Get_Value());
					}
					else
					{
						Q.push_back(vec_iterator_second->Get_Value());
					}
				}
				else if (vec_iterator_second->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					if (vec_iterator_second->Get_Value() < 0)
					{
						Q.push_back(vec_iterator_second->Get_Value());
					}
					else
					{
						Q.push_back((-1) * vec_iterator_second->Get_Value());
					}
				}
				return;
			}
		}
	}
}

void SAT::DPLL::Backtrack()
{
	//If we encountered a conflict, we are forced to change status to opposite site for example, we had literal 1 with true status and now we are chaning it into false and checking corectness again
	//In this function we are going backwards, removing last added element from queue and in rows where him exists, we mark literals to unvisited state. For example
	//We hava to pop back literal 1, if is true and literal is 1 then unvisit whole row, where is -1 (with true state) unvisit only -1. This have the same behavior with false state but only -1 with false gives 1
	std::vector<SAT::Literal>::iterator it{};
	int64_t value{ Q.back() };
	Q.pop_back();
	for (typename std::vector<std::vector<SAT::Literal>>::iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		it = std::find(vec_iterator->begin(), vec_iterator->end(), value);
		if (it != vec_iterator->end() && it->Get_Status() != SAT::Literal::STATUS::UNTAGGED)
		{
			if (it->Get_Value() > 0)
			{
				if (it->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						vec_iterator_second->Set_Visited(false);
					}
				}
				else if (it->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					it->Set_Visited(false);
				}
			}
			else
			{
				if (it->Get_Status() == SAT::Literal::STATUS::TRUE)
				{
					it->Set_Visited(false);
				}
				else if (it->Get_Status() == SAT::Literal::STATUS::FALSE)
				{
					for (typename std::vector<SAT::Literal>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
					{
						vec_iterator_second->Set_Visited(false);
					}
				}
			}
		}
	}
}

void SAT::DPLL::Set_Literal_Status(const int64_t value)
{
	//Here we set up a state to each literal equal to our value
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
			//if (it->Get_Status() == SAT::Literal::STATUS::UNTAGGED)
			//{
			//	it->status = SAT::Literal::STATUS::FALSE;
			//}
			//else if (it->Get_Status() == SAT::Literal::STATUS::FALSE)
			//{
			//	it->status = SAT::Literal::STATUS::TRUE;
			//}
		}
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
		//Print_Data();
		if (Is_Conflict() == false)	//check this function later
		{
		
			//system("pause");
			if (Find_Unaries() == true)
			{
				Mark_As_Visited();
				//Print_Data();
				//std::cout << "\n Unary\n";
				//std::cout << "===========================================\n";
				//system("pause");
				//std::cout << "\n\n";
				SAT_or_UNSAT();
			}
			else
			{
				Take_First_Literal();
				Mark_As_Visited();
			//	Print_Data();
				//std::cout << "\n Took first literal\n";
				//std::cout << "===========================================\n";
				//system("pause");
				//std::cout << "\n\n";
				SAT_or_UNSAT();
			}
		}
		else
		{
			//backtrack
			//remember to check is USATISFIABLE, if everything status == false then print unsatisfiable
			Backtrack();
			//Print_Data();
			//std::cout << "\n Going backwards\n";
			//std::cout << "===========================================\n";
		//	system("pause");
			//std::cout << "\n\n";
			SAT_or_UNSAT();
		}
	}
	else
	{
		if (Is_satisfiable() == false)
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