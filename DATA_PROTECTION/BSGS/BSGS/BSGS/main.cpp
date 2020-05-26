#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <bitset>
#include <string>
#include <math.h>


const int32_t Multiplication(const int32_t a, const int32_t mod, const int32_t d);
const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod);
const uint32_t Baby_Giant_Step(const int32_t a, const int32_t n, const int32_t d);


int main(int argc, char* argv[])
{
	std::cout << Multiplication(3, 17, 2) << '\n';
	std::cout << Baby_Giant_Step(3, 17, 2) << '\n';

	std::cin.get();
	return EXIT_SUCCESS;
}

const int32_t Multiplication(const int32_t a, const int32_t mod, const int32_t d)
{
	int32_t result{ a };
	int32_t x{ 1 };

	while (result != d)
	{
		result *= a;
		result %= mod;
		++x;
	}

	return x;
}

const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod)
{
	int32_t result{ 1 };
	int32_t temp{};

	std::bitset<sizeof(a) * 8> bits(b);

	temp = a % mod;

	for (size_t i = 0; i < bits.size(); ++i)
	{
		if (bits[i] == 1)
		{
			result *= temp;
			result %= mod;
		}
		temp = (temp * temp) % mod;
	}

	return result;
}

const uint32_t Baby_Giant_Step(const int32_t a, const int32_t mod, const int32_t d)
{
	uint32_t result{ static_cast<uint32_t>(a) };
	uint64_t x{ 1 };
	const uint32_t m{ static_cast<uint32_t>(std::ceil(std::sqrt(mod))) };
	std::vector<uint32_t> array{};

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		array.emplace_back(static_cast<uint32_t>(x));
		x = (x * a);
		x %= mod;
	}

	const int32_t v = powmod(a, mod - m - 1, mod);
	x = d;

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		std::vector<uint32_t>::iterator vec_iterator{ std::find(array.begin(), array.end(), x) };
		if (vec_iterator != array.end())
		{
			auto cos = std::distance(array.begin(), vec_iterator);
			return static_cast<uint32_t>(i*m + std::distance(array.begin(), vec_iterator));
		}
		x = (x * v);
		x %= mod;
	}
	return 0;
}