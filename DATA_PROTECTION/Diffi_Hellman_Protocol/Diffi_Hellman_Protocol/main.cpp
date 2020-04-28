#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod);

int main(int argc, char* argv[])
{
	int32_t a{ 4321 };
	int32_t b{ 5678 };
	uint32_t mod{ 9876 };


	std::cout << powmod(a,b,mod) << '\n';

	system("pause");
	return EXIT_SUCCESS;
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
