#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <random>




const int32_t powmod(const int32_t a, const int32_t b, const uint32_t mod);
bool Is_Prime(const int32_t a);
const int32_t NWD(int32_t a, int32_t b);
const int32_t Inverse_Euclidean(int32_t a, int32_t b);




int main(int argc, char* argv[])
{
	int32_t p{};
	int32_t q{};

	std::cout << "Podaj p \n$ ";
	std::cin >> p;
	std::cout << "Podaj q \n$ ";
	std::cin >> q;

	if (Is_Prime(p) == true && Is_Prime(q) == true)
	{

		int32_t n{ p * q };
		int32_t fin{ (p - 1) * (q - 1) };	//fi(n)
		int32_t e{ 2 };
		int32_t d{};

		while (d == -1 || d == 0)
		{
			d = Inverse_Euclidean(e, fin);
			if (e < fin)
			{
				e++;
			}
			else
			{
				break;
			}
		}
		std::cout << "n: " << n << '\n';
		std::cout << "fi(n): " << fin << '\n';
		std::cout << "e: " << e << '\n';
		std::cout << "d: " << d << '\n';

		//std::string Text{ "DAMIAN_ANDRYSIAK" };
		std::string Text{ };
		std::cout << "Podaj tekst \n$ ";
		std::cin >> Text;
		size_t amount_of_blocks{ static_cast<size_t>(ceil((double)((double)Text.size() / (double)3))) };
		size_t counter{};

		int32_t** Blocks;
		int32_t* Blocks_Values;
		Blocks = new int32_t * [amount_of_blocks] {};
		Blocks_Values = new int32_t[amount_of_blocks]{};
		for (size_t i = 0; i < amount_of_blocks; ++i)
		{
			Blocks[i] = new int32_t[3];
			for (size_t j = 0; j < 3; ++j)
			{
				if (counter < Text.size())
				{
					Blocks[i][j] = static_cast<int32_t>(Text[counter]);
					++counter;
				}
				else
				{
					Blocks[i][j] = 0;
				}
			}
			Blocks_Values[i] = (Blocks[i][0] << 16) + (Blocks[i][1] << 8) + (Blocks[i][2]);	//poniewaz mamy bloki 3 elementowe
		}

		//ZASZYFROWANE
		for (size_t i = 0; i < amount_of_blocks; ++i)
		{
			std::cout << Blocks_Values[i] << ' ';
		}
		std::cout << '\n';
		//ODSZYFROWANE
		for (size_t i = 0; i < amount_of_blocks; ++i)
		{
			std::cout << static_cast<char>((Blocks_Values[i] / 65536) % 256);
			std::cout << static_cast<char>((Blocks_Values[i] / 256) % 256);
			std::cout << static_cast<char>((Blocks_Values[i]) % 256);
		}
		std::cout << '\n';

		for (size_t i = 0; i < amount_of_blocks; ++i)
		{
			delete[] Blocks[i];
		}
		delete[] Blocks;
		delete[] Blocks_Values;
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

const int32_t NWD(int32_t a, int32_t b)
{
	int32_t temp{};
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

const int32_t Inverse_Euclidean(int32_t a, int32_t b)
{
	int32_t q{}, r1{ a }, r2{ b }, r{}, s1{}, s2{}, s{}, t1{}, t2{}, t{};

	//Initialize variables
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;

	while (r2 != 0)
	{
		q = static_cast<int32_t>(r1 / r2);
		r = r1 % r2;
		s = s1 - s2 * q;
		t = t1 - t2 * q;
		if (r == 0)
		{
			r1 = r2;
			r2 = r;
			s1 = s2;
			s = s2;
			t1 = t2;
			t = t2;
			break;
		}
		else if (r == 1)
		{
			break;
		}
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	if (s < 0)
	{
		s += b;
	}
	int32_t result = (a * s) % b;
	if (result == 1)
	{
		//std::cout << "Istnieje ";
		return s;
	}
	else
	{
		//std::cout << "Nie istnieje ";
		return -1;
	}
}