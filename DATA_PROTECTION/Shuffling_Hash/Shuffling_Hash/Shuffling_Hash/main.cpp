#include <iostream>
#include <cstdint>
#include <vector>
#include <string>


void DJB(const std::string & text);
void Adler32(const std::string& text);


int main(int argc, char* argv[])
{
	DJB("test");

	std::cin.get();
	return EXIT_SUCCESS;
}




void DJB(const std::string& text)
{
	int32_t final_hash{};

}

void Adler32(const std::string& text)
{

}