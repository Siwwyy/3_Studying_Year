#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <time.h>
#include <fstream>

#define NEW_LINE '\n'


float losuj();
const __int32 silnia(const __int32 value);


int main(int argc, char* argv[])
{
	float lambda{2.0f};
    int k{};
    float s{};
    float y{};

	_STD fstream file_out1("out1.out", _STD ios_base::out);
	_STD fstream file_out2("out2.out", _STD ios_base::out);
	srand(time(NULL));


    for (size_t i = 0; i < 1000; i++)
    {
        while (s <= lambda)
        {
            y = losuj();
            s = s + y;
            k = k + 1;
        }
        file_out1 << k << NEW_LINE;
        y = NULL;
        k = NULL;
        s = NULL;
    }

    for (size_t i = 0; i < 1000; i++)
    {
        int k2 = -1;
        float s2 = 0.0;
        float lambda2 = 2.5;
        float y2{};

        while (s2 <= lambda2)
        {
            y2 = losuj();
            s2 = s2 + y2;
            k2 = k2 + 1;
        }
        file_out2 << k2 << NEW_LINE;
    }

    for (int i = 0; i < 20; i++)
    {
        double temp{};
        temp = (pow(lambda, (double)i) * pow(2.71828182, (-lambda)) / silnia(i));
        _STD cout << temp << NEW_LINE;
    }

	system("pause");
	return 0;
}


float losuj()
{
	float de = (float)rand() / RAND_MAX;
	float y = -log(1 - de);
	return y;
}

const __int32 silnia(const __int32 value)
{
	if (value == 0)
	{
		return 1;
	}
	else
	{
		return value * silnia(value - 1);
	}
}