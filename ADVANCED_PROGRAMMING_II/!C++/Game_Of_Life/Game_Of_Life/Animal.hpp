#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Creature.hpp"

namespace Creature
{

	


	class Animal :
		public Creature
	{
	protected:
		std::string m_breed;
		bool m_is_predator;

		virtual ~Animal();
	public:
		virtual void Set_Breed(const std::string& breed);
		virtual void Set_Is_Predator(const bool is_predator);

		virtual const std::string& Get_Breed() const;
		virtual const bool Get_Is_Predator() const;

		virtual void Set_Name(const std::string& name);
		virtual void Set_Pos_X(const int32_t pos_x);
		virtual void Set_Pos_Y(const int32_t pos_y);

		virtual const std::string& Get_Name() const;
		virtual const int32_t Get_Pos_X() const;
		virtual const int32_t Get_Pos_Y() const;

		Animal();
		Animal(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator);
		Animal(const Animal& Object);

		virtual void Move_Forwards() = 0;
		virtual void Move_Backwards() = 0;
		virtual void Move_Upwards() = 0;
		virtual void Move_Downwards() = 0;

		Animal& operator=(const Animal& rhs);
	};

	struct Animal_Hash
	{
		const std::size_t operator()(const Animal* ptr) const
		{
			return ptr->Get_Pos_X();
		}
	};

	struct Animal_Equal
	{
		bool operator()(const Animal* lhs, const Animal* rhs) const
		{
			if (lhs->Get_Pos_X() == rhs->Get_Pos_X() && lhs->Get_Pos_Y() == rhs->Get_Pos_Y())
			{
				return true;
			}
			return false;
		}
	};

}

#endif /* _ANIMAL_HPP_ */