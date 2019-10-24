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
const float get_arcsin(const float D);
const float funkcja_first(const float x1);


int main(int argc, char* argv[])
{
	srand(time(NULL));
	float przedzial_od = -1*(M_PI / 8);
	float przedzial_do = ((3 * M_PI) / 8);
	float D{};
	_STD fstream file_out;
	file_out.open("4_case.out", _STD ios_base::out);
	for (size_t i = 0; i < 10000; ++i)
	{//E:\!!Projects VS\!!!3_Studying_Year\3_Studying_Year\MODELOWANIE_I_SYMULACJE
		//D = get_random(przedzial_od, przedzial_do);
		D = get_random(0, 1);
		//_STD cout << get_arcsin(D) << NEW_LINE;
		file_out << get_arcsin(D) << NEW_LINE;
	}
	file_out.close();
	file_out.open("5_case.out", _STD ios_base::out);
	float fmax = 1.0f;
	for (size_t i = 0; i < 10000; ++i)
	{
		float y1 = get_random(0.f, fmax);
		float x1 = get_random(0, 1);
		float xl2 = funkcja_first(x1);
		if (y1 <= xl2) file_out << x1 << NEW_LINE;
		else --i;
		//file_out << get_arcsin(D) << NEW_LINE;
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

const float get_arcsin(const float D)
{
	//float my_arcsin{};
	float value = ((2*D) - 1);
	float x = (0.5) * asin(value) + (M_PI / 8);
	return x;
}

const float funkcja_first(const float x1)
{
	return cosf((2*x1) - (M_PI/4.f));
}
