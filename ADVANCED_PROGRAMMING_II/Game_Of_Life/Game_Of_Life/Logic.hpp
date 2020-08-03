#ifndef _LOGIC_HPP_
#define _LOGIC_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <windows.h>

#include "Sheep.hpp"
#include "Wolf.hpp"
#include "Keyboard_Event.hpp"
#include "Drawing.hpp"

namespace Engine
{
	class Logic
	{
	private:
		Drawing Draw;
		Keyboard_Event Key_Event;

		//std::unordered_set<std::unique_ptr<Creature::Sheep*>> Sheeps;
		std::vector<Creature::Sheep> Sheeps;

		

	public:
		Logic() = delete;
		Logic(const int32_t width, const int32_t height);
		Logic(const Logic & Object);

		void Run_Game();

		virtual ~Logic();
	};
}

#endif /* _ENGINE_HPP_ */