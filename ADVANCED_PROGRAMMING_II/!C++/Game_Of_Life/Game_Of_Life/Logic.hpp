#ifndef _LOGIC_HPP_
#define _LOGIC_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_set>
#include <algorithm>
#include <thread>
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

		volatile bool is_not_end = true;
		//std::unordered_set<std::unique_ptr<Creature::Sheep*>> Sheeps;
		std::vector<Creature::Animal*> Sheeps;

		void Draw_Objects();
		void Clear_Objects();
		
		void Key();
		void Game();

	public:
		Logic() = delete;
		Logic(const int32_t width, const int32_t height);
		Logic(const Logic & Object);

		void Run_Game();

		virtual ~Logic();
	};
}

#endif /* _ENGINE_HPP_ */