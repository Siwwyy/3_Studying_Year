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
		std::deque<std::pair<int64_t, SAT::Literal::STATUS>> Q;
		int64_t amount_of_literals;
		int64_t* Knowledge;
		int64_t max_iteration;
		int64_t current_iteration;
		///////////////////////////////////////////////
		/*
			PRIVATE FUNCTIONS
		*/
		const bool Find_Unaries();
		const bool Is_End() const;
		const bool Is_unsatisfiable() const;
		const bool Is_Conflict() const;
		void Take_First_Literal();
		void Backtrack();
		void Mark_Visited(const std::vector<SAT::Literal>::iterator& _Where);
		void Set_Status(const std::vector<SAT::Literal>::iterator& _Where);
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