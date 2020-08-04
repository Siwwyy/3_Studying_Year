#ifndef _WOLF_HPP_
#define _WOLF_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Animal.hpp"

namespace Creature
{
	class Wolf :
		public Animal
	{
	private:

	public:
		Wolf();
		Wolf(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator);
		Wolf(const Wolf& Object);


		//virtual void Set_Breed(const std::string& breed);
		//virtual void Set_Is_Predator(const bool is_predator);
		//virtual void Set_Name(const std::string& name);
		//virtual void Set_Pos_X(const int32_t pos_x);
		//virtual void Set_Pos_Y(const int32_t pos_y);


		virtual void Move_Forwards();
		virtual void Move_Backwards();
		virtual void Move_Upwards();
		virtual void Move_Downwards();

		Wolf& operator=(const Wolf& rhs);

		//virtual const std::string& Get_Breed() const;
		//virtual const bool Get_Is_Predator() const;
		//virtual const std::string& Get_Name() const;
		//virtual const int32_t Get_Pos_X() const;
		//virtual const int32_t Get_Pos_Y() const;

		virtual ~Wolf();
	};
}

#endif /* _WOLF_HPP_ */