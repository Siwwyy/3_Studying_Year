#ifndef _TESTING_ENGINE_HPP_
#define _TESTING_ENGINE_HPP_
#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <fstream>
#include <functional>
#define STOPWATCH_ON
#include "StopWatch.h"
#define NEW_LINE '\n'

namespace Testing
{
	using _STD cout;
	using _STD cin;
	using _STD cerr;



	template<typename _Ty = void>
	class Testing_Engine
	{
	private:
		/*
			PRIVATE VARIABLES
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////
	protected:
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PROTECTED FUNCTIONS
		*/
		_STD string file_path;
		_STD vector<_STD string> test_names;
		_STD vector<__int32> content_from_file;
		_STD vector<_Ty> Pointer_To_Functions;
		/////////////////////////////////////////////////////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Testing_Engine();
		Testing_Engine(const _STD string & file_path);
		Testing_Engine(const Testing_Engine& Object) = delete;	//currently unavailable
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			PUBLIC FUNCTIONS
		*/
		void Push_Function(const _Ty _Ptr);
		void Push_Names(const _STD string & test_name);
		void Show_Pointer_To_Functions() const;
		void Show_File_Content() const;
		void Test(const size_t position);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			SETTERS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			GETTERS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			OPERATORS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Testing_Engine& operator=(const Testing_Engine& Object) = delete;	//currently unavailable
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			DESTRUCTOR
		*/
		virtual ~Testing_Engine();
		/////////////////////////////////////////////////////////////////////////////////////////////
	};

	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::Testing_Engine():
		file_path(NULL)
	{

	}

	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::Testing_Engine(const::std::string& file_path) :
		file_path(file_path)
	{
		std::fstream file_in;
		file_in.open(file_path.c_str(), std::ios_base::in);

		if (file_in.good() == false)
		{
			_STD cerr << "[WARRNING:0001] Invalid file_path\n";
		}
		else
		{
			__int32 temp{};
			while (file_in.eof() == false)
			{
				file_in >> temp;
				this->content_from_file.emplace_back(temp);
				temp = NULL;
			}
		}
		file_in.close();
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Push_Function(const _Ty _Ptr)
	{
		Pointer_To_Functions.emplace_back(_Ptr);
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Push_Names(const::std::string& test_name)
	{
		test_names.emplace_back(test_name);
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Show_Pointer_To_Functions() const
	{
		for (typename _STD vector<_Ty>::const_iterator vec_iterator = Pointer_To_Functions.begin(); vec_iterator != Pointer_To_Functions.end(); ++vec_iterator)
		{
			_STD cout << (*vec_iterator) << ' ';
		}
		_STD cout << NEW_LINE;
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Show_File_Content() const
	{
		for (typename _STD vector<__int32>::const_iterator vec_iterator = content_from_file.begin(); vec_iterator != content_from_file.end(); ++vec_iterator)
		{
			_STD cout << (*vec_iterator);
		}
		_STD cout << NEW_LINE;
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Test(const size_t position)
	{
		if (position > Pointer_To_Functions.size())
		{
			_STD cerr << "[WARRNING:0002] Invalid vector of function pointers position\n";
		}
		else
		{
			START_STOPWATCH
			_STD cout << "|================================================|" << '\n';
			_STD cout << "		NAME OF TEST: " << test_names[position] << '\n';
			_STD cout << "|================================================|" << '\n';
			_STD cout << '\n';
			_Ty _Ptr = Pointer_To_Functions[position];
			_Ptr(content_from_file);
			STOP_STOPWATCH
			_STD cout << '\n';
		}
	}

	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::~Testing_Engine()
	{
		Pointer_To_Functions.clear();
		content_from_file.clear();
	}
}

#endif /* _TESTING_ENGINE_HPP_ */