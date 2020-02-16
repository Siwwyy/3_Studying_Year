#include "DPLL.hpp"

SAT::DPLL::DPLL() :
	Data()
{

}

SAT::DPLL::DPLL(const std::vector<int> & my_data):
	Data(my_data)
{

}

SAT::DPLL::DPLL(const DPLL& Object) :
	Data(Object.Data)
{

}

void SAT::DPLL::Print_Object() const
{
	for (typename std::vector<int>::const_iterator vec_iterator = this->Data.begin(); vec_iterator != this->Data.end(); ++vec_iterator)
	{
		std::cout << *vec_iterator << ' ';
		if (*vec_iterator == 0)
		{
			std::cout << '\n';
		}
	}
}

const bool SAT::DPLL::SAT_or_UNSAT()
{
	return false;
}

SAT::DPLL& SAT::DPLL::operator=(const DPLL& Object)
{
	if (this != std::addressof(Object))
	{
		this->Data.clear();
	}
	return *this;
}

SAT::DPLL::~DPLL()
{
	this->Data.clear();
}