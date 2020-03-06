#ifndef _FILE_READER_HPP_
#define _FILE_READER_HPP_
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <cstdint>
#include <functional>

namespace SAT_File_Reader
{
	class File_Reader
	{
	private:
		/*
			PRIVATE VARIABLES
		*/
		std::vector<std::vector<std::pair<int64_t, bool>>> File;
		std::string file_path;
		std::fstream file_in;
		int64_t amout_of_literals;
		///////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		File_Reader();
		File_Reader(const char * const file_path);
		File_Reader(const File_Reader& Object);
		///////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/
		void Read();
		void Print() const;
		///////////////////////////////////////////////
		/*
			PUBLIC SETTERS
		*/
		void Set_File_Path(const char* const file_path);
		///////////////////////////////////////////////
		/*
			PUBLIC GETTERS
		*/
		const std::string Get_File_Path() const;
		const int64_t Get_Amout_Of_Literals() const;
		const std::vector<std::vector<std::pair<int64_t, bool>>> Get_File() const;
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