#ifndef _DRAWING_HPP_
#define _DRAWING_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>

#include "Engine.hpp"

namespace Engine
{
	class Drawing :
		public Engine
	{
	private:
		int32_t m_width;
		int32_t m_height;
		COORD m_coord;

		void Set_Cursor_Position(const SHORT pos_x, const SHORT pos_y);

	public:
		Drawing();
		Drawing(const int32_t width, const int32_t height);
		Drawing(const Drawing& Object);

		void Set_Width(const int32_t width);
		void Set_Height(const int32_t height);

		void Draw_Area();
		void Draw_Object(const int32_t pos_x, const int32_t pos_y, const char sign);
		void Clear_Object(const int32_t pos_x, const int32_t pos_y);
		void Clear_Area() const;

		Drawing& operator=(const Drawing& rhs);

		const int32_t Get_Width() const;
		const int32_t Get_Height() const;

		virtual ~Drawing();
	};
}

#endif /* _DRAWING_HPP_ */