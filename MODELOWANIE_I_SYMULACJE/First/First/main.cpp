// c i m nie maja dzielnikow
// a-1 wielokrotnosc liczby pierwszej bedacej dzielnikiem m
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#define NEW_LINE '\n'
#define M_PI 3.14

class Gen
{
public:
	Gen();
	Gen(int seed);

public:
	float Gen01();

private:
	long long a;
	long long c;
	long long m;
	long long xi;
};

Gen::Gen()
	:
	xi(0)
	, a(22695477)
	, c(1)
	, m(4294967296)
{}

Gen::Gen(int seed)
	:
	xi(seed)
{}

float Gen::Gen01()
{
	xi = (a * xi + c) % m;
	return (float)xi / (m - 1);
}


class Histogram
{
public:
	Histogram(int nClass);
	~Histogram();

	void show();
	void addNumber(float num);

	int* get() { return ClassCount; };
private:
	int nClass;
	float fClassWidth;
	int* ClassCount;
};


Histogram::Histogram(int nClass)
	:
	nClass(nClass)
	, fClassWidth(1.0f / nClass)
{
	ClassCount = new int[nClass];

	for (int i = 0; i < nClass; ++i)
		ClassCount[i] = 0;
}

Histogram::~Histogram()
{
	delete[] ClassCount;
}

void Histogram::show()
{
	for (int i = 0; i < nClass; ++i)
	{
		printf("<%1.1f - %1.1f) :", fClassWidth * i, fClassWidth * (i + 1));
		/*for (int j = 0; j < ClassCount[i]; ++j)
		{
			std::cout << "#";
		}*/
		_STD cout << ClassCount[i];
		std::cout << '\n';
	}
}

void Histogram::addNumber(float num)
{
	int a = int(num / fClassWidth);
	ClassCount[a]++;
}




int main()
{
	const int n = 1000;
	Gen x;
	float przedzial_od = -(M_PI / 8);
	float przedzial_do = ((3 *M_PI) / 8);
	//Histogram g(10);

	/*for (int i = 0; i < 10; ++i)
		printf("%1.2f\n", x.Gen01());*/


	//std::vector<float> vec;

	//for (int i = 0; i < n; ++i)
	//{
	//	vec.push_back(x.Gen01());
	//	g.addNumber(vec[i]);
	//}

	//g.show();

	//float suma = 0;
	//for (int i = 0; i < n; ++i)
	//	suma += vec[i];

	//float  _y = suma / n;
	//printf("_y %f\n", _y);

	//suma = 0;
	//for (int i = 0; i < n; ++i)
	//	suma += vec[i] * vec[i];

	//float  _y2 = suma / n;
	//printf("_y^2 %f\n", _y2);

	//suma = 0;
	//for (int i = 0; i < n; ++i)
	//	  suma += vec[i] * vec[i] * vec[i];

	//float  _y3 = suma / n;
	//printf("_y^3 %f\n", _y3);

	//int* c = g.get();
	//int teoretyczna = n / 10;
	//float x2 = 0;
	//for (int i = 0; i < 10; ++i)
	//{
	//	x2 += ((c[i] - teoretyczna) * (c[i] - teoretyczna)) / teoretyczna;
	//}


	//printf("X^2 %4.5f\n", x2);

	////Poparowanie liczb
	//struct point
	//{
	//	point(float x, float y) : x(x), y(y) {}
	//	float x;
	//	float y;
	//};

	////int d = 0;
	//std::vector<point> vec2;
	//for (int i = 0; i < n; i += 2)
	//{
	//	vec2.push_back(point(vec[i], vec[i + 1]));
	//	//++d;
	//}
	////Policzenie klas

	//int class2[10][10];

	//for (int i = 0; i < 10; ++i)
	//	for (int j = 0; j < 10; ++j)
	//		class2[i][j] = 0;
	//for (int i = 0; i < vec2.size(); ++i)
	//{
	//	class2[(int)(vec2[i].x / 0.1f)][(int)(vec2[i].y / 0.1f)]++;
	//}

	//_STD fstream file_in2;
	//file_in2.open("file.out", std::ios_base::out);
	//for (int i = 0; i < vec2.size(); ++i)
	//{
	//	//class3[(int)(vec3[i].x / 0.1f)][(int)(vec3[i].y / 0.1f)]++;
	//	file_in2 << vec2[i].x << ' ' << vec2[i].y << '\n';
	//}
	//file_in2.close();

	////Liczenie X2
	//float teoretyczna2 = (n / 2) / (10 * 10);
	//float x3 = 0;


	//for (int i = 0; i < 10; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		x3 += (float)((float)class2[i][j] - teoretyczna2) * ((float)class2[i][j] - teoretyczna2) / (teoretyczna2);
	//	}
	//}

	//printf("X^3 %.4f\n", x3);

	////_STD cout << "X2 = " << x3 << NEW_LINE;



	////tablica 3
	////int d = 0;
	//std::vector<point> vec3;
	//for (int i = 0; i < n-1; i++)
	//{
	//	vec3.push_back(point(vec[i], vec[i + 1]));
	//	//++d;
	//}

	//int class3[10][10]{};
	////int class2[10][10];

	//for (int i = 0; i < 10; ++i)
	//	for (int j = 0; j < 10; ++j)
	//		class3[i][j] = 0;
	//for (int i = 0; i < vec3.size(); ++i)
	//{
	//	class3[(int)(vec3[i].x / 0.1f)][(int)(vec3[i].y / 0.1f)]++;
	//}

	//_STD fstream file_in3;
	//file_in3.open("file1.out", std::ios_base::out);
	//for (int i = 0; i < vec3.size(); ++i)
	//{
	//	//class3[(int)(vec3[i].x / 0.1f)][(int)(vec3[i].y / 0.1f)]++;
	//	file_in3 << vec3[i].x << ' ' << vec3[i].y << '\n';
	//}
	//file_in3.close();
	////Liczenie X2
	//float teoretyczna3 = (n -1) / (10 * 10);
	//float x4 = 0;


	//for (int i = 0; i < 10; ++i)
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		x4 += (float)((float)class3[i][j] - teoretyczna3) * ((float)class3[i][j] - teoretyczna3) / (teoretyczna3);
	//	}
	//}

	//printf("X^4 %.4f\n", x4);

	system("pause");
	return 0;
}

/*
Ilos losowanych / licba przeddzialow
n/nClass;
*/