#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <fstream>

#define M_PI 3.14
#define NEW_LINE '\n'

const float get_random(const float a, const float b);
const float BoxMuller(double y1, double mi, double sigma);
void metoda2();

int main(int argc, char* argv[])
{
	srand(time(NULL));

	float D1{};
	float D2{};
	float sigma{ 10 }, mi{ 3 };

	_STD fstream file_out;
	file_out.open("file.out", _STD ios::out);

	float randMax = (float)RAND_MAX;

	float z1 = rand() / randMax;

	float r2 = -2. * log(z1);
	float teta = (rand() / randMax) * 2 * M_PI;
	float y1 = sqrt(r2) * cos(teta);

	for (size_t i = 0; i < 1000; i++)
	{
		float randMax = (float)RAND_MAX;
		float z1 = rand() / randMax;
		float r2 = -2. * log(z1);
		float y1 = sqrt(r2) * cos((rand() / randMax) * 2 * 3.14);

		file_out << BoxMuller(y1, mi, sigma) << _STD endl;
	}

	metoda2();


	file_out.close();
	system("pause");
	return 0;
}

const float get_random(const float a, const float b)
{
	float r = ((float)rand() / RAND_MAX);
	return ((r * (b - a)) + a);
}

const float BoxMuller(double y1, double mi, double sigma)
{
	return (float)(y1 * sigma) + mi;
}


void metoda2()
{
	float losowane[6]{};
	float z = 0.f;
	float randMax = (float)RAND_MAX;
	float dzielnik = (float)sqrt(3.f) / sqrt(6.f);

	_STD fstream file_out;
	file_out.open("file_2.out", _STD ios::out);

	for (size_t i = 0; i < 1000; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			losowane[j] = rand() / randMax;
			z += (losowane[j] - 0.5f);
		}

		z *= (1. / 6);
		z /= dzielnik;

		file_out << z << _STD endl;

	}
	file_out.close();
}