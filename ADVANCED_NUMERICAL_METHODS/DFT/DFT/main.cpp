
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <complex>
#include <fstream>
#include <vector>

#define NEW_LINE '\n'

#define PI acos(-1);

void FastFourierTransform(std::vector<std::complex<double>>& in_array, bool logic);
void Display_Array(const std::vector<std::complex<double>>& in_array);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	using _STD cerr;

	//_STD fstream file_in;
	//file_in.open("file.in", std::ios_base::in);

	///////////////////////////////////////////
	size_t N{};
	float temp{};
	///////////////////////////////////////////

	//file_in >> N;
	_STD cin >> N;

	_STD vector<std::complex<double>> data(N);
	_STD vector<std::complex<double>> data2(N);

	for (size_t i = 0; i < N; ++i)
	{
		//file_in >> temp;
		_STD cin >> temp;
		data[i].real(temp);
		//file_in >> temp;
		_STD cin >> temp;
		data[i].imag(temp);
		temp = 0.0f;
	}

	data2 = data;

	//Display_Array(data2);
	FastFourierTransform(data2, false);
	//Display_Array(data2);
	printf("FFT\n");
	for (auto& x : data2) printf("( %.4f , %.4f )\n", abs(x.real()) > 0.0001 ? x.real() : 0., abs(x.imag()) > 0.0001 ? x.imag() : 0.);

	FastFourierTransform(data2, true);
	printf("Inverse \n");
	for (auto& x : data2) printf("( %.4f , %.4f )\n", abs(x.real()) > 0.0001 ? x.real() : 0., abs(x.imag()) > 0.0001 ? x.imag() : 0.);

	//Display_Array(data2);

	//file_in.close();
	system("pause");
	return EXIT_SUCCESS;
}

void FastFourierTransform(std::vector<std::complex<double>>& vec, bool invert)
{
	const int n = static_cast<int>(vec.size());
	if (n == 1) return;

	std::vector<std::complex<double>> v1, v2;
	for (int i = 0; 2 * i < n; i++)
	{
		v1.push_back(vec[2 * i]);
		v2.push_back(vec[2 * i + 1]);
	}


	FastFourierTransform(v1, invert);
	FastFourierTransform(v2, invert);

	double ang = 2 * M_PI / n;
	if (invert) ang *= -1;
	std::complex<double> o(1);
	std::complex<double> on = std::exp(std::complex<double>(0., 1.) * ang);
	for (int i = 0; 2 * i < n; i++)
	{
		vec[i] = v1[i] + o * v2[i];
		vec[i + n / 2] = v1[i] - o * v2[i];
		if (invert)
		{
			vec[i] /= 2;
			vec[i + n / 2] /= 2;
		}
		o *= on;
	}
}

void Display_Array(const std::vector<std::complex<double>>& in_array)
{
	/*for (auto& x : in_array)
	{
		if (x.real() > 0.0001)
		{
			_STD cout << "[ " << x.real() << " ]";
		}
		else
		{
			_STD cout << "[ 0.000 ]";
		}
		_STD cout << ' ';
		if (x.imag() > 0.0001)
		{
			_STD cout << "[ " << x.imag() << " ]";
		}
		else
		{
			_STD cout << "[ 0.000" << " ]";
		}
		_STD cout << NEW_LINE;
	}
	_STD cout << NEW_LINE;
	_STD cout << NEW_LINE;*/
}