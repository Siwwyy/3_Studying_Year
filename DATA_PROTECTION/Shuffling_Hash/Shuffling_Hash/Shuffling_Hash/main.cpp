#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <string>

constexpr char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

const int32_t DJB(const std::string& text);
const int32_t Adler32(const std::string& text);
const std::string& Get_Text(const size_t size);


int main(int argc, char* argv[])
{
	std::cout << DJB("test");
	std::cout << '\n';
	std::cout << Adler32("test");

	std::cin.get();
	return EXIT_SUCCESS;
}




const int32_t DJB(const std::string& text)
{
	int32_t starting_value{ 5381 };
	int32_t final_hash{ starting_value };

	for (size_t i = 0; i < text.size(); ++i)
	{
		final_hash = final_hash * 32 + final_hash + static_cast<int32_t>(text[i]);
		//std::cout << final_hash << '\n';
	}
	//std::cout << '\n';
	return final_hash;
}

const int32_t Adler32(const std::string& text)
{
	int32_t A{ 1 };
	int32_t B{ 0 };
	int32_t P{ 65521 };

	for (size_t i = 0; i < text.size(); ++i)
	{
		A = (A + static_cast<int32_t>(text[i])) % P;
		B = (B + A) % P;
		//std::cout << "a=" << A << " b=" << B << '\n';
	}
	//std::cout << '\n';
	return ((B * P) + A);
}

const std::string& Get_Text(const size_t size)
{
	std::string text{};
	std::random_device rand;

	std::default_random_engine rand_engine(rand());
	std::uniform_int_distribution<int> dist(0, 6);
	for (size_t i = 0; i < size; ++i)
	{
		text += alphabet[];
	}

	return text;
}
