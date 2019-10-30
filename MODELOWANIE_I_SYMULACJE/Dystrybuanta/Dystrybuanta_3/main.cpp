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
const float get_fun(const float D);
const float funkcja_first(const float x);


int main(int argc, char* argv[])
{
	srand(time(NULL));

	float D{};
	float b{1};
	float x{};
	float C{2};
	float przedzial_od = C;
	float przedzial_do = 1000000.0f;
	_STD fstream file_out;
	file_out.open("4_case.out", _STD ios_base::out);
	for (size_t i = 0; i < 10000; ++i)
	{//E:\!!Projects VS\!!!3_Studying_Year\3_Studying_Year\MODELOWANIE_I_SYMULACJE
		//D = get_random(przedzial_od, przedzial_do);
		D = get_random(0, 1);
		file_out << get_fun(D) << NEW_LINE;
	}
	file_out.close();
	file_out.open("5_case.out", _STD ios_base::out);
	float fmax = 7;
	//float xmax = -1 * (log(1000) / b) + C;
	float xmax = 30;
	for (size_t i = 0; i < 10000; ++i)
	{
		//float xl2 = funkcja_first(x,b,C);
		float y1 = get_random(0,fmax);
		float x1 = get_random(2, 3);
		float xl2 = funkcja_first(x1);
		//x1 = ((int)(x1)% 2) + 2;
		//y1 = ((int)(x1) % 8);
		if (y1 <= xl2) file_out << x1 << NEW_LINE;
		else --i;
	}
	file_out.close();
	system("pause");
	return 0;
}

const float get_random(const float a, const float b)
{
	float r = ((float)rand() / RAND_MAX);
	return ((r * (b - a))+a);
}

const float get_fun(const float D)
{
	//float my_arcsin{};
	float x = (float)(pow(D,(1.f/71.)) + 2.f);//-1* (log(value)/b) +C;
	return x;
}

const float funkcja_first(const float x)
{
	return float(7*(pow((x-2),6)));
}
