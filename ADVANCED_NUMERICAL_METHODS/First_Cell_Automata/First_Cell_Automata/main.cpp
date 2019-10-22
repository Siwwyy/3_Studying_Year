#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <random>
#include <map>

#include "FreqCounter.h"

#define NEW_LINE '\n'

void Read_File(const _STD string& file_path, __int32& width, __int32& height);
void Print_Area(const short* const* const area, const __int32& width,const __int32& height);
void Initialize_Area(short* const* const area, const __int32& width,const __int32& height);
const __int32 Count_Energy(short* const* const area, const __int32& width,const __int32& height);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	///////////////////////////////////////
	__int32 width{}, height{};
	__int32 J{ 1 };
	__int32 energy{};
	__int32 energy_total{};
	short** area{};
	size_t x{};
	size_t y{};
	__int32 temp_energy{};
	size_t iterations{ 10000 };
	__int32 demon_energy{ 10000 };
	__int32 magnetization{ 0 };
	__int32 spin_value{ 0 };
	double test{};
	_STD map<int, int> freq{};
	///////////////////////////////////////


	Read_File("file.in", width, height);	//file reader

	area = new short* [width];

	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		*(area + i) = new short[height];
	}

	Initialize_Area(area, width, height);
	//Print_Area(area, width, height);	//uncomment if you want to display 2D matrix

	//FreqCounter<__int32> Object;

	//SPIN FLIP
	std::default_random_engine generator;
	std::uniform_int_distribution<> dis_x(0, width - 1);			//zakres naszego losowania
	std::uniform_int_distribution<> dis_y(0, height - 1);			//zakres naszego losowania


	//lambda case
	auto energy_sum = [](const __int32& J, const __int32& energy) -> __int32 { return (-1) * J * energy; };

	//energy = (-2) *width*height;//= Count_Energy(area, width, height);
	energy = Count_Energy(area, width, height);
	energy_total = energy_sum(J,energy);


	//OUTPUT FILE
	std::fstream file_out;
	file_out.open("file_to_csv3.csv", std::ios_base::out);
	file_out << "For iterations: " << iterations << " Initial energy of demon: " << demon_energy << NEW_LINE;

	//nx = ny = 100
	//liczba spinow = 10000
	//Energia minimalna = -2*10^4
	//Energia maksymalna = 2*10^4

	for (size_t i = 0; i < iterations; i++)
	{
		temp_energy = energy_total;
		x = dis_x(generator);
		y = dis_y(generator);
		//TIME TO SPIN !
		area[x][y] *= (-1);

		energy = Count_Energy(area, width, height);
		energy_total = energy_sum(J, energy);
		//popraw energie
		if (energy_total > temp_energy)	//here may be a problem with positive values !
		{
			spin_value = ((temp_energy)-(energy_total));
			if (demon_energy >= ((-1) * spin_value))
			{
				demon_energy += spin_value;
				//energy_total = temp_energy;
			}
			else
			{
				area[x][y] *= (-1);
				energy_total = temp_energy;
			}
		}
		else 
		{
			spin_value = ((energy_total)-(temp_energy)) * (-1);
			demon_energy += spin_value;
		}
		
		for (size_t j = 0; j < width; ++j)
		{
			for (size_t k = 0; k < height; ++k)
			{
				magnetization += area[j][k];
			}
		}
		//Object.Push_Data(iterations,magnetization);
		//_STD cout << "Iteration nr:" << i << " Demon energy: " << demon_energy << " Magnetization: " << magnetization << " Total energy: " << energy_total << NEW_LINE;
		//file_out << "Iteration nr:" << i << " Demon energy: " << demon_energy << " Magnetization: " << magnetization << " Total energy: " << energy_total << NEW_LINE;
		//file_out << i << "," << magnetization << NEW_LINE;
		file_out << i << ',' << demon_energy << NEW_LINE;
		
		//if (i > 1399)
		//{
		//	/*test += demon_energy;
		//	freq[demon_energy]++;
		//}
		/*if (i > 1399)
		{
			test += magnetization;
		}*/
		x = NULL;
		y = NULL;
		magnetization = NULL;
		spin_value = NULL;
	}
	/*for (auto& x : freq)
	{
		file_out << x.first << ',' << x.second << NEW_LINE;
	}*/
	//Object.Create_Chart();
	//SPIN FLIP BY DEMON MA ENERGI NA TO BY TO WYKONAC
	/*
		Przyjmijmy: energia to -32 a po spinie to -24, spadla o 8, a demon ma 12 energi wiec spin sie wykona.
		Lecz, gdyby mial 4 energi to musimy pominac spin flipa i poczekac na takiego ktorego moze zrobic
		Jak energia to -32 a po spinie np. -34 to demonowi dodajemy 2 energie do gory ! jesli mial 20 to ma 22	
		Jak energia to -32 a po spinie np. -30 to demonowi odejmujemy 2 energie do dolu ! jesli mial 20 to ma 18

		Jak mamy same 1 to na samym poczatku policz energie !! -2 * width * height
	*/
	/*
		NA ZA TYDZIEN POCZYTAJ O AUTOMACIE WOLFRAMA, 256 regul, topologia, stany. Zwroc uwage na
		oznaczanie regul ! Regula jest konkretna liczba z zakresu 0-255
	*/
	
	//memory free
	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		delete[] *(area + i);
	}
	delete[] area;

	file_out << "Average: " << double(test / (1000));

	file_out.close();

	system("pause");
	return 0;
}

void Read_File(const _STD string& file_path, __int32 & width, __int32 & height)
{
	std::fstream file_in;
	file_in.open(file_path, std::ios_base::in);
	if (file_in.good() == false)
	{
		exit(0);
	}
	else
	{
		file_in >> width;
		file_in >> height;
	}
	_STD cout << "I read following things" << NEW_LINE;

	_STD cout << "Area width: " << width << NEW_LINE;
	_STD cout << "Area height: " << height << NEW_LINE;

	file_in.close();
}

void Print_Area(const short* const* const area, const __int32& width, const __int32& height)
{
	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		for (size_t j = 0; j < static_cast<size_t>(height); ++j)
		{
			_STD cout << *(*(area + i) + j) << ' ';
		}
		_STD cout << NEW_LINE;
	}
}

void Initialize_Area(short* const* const area, const __int32& width, const __int32& height)
{
	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		for (size_t j = 0; j < static_cast<size_t>(height); ++j)
		{
			*(*(area + i) + j) = static_cast<short>(1);
		}
	}
}

const __int32 Count_Energy(short* const* const area, const __int32& width, const __int32& height)
{
	unsigned energy{};
	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		for (size_t j = 0; j < static_cast<size_t>(height); ++j)
		{
			if (i == static_cast<size_t>(width - static_cast<size_t>(1)))
			{
				energy += (area[i][j] * area[0][j]);
			}
			else
			{
				energy += (area[i][j] * area[i+1][j]);
			}

			if (j == static_cast<size_t>(height - static_cast<size_t>(1)))
			{
				energy += (area[i][j] * area[i][0]);
			}
			else
			{
				energy += (area[i][j] * area[i][j + 1]);
			}
		}
	}

	return energy;
}