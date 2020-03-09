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
void Initialize_Alphabet(std::vector<std::vector<char>> & Alphabet, const int32_t Shift_Value);

int main(int argc, char* argv[])
{
	std::string Data{};
	std::vector<std::vector<char>> Alphabet{};
	Load_Data(Data, "file.in");
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

void Initialize_Alphabet(std::vector<std::vector<char>>& Alphabet , const int32_t Shift_Value)
{

}
