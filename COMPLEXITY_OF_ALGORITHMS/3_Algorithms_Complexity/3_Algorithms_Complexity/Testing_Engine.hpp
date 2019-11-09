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
		_STD vector<_STD string> file_paths;
		_STD vector<_STD string> test_names;
		_STD vector<_STD vector<__int32>> content_from_file;
		_STD vector<_Ty> Pointer_To_Functions;
		/////////////////////////////////////////////////////////////////////////////////////////////
	public:
		/*
			PUBLIC CONSTRUCTORS
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Testing_Engine();
		Testing_Engine(const _STD string & file_path);
		Testing_Engine(_STD initializer_list<const _STD string> _Initializer); //using initializer list you have to insert equivalent amount of functions to test
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
		file_paths(NULL)
	{

	}

	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::Testing_Engine(const::std::string& file_path) :
		content_from_file(1)
	{
		this->file_paths.emplace_back(file_path);
		std::fstream file_in;
		file_in.open(this->file_paths[0].c_str(), std::ios_base::in);

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
				this->content_from_file[0].emplace_back(temp);
				temp = NULL;
			}
		}
		file_in.close();
	}


	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::Testing_Engine(::std::initializer_list<const::std::string> _Initializer)	:
		content_from_file(_Initializer.size())
	{
		std::fstream file_in;
		for (typename ::std::initializer_list<const::std::string>::iterator initializer_list_iterator = _Initializer.begin(); initializer_list_iterator != _Initializer.end(); ++initializer_list_iterator)
		{
			this->file_paths.emplace_back((*initializer_list_iterator));

			file_in.open(this->file_paths[_STD distance(_Initializer.begin(), initializer_list_iterator)].c_str(), std::ios_base::in);
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
					this->content_from_file[_STD distance(_Initializer.begin(), initializer_list_iterator)].emplace_back(temp);
					temp = NULL;
				}
			}
			file_in.close();
		}
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Push_Function(const _Ty _Ptr)
	{
		this->Pointer_To_Functions.emplace_back(_Ptr);
	}

	template<typename _Ty>
	__forceinline void Testing_Engine<_Ty>::Push_Names(const::std::string& test_name)
	{
		this->test_names.emplace_back(test_name);
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
		for (typename _STD vector<_STD vector<__int32>>::const_iterator vec_iterator = content_from_file.begin(); vec_iterator != content_from_file.end(); ++vec_iterator)
		{
			_STD cout << "|================================================|" << '\n';
			_STD cout << "	    From file: " << file_paths[_STD distance(content_from_file.begin(), vec_iterator)] << '\n';
			_STD cout << "|================================================|" << '\n';
			_STD cout << '\n';
			for (typename _STD vector<__int32>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
			{
				_STD cout << (*vec_iterator_second);
			}
			_STD cout << NEW_LINE;
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
			//_STD cout << "|================================================|" << '\n';
			_STD cout << "|========================================================================|" << '\n';
			_STD cout << "       |================================================|" << '\n';
			_STD cout << "	            NAME OF TEST: " << test_names[position] << '\n';
			_STD cout << "       |================================================|" << '\n';
			_STD cout << '\n';
			for (size_t i = 0; i < file_paths.size(); ++i)
			{
				START_STOPWATCH
				_STD cout << "	             From file: " << file_paths[i] << '\n';
				_Ty _Ptr = Pointer_To_Functions[position];
				_Ptr(content_from_file[i]);
				STOP_STOPWATCH
				_STD cout << '\n';
			};
		}
	}

	template<typename _Ty>
	__forceinline Testing_Engine<_Ty>::~Testing_Engine()
	{
		this->Pointer_To_Functions.clear();
		this->content_from_file.clear();
		this->file_paths.clear();
	}
}

#endif /* _TESTING_ENGINE_HPP_ */