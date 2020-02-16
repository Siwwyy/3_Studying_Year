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
		std::vector<int> File;
		std::string file_path;
		std::fstream file_in;
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
		const std::vector<int> Get_File() const;
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