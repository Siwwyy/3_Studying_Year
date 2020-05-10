#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


const int32_t NWD(int32_t a, int32_t b);
const int32_t Inverse_Euclidean(int32_t a, int32_t b);

int main(int argc, char* argv[])
{
	//std::cout << NWD(28, 24) << '\n';
	std::cout << Inverse_Euclidean(337, 123) << '\n';
	std::cout << Inverse_Euclidean(4321, 1234) << '\n';
	std::cout << Inverse_Euclidean(432, 321) << '\n';

	system("pause");
	return EXIT_SUCCESS;
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
	//s*a+t*b = gcd(a,b)
	/*
		my sample
		GCD = 7
		s = -1
		t = 6

		s*a + t*b => (-1)*161+6*28 = -161 + 168 = 7 = GCD
	*/
	int32_t result = (a*s)%b;
	if (result == 1)
	{
		std::cout << "Istnieje ";
		return s;
	}
	else
	{
		std::cout << "Nie istnieje ";
		return -1;
	}
}