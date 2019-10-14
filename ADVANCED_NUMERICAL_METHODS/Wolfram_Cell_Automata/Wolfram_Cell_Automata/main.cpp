#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <random>
#include <bitset>


#define NEW_LINE '\n'
#define SIZE 80

void Fill_Array(bool array[], _STD bitset<sizeof(__int32) * 8>& bits);
void Display_Array(bool array[]);
void Wolfram_Rule(bool array_start[], _STD bitset<sizeof(__int32)*8> & bits, bool array_end[]);
void Print(const bool const array_end[]);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	///////////////////////////////////////
	__int32 value = 126;
	_STD bitset<sizeof(__int32) * 8> bits = value;
	bool array_start_status[SIZE]{};
	bool array_final_status[SIZE]{};
	bool array_final_status_temp[SIZE]{};
	size_t iterations{39};
	///////////////////////////////////////

	Fill_Array(array_start_status, bits);
	//Display_Array(array_start_status);
	Print(array_start_status);
	Wolfram_Rule(array_start_status, bits, array_final_status);

	//Print(array_start_status);

	for (size_t i = 0; i < iterations; ++i)
	{
		Print(array_final_status);
		for (size_t j = 0; j < SIZE; ++j)
		{
			array_final_status_temp[j] = array_final_status[j];
		}
		Wolfram_Rule(array_final_status_temp, bits, array_final_status);

	}


	system("pause");
	return 0;
}

void Fill_Array(bool array[], _STD bitset<sizeof(__int32) * 8>& bits)
{
	//array[0] = true;
	//array[1] = false;
	//array[2] = true;
	//array[3] = true;
	//array[4] = false;
	//array[5] = false;
	//array[6] = false;
	//array[7] = true;
	//array[8] = false;
	//array[9] = true;
	//array[10] = true;
	//array[11] = true;
	//array[12] = false;
	///
	for (size_t i = 0; i < SIZE; ++i)
	{
		array[i] = false;
	}
	array[(SIZE / 2)] = true;
}

void Display_Array(bool array[])
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		_STD cout << array[i] << " | ";
	}
	_STD cout << NEW_LINE;
}

void Wolfram_Rule(bool array_start[], _STD bitset<sizeof(__int32) * 8>& bits, bool array_end[])
{
	_STD bitset<3> temp_bits;
	unsigned __int32 temp_value{};
	for (size_t i = 0; i < SIZE; ++i)
	{
		//_STD cout << array[i] << " | ";
		if (i == 0)
		{
			temp_bits[0] = array_start[i + 1];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[(SIZE - 1)];

			temp_value = temp_bits.to_ulong();

			//_STD cout << temp_bits[0] << temp_bits[1] << temp_bits[2] << NEW_LINE;
			//_STD cout << temp_value << ' ' << bits[temp_value] << NEW_LINE;
			array_end[i] = bits[temp_value];
			//_STD cin.get();
		}
		else if (i > 0 && i < (SIZE - 1))
		{
			temp_bits[0] = array_start[i + 1];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[i - 1];

			temp_value = temp_bits.to_ulong();

			//_STD cout << temp_bits[0] << temp_bits[1] << temp_bits[2] << NEW_LINE;
			//_STD cout << temp_value << ' ' << bits[temp_value] << NEW_LINE;
			array_end[i] = bits[temp_value];
			//_STD cin.get();		//	array_end[i] = bits[temp_value];
		}
		else
		{
			temp_bits[0] = array_start[0];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[i-1];

			temp_value = temp_bits.to_ulong();

			//_STD cout << temp_bits[0] << temp_bits[1] << temp_bits[2] << NEW_LINE;
			//_STD cout << temp_value << ' ' << bits[temp_value] << NEW_LINE;
			array_end[i] = bits[temp_value];
			//_STD cin.get();
		}
	}
}

void Print(const bool const array_end[])
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		if (array_end[i] == false)
		{
			_STD cout << ' ';
		}
		else
		{
			_STD cout << '*';
		}
	}
	_STD cout << NEW_LINE;
}
