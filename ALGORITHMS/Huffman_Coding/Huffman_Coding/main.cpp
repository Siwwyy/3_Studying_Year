/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <map>
#include <math.h>

#define NEW_LINE '\n'

//CLASS OF _Element

class _Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	char sign;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Element();
	_Element(const char & sign);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE

	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Element();
};

//CLASS OF Huffmatemplate <class _Ty = void>
// STRUCT TEMPLATE less


class Huffman_Coding
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	std::string Data;
	std::map<char, int32_t> Occurencies;
	std::vector<std::pair<char, int32_t>> map_copy;
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNCTORS
	*/
	//////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	Huffman_Coding();
	Huffman_Coding(const std::string & Data);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void Find_Occurencies();
	void Print_Occurencies() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	//////////////////////////////////////////////////////////////////////////////

	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE

	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~Huffman_Coding();
};

//////////////////////////////////////////////////////////////////////////////

//FUNCTION FOR INSERTING VALUES FROM file_in
void Load_Data(std::string& Data, const std::string & file_name);
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	std::string Data{};
	std::string file_name{ "file.in" };
	Load_Data(Data,file_name);

	Huffman_Coding Obj(Data);
	Obj.Print_Occurencies();
	std::cin.get();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void Load_Data(std::string& Data, const std::string & file_name)
{
	std::fstream file;
	file.open(file_name.c_str(), std::ios_base::in);
	std::stringstream buffer;
	buffer << file.rdbuf();
	Data = buffer.str();
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_MST_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Element::_Element()
{
}

_Element::_Element(const char& sign):
	sign(sign)
{

}

_Element::~_Element()
{
	sign = ' ';
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Huffman_Coding METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


Huffman_Coding::Huffman_Coding()
{

}

Huffman_Coding::Huffman_Coding(const std::string& Data) :
	Data(Data)
{
	Find_Occurencies();
}

void Huffman_Coding::Find_Occurencies()
{
	for (typename std::string::const_iterator string_iterator = this->Data.begin(); string_iterator != this->Data.end(); ++string_iterator)
	{
		this->Occurencies[*string_iterator]++;
	}
	//for (typename std::map<char, int32_t>::iterator map_iterator = this->Occurencies.begin(); map_iterator != this->Occurencies.end(); ++map_iterator)
	//{
	//	map_copy.emplace_back(std::make_pair(map_iterator->first, map_iterator->second));
	//}
	std::vector<std::pair<char, int32_t>> mapcopy1(Occurencies.begin(), Occurencies.end());
	typedef std::function<bool(std::pair<char, int32_t>, std::pair<char, int32_t>)> Comparator;
	Comparator compFunctor =
		[](std::pair<char, int32_t> elem1, std::pair<char, int32_t> elem2)
	{
		return elem1.second < elem2.second;
	};
	std::sort(mapcopy1.begin(), mapcopy1.end(), compFunctor);

	//for (typename std::vector<std::pair<char, int32_t>>::const_iterator vec_iterator = mapcopy1.begin(); vec_iterator != mapcopy1.end(); ++vec_iterator)
	//{
	//	std::cout << "Sign: " << vec_iterator->first << " Took place: " << vec_iterator->second << " times" << NEW_LINE;
	//}
	//for (typename std::map<char, int32_t>::const_iterator map_iterator = this->Occurencies.begin(); map_iterator != this->Occurencies.end(); ++map_iterator)
	//{
	//	if(map_iterator->second < (map_iterator + 1)->s)
	//}
	this->map_copy = mapcopy1;
}

void Huffman_Coding::Print_Occurencies() const
{
	//for (typename std::map<char, int32_t>::const_iterator map_iterator = this->Occurencies.begin(); map_iterator != this->Occurencies.end(); ++map_iterator)
	//{
	//	std::cout << "Sign: " << map_iterator->first << " Took place: " << map_iterator->second << " times" << NEW_LINE;
	//}

	for (typename std::vector<std::pair<char, int32_t>>::const_iterator vec_iterator = this->map_copy.begin(); vec_iterator != this->map_copy.end(); ++vec_iterator)
	{
		std::cout << "Sign: " << vec_iterator->first << " Took place: " << vec_iterator->second << " times" << NEW_LINE;
	}
}

Huffman_Coding::~Huffman_Coding()
{
}


