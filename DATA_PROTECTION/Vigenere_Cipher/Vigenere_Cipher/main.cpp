#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cstdint>

#define NEW_LINE '\n'

void Load_Data(std::string & Data, const std::string file_name);
void Save_Data(std::string & Data, const std::string file_name);
void Initialize_Alphabet(std::vector<std::vector<char>> & Alphabet);
void Print_Alphabet(std::vector<std::vector<char>> & Alphabet);
void Encrypt(std::vector<std::vector<char>> & Alphabet, std::string & Data, std::string& Key);
void Decrypt(std::vector<std::vector<char>> & Alphabet, std::string & Data, std::string& Key);

const std::string our_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main(int argc, char* argv[])
{
	std::string Data{};
	std::vector<std::vector<char>> Alphabet(our_alphabet.size());
	//std::string Key = "9AB";
	std::string Key = "BCDE";
	//Load_Data(Data, "file.in");
	Load_Data(Data, "file.out"); //out means is ready for decrypt
	Initialize_Alphabet(Alphabet);
	/*Print_Alphabet(Alphabet);
	std::cin.get();*/
	//Encrypt(Alphabet, Data, Key);
	Decrypt(Alphabet, Data, Key);
	//Save_Data(Data, "file.out");
	Save_Data(Data, "file_decrypted.out");
	system("pause");
	return 0;
}

void Load_Data(std::string& Data, const std::string file_name)
{
	std::fstream file;
	file.open(file_name.c_str(), std::ios_base::in);
	std::stringstream buffer;
	buffer << file.rdbuf();
	Data = buffer.str();
}

void Save_Data(std::string& Data, const std::string file_name)
{
	std::fstream file;
	file.open(file_name.c_str(), std::ios_base::out);
	std::stringstream buffer(Data);
	file << buffer.rdbuf();
}

void Initialize_Alphabet(std::vector<std::vector<char>>& Alphabet)
{
	size_t counter{};
	for (typename std::vector<std::vector<char>>::iterator vec_iterator_first = Alphabet.begin(); vec_iterator_first != Alphabet.end(); ++vec_iterator_first)
	{
		vec_iterator_first->resize(our_alphabet.size());
		for (typename std::vector<char>::iterator vec_iterator_second = vec_iterator_first->begin(); vec_iterator_second != vec_iterator_first->end(); ++vec_iterator_second)
		{
			*vec_iterator_second = our_alphabet.at(static_cast<size_t>(((0 + std::distance(Alphabet.begin(),vec_iterator_first) + counter) % our_alphabet.size())));
			counter++;
		}
	}
}

void Print_Alphabet(std::vector<std::vector<char>>& Alphabet)
{
	for (typename std::vector<std::vector<char>>::iterator vec_iterator_first = Alphabet.begin(); vec_iterator_first != Alphabet.end(); ++vec_iterator_first)
	{
		for (typename std::vector<char>::iterator vec_iterator_second = vec_iterator_first->begin(); vec_iterator_second != vec_iterator_first->end(); ++vec_iterator_second)
		{
			std::cout << *vec_iterator_second << ' ';
		}
		std::cout << '\n';
	}
}

void Encrypt(std::vector<std::vector<char>>& Alphabet, std::string& Data, std::string & Key)
{
	auto Correct_Sign = [&](char & sign) -> bool
	{
		int8_t sign_value = static_cast<int8_t>(sign);
		if (sign_value >= 97 && sign_value <= 122)
		{
			sign_value -= 32;

		}

		if ((sign_value >= 48 && sign_value <= 57))
		{
			sign = static_cast<char>(sign_value);
			return true;
		}
		else if (sign_value >= 65 && sign_value <= 90)
		{
			sign = static_cast<char>(sign_value);
			return true;
		}
		return false;
	};
	std::string::iterator string_iterator_key = Key.begin();
	for (typename std::string::iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
	{
		if (Correct_Sign(*string_iterator) == true)
		{
			if (string_iterator_key != Key.end())
			{
				std::vector<char>::iterator it = std::find(Alphabet[0].begin(), Alphabet[0].end(), *string_iterator);
				std::vector<char>::iterator it_second = std::find(Alphabet[0].begin(), Alphabet[0].end(), *string_iterator_key);

				const size_t position_data = std::distance(Alphabet[0].begin(), it);
				const size_t position_key = std::distance(Alphabet[0].begin(), it_second);

				//std::cout << *it << " -> " << Alphabet[position_key][position_data] << '\n';
				//std::cin.get();
				//*string_iterator = it_second[position];
				*string_iterator = Alphabet[position_key][position_data];
				++string_iterator_key;
			}
			if (string_iterator_key == Key.end())
			{
				string_iterator_key = Key.begin();
			}
		}
	}
}

void Decrypt(std::vector<std::vector<char>>& Alphabet, std::string& Data, std::string& Key)
{
	auto Correct_Sign = [&](const char& sign) -> bool
	{
		int8_t sign_value = static_cast<int8_t>(sign);
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
	std::string::iterator string_iterator_key = Key.begin();
	for (typename std::string::iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
	{
		if (Correct_Sign(*string_iterator) == true)
		{
			if (string_iterator_key != Key.end())
			{
				//std::vector<char>::iterator it = std::find(Alphabet[0].begin(), Alphabet[0].end(), *string_iterator);
				//std::vector<char>::iterator it_second = std::find(Alphabet[0].begin(), Alphabet[0].end(), *string_iterator_key);

				//const size_t position_data = std::distance(Alphabet[0].begin(), it);
				//const size_t position_key = std::distance(Alphabet[0].begin(), it_second);

				//std::cout << *it << " -> " << Alphabet[position_key][position_data] << '\n';
				//std::cin.get();
				//*string_iterator = it_second[position];

				std::vector<char>::iterator it = std::find(Alphabet[0].begin(), Alphabet[0].end(), *string_iterator_key);
				const size_t position_data = std::distance(Alphabet[0].begin(), it);
				std::vector<char>::iterator it_second = std::find(Alphabet[position_data].begin(), Alphabet[position_data].end(), *string_iterator);
				const size_t position_key = std::distance(Alphabet[position_data].begin(), it_second);

				*string_iterator = Alphabet[0][position_key];
				++string_iterator_key;
			}
			if (string_iterator_key == Key.end())
			{
				string_iterator_key = Key.begin();
			}
		}
	}
}