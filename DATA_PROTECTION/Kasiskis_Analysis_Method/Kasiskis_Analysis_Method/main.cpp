#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <sstream>

#define NEW_LINE '\n'

constexpr char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void Load_Data(std::string& Data, const std::string &file_name);
void Print_Data(const std::string& Data);
void Find_Occurences(const std::string& Data, std::string& Occurences, size_t minimal_seeking_length);

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::string Data{};
	std::string Occurences{};
	const size_t minimal_seeking_length{ 3 };


	Load_Data(Data, "file.in");
	//Print_Data(Data);

	Find_Occurences(Data, Occurences, minimal_seeking_length);

	system("pause");
	return EXIT_SUCCESS;
}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



void Load_Data(std::string& Data, const std::string & file_name)
{
	//std::fstream file;
	//file.open(file_name.c_str(), std::ios_base::in);
	//std::stringstream buffer;
	//buffer << file.rdbuf();
	//Data = buffer.str();
	//file.close();
	std::fstream file_in{};
	file_in.open(file_name.c_str(), std::ios_base::in);
	if (file_in.good() == false)
	{
		std::cerr << "[ FILE UNABLE TO OPEN ] \n";
		file_in.close();
	}
	else
	{
		auto If_correct_sign = [&](const char _sign) -> bool
		{
			int32_t sign_value = static_cast<char>(_sign);
			if (sign_value >= 97 && sign_value <= 122)
			{
				sign_value -= 32;
			}

			if ((sign_value >= 48 && sign_value <= 57))
			{
				return true;
			}
			else if (sign_value >= 65 && sign_value <= 90)
			{
				return true;
			}
			return false;
		};

		auto Sign_Value = [&](const char _sign) -> char
		{
			int8_t sign_value = static_cast<int8_t>(_sign);
			if (sign_value >= 97 && sign_value <= 122)
			{
				sign_value -= 32;
			}
			return static_cast<char>(sign_value);
		};

		char temp{};
		while (file_in.eof() == false)
		{
			file_in.read(&temp, sizeof(char));
			if (If_correct_sign(temp))
			{
				Data += temp;
			}
			temp = {};
		}
	}
	file_in.close();
}

void Print_Data(const std::string& Data)
{
	for (typename std::string::const_iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
	{
		std::cout << *string_iterator;
	}
	std::cout << NEW_LINE;
}

void Find_Occurences(const std::string& Data, std::string& Occurences, size_t minimal_seeking_length)
{
	std::string sub_string{};
	while(minimal_seeking_length != Data.length())
	{
		//std::cout << minimal_seeking_length << ' ' << Data.length() << '\n';
		for (typename std::string::const_iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
		{
			std::string second_sub_string{};
			const size_t current_position = std::distance(Data.begin(), string_iterator);
			sub_string = Data.substr(current_position, minimal_seeking_length);
			//std::cout << sub_string << '\n';
			//std::cout << current_position << ' ' << current_position + minimal_seeking_length << ' ' << sub_string << '\n';
			for (typename std::string::const_iterator string_iterator_third = string_iterator; string_iterator_third != Data.end(); ++string_iterator_third)
			{
				std::string second_sub_string{};
				const size_t second_current_position = std::distance(Data.begin(), string_iterator_third);
				second_sub_string = Data.substr(second_current_position, minimal_seeking_length);
				if (sub_string == second_sub_string && second_sub_string.length() == minimal_seeking_length)
				{
					std::cout << sub_string << '\n';
				}
				/*std::cout << second_sub_string << '\n';*/
			}
			std::cin.get();
		}
		++minimal_seeking_length;
	}
}