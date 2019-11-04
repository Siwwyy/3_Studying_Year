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
	__int32 value = 69;
	_STD bitset<sizeof(__int32) * 8> bits = value;
	bool array_start_status[SIZE]{};
	bool array_final_status[SIZE]{};
	bool array_final_status_temp[SIZE]{};
	size_t iterations{100};
	///////////////////////////////////////

	Fill_Array(array_start_status, bits);
	//Display_Array(array_start_status);
	Print(array_start_status);
	Wolfram_Rule(array_start_status, bits, array_final_status);

	//Print(array_start_status);
	__int32 magnet_i{};
	__int32 magnet_i1{};

	//lambda case
	auto magnetization = [](const __int32 & value) -> __int32 { return ((value == 1) ? 1 : (-1)); };
	auto average = [](const bool * array) -> float 
	{	
		__int32 sum{};
		for (size_t i = 0; i < SIZE; ++i)
		{
			sum += array[i];
		}
		return (static_cast<float>(sum) / static_cast<float>(SIZE));
	};


	////////////////////////////////////////
	std::fstream file_out;
	file_out.open("magnetization.csv", std::ios_base::out);
	float temp{};
	float mg{};
	float mg1{};
	for (size_t i = 0; i < iterations; ++i)
	{
		Print(array_final_status);
		for (size_t j = 0; j < SIZE; ++j)
		{
			array_final_status_temp[j] = array_final_status[j];
		}
		Wolfram_Rule(array_final_status_temp, bits, array_final_status);
		//magnet_i += magnetization(array_final_status[i]);
		//magnet_i1 += magnetization(array_final_status[i+1]);
		//_STD cout << "Iteration: " << i << ' ' << array_final_status[14] << ' ' << array_final_status[15] << " | "<< array_final_status[24] << ' ' << array_final_status[25] << NEW_LINE;
		//_STD cout << "Iteration: " << i << ' ' << magnet_i << ' ' << magnet_i1 << NEW_LINE;
		//file_out << magnet_i << ',' << magnet_i1 << NEW_LINE;
		if (i > 0 && i%2 == 0)
		{
			mg1 = average(array_final_status);
			file_out << mg << ',' << mg1 << NEW_LINE;
			mg = mg1;
		}
		else
		{
			mg = average(array_final_status_temp);
		}

	}
	//_STD cout << "Magnetization i: " << magnet_i << " | Magnetization i+1: " << magnet_i1 << NEW_LINE;

	file_out.close();

	system("pause");
	return 0;
}

void Fill_Array(bool array[], _STD bitset<sizeof(__int32) * 8>& bits)
{
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
		if (i == 0)
		{
			temp_bits[0] = array_start[i + 1];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[(SIZE - 1)];

			temp_value = temp_bits.to_ulong();

			array_end[i] = bits[temp_value];
		}
		else if (i > 0 && i < (SIZE - 1))
		{
			temp_bits[0] = array_start[i + 1];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[i - 1];

			temp_value = temp_bits.to_ulong();

			array_end[i] = bits[temp_value];
		}
		else
		{
			temp_bits[0] = array_start[0];
			temp_bits[1] = array_start[i];
			temp_bits[2] = array_start[i-1];

			temp_value = temp_bits.to_ulong();

			array_end[i] = bits[temp_value];
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