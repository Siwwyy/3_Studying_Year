#include "Literal.hpp"

SAT::Literal::Literal() :
	value(0),
	who_visited(0),
	visited(false),
	status(SAT::Literal::STATUS::UNTAGGED)
{

}

SAT::Literal::Literal(const int64_t& value):
	value(value),
	who_visited(0),
	visited(false),
	status(SAT::Literal::STATUS::UNTAGGED)
{
	//if (value < 0)
	//{
	//	status = false;
	//}
}

SAT::Literal::Literal(const Literal& Object) :
	value(Object.value),
	who_visited(Object.who_visited),
	visited(Object.visited),
	status(Object.status)
{

}

void SAT::Literal::Set_Status(const Literal::STATUS status)
{
	this->status = status;
}

void SAT::Literal::Set_Who_Visited(const int64_t who_visited)
{
	this->who_visited = who_visited;
}

void SAT::Literal::Set_Value(const int64_t value)
{
	this->value = value;
}

void SAT::Literal::Set_Visited(const bool visited)
{
	this->visited = visited;
}

const SAT::Literal::STATUS SAT::Literal::Get_Status() const
{
	return this->status;
}

const int64_t SAT::Literal::Get_Value() const
{
	return this->value;
}

const int64_t SAT::Literal::Get_Who_Visited() const
{
	return this->who_visited;
}

const bool SAT::Literal::Get_Visited() const
{
	return this->visited;
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
		this->who_visited = Object.who_visited;
		this->visited = Object.visited;
	}
	return *this;
}

const bool SAT::Literal::operator==(const int64_t& value) const
{
	if (this->value == value || this->value == (-1)*value)
	{
		return true;
	}
	return false;
}

const bool SAT::Literal::operator==(const Literal& Object) const
{
	if (this->value == (-1) * Object.value)
	{
		return true;
	}
	return false;
}

SAT::Literal::~Literal()
{
	this->status = SAT::Literal::STATUS::UNTAGGED;
	this->value = 0;
	this->who_visited = 0;
	this->visited = false;
}