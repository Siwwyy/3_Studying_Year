#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <random>


#define NEW_LINE '\n'

void Read_File(const _STD string& file_path, __int32& width, __int32& height);
void Print_Area(const short* const* const area, const __int32& width,const __int32& height);
void Initialize_Area(short* const* const area, const __int32& width,const __int32& height);
const unsigned __int32 Count_Energy(short* const* const area, const __int32& width,const __int32& height);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	__int32 width{}, height{};
	__int32 J{ 1 };
	unsigned __int32 energy{};
	short** area{};
	Read_File("file.in", width, height);

	area = new short* [width];

	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		*(area + i) = new short[height];
	}

	Initialize_Area(area, width, height);
	Print_Area(area, width, height);


	//SPIN FLIP
	/*area[1][1] = static_cast<short>(-1);*/
	std::default_random_engine generator;
	std::uniform_int_distribution<> dis_x(0, width - 1);			//zakres naszego losowania
	std::uniform_int_distribution<> dis_y(0, height - 1);			//zakres naszego losowania
	size_t iterations{ 100 };
	__int32 demon_energy{ 20 };

	energy = Count_Energy(area, width, height);
	__int32 energy_total{};
	energy_total = (-1) * J * energy;
	_STD cout << energy_total << NEW_LINE;
//	for (size_t i = 0; i < iterations; i++)
//	{
//		//fc_i.Push_Data(dis(generator));						//nowy silnik stl random  
//		__int32 temp{energy_total};
//		//_STD cout << "Energy: " << energy_total << NEW_LINE;
//		//TIME TO SPIN !
//		size_t x = dis_x(generator);
//		size_t y = dis_y(generator);
//		//area[x][y] *= (-1);
//		/*_STD cout << x << ' ' << y << NEW_LINE;*/
////		energy = Count_Energy(area, width, height);
////		energy_total = (-1) * J * energy;
////
////		__int32 roznica = (temp - energy_total);
//////		_STD cout << demon_energy << NEW_LINE;
////		if (roznica > demon_energy)
////		{
////			_STD cout << "Koniec: " << demon_energy << NEW_LINE;
////			break;
////		}
//
//		//SPIN FLIP BY DEMON MA ENERGI NA TO BY TO WYKONAC
//		/*
//			Przyjmijmy: energia to -32 a po spinie to -24, spadla o 8, a demon ma 12 energi wiec spin sie wykona.
//			Lecz, gdyby mial 4 energi to musimy pominac spin flipa i poczekac na takiego ktorego moze zrobic
//			Jak energia to -32 a po spinie np. -34 to demonowi dodajemy 2 energie do gory ! jesli mial 20 to ma 22	
//			Jak energia to -32 a po spinie np. -30 to demonowi odejmujemy 2 energie do dolu ! jesli mial 20 to ma 18
//
//			Jak mamy same 1 to na samym poczatku policz energie !! -2 * width * height
//			*/
//	}
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
			//*(*(area + i) + j) = static_cast<short>((i* height) + j) + 1;
		}
		//_STD cout << NEW_LINE;
	}
}

const unsigned __int32 Count_Energy(short* const* const area, const __int32& width, const __int32& height)
{
	unsigned __int32 energy{};

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
