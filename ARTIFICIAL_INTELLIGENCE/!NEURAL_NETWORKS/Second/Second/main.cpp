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
const float normalized_point(const float value, const __int16 min, const __int16 max, const __int16 new_min, const __int16 new_max);
void initial_weights(float * weights, const size_t size);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	__int16 choice{};

	_STD cin >> choice;
	if (choice == 0)	//without bias
	{
		float weights[4]{};
		float y{};
		initial_weights(weights,4);
		choice = {};
		_STD cin >> choice;
		switch (choice)
		{
			//first neural
			case 1:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[0];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[1];
						y = f1(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y == 1)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 2:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[0];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[1];
						y = f2(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 3:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[0];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[1];
						y = f3(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			//second neural
			case 4:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};
						
						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];

						y = f1(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y == 1)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 5:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};

						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];

						y = f2(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 6:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};

						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];

						y = f3(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;

			default:	_STD cout << "An error occured with choice" << NEW_LINE;
				break;
		}
	}
	else  //with bias
	{
		float weights[5]{};
		float y{};
		initial_weights(weights, 5);
		//weights[0] = 1;
		_STD cin >> choice;
		switch (choice)
		{
			//first neural
			case 1:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += weights[0];
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
						y = f3(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y == 1)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 2:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += weights[0];
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
						y = f3(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 3:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum{};
						sum += weights[0];
						sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
						sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
						y = f3(sum);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			//second neural
			case 4:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};

						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

						//initial_weights(weights, 2);

						sum1 += 1;
						sum2 += 1;

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];
						sum3 += 1;

						y = f3(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y == 1)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 5:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};

						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 


						sum1 += 1;
						sum2 += 1;

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];
						sum3 += 1;

						y = f2(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
			}
			break;
			case 6:
			{
				for (size_t i = 0; i < 500; ++i)
				{
					for (size_t j = 0; j < 500; ++j)
					{
						float sum1{};
						float sum2{};
						float sum3{};

						sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
						sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

						sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
						sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 


						sum1 += 1;
						sum2 += 1;

						sum3 += sum1 * weights[0];
						sum3 += sum2 * weights[1];
						sum3 += 1;

						y = f3(sum3);
						COORD c;
						c.X = i;
						c.Y = j;
						if (y <= 1 && y > 0.5)
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'o';
						}
						else
						{
							SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
							_STD cout << 'x';
						}
					}
				}
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

const float normalized_point(const float value, const __int16 min, const __int16 max, const __int16 new_min, const __int16 new_max)
{
	return ((value - (min)) / (max - min)) * (new_max - new_min) + (new_min);
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