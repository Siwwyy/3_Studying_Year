#include "Literal.hpp"

SAT::Literal::Literal() :
	value(0),
	status(SAT::Literal::STATUS::UNTAGGED)
{

}

SAT::Literal::Literal(const int64_t& value):
	value(value),
	status(SAT::Literal::STATUS::UNTAGGED)
{
	//if (value < 0)
	//{
	//	status = false;
	//}
}

SAT::Literal::Literal(const Literal& Object) :
	value(Object.value),
	status(Object.status)

{

}

void SAT::Literal::Set_Status(const Literal::STATUS status)
{
	this->status = status;
}

void SAT::Literal::Set_Value(const int64_t value)
{
	this->value = value;
}

const SAT::Literal::STATUS SAT::Literal::Get_Status() const
{
	return Literal::STATUS(this->status);
}

const int64_t SAT::Literal::Get_Value() const
{
	return int64_t(this->value);
}

const SAT::Literal& SAT::Literal::Get_Object() const
{
	return *this;
}

SAT::Literal& SAT::Literal::operator=(const Literal& Object)
{
	if (this != std::addressof(Object))
	{
		this->status = Object.status;
		this->value = Object.value;
	}
	return *this;
}

SAT::Literal::~Literal()
{
	this->status = SAT::Literal::STATUS::UNTAGGED;
	this->value = 0;
}