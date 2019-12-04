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
double losujLiczbe();
int losujliczbe10();


int main(int argc, char* argv[])
{
	srand(time(NULL));


	_STD fstream file_out;
	file_out.open("file.out", _STD ios::out);

	//const size_t size{ 5 };
	//double tabP[size]{};
	//int tabX[size]{};
	//tabP[0] = (double)1 / 8;
	//tabX[0] = 2;

	//tabP[1] = (double)1 / 8;
	//tabX[1] = 8;

	//tabP[2] = (double)1 / 8;
	//tabX[2] = 10;

	//tabP[3] = (double)1 / 8;
	//tabX[3] = 11;

	//tabP[4] = (double)4 / 8;
	//tabX[4] = 15;

	///*tabP[5] = (double)1 / 12;
	//tabX[5] = 16;

	//tabP[6] = (double)1 / 12;
	//tabX[6] = 22;

	//tabP[7] = (double)1 / 12;
	//tabX[7] = 25;

	//tabP[8] = (double)1 / 12;
	//tabX[8] = 27;

	//tabP[9] = (double)3 / 12;
	//tabX[9] = 29;*/


	//for (size_t i = 0; i < 1000; i++)
	//{
	//	double y = losujLiczbe();
	//	int pi = losujliczbe10();
	//	if (y > tabP[pi])
	//	{
	//		y = losujLiczbe();
	//		pi = losujliczbe10();
	//	}
	//	file_out << tabX[pi] << _STD endl;
	//}


	//_STD fstream file("out.txt", ios::out);
	srand(time(NULL));
	double x[1000];

	for (int i = 0; i < 1000; i++)
	{
		x[i] = losujLiczbe();
		if (x[i] > 0 && x[i] <= 0.125) file_out << 0 << _STD endl;
		else if (x[i] > 0.125 && x[i] <= 0.25) file_out << 8 << _STD endl;
		else if (x[i] > 0.25 && x[i] <= 0.375) file_out << 10 << _STD endl;
		else if (x[i] > 0.375 && x[i] <= 0.5) file_out << 11 << _STD endl;
		else if (x[i] > 0.5) file_out << 15 << _STD endl;
	}


	file_out.close();
	system("pause");
	return 0;
}

double losujLiczbe()
{
	return (double)rand() / RAND_MAX;
}

int losujliczbe10()
{
	return rand() % 5;
}

const float get_random(const float a, const float b)
{
	float r = ((float)rand() / RAND_MAX);
	return ((r * (b - a)) + a);
}

/*
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

double losujLiczbe();
int losujliczbe5();
//odwr�cona dystrybuanta - wykres kto jak chodzi� na zaj�cia
/*int main()
{
		fstream file("out.txt", ios::out);
		srand(time(NULL));
		double x[1000];

		for (int i = 0; i < 1000; i++)
		{
				x[i] = losujLiczbe();
				if (x[i] > 0 && x[i] <= 0.125) file << 0 << endl;
				else if (x[i] > 0.125 && x[i] <= 0.25) file << 8 << endl;
				else if (x[i] > 0.25 && x[i] <= 0.375) file << 10 << endl;
				else if (x[i] > 0.375 && x[i] <= 0.5) file << 11 << endl;
				else if (x[i] > 0.5) file << 15 << endl;
		}



}

//Dyskretyny wykres kto jak chodzi� na zaj�cia

int main()
{
	fstream file("out2.txt", ios::out);
	srand(time(NULL));
	double tabP[5];
	int tabX[5];
	tabP[0] = (double)1 / 8;
	tabX[0] = 0;

	tabP[1] = (double)1 / 8;
	tabX[1] = 8;

	tabP[2] = (double)1 / 8;
	tabX[2] = 10;

	tabP[3] = (double)1 / 8;
	tabX[3] = 11;

	tabP[4] = (double)4 / 8;
	tabX[4] = 15;


	for (int i = 0; i < 2500; i++)
	{
		double y = losujLiczbe();
		int pi = losujliczbe5();
		if (y <= tabP[pi]) file << tabX[pi] << endl;



	}
	return 0;

}


double losujLiczbe()
{
	return (double)rand() / RAND_MAX;

}

int losujliczbe5()
{
	return rand() % 5;
}
*/