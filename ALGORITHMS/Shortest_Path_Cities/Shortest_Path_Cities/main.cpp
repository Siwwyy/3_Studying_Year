#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Djikstra.hpp"


const _STD vector<int32_t>& Get_File_Data(const std::string& file_path);
const bool Invalid_Characters(const char character);

int main(int argc, char* argv[])
{
	//inserter_DJIKSTRA();
	const std::vector<int32_t>& File_Data{ Get_File_Data("current.in") };


	system("pause");
	return EXIT_SUCCESS;
}

/*

	Funkcja podajaca na wejscie insert djikstra

	miasto miasto droga_laczaca
	miasto miasto droga_laczaca
	miasto miasto droga_laczaca
	miasto miasto droga_laczaca
	miasto miasto droga_laczaca
	EOF
*/

//

const::std::vector<int32_t>& Get_File_Data(const std::string& file_path)
{
	std::vector<int32_t> Data{};

	std::vector<std::string> Temp_Data{};

	std::vector<std::string> Cities{};
	std::vector<std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>> Coords{};

	std::fstream file_in{};
	file_in.open(file_path.c_str(), std::ios_base::in | std::ios_base::binary);

	if (file_in.good() == false)
	{
		std::cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		//int32_t temp{};
		std::string temp{};
		size_t counter{};
		while (file_in.eof() == false)	//works
		{
			std::getline(file_in, temp);
			for (size_t i = 0; i < temp.size(); ++i)
			{
				if (Invalid_Characters(temp[i]) != false)
				{
					temp[i] = '/';
				}
			}
			Temp_Data.emplace_back(temp);
			temp.clear();
		}
	}
	file_in.close();


	for (size_t i = 0; i < Temp_Data.size(); ++i)	//works
	{
		//std::cout << Temp_Data[i] << '\n';
		std::string city_name{};
		std::string single_coord{};
		int32_t coords[4]{};
		size_t counter{};
		for (size_t j = 0; j < Temp_Data[i].size(); ++j)
		{
			//Inserting city name
			if (Temp_Data[i][j] == '(' || Temp_Data[i][j] == ')' || ((static_cast<int32_t>(Temp_Data[i][j]) >= 97 && static_cast<int32_t>(Temp_Data[i][j]) <= 122) || (static_cast<int32_t>(Temp_Data[i][j]) >= 65 && static_cast<int32_t>(Temp_Data[i][j]) <= 90)))
			{
				city_name += Temp_Data[i][j];
			}

			/////////////////////////////////////////////////////
			//Inserting Coords
			if (static_cast<int32_t>(Temp_Data[i][j]) >= 48 && static_cast<int32_t>(Temp_Data[i][j]) <= 57)
			{
				single_coord += Temp_Data[i][j];
				if (single_coord.size() == 2)
				{
					coords[counter] = std::stoi(single_coord);
					single_coord.clear();
					++counter;
				}
			}
		}
		//Inserting city names
		Cities.emplace_back(city_name);
		//Inserting coordinates
		Coords.emplace_back(std::make_pair(std::make_pair(coords[0], coords[1]), std::make_pair(coords[2], coords[3])));
	}

	//for (size_t i = 0; i < Cities.size(); ++i)	//works
	//{
	//	std::cout << Cities[i] << '\n';
	//}

	for (size_t i = 0; i < Coords.size(); ++i)	//works
	{
		std::cout << Cities[i] << "  | x1:" << Coords[i].first.first << " y1:" << Coords[i].first.second << " | x2:" << Coords[i].second.first << " y2:" << Coords[i].second.second << '\n';
	}


	return Data;
}

const bool Invalid_Characters(const char character)
{
	std::fstream file_in{};
	file_in.open("invalid_characters.in", std::ios_base::in | std::ios_base::binary);

	if (file_in.good() == false)
	{
		std::cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		char temp{};
		while (file_in.eof() == false)
		{
			file_in >> temp;
			if (character == temp)
			{
				file_in.close();
				return true;
			}
		}
	}
	file_in.close();
	return false;
}