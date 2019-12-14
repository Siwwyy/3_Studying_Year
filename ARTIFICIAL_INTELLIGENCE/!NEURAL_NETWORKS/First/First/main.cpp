#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <random>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'
#define e 2.71

template <typename _Variable_Type, _STD size_t N>
constexpr _STD size_t Array_Size(const _Variable_Type(&_array)[N]) noexcept;
void Fill_Matrix(bool Matrix[2][7][5]);
void Print_Matrix(bool Matrix[2][7][5]);
const float f(const float value);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;


	bool Matrix[2][7][5]{};	//collection P
	bool T[]{ 0,1 };	//collection T
	constexpr size_t N = 7 * 5;
	constexpr float E_max = 0.03;
	constexpr float E = 0.0f;
	constexpr size_t C_max = 20;
	constexpr __int32 c{};
	constexpr __int32 i{};
	float weights[N]{};
	float neurons[N]{};

	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(-1.0f, 1.0f);

	//set weights
	for (size_t i = 0; i < N; ++i)
	{
		weights[i] = dis(generator);
	}


	Fill_Matrix(Matrix);
	Print_Matrix(Matrix);

	while (E_max <= E)
	{
		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = 0; j < 7; ++j)
			{
				float sum{};
				for (size_t k = 0; k < 5; ++k)
				{
					neurons[(j*N) + k] = Matrix[i][j][k];
				}

				for (size_t k = 0; k < N; ++k)
				{
					sum += neurons[k] * weights[k];
				}
			}
		}
	}

	system("pause");
	return 0;
}

void Fill_Matrix(bool Matrix[2][7][5])
{
	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in | std::ios_base::binary);

	if (file_in.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		char temp{};
		size_t i{};
		auto to_bool = [](const char& _char) -> bool { if (_char == '1') { return 1; } else { return 0; }; };
		while (i < 2)
		{
			for (size_t j = 0; j < 7; ++j)
			{
				for (size_t k = 0; k < 5; ++k)
				{
					file_in >> temp;
					Matrix[i][j][k] = to_bool(temp);
				}
			}
			++i;
		}
	}

	file_in.close();
}

void Print_Matrix(bool Matrix[2][7][5])
{
	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 7; ++j)
		{
			for (size_t k = 0; k < 5; ++k)
			{
				_STD cout << Matrix[i][j][k];
			}
			_STD cout << " ";
		}
		_STD cout << NEW_LINE;
	}
	//_STD cout << __FILE__ << NEW_LINE;
	//_STD cout << __LINE__ << NEW_LINE;
	//Array_Size(*Matrix);
}

const float f(const float value)
{
	return static_cast<float>(1/(1+static_cast<float>(pow((1/e),value))));
}

template<typename _Variable_Type, ::std::size_t N>
constexpr _STD size_t Array_Size(const _Variable_Type(&_array)[N]) noexcept
{
	return N;
}