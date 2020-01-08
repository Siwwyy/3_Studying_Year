
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <complex>
#include <fstream>
#include <vector>

#define NEW_LINE '\n'

void fft(int *x_in,  std::complex<double> *x_out, int N);
void fft_rec(std::complex<double> *x, int N);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in);

	///////////////////////////////////////////
	size_t N{};
	float temp{};
	///////////////////////////////////////////

	file_in >> N;

	_STD vector<std::complex<double>> data(N);
	//_STD vector<double> Cn(N);
	std::complex<double>* Cn = new std::complex<double>[N];

	for (size_t i = 0; i < N; ++i)
	{
		file_in >> temp;
		data[i].real(temp);
		file_in >> temp;
		data[i].imag(temp);
		temp = 0.0f;
		Cn[i]._Val[0] = 0.0;
		Cn[i]._Val[1] = 0.0;
	}

	//_STD cout << "i: " << i << " Real: " << temp_Re << " Imaginary: " << temp_Im << NEW_LINE;
	for (size_t i = 0; i < N; ++i)
	{
		__int32 temp = data[i]._Val[0];
		fft(&temp, Cn, N);
		temp = data[i]._Val[1];
		fft(&temp, Cn, N);
	}

	for (size_t i = 0; i < N; ++i)
	{
		_STD cout << Cn[i]._Val[0] << " " << Cn[i]._Val[1] << NEW_LINE;
	}
	_STD cout << NEW_LINE;

	file_in.close();
	system("pause");
	return 0;
}

void fft(int* x_in, std::complex<double>* x_out, int N) 
{
	for (int i = 0; i < N; i++)
	{
		x_out[i] = std::complex<double>(x_in[i], 0);
	}
	fft_rec(x_out, N);
}

void fft_rec(std::complex<double>* x, int N) 
{
	if (N <= 1) 
	{
		return;
	}
	else
	{
		const size_t size = N / 2;
		std::complex<double>* odd = new std::complex<double>[size];
		std::complex<double>* even = new std::complex<double>[size];
		for (int i = 0; i < N / 2; i++)
		{
			even[i] = x[i * 2];
			odd[i] = x[i * 2 + 1];
		}

		fft_rec(even, N / 2);
		fft_rec(odd, N / 2);

		for (int k = 0; k < N / 2; k++)
		{
			std::complex<double> t = exp(std::complex<double>(0, -2 * M_PI * k / N)) * odd[k];
			x[k] = even[k] + t;
			x[N / 2 + k] = even[k] - t;
		}

		delete[] odd;
		delete[] even;
	}
}