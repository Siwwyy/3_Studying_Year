#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <algorithm>


const uint64_t Power(uint64_t base, uint64_t power);
//const uint64_t Lucas_Lehmer(uint64_t last_value, uint64_t k);
void Lucas_Lehmer(uint64_t p);
bool Is_Prime(uint64_t number);




int main(int argc, char* argv[])
{
	const size_t k{ 31 };
	for (size_t i = 3; i <= k; ++i)
	{
		if (static_cast<uint64_t>(i) % 2 != 0 && Is_Prime(static_cast<uint64_t>(i)) == true)
		{
			std::cout << "2^" << i << " - 1 = " << (Power(2, static_cast<uint64_t>(i)) - 1) << " | ";
			Lucas_Lehmer(static_cast<uint64_t>(i));
		}
	}


	system("pause");
	return EXIT_SUCCESS;
}


const uint64_t Power(uint64_t base, uint64_t power)
{
	uint64_t result = 1;
	while (power > 0)
	{
		if (power % 2 == 1)
		{
			result = (result * base);
		}
		base = (base * base);
		power = power / 2;
	}
	return result;
}

void Lucas_Lehmer(uint64_t p)
{
	uint64_t s{ 4 };
	uint64_t M{ Power(2,p) - 1 };

	for (size_t i = 0; i < static_cast<size_t>((p - 2)); ++i)
	{
		s = ((s * s) - 2) % M;
	}
	if (s == 0)
	{
		std::cout << "Pierwsza\n";
	}
	else
	{
		std::cout << "Zlozona\n";
	}
}

bool Is_Prime(uint64_t number)
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

}

//const uint64_t Lucas_Lehmer(uint64_t last_value, uint64_t k)
//{
//	if (k == 0)
//	{
//		return static_cast<uint64_t>(4);
//	}
//	else
//	{
//		return static_cast<uint64_t>((Power(last_value,2)) - 2);
//	}
//}
