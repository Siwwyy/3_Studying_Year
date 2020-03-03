#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define NEW_LINE '\n'

void Load_Data(std::vector<std::vector<char>> & Data, const std::string file_name);
void Load_Data(std::vector<char> & Data, const std::string file_name);
void Save_Data(const std::vector<std::vector<char>> & Data, const std::string file_name);
void Print_Data(const std::vector<std::vector<char>> & Data);
void Encrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value);
void Decrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value);
void Count_Frequency(std::vector<char>& Data, std::map<char, float> & Freq);

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::vector<std::vector<char>> Data{};
	std::vector<char> Data2{};
	std::map<char, float> Freq{};

	//int16_t choice{};
	//int16_t shift_value{};
	//std::cout << "Shift value: ";
	//std::cin >> shift_value;
	//std::cout << NEW_LINE;
	//std::cin >> choice;
	//if (choice == 1)
	//{
	//	Load_Data(Data, "file6.in");
	//	Encrypt_Data(Data, shift_value);
	//	Save_Data(Data, "file6.out");
	//}
	//else if (choice == 2)
	//{
	//	Load_Data(Data, "file6.out");
	//	Decrypt_Data(Data, shift_value);
	//	Save_Data(Data, "file6_decrypted.out");
	//}

	//Load_Data(Data2, "bardzotajnezaszyfrowane.txt");
	//Count_Frequency(Data2, Freq);

	//typedef std::function<bool(std::pair<char, float>, std::pair<char, float>)> Comparator;

	//// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	//Comparator compFunctor = [](std::pair<char, float> elem1, std::pair<char, float> elem2)
	//{
	//	return elem1.second > elem2.second;
	//};

	//// Declaring a set that will store the pairs using above comparision logic
	//std::set<std::pair<char, float>, Comparator> setOfWords(Freq.begin(), Freq.end(), compFunctor);

	//// Iterate over a set using range base for loop
	//// It will display the items in sorted order of values
	//for (std::pair<char, float> element : setOfWords)
	//	std::cout << element.first << " :: " << element.second << std::endl;

	//Load_Data(Data2, "file6.in");
	//Count_Frequency(Data2, Freq);

	//std::cout << '\n';
	//// Declaring a set that will store the pairs using above comparision logic
	//std::set<std::pair<char, float>, Comparator> setOfWords1(Freq.begin(), Freq.end(), compFunctor);

	//// Iterate over a set using range base for loop
	//// It will display the items in sorted order of values
	//for (std::pair<char, float> element : setOfWords1)
	//	std::cout << element.first << " :: " << element.second << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}

void Load_Data(std::vector<std::vector<char>>& Data, const std::string file_name)
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
		char temp{};
		std::vector<char> temp_vector{};
		while (file_in.eof() == false)
		{
			file_in.read(&temp, sizeof(char));
			temp_vector.emplace_back(temp);
			if (temp == '\n')
			{
				Data.emplace_back(temp_vector);
				temp_vector.clear();
			}
			else if (file_in.eof() == true)
			{
				temp_vector.emplace_back('\n');
				Data.emplace_back(temp_vector);
				temp_vector.clear();
			}
			temp = {};
		}
	}
	file_in.close();
}

void Load_Data(std::vector<char>& Data, const std::string file_name)
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
		char temp{};
		while (file_in.eof() == false)
		{
			file_in.read(&temp, sizeof(char));
			if (If_correct_sign(temp))
			{
				Data.emplace_back(temp);
			}
			temp = {};
		}
	}
	file_in.close();
}

