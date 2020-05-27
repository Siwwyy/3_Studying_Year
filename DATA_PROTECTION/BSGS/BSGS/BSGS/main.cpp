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
	/*uint32_t result{ static_cast<uint32_t>(a) };
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
	return 0;*/

	auto Is_Prime = [](uint32_t number) -> bool
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


	auto Hash = [](const uint32_t aj, const uint32_t p) -> uint32_t
	{
		uint32_t my_hash{};
		my_hash = aj % p;
		return my_hash;
	};

	uint32_t result{ static_cast<uint32_t>(a) };
	uint64_t x{ 1 };
	const uint32_t m{ static_cast<uint32_t>(std::ceil(std::sqrt(mod))) };
	uint32_t p{};
	for (uint32_t i = m; i >= 2; ++i)
	{
		if (Is_Prime(i) == true)
		{
			p = i;
			break;
		}
	}

	std::vector<std::vector<uint32_t>> array{};
	array.resize(static_cast<size_t>(p));

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		array[Hash(static_cast<uint32_t>(x),p)].emplace_back(static_cast<uint32_t>(x));
		x = (x * a);
		x %= mod;
	}

	const int32_t v = powmod(a, mod - m - 1, mod);
	x = d;

	for (size_t i = 0; i < static_cast<size_t>(m); ++i)
	{
		const size_t position = static_cast<size_t>(Hash(static_cast<uint32_t>(x), p));
		std::vector<uint32_t>::iterator vec_iterator{ std::find(array[position].begin(), array[position].end(), x) };
		if (vec_iterator != array[position].end())
		{
			return static_cast<uint32_t>(i * m + std::distance(array[position].begin(), vec_iterator) + i + 1);
		}
		x = (x * v);
		x %= mod;
	}
	return 0;
}