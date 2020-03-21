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
	const size_t minimal_seeking_length{ 5 };


	//Load_Data(Data, "file.in");
	Load_Data(Data, "Out.out");
	//Load_Data(Data, "file_big.in");
	//Load_Data(Data, "file2.in");
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
	auto length_case = [](const size_t& _Left, const size_t _Right) -> bool
	{
		return _Left != _Right;
	};

	std::vector<std::vector<std::pair<std::string, size_t>>> Temp{};
	std::vector<std::pair<std::string, size_t>> Temp_Second{};
	std::set<std::string> visitied{};

	//while(length_case(minimal_seeking_length,static_cast<size_t>((Data.length() + 1)/2)))
	while(minimal_seeking_length <= 20)
	{
		for (typename std::string::const_iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
		{
			const size_t current_position = std::distance(Data.begin(), string_iterator);
			if (length_case(static_cast<size_t>(current_position + minimal_seeking_length), Data.length() + 1))
			{
				std::string second_sub_string{};
				sub_string = Data.substr(current_position, minimal_seeking_length);
				if (visitied.find(sub_string) == visitied.end())
				{
					visitied.insert(sub_string);
					for (typename std::string::const_iterator string_iterator_third = string_iterator; string_iterator_third != Data.end(); ++string_iterator_third)
					{
						const size_t second_current_position = std::distance(Data.begin(), string_iterator_third);
						if (length_case(static_cast<size_t>(second_current_position + minimal_seeking_length), Data.length() + 1))
						{
							std::string second_sub_string{};
							second_sub_string = Data.substr(second_current_position, minimal_seeking_length);
							if (second_sub_string == sub_string)
							{
								Temp_Second.emplace_back(std::make_pair(sub_string, second_current_position));
							}
						}
						else
						{
							if (Temp_Second.size() > 1)
							{
								Temp.emplace_back(Temp_Second);
							}		
							Temp_Second.clear();
							break;
						}
					}
				}
			}
			else
			{
				break;
			}			
		}
		++minimal_seeking_length;
	}

	std::vector<int32_t> Differences{};
	int tab[19]{};

	for (typename std::vector<std::vector<std::pair<std::string, size_t>>>::const_iterator vec_iterator = Temp.begin(); vec_iterator != Temp.end(); ++vec_iterator)
	{
		for (typename std::vector<std::pair<std::string, size_t>>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != (vec_iterator->end() - 1); ++vec_iterator_second)
		{
			Differences.emplace_back((vec_iterator_second + 1)->second - vec_iterator->begin()->second);
		}
	}

	for (typename std::vector<int32_t>::const_iterator vec_iterator = Differences.begin(); vec_iterator != Differences.end(); ++vec_iterator)
	{
		for (size_t i = 2; i <= 20; ++i)
		{
			if (*vec_iterator % i == 0)
			{
				tab[i - 2]++;
			}
		}
	}

	for (size_t i = 0; i < 19; ++i)
	{
		std::cout << "Dla N: " << (i + 2) << " " << tab[i] << std::endl;
	}
}