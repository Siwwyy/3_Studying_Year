#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

namespace Creature
{
	
	class Creature
	{
	protected:
		std::string m_name;
		int32_t m_pos_x;
		int32_t m_pos_y;

		virtual void Set_Name(const std::string& name);
		virtual void Set_Pos_X(const int32_t pos_x);
		virtual void Set_Pos_Y(const int32_t pos_y);

		virtual const std::string& Get_Name() const;
		virtual const int32_t Get_Pos_X() const;
		virtual const int32_t Get_Pos_Y() const;

		Creature();
		Creature(const std::string& name);
		Creature(const std::string& name, const int32_t pos_x, const int32_t pos_y);
		Creature(const Creature& Object);

		virtual void Move_Forwards() = 0;
		virtual void Move_Backwards() = 0;
		virtual void Move_Upwards() = 0;
		virtual void Move_Downwards() = 0;

		Creature& operator=(const Creature& rhs);
		//virtual bool operator==(const Creature& rhs);
		//virtual const std::int32_t operator()(const Creature& rhs);

		virtual ~Creature();
	};

}

#endif /* _CREATURE_HPP_ */