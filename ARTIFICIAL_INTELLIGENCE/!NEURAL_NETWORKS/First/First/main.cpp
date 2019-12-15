#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <random>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'
#define e 2.71828182

template <typename _Variable_Type, _STD size_t N>
constexpr _STD size_t Array_Size(const _Variable_Type(&_array)[N]) noexcept;
void Fill_Matrix(bool Matrix[2][7][5]);
void Print_Matrix(bool Matrix[2][7][5]);
void Save_Weights(const float * const Weights, const size_t & size);
const float f(const float value);
const float df(const float value);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;


	bool Matrix[2][7][5]{};	//collection P
	bool T[]{ 0,1 };	//collection T
	constexpr size_t N = 7 * 5;
	float learning_cofficient = 0.2f;
	constexpr float E_max = 0.03;
	float E = 1.f;
	constexpr size_t C_max = 100;
	size_t c{1};
	float y{};
	size_t counter{};
	float weights[N]{};
	float neurons[N]{};

	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(-1.0f, 1.0f);

	//set weights
	for (size_t j = 0; j < N; ++j)
	{
		weights[j] = dis(generator);
	}


	Fill_Matrix(Matrix);
	Print_Matrix(Matrix);

	/*for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 7; ++j)
		{

			for (size_t k = 0; k < 5; ++k)
			{
				neurons[counter] = Matrix[i][j][k];
				++counter;
			}

		}
		counter = 0;
		while (E_max < E)
		{
			if (c >= C_max)
			{
				break;
			}
			float sum{};
			
			for (size_t k = 0; k < N; ++k)
			{
				sum += (neurons[k] * weights[i][k]);
			}

			y = f(sum);

			for (size_t k = 0; k < (N - 1); ++k)
			{
				weights[i][k + 1] = weights[i][k] + (learning_cofficient * (T[i] - y) * (1 - y) * neurons[k] * y);
			}
			_STD cout << "For image nr: " << (i + 1) << " E: " << E << " Y: " << y << " Sum: " << sum << NEW_LINE;
			E = E + static_cast<float>((0.5f) * pow((T[i] - y),2));
			_STD cin.get();
			c++;
		}
	}*/
	for (size_t j = 0; j < 7; ++j)
	{

		for (size_t k = 0; k < 5; ++k)
		{
			neurons[counter] = Matrix[0][j][k];
			++counter;
		}

	}
	weights[0] = 1;
	counter = {};
	while (c < C_max)
	{
		float sum{};
		sum += weights[0]; //adding bias
		for (size_t k = 1; k < N; ++k)
		{
			sum += (neurons[k] * weights[k]);
		}

		y = f(sum);
		//_STD cout << "For image nr: " << (1) << " E: " << E << " Y: " << y << " Sum: " << sum << NEW_LINE;
		//_STD cin.get();
		//for (size_t k = 0; k < (N - 1); ++k)
		//{
		//	//_STD cout << weights[k] + (learning_cofficient * (T[0] - y) * (1 - y) * neurons[k] * y) << NEW_LINE;
		//	_STD cout << weights[k + 1] << NEW_LINE;
		//	weights[k + 1] = weights[k] + (learning_cofficient * (T[0] - y) * (1 - y) * neurons[k] * y);
		//	//_STD cin.get();
		//}
		//E = E + static_cast<float>((0.5f) * pow((T[0] - y), 2));
		//E = (-0.5) * pow(static_cast<float>((T[0] - y)),2);	//counting error
		
		E += static_cast<float>((0.5f) * pow((T[0] - y), 2));
		
		if (E > E_max)
		{
			float mod{};
			for (size_t i = 0; i < 7; i++) 
			{
				for (size_t j = 0; j < 5; j++) 
				{
					mod = -((T[0] - y) * (1 - y) * y * Matrix[0][i][j]);
					weights[counter] = weights[counter] - learning_cofficient * mod;
					counter++;
				}
			}
			learning_cofficient *= 0.95;
		}
		c++;
	}

	Save_Weights(weights,N);
	_STD cout << "Learned" << NEW_LINE;

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

void Save_Weights(const float* const Weights, const size_t & size)
{
	_STD fstream file_out;
	file_out.open("weights_A.out", std::ios_base::out);

	if (file_out.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			file_out << Weights[i] << '\n';
		}
	}

	file_out.close();
}

const float f(const float value)
{
	return static_cast<float>(1.0f /(1.0f + static_cast<float>(pow((1.0f/e),value))));
	//return static_cast<float>(1.0f/(1.0f + pow(e, (-1)*value)));
}

const float df(const float value)
{
	return static_cast<float>(value * (1 - value));
	//return static_cast<float>(1.0f/(1.0f + pow(e, (-1)*value)));
}

template<typename _Variable_Type, ::std::size_t N>
constexpr _STD size_t Array_Size(const _Variable_Type(&_array)[N]) noexcept
{
	return N;
}