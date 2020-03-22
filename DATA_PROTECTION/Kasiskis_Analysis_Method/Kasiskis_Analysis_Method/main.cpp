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
void Find_Occurences(const std::string& Data, size_t minimal_seeking_length);

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::string Data{};
	const size_t minimal_seeking_length{ 5 };


	//Load_Data(Data, "file.in");
	Load_Data(Data, "Out.out");
	//Load_Data(Data, "file_big.in");
	//Load_Data(Data, "file2.in");
	//Print_Data(Data);

	Find_Occurences(Data, minimal_seeking_length);

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

void Find_Occurences(const std::string& Data, size_t minimal_seeking_length)
{

	//std::vector<std::vector<std::pair<std::string, size_t>>> Temp{};
	//std::vector<std::pair<std::string, size_t>> Temp_Second{};
	//std::set<std::string> visitied{};

	std::map<std::string, std::set<int32_t>> Occurences;
	std::string sub_string{};
	
	while(minimal_seeking_length <= 20)
	{
		for (size_t i = 0; i < Data.size(); ++i)
		{
			sub_string = Data.substr(i, minimal_seeking_length);
			if (sub_string.size() == minimal_seeking_length)
			{
				Occurences[sub_string].insert(i);
//				std::cout << sub_string << '\n';
			}
		}
		//std::cin.get();
		++minimal_seeking_length;
	}

	std::vector<int32_t> Differences{};
	int tab[19]{};

	for (typename std::map<std::string, std::set<int32_t>>::const_iterator map_iterator = Occurences.begin(); map_iterator != Occurences.end(); ++map_iterator)
	{
		if (map_iterator->second.size() > 1)
		{
			//std::cout << map_iterator->first << " : ";
			for (typename std::set<int32_t>::const_iterator set_iterator = map_iterator->second.begin(); set_iterator != map_iterator->second.end(); ++set_iterator)
			{
				//std::cout << *set_iterator << ' ';
				//int32_t temporary{ *map_iterator->second.begin() };
				Differences.emplace_back((*set_iterator) - *map_iterator->second.begin());
				
			}
			//std::cout << '\n';
		}

	}
	//system("pause");

	for (typename std::vector<int32_t>::const_iterator vec_iterator = Differences.begin(); vec_iterator != Differences.end(); ++vec_iterator)
	{
		for (size_t i = 2; i <= 20; ++i)
		{
			if (*(vec_iterator) % i == 0)
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