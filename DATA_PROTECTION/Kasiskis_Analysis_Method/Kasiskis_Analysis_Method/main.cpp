#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <functional>
#include <sstream>

#define NEW_LINE '\n'

constexpr char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void Load_Data(std::string& Data, const std::string &file_name);
void Find_Occurences(const std::string& Data, size_t minimal_seeking_length);

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::string Data{};
	std::string file_path{};
	size_t minimal_seeking_length{ 3 };

	std::cout << "Podaj sciezke do pliku \n$ ";
	std::cin >> file_path;
	std::cout << "\nPodaj minimalna dlugosc \n$ ";
	std::cin >> minimal_seeking_length;

	if (minimal_seeking_length < 2)
	{
		minimal_seeking_length = 2;
	}

	Load_Data(Data, file_path);
	Find_Occurences(Data, minimal_seeking_length);

	return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

void Load_Data(std::string& Data, const std::string & file_name)
{
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

void Find_Occurences(const std::string& Data, size_t minimal_seeking_length)
{
	std::unordered_map<std::string, std::set<int32_t>> Occurences;
	std::string sub_string{};

	while(minimal_seeking_length <= 20)
	{
		for (size_t i = 0; i < Data.size(); ++i)
		{
			sub_string = Data.substr(i, minimal_seeking_length);
			Occurences[sub_string].insert(i);
		}
		++minimal_seeking_length;
	}

	std::vector<int32_t> Differences{};
	int tab[19]{};

	for (typename std::unordered_map<std::string, std::set<int32_t>>::const_iterator map_iterator = Occurences.begin(); map_iterator != Occurences.end(); ++map_iterator)
	{
		if (map_iterator->second.size() > 1)
		{
			size_t counter{};
			int32_t temporary{ *map_iterator->second.begin() };
			for (typename std::set<int32_t>::iterator set_iterator = map_iterator->second.begin(); set_iterator != map_iterator->second.end(); ++set_iterator)
			{
				if (counter > 0)
				{
					Differences.emplace_back(static_cast<int32_t>(*set_iterator - temporary));
					for (size_t i = 2; i <= 20; ++i)
					{
						if (*(Differences.end() - 1) % i == 0)
						{
							tab[i - 2]++;
						}
					}
				}
				++counter;
			}
		}
	}

	for (size_t i = 0; i < 19; ++i)
	{
		std::cout << "Dla N: " << (i + 2) << " " << tab[i] << std::endl;
	}
}