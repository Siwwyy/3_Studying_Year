#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
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
void Predict_Result(const bool const Matrix[2][7][5], const size_t choice);
void Predict_Result(const bool const Matrix[7][5]);
const float f(const float value);
const float df(const float value);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	srand(time(NULL));


	bool Matrix[2][7][5]{};	//collection P
	bool T[]{ 0,1 };	//collection T
	constexpr size_t N = (7 * 5) + 1;
	float learning_cofficient = 0.5f;
	constexpr float E_max = 0.03;
	float E = 1.f;
	constexpr size_t C_max = 200;
	size_t c{0};
	float y{};
	size_t counter{};
	float weights[N]{};
	float neurons[N]{};
	size_t choice = { 0 };


	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	Fill_Matrix(Matrix);
	//weights[0] = 1; //SET BIAS
	//for (size_t i = 1; i < N; ++i)
	//{
	//	weights[i] = dis(generator);
	//}

	//bool if_break = false;
	//while (c < C_max && if_break == false) 
	//{
	//	float sum{};
	//	__int16 choice = rand() % 2;
	//	if (choice == 0)
	//	{
	//		for (size_t i = 0; i < 7; ++i)
	//		{
	//			for (size_t j = 0; j < 5; ++j)
	//			{
	//				neurons[counter] = Matrix[choice][i][j];
	//				++counter;
	//			}
	//		}		

	//		for (size_t i = 0; i < N; ++i)
	//		{
	//			sum += neurons[i] * weights[i];
	//		}

	//		y = f(sum);

	//		E += static_cast<float>((0.5f) * pow((T[choice] - y), 2));
	//			
	//		if (E > E_max)
	//		{
	//			for (size_t i = 1; i < N; ++i)
	//			{
	//				weights[i] = weights[i] + learning_cofficient * ((-1)*((T[choice] - y))* y*(1-y)*neurons[i]);
	//			}
	//			learning_cofficient *= 0.95;
	//		}
	//		else
	//		{
	//			if_break = true;
	//		}


	//		//////////////////////////////////////////////////////
	//		choice++;
	//		sum = 0.0f;
	//		counter = NULL;

	//			
	//		for (size_t i = 0; i < 7; ++i)
	//		{
	//			for (size_t j = 0; j < 5; ++j)
	//			{
	//				neurons[counter] = Matrix[choice][i][j];
	//				++counter;
	//			}
	//		}

	//		for (size_t i = 0; i < N; ++i)
	//		{
	//			sum += neurons[i] * weights[i];
	//		}

	//		y = f(sum);

	//		E += static_cast<float>((0.5f) * pow((T[choice] - y), 2));

	//		if (E > E_max)
	//		{
	//			for (size_t i = 1; i < N; ++i)
	//			{
	//				weights[i] = weights[i] + learning_cofficient * ((-1) * ((T[choice] - y)) * y * (1 - y) * neurons[i]);
	//			}
	//			learning_cofficient *= 0.95;
	//		}
	//		else
	//		{
	//			if_break = true;
	//		}

	//		counter = NULL;
	//	}
	//	else
	//	{

	//		for (size_t i = 0; i < 7; ++i)
	//		{
	//			for (size_t j = 0; j < 5; ++j)
	//			{
	//				neurons[counter] = Matrix[choice][i][j];
	//				++counter;
	//			}
	//		}

	//		for (size_t i = 0; i < N; ++i)
	//		{
	//			sum += neurons[i] * weights[i];
	//		}

	//		y = f(sum);

	//		E += static_cast<float>((0.5f) * pow((T[choice] - y), 2));

	//		if (E > E_max)
	//		{
	//			for (size_t i = 1; i < N; ++i)
	//			{
	//				weights[i] = weights[i] + learning_cofficient * ((-1) * ((T[choice] - y)) * y * (1 - y) * neurons[i]);
	//			}
	//			learning_cofficient *= 0.95;
	//		}
	//		else
	//		{
	//			if_break = true;
	//		}

	//		//////////////////////////////////////////////////////
	//		choice--;
	//		sum = 0.0f;
	//		counter = NULL;


	//		for (size_t i = 0; i < 7; ++i)
	//		{
	//			for (size_t j = 0; j < 5; ++j)
	//			{
	//				neurons[counter] = Matrix[choice][i][j];
	//				++counter;
	//			}
	//		}

	//		for (size_t i = 0; i < N; ++i)
	//		{
	//			sum += neurons[i] * weights[i];
	//		}

	//		y = f(sum);

	//		E += static_cast<float>((0.5f) * pow((T[choice] - y), 2));

	//		if (E > E_max)
	//		{
	//			for (size_t i = 1; i < N; ++i)
	//			{
	//				weights[i] = weights[i] + learning_cofficient * ((-1) * ((T[choice] - y)) * y * (1 - y) * neurons[i]);
	//			}
	//			learning_cofficient *= 0.95;
	//		}
	//		else
	//		{
	//			if_break = true;
	//		}

	//		counter = NULL;

	//	}
	//	++c;
	//}


	//Save_Weights(weights, N);
	//ALREADY LEARNED
	Predict_Result(Matrix[0]);
	Predict_Result(Matrix[1]);
	Predict_Result(Matrix[0]);
	Predict_Result(Matrix[0]);
	Predict_Result(Matrix[1]);

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
	file_out.open("learned.out", std::ios_base::out);

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

