#ifndef _LOGIC_HPP_
#define _LOGIC_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
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
		Creature::Animal* m_Wolf;

		volatile bool is_not_end = true;
		std::mutex Wolf_Resources{};
		std::mutex Sheep_Resources{};
		std::random_device rand{};


		std::unordered_set< Creature::Animal*, Creature::Animal_Hash, Creature::Animal_Equal >m_Sheeps;

		void Draw_Objects();
		void Clear_Objects();

		void Key();
		void Move();
		void Add_Sheep();
		void Game_Draw();
		void Game_Logic();
		void Difusion();
		void Collision();

	public:
		Logic() = delete;
		Logic(const int32_t width, const int32_t height);
		Logic(const Logic& Object);

		void Run_Game();

		virtual ~Logic();
	};
}

#endif /* _ENGINE_HPP_ */