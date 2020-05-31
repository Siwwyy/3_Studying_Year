#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>
#include <string>
#include <math.h>
#include <cmath>

#define STOPWATCH_ON
#include "StopWatch.h"


const int32_t Multiplication(const int32_t a, const int32_t mod, const int32_t d);
const uint64_t powmod(const uint64_t a, const uint64_t b, const uint64_t mod);
const uint64_t Baby_Giant_Step(const uint64_t a, const uint64_t mod, const uint64_t d);


int main(int argc, char* argv[])
{
	START_STOPWATCH
	std::cout << Baby_Giant_Step(1004289383, 1781692777, 847996840) << '\n';
	STOP_STOPWATCH

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

const uint64_t powmod(const uint64_t a, const uint64_t b, const uint64_t mod)
{
	uint64_t result{ 1 };
	uint64_t temp{};

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

const uint64_t Baby_Giant_Step(const uint64_t a, const uint64_t mod, const uint64_t d)
{
	auto Is_Prime = [](uint64_t & number) -> bool
	{
		bool isPrime = true;

		for (size_t i = 2; i <= static_cast<size_t>(number / 2); ++i)
		{
			if (number % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	};


	auto Hash = [](const uint64_t & aj, const uint64_t & p) -> uint64_t
	{
		return static_cast<uint64_t>(aj % p);
	};

	uint64_t x{ 1 };
	const uint64_t m{ static_cast<uint64_t>(std::ceil(std::sqrt(mod))) };
	uint64_t p{ 0 };
	for (uint64_t i = m; i >= 2; --i)
	{
		if (Is_Prime(i) == true)
		{
			p = i;
			break;
		}
	}

	std::vector<std::vector<std::pair<size_t,uint64_t>>> array{};
	array.resize(static_cast<size_t>(p));

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		array[Hash(static_cast<uint64_t>(x), p)].emplace_back(std::make_pair(i,static_cast<uint64_t>(x)));
		x = (x * a);
		x %= mod;
	}

	const uint64_t v = powmod(a, mod - m - 1, mod);
	x = d;

	auto Comp = [&](const std::pair<size_t, uint64_t>& _pair) -> bool
	{
		if (_pair.second == x)
		{
			return true;
		}
		return false;
	};

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		const size_t position = static_cast<size_t>(Hash(static_cast<uint64_t>(x), p));
		std::vector<std::pair<size_t, uint64_t>>::iterator vec_iterator{ std::find_if(array[position].begin(), array[position].end(), Comp) };
		if (vec_iterator != array[position].end())
		{
			const size_t j = std::distance(array[position].begin(), vec_iterator);
			return static_cast<uint64_t>(i * m + vec_iterator->first);
		}
		x = (x * v);
		x %= mod;
	}
	return 0;
}