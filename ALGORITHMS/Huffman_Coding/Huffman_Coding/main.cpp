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
	_Element(const char& sign);
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
	Huffman_Coding(const std::string& Data);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void Find_Occurencies();
	void Print_Occurencies() const;
	void Create_Tree();
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
void Load_Data(std::string& Data, const std::string& file_name);
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	std::string Data{};
	std::string file_name{ "file.in" };
	Load_Data(Data, file_name);

	Huffman_Coding Obj(Data);
	//Obj.Print_Occurencies();
	Obj.Create_Tree();
	std::cin.get();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void Load_Data(std::string& Data, const std::string& file_name)
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
	_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Element::_Element()
{
}

_Element::_Element(const char& sign) :
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

	std::vector<std::pair<char, int32_t>> mapcopy1(Occurencies.begin(), Occurencies.end());

	auto compFunctor = [&](std::pair<char, int32_t>& elem1, std::pair<char, int32_t>& elem2)
	{
		return elem1.second < elem2.second;
	};
	std::sort(mapcopy1.begin(), mapcopy1.end(), compFunctor);

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

void Huffman_Coding::Create_Tree()
{
	std::vector<std::pair<int32_t, bool>> Tree{};

	//auto the_smallest_in_tree = [&](const typename std::vector<int32_t>::const_iterator current_pos)
	//{
	//	return (current_pos + 1);
	//};

	//auto the_smallest_in_map_copy = [&](const typename std::vector<std::pair<char, int32_t>>::const_iterator current_pos)
	//{
	//	return (current_pos + 1)->second;
	//};

	//for (typename std::vector<std::pair<char, int32_t>>::const_iterator vec_iterator = this->map_copy.begin(); vec_iterator != this->map_copy.end(); ++vec_iterator)
	//{
	//	Tree.emplace_back(vec_iterator->second);
	//}

	if (this->map_copy.size() > 1)
	{
		for (typename std::vector<std::pair<char, int32_t>>::iterator vec_iterator = this->map_copy.begin(); vec_iterator != this->map_copy.end(); ++vec_iterator)
		{
			if (std::distance(this->map_copy.begin(), vec_iterator) == 0)
			{
				//false means it is not a node
				//true means it is a node
				Tree.emplace_back(std::make_pair(vec_iterator->second, false));
				Tree.emplace_back(std::make_pair((vec_iterator + 1)->second, false));
				Tree.emplace_back(std::make_pair(vec_iterator->second + (vec_iterator + 1)->second, true));
			}
			//else if (std::distance(this->map_copy.begin(), vec_iterator) % 2 == 0)
			else if (vec_iterator->second != (Tree.end() - 2)->first || (vec_iterator + 1) == this->map_copy.end())
			{
				if ((vec_iterator + 1) != this->map_copy.end())
				{
					if ((Tree.end() - 1)->first <= (vec_iterator + 1)->second)
					{
						Tree.emplace_back(std::make_pair(vec_iterator->second, false));
						Tree.emplace_back(std::make_pair(vec_iterator->second + (Tree.end() - 2)->first, true));
					}
					else
					{
						Tree.emplace_back(std::make_pair(vec_iterator->second, false));
						Tree.emplace_back(std::make_pair((vec_iterator + 1)->second, false));
						Tree.emplace_back(std::make_pair(vec_iterator->second + (vec_iterator + 1)->second, true));
					}
				}
				else
				{
					////std::cin.get();
					//int32_t sum{};
					//size_t counter{};
					//for (int32_t i = Tree.size() - 1; i >= 0; --i)
					//{
					//	//std::cout << Tree[i].first << ' ' << std::boolalpha << Tree[i].second << '\n';
					//	if (Tree[i].second == true)
					//	{
					//		sum += Tree[i].first;
					//		++counter;
					//	}
					//	if (counter == 2)
					//	{

					//		break;
					//	}
					//}
					//std::cin.get();
				}
			}
		}
		//Tree.emplace_back(std::make_pair((Tree.end() - 1)->first + (Tree.end() - 2)->first, true));
		for (typename std::vector<std::pair<int32_t, bool>>::const_iterator vec_iterator = Tree.begin(); vec_iterator != Tree.end(); ++vec_iterator)
		{
			std::cout << vec_iterator->first << ' ' << std::boolalpha << vec_iterator->second << '\n';
		}
		std::cin.get();
	}
	else
	{
		std::cout << this->map_copy[0].first << " code is: " << "0\n";
	}
}

Huffman_Coding::~Huffman_Coding()
{
}


