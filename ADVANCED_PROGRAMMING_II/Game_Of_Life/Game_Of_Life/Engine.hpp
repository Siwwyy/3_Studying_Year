#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_
#pragma once

#include <string>
#include <iostream>
#include <cstdint>
#include <windows.h>


namespace Engine
{
	class Engine
	{
	protected:
		HANDLE m_hndl_in;
		HANDLE m_hndl_out;

		Engine();
		Engine(const Engine& Object);

		void Set_HNDL_in(const HANDLE& hndl_in);
		void Set_HNDL_out(const HANDLE& hndl_out);

		Engine& operator=(const Engine& rhs);

		const HANDLE& Get_HNDL_in() const;
		const HANDLE& Get_HNDL_out() const;

		virtual ~Engine();
	};
}

#endif /* _ENGINE_HPP_ */