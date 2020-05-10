#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <bitset>
#include <cmath>


const int32_t NWD(int32_t a, int32_t b);
const void Inverse_Euclidean(int32_t a, int32_t b);

int main(int argc, char* argv[])
{
	//std::cout << NWD(28, 24) << '\n';

	//std::cout << Inverse_Euclidean(7, 10) << '\n';
	//Inverse_Euclidean(161, 28);
	Inverse_Euclidean(5, 11);

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

const void Inverse_Euclidean(int32_t a, int32_t b)
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
		std::cout << "q = " << q << '\n';
		std::cout << "r1 = " << r1 << '\n';
		std::cout << "r2 = " << r2 << '\n';
		std::cout << "r = " << r << '\n';
		std::cout << "s1 = " << s1 << '\n';
		std::cout << "s2 = " << s2 << '\n';
		std::cout << "s = " << s << '\n';
		std::cout << "t1 = " << t1 << '\n';
		std::cout << "t2 = " << t2 << '\n';
		std::cout << "t = " << t << '\n';
		std::cout << "-------------------------------------\n";
		//std::cout << q << ' ' << r1 << ' ' << r2 << ' ' << r << ' ' << s1 << ' ' << s2 << ' ' << s << ' ' << t1 << ' ' << t2 << ' ' << t << '\n';

		//int32_t temp_q{q}, temp_r1{ r1 }, temp_r2{ r2 }, temp_r{r}, temp_s1{s1}, temp_s2{s2}, temp_s{s}, temp_t1{t1}, temp_t2{t2}, temp_t{t};
		if (r == 0)
		{
			r1 = r2;
			r2 = r;
			s1 = s2;
			s2 = s;
			t1 = t2;
			t2 = t;
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
	//std::cout << q << ' ' << r1 << ' ' << r2 << ' ' << r << ' ' << s1 << ' ' << s2 << ' ' << s << ' ' << t1 << ' ' << t2 << ' ' << t << '\n';
	//std::cout << '\n';
	std::cout << "q = " << q << '\n';
	std::cout << "r1 = " << r1 << '\n';
	std::cout << "r2 = " << r2 << '\n';
	std::cout << "r = " << r << '\n';
	std::cout << "s1 = " << s1 << '\n';
	std::cout << "s2 = " << s2 << '\n';
	std::cout << "s = " << s << '\n';
	std::cout << "t1 = " << t1 << '\n';
	std::cout << "t2 = " << t2 << '\n';
	std::cout << "t = " << t << '\n';
	std::cout << "-------------------------------------\n";
	if (s < 0)
	{
		s += b;
	}
	std::cout << r1 << " " << s << " " << t << '\n';
	std::cout << '\n';
	//s*a+t*b = gcd(a,b)
	/*
		GCD = 7
		s = -1
		t = 6

		s*a + t*b => (-1)*161+6*28 = -161 + 168 = 7 = GCD
	*/

	int32_t cos = (s1 * a + t1 * b);
	int32_t result = (s1 * a + t1 * b) % b;


	std::cout << result;
	std::cout << '\n';















	//std::cout << r1 << " " << s1 << " " << t1 << '\n';

	//int u, w, x, z, q;

	//u = 1; w = a;
	//x = 0; z = b;
	//while (w)
	//{
	//	if (w < z)
	//	{
	//		q = u; u = x; x = q;
	//		q = w; w = z; z = q;
	//	}
	//	q = w / z;
	//	u -= q * x;
	//	w -= q * z;
	//}
	//if (z == 1)
	//{
	//	if (x < 0) x += b;
	//	std::cout << x << std::endl;
	//}
	//else std::cout << "BRAK\n";
}