#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <fstream>
#include <random>
#include <map>

#define NEW_LINE '\n'

void Initialize_Area(short* const* const area, const __int32& width,const __int32& height);
const unsigned __int32 Count_Energy(short* const* const area, const __int32& width,const __int32& height);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	///////////////////////////////////////
	__int32 width{ 100 }, height{ 100 };
	__int32 J{ 1 };
	__int32 energy{};
	__int32 energy_total{};
	short** area{};
	size_t x{};
	size_t y{};
	__int32 temp_energy{};
	size_t iterations{ 150000 };
	__int32 demon_energy{ 0 };
	__int32 magnetization{ 0 };
	__int32 average_magnetization{ 0 };
	__int32 spin_value{ 0 };
	float temperatura{};
	_STD map<int, int> freq{};
	///////////////////////////////////////

	area = new short* [width];

	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		*(area + i) = new short[height];
	}

	//SPIN FLIP
	std::default_random_engine generator;
	std::uniform_int_distribution<> dis_x(0, width - 1);			//zakres naszego losowania
	std::uniform_int_distribution<> dis_y(0, height - 1);			//zakres naszego losowania

	//lambda case
	auto energy_sum = [](const __int32& J, const __int32& energy) -> __int32 { return (-1) * J * energy; };

	//OUTPUT FILE
	std::fstream file_in;
	std::fstream file_out;
	file_in.open("ZMOI_AndrysiakD_Ising.in", std::ios_base::in);
	file_out.open("ZMOI_AndrysiakD_Ising.csv", std::ios_base::out);

	while (file_in.eof() == false)
	{
		file_in >> demon_energy;
		Initialize_Area(area, width, height);
		energy = Count_Energy(area, width, height);
		energy_total = energy_sum(J, energy);
		for (size_t i = 0; i < iterations; i++)
		{
			temp_energy = energy_total;
			x = dis_x(generator);
			y = dis_y(generator);
			//TIME TO SPIN !
			area[x][y] *= (-1);

			energy = Count_Energy(area, width, height);
			energy_total = energy_sum(J, energy);
			if (energy_total > temp_energy)
			{
				spin_value = ((temp_energy)-(energy_total));
				if (demon_energy >= ((-1) * spin_value))
				{
					demon_energy += spin_value;
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
			if (i >= 90000 && i <= 91000)
			{
				for (size_t j = 0; j < width; ++j)
				{
					for (size_t k = 0; k < height; ++k)
					{
						magnetization += area[j][k];
					}
				}
				average_magnetization += magnetization;
				freq[demon_energy]++;
			}
			x = NULL;
			y = NULL;
			magnetization = NULL;
			spin_value = NULL;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/*
			MATH CASE
		*/
		float _x_2{}; //done
		float _x2_{}; //done
		float _x_{}; //done
		float _y_{}; //done
		float _xy_{}; //done
		for (typename _STD map<int, int>::iterator map_iterator = freq.begin(); map_iterator != freq.end(); ++map_iterator)
		{
			_x2_ += pow((*map_iterator).first, 2);
			_x_ += (*map_iterator).first;
			_y_ += log((*map_iterator).second);
			_xy_ += ((*map_iterator).first + log((*map_iterator).second));
		}
		_x_ = static_cast<float>(_x_ / static_cast<float>(freq.size()));
		_x2_ = static_cast<float>(_x2_ / static_cast<float>(freq.size()));
		_xy_ = static_cast<float>(_xy_ / static_cast<float>(freq.size()));
		_x_2 = pow(_x_, 2);
		temperatura = static_cast<float>(-1.f)* static_cast<float>((_x_2 - _x2_) / ((_x_ * _y_) - _xy_));
		file_out << static_cast<float>(static_cast<float>(average_magnetization) / 1000.f) << ',' << temperatura << NEW_LINE;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		demon_energy = NULL;
		temperatura = NULL;
		average_magnetization = NULL;
	}

	//memory free
	for (size_t i = 0; i < static_cast<size_t>(width); ++i)
	{
		delete[] * (area + i);
	}
	delete[] area;

	file_in.close();
	file_out.close();

	system("pause");
	return 0;
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