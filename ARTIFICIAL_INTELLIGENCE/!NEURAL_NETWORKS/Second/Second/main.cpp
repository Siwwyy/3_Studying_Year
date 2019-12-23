#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'
#define e 2.71828182

const float f1(const float value);
const float f2(const float value);
const float f3(const float value);
void initial_weights(float * weights, const size_t size);
const float first_neural();

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;
	srand(time(NULL));

	//////////////////////////////////////////////////////////////////
	_STD vector<_STD vector<char>> Matrix(500);
	for (typename _STD vector<_STD vector<char>>::iterator vec_iterator = Matrix.begin(); vec_iterator != Matrix.end(); ++vec_iterator)
	{
		vec_iterator->resize(500);
	}
	//////////////////////////////////////////////////////////////////
	__int16 choice{};


	_STD cin >> choice;
	if (choice == 0)	//without bias
	{
		float weights[2]{};
		float y{};
		initial_weights(weights,2);
		_STD cin >> choice;
		switch (choice)
		{
			//first neural
			case 1:
			{
				
			}
			break;
			case 2:
			{

			}
			break;
			case 3:
			{

			}
			break;
			//second neural
			case 4:
			{

			}
			break;
			case 5:
			{

			}
			break;
			case 6:
			{

			}
			break;

			default:	_STD cout << "An error occured with choice" << NEW_LINE;
				break;
		}
	}
	else  //with bias
	{
		float weights[3]{};
		float y{};
		initial_weights(weights, 2);
		weights[0] = 1;
		_STD cin >> choice;
		switch (choice)
		{
			//first neural
			case 1:
			{

			}
			break;
			case 2:
			{

			}
			break;
			case 3:
			{

			}
			break;
			//second neural
			case 4:
			{

			}
			break;
			case 5:
			{

			}
			break;
			case 6:
			{

			}
			break;

			default:	_STD cout << "An error occured with choice" << NEW_LINE;
				break;
		}
	}


	system("pause");
	return 0;
}


const float f1(const float value)
{
	if (value >= 0)
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}

const float f2(const float value)
{
	return value;
}

const float f3(const float value)
{
	return static_cast<float>(1.0f / (1.0f + static_cast<float>(pow((1.0f / e), value))));
}

void initial_weights(float* weights, const size_t size)
{
	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-5.0f, 5.0f);

	for (size_t i = 0; i < size; ++i)
	{
		weights[i] = dis(generator);
	}
}