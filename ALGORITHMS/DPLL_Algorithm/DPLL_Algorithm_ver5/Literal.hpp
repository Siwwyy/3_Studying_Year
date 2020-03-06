#ifndef _LITERAL_HPP_
#define _LITERAL_HPP_
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cstdint>
#include <functional>

namespace SAT
{
	class Literal
	{
	private:

		/*
			PRIVATE VARIABLES
		*/
		//STATUS status;
		int64_t value;
		///////////////////////////////////////////////
	public:
		enum class STATUS
		{
			TRUE,
			FALSE,
			UNTAGGED
		}status;
		/*
			PUBLIC CONSTRUCTORS
		*/
		Literal();
		Literal(const int64_t & value);
		Literal(const Literal& Object);
		///////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/

		///////////////////////////////////////////////
		/*
			PUBLIC SETTERS
		*/
		void Set_Status(const Literal::STATUS status);
		void Set_Value(const int64_t value);
		///////////////////////////////////////////////
		/*
			PUBLIC GETTERS
		*/
		const Literal::STATUS Get_Status() const;
		const int64_t Get_Value() const;
		const Literal & Get_Object() const;
		///////////////////////////////////////////////
		/*
			PUBLIC OPERATORS
		*/
		//UNARY
		Literal& operator=(const Literal& Object);
		//BINARY
		///////////////////////////////////////////////
		/*
			DESTRUCTOR
		*/
		///////////////////////////////////////////////
		virtual ~Literal();
	};
}

#endif /* _LITERAL_HPP_ */