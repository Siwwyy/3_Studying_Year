#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <iomanip>
#include <math.h>
#include <cstdint>
#include <windows.h>

#define NEW_LINE '\n'

//const __int16 const* const* Read_Inputs(const char * file_name, size_t & width, size_t & height);
__int16** Read_Inputs(const char* file_name, size_t& width, size_t& height);
const void Show_Memory(const __int16 const* const* Matrix, const size_t& width, const size_t& height);
const void Display_Matrix(const __int16 const* const* Matrix, const size_t& width, const size_t& height);
const void Display_Single_Matrix(const __int16 const* Matrix, const size_t& width);
const void Hopfield(__int16** Matrix, const size_t& width);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	__int16** Matrix{};
	size_t width{};
	size_t height{};
	Matrix = Read_Inputs("file.in", width, height);
	Display_Matrix(Matrix, width, height);

	//Hopfield(Matrix, width);	//A letter



	//DEALLOCATE ALLOCATED MEMORY
	for (size_t i = 0; i < height; ++i)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
	system("pause");
	return 0;
}

__int16** Read_Inputs(const char* file_name, size_t& width, size_t& height)
{
	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in | std::ios_base::binary);

	__int16** Matrix{};

	if (file_in.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		char temp{};

		auto to_bool = [](const char& _char) -> __int16 { if (_char == '1') { return 1; } else { return -1; }; };
		file_in >> height;
		file_in >> width;
		Matrix = new __int16* [height];
		for (size_t i = 0; i < height; ++i)
		{
			Matrix[i] = new __int16[width];
			for (size_t j = 0; j < width; ++j)
			{
				file_in >> temp;
				//_STD cout << to_bool(temp) << ' ';
				Matrix[i][j] = to_bool(temp);
			}
			//_STD cout << NEW_LINE;
		}
	}

	file_in.close();

	return Matrix;
}

const void Show_Memory(const __int16 const* const* Matrix, const size_t& width, const size_t& height)
{
	for (size_t i = 0; i < height; ++i)
	{
		_STD cout << "==========================================" << NEW_LINE;
		_STD cout << "THE BEGINNING " << (Matrix + i) << NEW_LINE;
		for (size_t j = 0; j < width; ++j)
		{
			if (j % 5 == 0 && j > 0)
			{
				_STD cout << NEW_LINE;
			}
			_STD cout << ((Matrix + i) + j) << ' ';
		}
		_STD cout << NEW_LINE;
		_STD cout << "==========================================" << NEW_LINE;
		_STD cout << NEW_LINE;
	}
}

const void Display_Matrix(const __int16 const* const* Matrix, const size_t& width, const size_t& height)
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			if (j % 5 == 0 && j > 0)
			{
				_STD cout << NEW_LINE;
			}
			if (Matrix[i][j] == 1)
			{
				SetConsoleTextAttribute(hndl, 0x003);
				_STD cout << "x";
			}
			else if (Matrix[i][j] == -1)
			{
			SetConsoleTextAttribute(hndl, 14);
			_STD cout << "o";
			}

			//_STD cout << Matrix[i][j] << ' ';
		}
		_STD cout << NEW_LINE;
		_STD cout << NEW_LINE;
	}
	SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

const void Display_Single_Matrix(const __int16 const* Matrix, const size_t& width)
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < width; ++i)
	{
		if (i % 5 == 0 && i > 0)
		{
			_STD cout << NEW_LINE;
		}
		if (Matrix[i] == 1)
		{
			SetConsoleTextAttribute(hndl, 0x003);
			_STD cout << "x";
		}
		else if (Matrix[i] == -1)
		{
			SetConsoleTextAttribute(hndl, 14);
			_STD cout << "o";
		}
	}
	_STD cout << NEW_LINE;
	SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

const void Hopfield(__int16** Matrix, const size_t& width)
{
	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

	float* weights{};
	//float * neurons{};
	weights = new float[width];
	//neurons = new float[width];
	//for (size_t i = 0; i < width; ++i)
	//{
	//	weights[i] = dis(generator);
	//}

	auto delta = [](const size_t& i, const size_t& j) -> const __int16 { if (i == j) { return 1; } else { return 0; }; };
	int_fast16_t sum{};

	bool if_break = true;
	while (if_break)
	{
		//Display_Single_Matrix(Matrix, width);
		//for (size_t i = 0; i < 7; ++i)
		//{
		//	for (size_t j = 0; j < 5; ++j)
		//	{
		//		sum += (Matrix[((i * 5) + i)] * Matrix[((i * 5) + j)]);
		//	}
		//}
		//for (size_t i = 0; i < 7; ++i)
		//{
		//	for (size_t j = 0; j < 5; ++j)
		//	{
		//		weights[static_cast<size_t>((i * 5) + j)] = (1 - delta(i, j)) * sum;
		//	}

		//}




		////for (size_t i = 0; i < width; ++i)
		////{
		////	if (weights[i] > 0)
		////	{
		////		Matrix[i] = 1;
		////	}
		////	else if (weights[i] < 0)
		////	{
		////		Matrix[i] = -1;
		////	}
		////}

		//for (size_t k = 0; k < width; ++k)
		//{
		//	for (size_t i = 0; i < 7; ++i)
		//	{
		//		for (size_t j = 0; j < 5; ++j)
		//		{
		//			if (k != (i * 5) + j)
		//			{
		//				Matrix[k] = weights[static_cast<size_t>((i * 5) + j)] * Matrix[static_cast<size_t>((i * 5) + j)];
		//			}
		//		}
		//	}
		//}
		//system("pause");
		//system("cls");


	}

	delete[] weights;
}