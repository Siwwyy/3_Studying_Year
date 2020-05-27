#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include "Prims.h"

#define M_PI 3.14159265358979323846

const std::vector<std::vector<int32_t>> Get_File_Data(const std::string& file_path);
const bool Invalid_Characters(const char character);
void Create_MST(const std::vector<std::vector<int32_t>>& Connections);

std::vector<std::string> Cities{};

int main(int argc, char* argv[])
{
	//std::vector<std::vector<int32_t>> File_Data{ Get_File_Data("current.in") };
	std::vector<std::vector<int32_t>> File_Data{ Get_File_Data("miasta.txt") };
	Create_MST(File_Data);

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

const::std::vector<std::vector<int32_t>> Get_File_Data(const std::string& file_path)
{
	std::vector<std::vector<int32_t>> Data{};
	std::vector<std::string> Temp_Data{};

	std::vector<std::pair<float, float>> Coords{};


	std::fstream file_in{};
	file_in.open(file_path.c_str(), std::ios_base::in | std::ios_base::binary);

	if (file_in.good() == false)
	{
		std::cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
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


	//for (size_t i = 0; i < Temp_Data.size(); ++i)	//works, wczytywanie mateusza
	//{
	//	std::string city_name{};
	//	std::string single_coord{};
	//	int32_t coords[2]{};
	//	size_t counter{};
	//	float x{};
	//	float y{};

	//	for (size_t j = 0; j < Temp_Data[i].size(); ++j)
	//	{
	//		//Inserting city name
	//		if (Temp_Data[i][j] == '(' || Temp_Data[i][j] == ')' || ((static_cast<int32_t>(Temp_Data[i][j]) >= 97 && static_cast<int32_t>(Temp_Data[i][j]) <= 122) || (static_cast<int32_t>(Temp_Data[i][j]) >= 65 && static_cast<int32_t>(Temp_Data[i][j]) <= 90)))
	//		{
	//			city_name += Temp_Data[i][j];
	//		}

	//		/////////////////////////////////////////////////////
	//		//Inserting Coords
	//		if (static_cast<int32_t>(Temp_Data[i][j]) >= 48 && static_cast<int32_t>(Temp_Data[i][j]) <= 57)
	//		{
	//			single_coord += Temp_Data[i][j];
	//			if (single_coord.size() == 2)
	//			{
	//				coords[counter] = std::stoi(single_coord);
	//				single_coord.clear();
	//				++counter;
	//				if (counter % 2 == 0 && x == 0.f)
	//				{
	//					x = static_cast<float>(static_cast<float>(coords[1]) / 60.f) + static_cast<float>(coords[0]);
	//					counter = 0;
	//				}
	//			}
	//		}
	//	}
	//	//Inserting city names
	//	Cities.emplace_back(city_name);
	//	//Inserting coordinates
	//	y = static_cast<float>(static_cast<float>(coords[1]) / 60.f) + static_cast<float>(coords[0]);
	//	Coords.emplace_back(std::make_pair(x, y));
	//}



	for (size_t i = 0; i < Temp_Data.size(); ++i)	//works, wczytywanie sebastiana
	{
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
		Coords.emplace_back(std::make_pair(y, x));
	}



	Data.resize(Cities.size());
	for (size_t i = 0; i < Data.size(); ++i)	//works
	{
		Data[i].resize(Cities.size());
	}

	for (size_t i = 0; i < Coords.size(); ++i)	//works
	{
		for (size_t j = i + 1; j < Coords.size(); ++j)
		{
			float distance{};
			if (i == j)
			{
				Data[i][j] = static_cast<int32_t>(0);
				continue;
			}
			else
			{
				float x1{ Coords[i].second };
				float y1{ Coords[i].first };
				float x2{ Coords[j].second };
				float y2{ Coords[j].first };

				distance = static_cast<float>(sqrt(pow((x2 - x1), 2) + pow(cos((x1 * M_PI) / 180) * (y2 - y1), 2))) * static_cast<float>(40075.704f / 360.f);
				Data[i][j] = static_cast<int32_t>(distance);
				Data[j][i] = static_cast<int32_t>(distance);
			}
		}
	}

	//Printing matrix
	//std::cin.get();
	//size_t cities_counter{};
	//for (size_t i = 0; i < Data.size(); ++i)	//works
	//{
	//	COORD p = { 0, i };
	//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	//	std::cout << Cities[cities_counter];
	//	++cities_counter;
	//	p.X = 27;
	//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

	//	for (size_t j = 0; j < Data[i].size(); ++j)
	//	{
	//		std::cout << Data[i][j] << ' ';
	//		p.X = (p.X + 4);
	//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	//	}
	//	//std::cout << '\n';
	//}
	//std::cout << '\n';
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

void Create_MST(const std::vector<std::vector<int32_t>>& Connections)
{
	_MST* MST_Object = new _MST(Connections.size());

	for (size_t i = 0; i < Connections.size(); ++i)
	{
		for (size_t j = 0; j < Connections[i].size(); ++j)
		{
			MST_Object->push(static_cast<int>(i + 1), static_cast<int>(j + 1), Connections[i][j]);
		}
	}
	MST_Object->push_directions(1, Connections.size(),10);
	MST_Object->Print_Graph();
	MST_Object->minimal_spanning_tree_creator(1);
	MST_Object->Print_Prims_Matrix();
	std::cin.get();

	delete MST_Object;
}

/*

50.15 19.00 Katowice
50.53 20.37 Kielce
50.04 19.56 Krakow
51.47 19.28 Lodz
51.14 22.34 Lublin
53.47 20.30 Olsztyn
52.25 16.55 Poznan
50.03 22.01 Rzeszow
54.28 17.01 Slupsk
53.26 14.34 Szczecin
53.02 18.37 Torun
51.07 17.02 Wroclaw
*/