
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <random>
#include <map>
#include <complex.h>

#include "Complex.hpp"

#define NEW_LINE '\n'
#define E 2.71
#define Pi 3.14


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in);

	///////////////////////////////////////////
	size_t N{};
	float temp{};
	///////////////////////////////////////////

	file_in >> N;

	_STD vector<Complex::Complex> data(N);
	_STD vector<float> Cn(N);


	for (size_t i = 0; i < N; ++i)
	{
		file_in >> temp;
		data[i].Set_Re(temp);
		file_in >> temp;
		data[i].Set_Im(temp);
		temp = 0.0f;
	}

	//for (size_t i = 0; i < N; ++i)
	//{
	//	data[i].Print();
	//}

	//N w naszym przypadku to 8 -> ilosc przypadkow
	//n liczba na ktorej aktualnie jest
	for (size_t i = 0; i < N; ++i)
	{
		float value{};
		float temp_Im{};
		float temp_Re{};
		for (size_t j = 0; j < N; ++j)
		{
			//value = *(I._Val);
			//temp += static_cast<float>(pow(E, (data[i].Get_Re() * (value * (2*Pi*i)))/N));
			temp_Re += data[j].Get_Re() * cos((2 * M_PI * i * j) / N);
			temp_Im += data[j].Get_Re() * sin((2 * M_PI * i * j) / N);
		}
		//Cn[i] = temp;
		if (temp_Re < 0.01f && temp_Re > -0.01f)
		{
			temp_Re = 0.0f;
		}
		if (temp_Im < 0.01f && temp_Im > -0.01f)
		{
			temp_Im = 0.0f;
		}
		_STD cout << "i: " << i << " Real: " << temp_Re << " Imaginary: " << temp_Im << NEW_LINE;
	}

	/*for (size_t i = 0; i < N; ++i)
	{
		_STD cout << Cn[i] << NEW_LINE;
	}*/

	system("pause");
	return 0;
}