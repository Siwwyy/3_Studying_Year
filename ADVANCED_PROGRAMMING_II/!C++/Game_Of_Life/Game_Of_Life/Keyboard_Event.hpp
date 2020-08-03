#ifndef _KEYBOARD_EVENT_HPP_
#define _KEYBOARD_EVENT_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Engine.hpp"

namespace Engine
{
	class Keyboard_Event :
		public Engine
	{
	private:
		KEY_EVENT_RECORD m_key;

		bool KeyEvent(KEY_EVENT_RECORD& krec, HANDLE hndl_in);

	public:
		enum class Keys
		{
			W = 0x57,
			S = 0x53,
			A = 0x41,
			D = 0x44,
			ESC = VK_ESCAPE
		};

		Keyboard_Event();
		Keyboard_Event(const Keyboard_Event& Object);

		bool Detect_Key(const enum class Keyboard_Event::Keys key);

		Keyboard_Event& operator=(const Keyboard_Event& rhs);

		virtual ~Keyboard_Event();
	};
}

#endif /* _KEYBOARD_EVENT_HPP_ */