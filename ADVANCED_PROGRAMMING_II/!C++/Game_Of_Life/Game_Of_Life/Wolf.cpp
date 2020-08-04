#include "Wolf.hpp"

Creature::Wolf::Wolf() :
	Animal()
{

}

Creature::Wolf::Wolf(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator) : Animal(name, pos_x, pos_y, breed, is_predator)
{

}

Creature::Wolf::Wolf(const Wolf& Object):
	Animal(Object)
{

}

//void Creature::Wolf::Set_Breed(const std::string& breed)
//{
//	Animal::Set_Breed(breed);
//}
//
//void Creature::Wolf::Set_Is_Predator(const bool is_predator)
//{
//	Animal::Set_Is_Predator(is_predator);
//}
//
//void Creature::Wolf::Set_Name(const std::string& name)
//{
//	Creature::Set_Name(name);
//}
//
//void Creature::Wolf::Set_Pos_X(const int32_t pos_x)
//{
//	Creature::Set_Pos_X(pos_x);
//}
//
//void Creature::Wolf::Set_Pos_Y(const int32_t pos_y)
//{
//	Creature::Set_Pos_Y(pos_y);
//}

void Creature::Wolf::Move_Forwards()
{
	this->m_pos_x++;
}

void Creature::Wolf::Move_Backwards()
{
	this->m_pos_x--;
}

void Creature::Wolf::Move_Upwards()
{
	this->m_pos_y++;
}

void Creature::Wolf::Move_Downwards()
{
	this->m_pos_y--;
}

Creature::Wolf& Creature::Wolf::operator=(const Wolf& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		Animal::operator=(dynamic_cast<const Animal&>(rhs));
		//add wolf statements
	}
	return *this;
}

//const std::string& Creature::Wolf::Get_Breed() const
//{
//	return Animal::Get_Breed();
//}
//
//const bool Creature::Wolf::Get_Is_Predator() const
//{
//	return Animal::Get_Is_Predator();
//}
//
//const std::string& Creature::Wolf::Get_Name() const
//{
//	return Creature::Get_Name();
//}
//
//const int32_t Creature::Wolf::Get_Pos_X() const
//{
//	return Creature::Get_Pos_X();
//}
//
//const int32_t Creature::Wolf::Get_Pos_Y() const
//{
//	return Creature::Get_Pos_Y();
//}

Creature::Wolf::~Wolf()
{

}