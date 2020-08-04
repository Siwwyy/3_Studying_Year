#ifndef _SHEEP_HPP_
#define _SHEEP_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Animal.hpp"

namespace Creature
{
	class Sheep :
		public Animal
	{
	private:


	public:
		Sheep();
		Sheep(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator);
		Sheep(const Sheep& Object);


		//virtual void Set_Breed(const std::string& breed);
		//virtual void Set_Is_Predator(const bool is_predator);
		//virtual void Set_Name(const std::string& name);
		//virtual void Set_Pos_X(const int32_t pos_x);
		//virtual void Set_Pos_Y(const int32_t pos_y);


		virtual void Move_Forwards();
		virtual void Move_Backwards();
		virtual void Move_Upwards();
		virtual void Move_Downwards();

		Sheep& operator=(const Sheep& rhs);	

		//virtual const std::string& Get_Breed() const;
		//virtual const bool Get_Is_Predator() const;
		//virtual const std::string& Get_Name() const;
		//virtual const int32_t Get_Pos_X() const;
		//virtual const int32_t Get_Pos_Y() const;

		virtual ~Sheep();
	};
}

#endif /* _SHEEP_HPP_ */