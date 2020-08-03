#include "Engine.hpp"

Engine::Engine::Engine():
	m_hndl_in(GetStdHandle(STD_INPUT_HANDLE)),
	m_hndl_out(GetStdHandle(STD_OUTPUT_HANDLE))
{

}

Engine::Engine::Engine(const Engine& Object):
	m_hndl_in(Object.m_hndl_in),
	m_hndl_out(Object.m_hndl_out)
{

}

void Engine::Engine::Set_HNDL_in(const HANDLE& hndl_in)
{
	this->m_hndl_in = hndl_in;
}

void Engine::Engine::Set_HNDL_out(const HANDLE& hndl_out)
{
	this->m_hndl_out = hndl_out;
}

Engine::Engine& Engine::Engine::operator=(const Engine& rhs)
{
	if (this != std::addressof(rhs))
	{
		this->m_hndl_in = rhs.m_hndl_in;
		this->m_hndl_out = rhs.m_hndl_out;
	}
	return *this;
}

const HANDLE& Engine::Engine::Get_HNDL_in() const
{
	return this->m_hndl_in;
}

const HANDLE& Engine::Engine::Get_HNDL_out() const
{
	return this->m_hndl_out;
}

Engine::Engine::~Engine()
{
	this->m_hndl_in = NULL;
	this->m_hndl_out = NULL;
}