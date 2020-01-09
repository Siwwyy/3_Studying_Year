
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

	Display_Array(data2);
	FastFourierTransform(data2, false);
	Display_Array(data2);

	FastFourierTransform(data2, true);
	Display_Array(data2);

	//file_in.close();
	system("pause");
	return EXIT_SUCCESS;
}

void FastFourierTransform(std::vector<std::complex<double>>& in_array, bool logic)
{
	size_t size = in_array.size();
	if (size == 1)
	{
		return;
	}

	_STD vector<_STD complex<double>> left_array(size / 2);
	_STD vector<_STD complex<double>> right_array(size / 2);

	for (size_t i = 0; 2 * i < size; ++i)
	{
		left_array[i] = in_array[2 * i];
		right_array[i] = in_array[2 * i + 1];
	}

	FastFourierTransform(left_array, logic);
	FastFourierTransform(right_array, logic);

	double in_arrayng = 2 * M_PI / size * (logic ? -1 : 1);
	_STD complex<double> w(1), wn(cos(in_arrayng), sin(in_arrayng));

	for (size_t i = 0; (2 * i) < size; ++i)
	{
		in_array[i] = left_array[i] + w * right_array[i];
		in_array[i + (size / 2)] = left_array[i] - w * right_array[i];
		if (logic == true)
		{
			in_array[i] /= 2;
			in_array[i + (size / 2)] /= 2;
		}
		w *= wn;
	}
}

void Display_Array(const std::vector<std::complex<double>>& in_array)
{
	for (auto& x : in_array)
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
	_STD cout << NEW_LINE;
}