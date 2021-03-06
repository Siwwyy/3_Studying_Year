#ifndef _DPLL_HPP_
#define _DPLL_HPP_
#pragma once

#include "Literal.hpp"

#include <iostream>
#include <string>
#include <queue>
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
		std::vector<std::vector<SAT::Literal>> Data;
		std::deque<int64_t> Q;
		int64_t amount_of_literals;
		int64_t* Knowledge;
		///////////////////////////////////////////////
		/*
			PRIVATE FUNCTIONS
		*/
		const bool Find_Unaries();
		const bool Is_Conflict();
		const bool Is_End();
		const bool Is_satisfiable();
		void Mark_As_Visited();
		void Take_First_Literal();
		void Backtrack();
		void Set_Literal_Status(const int64_t value);
		///////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		DPLL() = delete;
		DPLL(const std::vector<std::vector<SAT::Literal>> & my_data, const int64_t amount_of_literals);
		DPLL(const DPLL& Object);
		///////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/
		void Print_Data() const;
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