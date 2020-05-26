#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <string>


const int32_t Multiplication(const int32_t a, const int32_t n, const int32_t d);
const int32_t Baby_Giant_Step(const int32_t a, const int32_t n, const int32_t d);


int main(int argc, char* argv[])
{
	std::cout << Multiplication(3, 17, 2) << '\n';

	std::cin.get();
	return EXIT_SUCCESS;
}

const int32_t Multiplication(const int32_t a, const int32_t n, const int32_t d)
{
	int32_t result{ a };
	int32_t x{ 1 };

	while (result != d)
	{
		result *= a;
		result %= n;
		++x;
	}

	return x;
}

const int32_t Baby_Giant_Step(const int32_t a, const int32_t n, const int32_t d)
{
	return int32_t();
}