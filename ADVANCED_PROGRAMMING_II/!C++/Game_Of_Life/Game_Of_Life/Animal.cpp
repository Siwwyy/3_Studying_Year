#include "Animal.hpp"

void Creature::Animal::Set_Breed(const std::string& breed)
{
	this->m_breed = breed;
}

void Creature::Animal::Set_Is_Predator(const bool is_predator)
{
	this->m_is_predator = is_predator;
}

const std::string& Creature::Animal::Get_Breed() const
{
	return this->m_breed;
}

const bool Creature::Animal::Get_Is_Predator() const
{
	return this->m_is_predator;
}

void Creature::Animal::Set_Name(const std::string& name)
{
	Creature::Set_Name(name);
}

void Creature::Animal::Set_Pos_X(const int32_t pos_x)
{
	Creature::Set_Pos_X(pos_x);
}

void Creature::Animal::Set_Pos_Y(const int32_t pos_y)
{
	Creature::Set_Pos_Y(pos_y);
}

const std::string& Creature::Animal::Get_Name() const
{
	return Creature::Get_Name();
}

const int32_t Creature::Animal::Get_Pos_X() const
{
	return Creature::Get_Pos_X();
}

const int32_t Creature::Animal::Get_Pos_Y() const
{
	return Creature::Get_Pos_Y();
}

Creature::Animal::Animal() :
	Creature::Creature(),
	m_breed("Dog"),
	m_is_predator(true)
{

}

Creature::Animal::Animal(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator) :
	Creature::Creature(name, pos_x, pos_y),
	m_breed(breed),
	m_is_predator(is_predator)
{

}

Creature::Animal::Animal(const Animal& Object) :
	Creature::Creature(Object),
	m_breed(Object.m_breed),
	m_is_predator(Object.m_is_predator)
{

}

Creature::Animal& Creature::Animal::operator=(const Animal& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		//try 
		//{
		//	this->m_breed = (dynamic_cast<const Animal&>(rhs)).m_breed;
		//	this->m_is_predator = (dynamic_cast<const Animal&>(rhs)).m_is_predator;
		//}
		//catch (std::bad_cast) 
		//{
		//	//
		//}
		this->m_breed = rhs.m_breed;
		this->m_is_predator = rhs.m_is_predator;
	}
	return *this;
}

//bool Creature::Animal::operator==(const Animal& rhs)
//{
//	return Creature::operator==(rhs);
//}
//
//const std::int32_t Creature::Animal::operator()(const Animal& rhs)
//{
//	return Creature::operator()(rhs);
//}

//bool Creature::Animal::operator==(const Animal& rhs)
//{
//	return Creature::operator==(rhs);
//}

Creature::Animal::~Animal()
{
	this->m_breed.clear();
	this->m_is_predator = false;
}