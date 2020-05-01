#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod);
bool Is_Prime(const int32_t a);

int main(int argc, char* argv[])
{
	//Zadanie1
	//int32_t a{ 4321 };
	//int32_t b{ 5678 };
	//uint32_t mod{ 9876 };

	//std::cout << powmod(a,b,mod) << '\n';

	//////////////////////////////////////////////////////////////////////////

	//Zadanie2

	/*
		1. A = g^a->(choosen number for Alicja) % p
		   B = g^b->(choosen number for Bob) % p

		2. k_A = B^a % p
		   k_B = A^b % p
	*/



	int32_t p{};	//check is it a prime number always !
	int32_t g{};

	/*
		SECRET NUMBERS
	*/

	int32_t a{};
	int32_t b{};

	/////////////////////////////////////
	std::cout << "p=";
	std::cin >> p;
	if (Is_Prime(p) == true)
	{
		std::cout << "g=";
		std::cin >> g;
		std::cout << "a=";
		std::cin >> a;

		int32_t A = powmod(g, a, p);	//powmod
		std::cout << "A=" << A << '\n';

		int32_t B{};
		std::cout << "B=";
		std::cin >> B;

		/*int32_t B{}*/; /*= powmod(g, b, p)*/;		//powmod

		int32_t k = powmod(B, a, p);
		std::cout << "k=" << k << '\n';
	}

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

bool Is_Prime(const int32_t a)
{
	int32_t root = sqrt(a);
	bool is_prime = true;

	for (size_t i = 2; i <= root; ++i) 
	{
		if (a % i == 0) 
		{
			is_prime = false;
			break;
		}
	}

	return is_prime;
}