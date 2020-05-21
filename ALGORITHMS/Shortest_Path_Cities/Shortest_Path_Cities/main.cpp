#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Djikstra.hpp"


const _STD vector<int32_t>& Get_File_Data(const std::string& file_path);
const bool Unvalid_Characters(const char character);

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
				if (Unvalid_Characters(temp[i]) != false)
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
		for (size_t j = 0; j < Temp_Data[i].size(); ++j)
		{
			if (Temp_Data[i][j] == '(' || Temp_Data[i][j] == ')' || ((static_cast<int32_t>(Temp_Data[i][j]) >= 97 && static_cast<int32_t>(Temp_Data[i][j]) <= 122) || (static_cast<int32_t>(Temp_Data[i][j]) >= 65 && static_cast<int32_t>(Temp_Data[i][j]) <= 90)))
			{
				city_name += Temp_Data[i][j];
			}
			if (Temp_Data[i][j] == '/')
			{
				break;
			}
		}
		Cities.emplace_back(city_name);
	}

	//for (size_t i = 0; i < Cities.size(); ++i)	//works
	//{
	//	std::cout << Cities[i] << '\n';
	//}




	return Data;
}

const bool Unvalid_Characters(const char character)
{
	std::fstream file_in{};
	file_in.open("unvalid_characters.in", std::ios_base::in | std::ios_base::binary);

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