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
	Obj.Print_Occurencies();
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
		if (elem1.second < elem2.second)
		{
			std::swap(elem1, elem1);
		}
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
	std::vector<std::pair<int32_t, std::pair<bool, bool>>> Tree{};

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
		size_t i = 0;
		bool if_break = false;
		for (typename std::vector<std::pair<char, int32_t>>::iterator vec_iterator = this->map_copy.begin(); vec_iterator != this->map_copy.end(); ++vec_iterator)
		{
			while (if_break == false)
			{
				if (Tree.size() == 0)
				{
					//false means it is not a node
					//true means it is a node
					Tree.emplace_back(std::make_pair(map_copy[i].second, std::make_pair(0,false)));
					Tree.emplace_back(std::make_pair(map_copy[i + 1].second, std::make_pair(1, false)));
					Tree.emplace_back(std::make_pair(map_copy[i].second + map_copy[i + 1].second, std::make_pair(0, true)));
					i = std::distance(this->map_copy.begin(), (vec_iterator + 2));
					break;
				}
				else
				{
					if (i + 1 < map_copy.size())
					{
						if ((Tree.end() - 1)->first <= map_copy[i + 1].second)
						{
							Tree.emplace_back(std::make_pair(map_copy[i].second, std::make_pair(1, false)));
							Tree.emplace_back(std::make_pair(map_copy[i].second + (Tree.end() - 2)->first, std::make_pair(0, true)));
							i = std::distance(this->map_copy.begin(), (vec_iterator + 2));
							break;
						}
						else
						{
							Tree.emplace_back(std::make_pair(map_copy[i].second, std::make_pair(1, false)));
							Tree.emplace_back(std::make_pair(map_copy[i + 1].second, std::make_pair(0, false)));
							Tree.emplace_back(std::make_pair(map_copy[i].second + map_copy[i + 1].second, std::make_pair(1, false)));
							i = std::distance(this->map_copy.begin(), (vec_iterator + 2));
							break;
						}
					}
					else
					{
						//to do something
						//merge array finally
						//std::cin.get();
						if_break = true;
						//Tree.emplace_back(std::make_pair(20,std::make_pair(0, true)));
						break;
					}
				}
			}
		}


		////Tree.emplace_back(std::make_pair((Tree.end() - 1)->first + (Tree.end() - 2)->first, true));
		//for (typename std::vector<std::pair<int32_t, bool>>::const_iterator vec_iterator = Tree.begin(); vec_iterator != Tree.end(); ++vec_iterator)
		//{
		//	std::cout << vec_iterator->first << ' ' << std::boolalpha << vec_iterator->second << '\n';
		//}
		//Tree.emplace_back(std::make_pair((Tree.end() - 1)->first + (Tree.end() - 2)->first, true));
		//for (typename std::vector<std::pair<int32_t, std::pair<bool, bool>>>::const_iterator vec_iterator = Tree.begin(); vec_iterator != Tree.end(); ++vec_iterator)
		//{
		//	std::cout << vec_iterator->first << ' ' << std::boolalpha << vec_iterator->second.second << '\n';
		//}
		//std::cin.get();
		size_t counter{};
		for (size_t i = 0; i < Tree.size(); ++i)
		{
			if (Tree[i].second.second == false)
			{
				std::cout << map_copy[counter].first << " ";
				counter++;
				for (size_t j = i; j < Tree.size(); ++j)
				{
					if (Tree[j].second.second == true)
					{
						if (Tree[j].second.first == 0)
						{
							std::cout << "0";
						}
						else
						{
							std::cout << "1";
						}
					}


				}
				std::cout << "\n";
			}

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