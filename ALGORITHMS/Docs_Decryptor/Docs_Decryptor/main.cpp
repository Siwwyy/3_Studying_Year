#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

void Load_Data(std::string& Data, const std::string file_name);
void Print_Data(std::string& Data);

int main(int argc, char* argv)
{
	std::string Data{};
	Load_Data(Data, "BCH.docx");
	Print_Data(Data);


	system("pause");
	return EXIT_SUCCESS;
}


void Load_Data(std::string& Data, const std::string file_name)
{
	std::fstream file;
	file.open(file_name.c_str(), std::ios_base::in | std::ios_base::binary);
	std::stringstream buffer;
	buffer << file.rdbuf();
	Data = buffer.str();
}

void Print_Data(std::string& Data)
{
	for (typename std::string::const_iterator string_iterator = Data.begin(); string_iterator != Data.end(); ++string_iterator)
	{
		std::cout << *string_iterator;
	}
}