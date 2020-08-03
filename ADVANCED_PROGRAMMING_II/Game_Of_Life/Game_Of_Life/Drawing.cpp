#include "Drawing.hpp"

void Engine::Drawing::Set_Cursor_Position(const SHORT pos_x, const SHORT pos_y)
{
	this->m_coord.X = pos_x;
	this->m_coord.Y = pos_y;
	SetConsoleCursorPosition(this->Get_HNDL_out(), this->m_coord);
}

Engine::Drawing::Drawing() :
	Engine::Engine(),
	m_width(50),
	m_height(50),
	m_coord({ 0,0 })
{

}

Engine::Drawing::Drawing(const int32_t width, const int32_t height) :
	Engine::Engine(),
	m_width(width),
	m_height(height),
	m_coord({ 0,0 })
{

}

Engine::Drawing::Drawing(const Drawing& Object) :
	Engine::Engine(Object),
	m_width(Object.m_width),
	m_height(Object.m_height),
	m_coord(Object.m_coord)
{

}

void Engine::Drawing::Set_Width(const int32_t width)
{
	this->m_width = width;
}

void Engine::Drawing::Set_Height(const int32_t height)
{
	this->m_height = height;
}

void Engine::Drawing::Draw_Area()
{
	for (size_t i = 0; i < static_cast<size_t>(this->m_height); ++i)
	{
		for (size_t j = 0; j < static_cast<size_t>(this->m_width); ++j)
		{
			Set_Cursor_Position(static_cast<SHORT>(j), static_cast<SHORT>(i));
			std::cout << "*";
		}
	}
}

void Engine::Drawing::Draw_Object(const int32_t pos_x, const int32_t pos_y, const char sign)
{
	if ((pos_x >= 0 && pos_x < this->m_width) && (pos_y >= 0 && pos_y < this->m_height))
	{
		Set_Cursor_Position(static_cast<SHORT>(pos_x), static_cast<SHORT>(pos_y));
		std::cout << sign;
	}
}

void Engine::Drawing::Clear_Object(const int32_t pos_x, const int32_t pos_y)
{
	if ((pos_x >= 0 && pos_x < this->m_width) && (pos_y >= 0 && pos_y < this->m_height))
	{
		Set_Cursor_Position(static_cast<SHORT>(pos_x), static_cast<SHORT>(pos_y));
		std::cout << ' ';
	}
}

void Engine::Drawing::Clear_Area() const
{
	system("cls");
}

Engine::Drawing& Engine::Drawing::operator=(const Drawing& rhs)
{
	if (this != std::addressof(rhs))
	{
		Engine::Engine::operator=(rhs);
		this->m_width = rhs.m_width;
		this->m_height = rhs.m_height;
		this->m_coord = rhs.m_coord;
	}
	return *this;
}

const int32_t Engine::Drawing::Get_Width() const
{
	return this->m_width;
}

const int32_t Engine::Drawing::Get_Height() const
{
	return this->m_height;
}

Engine::Drawing::~Drawing()
{
	this->m_width = 0;
	this->m_height = 0;
	this->m_coord = {};
	system("cls");
}