#include "Sheep.hpp"

Creature::Sheep::Sheep() :
	Animal()
{

}

Creature::Sheep::Sheep(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator) : Animal(name, pos_x, pos_y, breed, is_predator)
{

}

Creature::Sheep::Sheep(const Sheep& Object) :
	Animal(Object)
{

}

void Creature::Sheep::Set_Breed(const std::string& breed)
{
	Animal::Set_Breed(breed);
}

void Creature::Sheep::Set_Is_Predator(const bool is_predator)
{
	Animal::Set_Is_Predator(is_predator);
}

void Creature::Sheep::Set_Name(const std::string& name)
{
	Creature::Set_Name(name);
}

void Creature::Sheep::Set_Pos_X(const int32_t pos_x)
{
	Creature::Set_Pos_X(pos_x);
}

void Creature::Sheep::Set_Pos_Y(const int32_t pos_y)
{
	Creature::Set_Pos_Y(pos_y);
}

void Creature::Sheep::Move_Forwards()
{
	this->m_pos_x++;
}

void Creature::Sheep::Move_Backwards()
{
	this->m_pos_x--;
}

void Creature::Sheep::Move_Upwards()
{
	this->m_pos_y++;
}

void Creature::Sheep::Move_Downwards()
{
	this->m_pos_y--;
}

Creature::Sheep& Creature::Sheep::operator=(const Sheep& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		Animal::operator=(dynamic_cast<const Animal&>(rhs));
		//add sheep statements
	}
	return *this;
}

//bool Creature::Sheep::operator==(const Sheep& rhs)
//{
//	return Animal::operator==(rhs);
//}
//
//const std::int32_t Creature::Sheep::operator()(const Sheep& rhs)
//{
//	return Animal::operator()(rhs);
//}

//bool Creature::Sheep::operator==(const Sheep& rhs) const
//{
//	if (this->m_pos_x == rhs.m_pos_x && this->m_pos_y == rhs.m_pos_y)
//	{
//		return true;
//	}
//	return false;
//}

//bool Creature::Sheep::operator!=(const Sheep& rhs)
//{
//	if (this->m_pos_x != rhs.m_pos_x && this->m_pos_y != rhs.m_pos_y)
//	{
//		return true;
//	}
//	return false;
//}

const std::string& Creature::Sheep::Get_Breed() const
{
	return Animal::Get_Breed();
}

const bool Creature::Sheep::Get_Is_Predator() const
{
	return Animal::Get_Is_Predator();
}

const std::string& Creature::Sheep::Get_Name() const
{
	return Creature::Get_Name();
}

const int32_t Creature::Sheep::Get_Pos_X() const
{
	return Creature::Get_Pos_X();
}

const int32_t Creature::Sheep::Get_Pos_Y() const
{
	return Creature::Get_Pos_Y();
}

Creature::Sheep::~Sheep()
{

}

//bool Creature::operator==(const Sheep& lhs, const Sheep& rhs)
//{
//	if (lhs.m_pos_x == rhs.m_pos_x && lhs.m_pos_y == rhs.m_pos_y)
//	{
//		return true;
//	}
//	return false;
//}

//bool Creature::operator==(const Sheep& lhs, const Sheep& rhs)
//{
//	if (lhs.m_pos_x == rhs.m_pos_x && lhs.m_pos_y == rhs.m_pos_y)
//	{
//		return true;
//	}
//	return false;
//}
