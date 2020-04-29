#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod);

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



	int32_t p{ 7 };	//check is it a prime number always !
	int32_t g{ 2 };

	/*
		SECRET NUMBERS
	*/

	int32_t Alicja{ 5 };
	int32_t Bob{ 4 };

	/////////////////////////////////////
	std::cout << "p=";
	std::cin >> p;
	std::cout << "g=";
	std::cin >> g;
	std::cout << "a=";
	std::cin >> Alicja;

	int32_t A = powmod(g, Alicja, p);	//powmod

	std::cout << "b=";
	std::cin >> Bob;

	int32_t B = powmod(g, Bob, p);		//powmod


	int32_t k_A{ 1 };
	int32_t k_B{ };

	//std::cout << A << " " << B;
	//while (k_A != k_B)
	//{
	//	k_A = powmod(B, Alicja, p);
	//	k_B = powmod(A, Bob, p);
	//}
	k_A = powmod(B, Alicja, p);
	k_B = powmod(A, Bob, p);

	std::cout << k_A << " " << k_B << '\n';

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