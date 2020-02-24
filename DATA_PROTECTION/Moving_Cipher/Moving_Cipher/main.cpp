#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define NEW_LINE '\n'

void Load_Data(std::vector<std::vector<char>> & Data, const std::string file_name);
void Save_Data(const std::vector<std::vector<char>> & Data, const std::string file_name);
void Print_Data(const std::vector<std::vector<char>> & Data);
void Encrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value);
void Decrypt_Data(std::vector<std::vector<char>>& Data, size_t shift_value);

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;

	std::vector<std::vector<char>> Data{};

	int16_t choice{};
	int16_t shift_value{};
	std::cout << "Shift value: ";
	std::cin >> shift_value;
	std::cout << NEW_LINE;
	std::cin >> choice;
	if (choice == 1)
	{
		Load_Data(Data, "file3.in");
		Encrypt_Data(Data, shift_value);
		Save_Data(Data, "file3.out");
	}
	else if (choice == 2)
	{
		Load_Data(Data, "file3.out");
		Decrypt_Data(Data, shift_value);
		Save_Data(Data, "file3_decrypted.out");
	}
	//Print_Data(Data);

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
				if ((*vec_iterator_second) != '\0')
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
	const std::string alphabet = "ABCDEFGHIJKLMNOUPRSTWUXYZ0123456789";
	shift_value %= alphabet.size() + 1;
	auto Encryptor = [&](const char _sign) -> char
	{
		int32_t sign_value = static_cast<char>(_sign);
		if (sign_value >= 97 && sign_value <= 122)
		{
			sign_value -= 32;
		}

		if ((sign_value >= 48 && sign_value <= 57))
		{
			if (sign_value + shift_value > 57)
			{
				int32_t temp_value = (57 - sign_value) - 57;
				sign_value = (65 + temp_value) - 1;
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
				int32_t temp_value = (sign_value + shift_value) - 90;
				sign_value = (48 + temp_value) - 1;
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
	const std::string alphabet = "ABCDEFGHIJKLMNOUPRSTWUXYZ0123456789";
	shift_value %= alphabet.size() + 1;
	auto Encryptor = [&](const char _sign) -> char
	{
		int32_t sign_value = static_cast<char>(_sign);
		if (sign_value >= 97 && sign_value <= 122)
		{
			sign_value -= 32;
		}

		if ((sign_value >= 48 && sign_value <= 57))
		{
			if (sign_value - shift_value < 48)
			{
				int32_t temp_value = (sign_value - 48);
				sign_value = (90 - (shift_value - temp_value - 1));
			}
			else
			{
				sign_value -= shift_value;
			}
		}
		else if (sign_value >= 65 && sign_value <= 90)
		{
			if (sign_value - shift_value < 65)
			{
				int32_t temp_value = (sign_value - 65);
				sign_value = (57 - (shift_value - temp_value - 1));
			}
			else
			{
				sign_value -= shift_value;
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