void Predict_Result(const bool const Matrix[2][7][5], const size_t choice)
{
	float result{ 0.0f };
	float X{ 0.0f };
	_STD fstream file_in;
	
	if (choice == 0)
	{
		file_in.open("weights_A.out", std::ios_base::in);

		if (file_in.good() == false)
		{
			_STD cerr << "[WARRNING:0001] Invalid file_path\n";
		}
		else
		{
			float value{};
			for (size_t i = 0; i < 7; i++)
			{
				for (size_t j = 0; j < 5; j++)
				{
					file_in >> value;
					X += (value * Matrix[choice][i][j]);
				}
			}
		}
	}
	else
	{
		file_in.open("weights_C.out", std::ios_base::in);

		if (file_in.good() == false)
		{
			_STD cerr << "[WARRNING:0001] Invalid file_path\n";
		}
		else
		{
			float value{};
			for (size_t i = 0; i < 7; i++)
			{
				for (size_t j = 0; j < 5; j++)
				{
					file_in >> value;
					X += (value * Matrix[choice][i][j]);
				}
			}
		}
	}

	result = f(X);

	_STD cout << "Result: " << result;
	if (result < 0.5)
	{
		_STD cout << " Letter:" << " A" << NEW_LINE;
	}
	else
	{
		_STD cout << " Letter:" << " C" << NEW_LINE;
	}
	file_in.close();
}

void Predict_Result(const bool const Matrix[7][5])
{
	float result{ 0.0f };
	float X{ 0.0f };
	_STD fstream file_in;
	file_in.open("learned.out", std::ios_base::in);

	if (file_in.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		float value{};
		for (size_t i = 0; i < 7; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				file_in >> value;
				X += (value * Matrix[i][j]);
			}
		}
	}

	result = f(X);

	_STD cout << "Result: " << result;
	if (result < 0.5f && result > 0.003f)
	{
		_STD cout << " Letter:" << " A" << NEW_LINE;
	}
	else if(result >= 0.5f && result < 1.0f)
	{
		_STD cout << " Letter:" << " C" << NEW_LINE;
	}
	file_in.close();
}

const float f(const float value)
{
	return static_cast<float>(1.0f /(1.0f + static_cast<float>(pow((1.0f/e),value))));
}

const float df(const float value)
{
	return static_cast<float>(value * (1 - value));
}

template<typename _Variable_Type, ::std::size_t N>
constexpr _STD size_t Array_Size(const _Variable_Type(&_array)[N]) noexcept
{
	return N;
}