#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <iomanip>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'

//const __int16 const* const* Read_Inputs(const char * file_name, size_t & width, size_t & height);
__int16 ** Read_Inputs(const char * file_name, size_t & width, size_t & height);
const void Show_Memory(const __int16 const* const* Matrix, const size_t& width, const size_t& height);
const void Display_Matrix(const __int16 const* const* Matrix, const size_t & width, const size_t & height);

int main(int argc, char* argv[])
{
	//using _STD cout;
	//using _STD endl;
	//using _STD cin;

	//__int16 ** Matrix{};
	//size_t width{35};
	//size_t height{4};
	//Show_Memory(Matrix, width, height);
	//Matrix = Read_Inputs("file.in", width, height);
	//Display_Matrix(Matrix, width, height);
	//Show_Memory(Matrix, width, height);
	////DEALLOCATE ALLOCATED MEMORY
	//for (size_t i = 0; i < height; ++i)
	//{
	//	delete[] Matrix[i];
	//	//Matrix[i] = nullptr;
	//}
	//delete[] Matrix;
	////Matrix = nullptr;
	//Show_Memory(Matrix, width, height);
	//system("pause");
	//return 0;


	using _STD cout;
	using _STD endl;
	using _STD cin;

	__int16** Matrix{};
	size_t width{ 35 };
	size_t height{ 4 };
	Matrix = new __int16* [height];
	for (size_t i = 0; i < height; ++i)
	{
		Matrix[i] = new __int16[width];
		for (size_t j = 0; j < width; ++j)
		{
			Matrix[i][j] = NULL;
		}
	};
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

	__int16 ** Matrix{};

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
			else if(Matrix[i][j] == -1)
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