void Save_Data(const std::vector<std::vector<char>>& Data, const std::string file_name)
{
	std::fstream file_out{};
	file_out.open(file_name.c_str(), std::ios_base::out);
	if (file_out.good() == false)
	{
		std::cerr << "[ FILE UNABLE TO OPEN ] \n";
		file_out.close();
	}
	else
	{
		for (typename std::vector<std::vector<char>>::const_iterator vec_iterator = Data.begin(); vec_iterator != Data.end(); ++vec_iterator)
		{
			for (typename std::vector<char>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
			{
				if ((*vec_iterator_second) == '\0')
				{
					break;
				}
				else
				{
					file_out << (*vec_iterator_second);
				}
			}
		}
	}
	file_out.close();
}

void Print_Data(const std::vector<std::vector<char>>& Data)
{
	std::cout << "|================================|" << '\n';
	for (typename std::vector<std::vector<char>>::const_iterator vec_iterator = Data.begin(); vec_iterator != Data.end(); ++vec_iterator)
	{
		for (typename std::vector<char>::const_iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			std::cout << *vec_iterator_second;
		}
	}
	std::cout << "|================================|" << '\n';
}

void Encrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value)
{
	shift_value = (shift_value % ::alphabet.size());
	auto Encryptor = [&](const char _sign) -> char
	{
		int8_t sign_value = static_cast<int8_t>(_sign);
		if (sign_value >= 97 && sign_value <= 122)
		{
			sign_value -= 32;
		}

		if ((sign_value >= 48 && sign_value <= 57))
		{
			if (sign_value + shift_value > 57)
			{
				int8_t temp_value = (sign_value + shift_value) - 57 - 1;
				sign_value = 65 + temp_value;
				if (sign_value > 90)
				{
					sign_value = (sign_value - 90 - 1) + 48;
				}
			}
			else
			{
				sign_value += shift_value;
			}
		}
		else if (sign_value >= 65 && sign_value <= 90)
		{
			if (sign_value + shift_value > 90)
			{
				int8_t temp_value = (sign_value + shift_value) - 90 - 1;
				sign_value = 48 + temp_value;
				if (sign_value > 57)
				{
					sign_value = (sign_value - 57 - 1) + 65;
				}
			}
			else
			{
				sign_value += shift_value;
			}
		}
		return static_cast<char>(sign_value);
	};

	for (typename std::vector<std::vector<char>>::iterator vec_iterator = Data.begin(); vec_iterator != Data.end(); ++vec_iterator)
	{
		for (typename std::vector<char>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			*vec_iterator_second = Encryptor(*vec_iterator_second);
		}
	}
}

void Decrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value)
{
	shift_value = (shift_value % ::alphabet.size());
	auto Decryptor = [&](const char _sign) -> char
	{
		int8_t sign_value = static_cast<int8_t>(_sign);
		int8_t shift = shift_value;
		if (sign_value >= 97 && sign_value <= 122)
		{
			sign_value -= 32;
		}

		if ((sign_value >= 48 && sign_value <= 57))
		{
			if (sign_value - shift < 48)
			{
				shift -= (sign_value - 48) + 1;
				sign_value = 90 - shift;
				if (sign_value < 65)
				{
					sign_value = 57 - (65 - sign_value) + 1;
				}
			}
			else
			{
				sign_value -= shift;
			}
		}
		else if (sign_value >= 65 && sign_value <= 90)
		{
			if (sign_value - shift < 65)
			{
				shift -= (sign_value - 65) + 1;
				sign_value = 57 - shift;
				if (sign_value < 48)
				{
					sign_value = 90 - (48 - sign_value) + 1;
				}
			}
			else
			{
				sign_value -= shift;
			}
		}
		return static_cast<char>(sign_value);
	};

	for (typename std::vector<std::vector<char>>::iterator vec_iterator = Data.begin(); vec_iterator != Data.end(); ++vec_iterator)
	{
		for (typename std::vector<char>::iterator vec_iterator_second = vec_iterator->begin(); vec_iterator_second != vec_iterator->end(); ++vec_iterator_second)
		{
			*vec_iterator_second = Decryptor(*vec_iterator_second);
		}
	}
}

void Count_Frequency(std::vector<char>& Data, std::map<char, float>& Freq)
{
	for (typename std::vector<char>::iterator vec_iterator = Data.begin(); vec_iterator != Data.end(); ++vec_iterator)
	{
		Freq[*vec_iterator]++;
	}

	for (typename std::map<char, float>::iterator map_iterator = Freq.begin(); map_iterator != Freq.end(); ++map_iterator)
	{
		map_iterator->second = static_cast<float>(map_iterator->second / Data.size()) * 100;
	}
}