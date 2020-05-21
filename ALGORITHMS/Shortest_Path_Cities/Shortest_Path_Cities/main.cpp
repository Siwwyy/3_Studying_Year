#include <iostream>
#include <fstream>
#include <string>
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
		while (file_in.eof() == false)
		{
			std::getline(file_in, temp);
			for (size_t i = 0; i < temp.size(); ++i)
			{
				if (Unvalid_Characters(temp[i]) == false)
				{
					std::cout << temp[i];
				}
				else
				{
					temp[i] = '/';
					std::cout << temp[i];
				}
			}
			std::cout << '\n';
			temp.clear();
		}
	}
	file_in.close();

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