#ifndef _FILE_READER_HPP_
#define _FILE_READER_HPP_
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

namespace SAT_File_Reader
{
	class File_Reader
	{
	private:
		/*
			PRIVATE VARIABLES
		*/

		///////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		File_Reader();
		File_Reader(const File_Reader& Object);
		///////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/

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
		File_Reader& operator=(const File_Reader& Object);
		//BINARY
		///////////////////////////////////////////////
		/*
			DESTRUCTOR
		*/
		///////////////////////////////////////////////
		virtual ~File_Reader();
	};
}

#endif /* _FILE_READER_HPP_ */