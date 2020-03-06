#ifndef _DPLL_HPP_
#define _DPLL_HPP_
#pragma once

#include "Literal.hpp"

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

namespace SAT
{
	class DPLL
	{
	private:
		/*
			PRIVATE VARIABLES
		*/
		std::vector<std::vector<Literal>> Data;
		std::unordered_set<int32_t> Unary_Variables;
		int64_t amount_of_literals;
		int64_t* Knowledge;
		///////////////////////////////////////////////
		/*
			PRIVATE FUNCTIONS
		*/
		void Find_Unaries();
		void Add_To_Knowledge(int64_t value);
		///////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		DPLL() = delete;
		DPLL(const std::vector<std::vector<Literal>> & my_data, const int64_t amount_of_literals);
		DPLL(const DPLL& Object);
		///////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/
		void Print_Data() const;
		void Print_Unary_Variables() const;
		void Print_Knowledge() const;
		void SAT_or_UNSAT();
		///////////////////////////////////////////////
		/*
			PUBLIC SETTERS
		*/

		///////////////////////////////////////////////
		/*
			PUBLIC GETTERS
		*/

		///////////////////////////////////////////////
		/*
			PUBLIC OPERATORS
		*/
		//UNARY
		DPLL& operator=(const DPLL& Object);
		//BINARY
		///////////////////////////////////////////////
		/*
			DESTRUCTOR
		*/
		///////////////////////////////////////////////
		virtual ~DPLL();
	};
}


#endif /* _DPLL_HPP_ */