#include <math.h>
#include <fstream>
#include <random>
#include <map>

#include "Complex.hpp"

#define NEW_LINE '\n'


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD cin;
	using _STD endl;

	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in);

	///////////////////////////////////////////
	size_t N{};
	///////////////////////////////////////////

	file_in >> N;

	_STD vector<Complex::Complex> Cn(N);


	for (size_t i = 0; i < N; ++i)
	{
		file_in >> Cn[i].Im;
	}

	system("pause");
	return 0;
}