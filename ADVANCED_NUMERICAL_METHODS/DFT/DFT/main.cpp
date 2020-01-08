
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <complex>
#include <fstream>
#include <vector>

#define NEW_LINE '\n'

const double PI = acos(-1);

void fft(int *x_in,  std::complex<double> *x_out, int N);
void fft_rec(std::complex<double> *x, int N);

void fft2(std::vector<std::complex<double>>& a, bool invert)
{ 	
	int n = a.size(); 
	if (n == 1)
	{
		return;
	}

	std::vector<std::complex<double>> a0(n / 2), a1(n / 2);

	for (int i = 0; 2 * i < n; i++)
	{ 		
		a0[i] = a[2 * i]; 	
		a1[i] = a[2 * i + 1]; 
	} 	

	fft2(a0, invert);
	fft2(a1, invert);

	double ang = 2 * M_PI / n * (invert ? -1 : 1); 
	std::complex<double> w(1), wn(cos(ang), sin(ang));

	for (int i = 0; 2 * i < n; i++)
	{ 		
		a[i] = a0[i] + w * a1[i]; 
		a[i + n / 2] = a0[i] - w * a1[i]; 	
		if (invert == true) 
		{ 			
			a[i] /= 2; 		
			a[i + n / 2] /= 2; 		
		} 		
		w *= wn; 	
	}
} 

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
	_STD vector<std::complex<double>> data2(N);

	for (size_t i = 0; i < N; ++i)
	{
		file_in >> temp;
		data[i].real(temp);
		file_in >> temp;
		data[i].imag(temp);
		temp = 0.0f;
	}

	data2 = data;

	//_STD cout << "i: " << i << " Real: " << temp_Re << " Imaginary: " << temp_Im << NEW_LINE;
	//for (size_t i = 0; i < N; ++i)
	//{
	//	__int32 temp = data[i]._Val[0];
	//	fft(&temp, Cn, N);
	//	temp = data[i]._Val[1];
	//	fft(&temp, Cn, N);
	//}

	for (auto& x : data2)
		printf("( %4.4f , %4.4f )\n", x.real() > 0.0001 ? x.real() : 0., x.imag() > 0.0001 ? x.imag() : 0.);
	printf("\n\n\n");

	fft2(data2, false);

	//for (size_t i = 0; i < N; ++i)
	//{
	//	//_STD cout << Cn[i]._Val[0] << " " << Cn[i]._Val[1] << NEW_LINE;
	//	_STD cout << data2[i]._Val[0] << " " << data2[i]._Val[1] << NEW_LINE;
	//}
	//_STD cout << NEW_LINE;

	for (auto& x : data2)
		printf("( %4.4f , %4.4f )\n", x.real() > 0.0001 ? x.real() : 0., x.imag() > 0.0001 ? x.imag() : 0.);
	printf("\n\n\n");

	fft2(data2, true);

	for (auto& x : data2)
		printf("( %4.4f , %4.4f )\n", x.real() > 0.0001 ? x.real() : 0., x.imag() > 0.0001 ? x.imag() : 0.);
	printf("\n\n\n");

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


//#define _USE_MATH_DEFINES
//#include <iostream> 
//#include <complex>
//#include <cmath>
//#include <vector>
//#include <fstream>
//
//using cd = std::complex<double>; 
//
//const double PI = acos(-1); 
//
//void fft(std::vector<cd>& a, bool invert)
//{ 	
//	int n = a.size(); 
//	if (n == 1) 	
//		return; 	
//
//	std::vector<cd> a0(n / 2), a1(n / 2); 
//
//	for (int i = 0; 2 * i < n; i++)
//	{ 		
//		a0[i] = a[2 * i]; 	
//		a1[i] = a[2 * i + 1]; 
//	} 	
//	fft(a0, invert); 	
//	fft(a1, invert); 	
//	double ang = 2 * M_PI / n * (invert ? -1 : 1); 
//	cd w(1), wn(cos(ang), sin(ang));
//
//	for (int i = 0; 2 * i < n; i++)
//	{ 		
//		a[i] = a0[i] + w * a1[i]; 
//		a[i + n / 2] = a0[i] - w * a1[i]; 	
//		if (invert) 
//		{ 			
//			a[i] /= 2; 		
//			a[i + n / 2] /= 2; 		
//		} 		
//		w *= wn; 	
//	}
//} 
//
//
//int main()
//{ 	
//	std::fstream in; 
//	in.open("file.in", std::ios::in); 
//	size_t N; 
//	double temp; 	
//	in >> N; 
//	std::vector<std::complex<double>> data(N);
//	std::vector<std::complex<double>> data2(N); 
//	std::vector<std::complex<double>> data3; 	
//	//std::vector<double> Cn(N); 	
//	for (size_t i = 0; i < N; ++i) 
//	{ 		
//		in >> temp; 	
//		data[i].real(temp); 	
//		in >> temp; 	
//		data[i].imag(temp); 
//	} 
//	data2 = data; 
//
//	fft(data2, false); 
//
//	for (auto& x : data2) 
//		printf("( %4.4f , %4.4f )\n", x.real() > 0.0001? x.real():0.,x.imag() > 0.0001 ? x.imag() : 0.); 
//	printf("\n\n\n"); 
//
///*	fft(data2, true); 
//
//	for (auto& x : data2) 
//		printf("( %4.4f , %4.4f )\n", x.real() > 0.0001? x.real():0.,x.imag() > 0.0001 ? x.imag() : 0.); 
//	printf("\n\n\n"); */	
//
//	for (size_t n = 0; n < N; ++n) 
//	{ 		
//		std::complex<double> num(0., 0.); 
//		// od 0 do n/2 	
//		if (n < N / 2.) 	
//		{ 			
//			for (int m = 0; m < N / 2; ++m) 	
//			{ 			
//				num += (data[2 * m] + (data[2 * m + 1] * std::exp(std::complex<double>(0., 1.) * ((2. * M_PI * n) / (double)N)))) * std::exp(std::complex<double>(0., 1.) * (2 * M_PI * m * n) / (N / 2.));
//			} 		
//		} 	
//		else 		
//		{ 			
//			for (int m = 0; m < N / 2; ++m) 
//			{ 				
//				num += (data[2 * m] - (data[2 * m + 1] * std::exp(std::complex<double>(0., 1.) * ((2. * M_PI * n) / (double)N)))) * std::exp(std::complex<double>(0., 1.) * (2 * M_PI * m *(n + (N / 2.))) / (N / 2.)); 	
//			} 
//		} 	
//
//		printf("( %4.4f , %4.4f )\n", num.real() > 0.0001 ? num.real() : 0., num.imag() > 0.0001 ? num.imag() : 0.); 
//		data3.push_back(num); 	
//		if (n == N / 2 -1 )
//			printf("\n"); 	
//		//std::cout << num << '\n'; 	
//	} 	
//	printf("\n\n\n"); 
//
//	//for (size_t n = 0; n < N; ++n) 
//	//{ 	
//	//	std::complex<double> num(0., 0.); 
//	//	for (int k = 0; k < N; ++k) 	
//	//	{ 	
//	//		num += data3[k] * std::exp(std::complex<double>(0., 1.) * ((2. * M_PI * n * k) / (double)N)); 
//	//	} 
//	//	printf("( %4.4f , %4.4f )\n", num.real() > 0.0001 ? num.real() : 0., num.imag() > 0.0001 ? num.imag() : 0.); 
//	//	
//	//std::cout << num << '\n'; 	
//	//} 
//
//	_STD cin.get();
//	return 0;
//}