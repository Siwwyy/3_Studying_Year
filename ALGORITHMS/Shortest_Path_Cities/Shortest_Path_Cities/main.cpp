#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Djikstra.hpp"

#define M_PI 3.14159265358979323846

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
	/*std::vector<std::pair<std::pair<int32_t, int32_t>, std::pair<int32_t, int32_t>>> Coords{};*/

	std::vector<std::pair<float, float>> Coords{};

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
		int32_t coords[2]{};
		size_t counter{};
		float x{};
		float y{};
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
					if (counter % 2 == 0 && x == 0.f)
					{
						x = static_cast<float>(static_cast<float>(coords[1]) / 60.f) + static_cast<float>(coords[0]);
						counter = 0;
					}
				}
			}
		}
		//Inserting city names
		Cities.emplace_back(city_name);
		//Inserting coordinates
		y = static_cast<float>(static_cast<float>(coords[1]) / 60.f) + static_cast<float>(coords[0]);
		Coords.emplace_back(std::make_pair(x, y));
		//Coords.emplace_back(std::make_pair(std::make_pair(coords[0], coords[1]), std::make_pair(coords[2], coords[3])));
	}

	//for (size_t i = 0; i < Cities.size(); ++i)	//works
	//{
	//	std::cout << Cities[i] << '\n';
	//}

	//for (size_t i = 0; i < Coords.size(); ++i)	//works
	//{
	//	std::cout << Cities[i] << "  | x1:" << Coords[i].first.first << " y1:" << Coords[i].first.second << " | x2:" << Coords[i].second.first << " y2:" << Coords[i].second.second << '\n';
	//}


	for (size_t i = 0; i < Coords.size(); ++i)	//works
	{
		for (size_t j = 0; j < Coords.size(); ++j)
		{
			float distance{};
			if (i == j)
			{
				Data.emplace_back(0);
				continue;
			}
			else
			{
				float x1{ Coords[i].second };
				float y1{ Coords[i].first };
				float x2{ Coords[j].second };
				float y2{ Coords[j].first };

				distance = static_cast<float>(sqrt(pow((x2 - x1), 2) + pow(cos((x1 * M_PI) / 180) * (y2 - y1), 2))) * static_cast<float>(40075.704f / 360.f);
				Data.emplace_back(static_cast<int32_t>(distance));
			}
		}
	}
	size_t cities_counter{};
	for (size_t i = 0; i < Data.size(); ++i)	//works
	{
		//if (i == 0)
		//{
		//	for (size_t j = 0; j < Cities.size(); ++j)	//works
		//	{
		//		std::cout << Cities[j][0] << Cities[j][1] << Cities[j][2] << ' ';
		//	}
		//	std::cout << '\n';
		//}
		if (i == 0)
		{
			std::cout << Cities[cities_counter] << "	 ";
			++cities_counter;
		}
		if (i % Coords.size() == 0 && i > 0)
		{
			std::cout << '\n' << Cities[cities_counter] << "	  ";
			++cities_counter;
		}

		std::cout << Data[i] << ' ';

	}
	std::cout << '\n';


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