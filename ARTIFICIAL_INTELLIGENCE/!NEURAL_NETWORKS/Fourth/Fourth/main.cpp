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

const __int16 const* const* Read_Inputs(const char * file_name, size_t & width, size_t & height);
const void Display_Matrix(const __int16 const* const* Matrix, const size_t & width, const size_t & height);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	const __int16 const* const* Matrix{};
	size_t width{};
	size_t height{};
	Matrix = Read_Inputs("file.in", width, height);
	//Display_Matrix(Matrix, width, height);

	//DEALLOCATE ALLOCATED MEMORY
	//for (size_t i = 0; i < height; ++i);
	//{
	//	delete[] Matrix[i];
	//}
	//delete[] Matrix;
	system("pause");
	return 0;
}

const __int16 const* const* Read_Inputs(const char* file_name, size_t& width, size_t& height)
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

		auto to_bool = [](const char& _char) -> bool { if (_char == '1') { return 1; } else { return -1; }; };
		file_in >> height;
		file_in >> width;
		Matrix = new __int16* [height];
		for (size_t i = 0; i < height; ++i)
		{
			Matrix[i] = new __int16[width];
			for (size_t j = 0; j < width; ++j)
			{
				file_in >> temp;
				_STD cout << temp << ' ';
				Matrix[i][j] = to_bool(temp);
			}
			_STD cout << NEW_LINE;
		}
	}

	file_in.close();

	return Matrix;
}

const void Display_Matrix(const __int16 const* const* Matrix, const size_t& width, const size_t& height)
{
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			//if (Matrix[i][j] == 1)
			//{
			//	_STD cout << "O";
			//}
			//else
			//{
			//	_STD cout << " ";
			//}
			//if (j % 5)
			//{
			//	_STD cout << NEW_LINE;
			//}
			_STD cout << Matrix[i][j] << ' ';
		}
		_STD cout << NEW_LINE;
	}
}
