#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


int main(int argc, char* argv[])
{
	int32_t a{ 4321 };
	int32_t b{ 5678 };
	uint32_t mod{ 9876 };
	int32_t result{1};
	int32_t temp{};

	std::bitset<sizeof(a)*8> bits(b);

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

	std::cout << result << '\n';

	system("pause");
	return EXIT_SUCCESS;
}