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

const float f1(const float value);	//progowa
const float f2(const float value);	//liniowa	
const float f3(const float value);	//sigmoidalna
const float normalized_point(const float value, const __int16 min, const __int16 max, const __int16 new_min, const __int16 new_max);
void initial_weights(float * weights, const size_t size);


class Pixel
{
	__int16 R;
	__int16 G;
	__int16 B;
public:
	Pixel():
		R(NULL),
		G(NULL),
		B(NULL)
	{

	}
	Pixel(const __int16 R, const __int16 G, const __int16 B) :
		R(R),
		G(G),
		B(B)
	{

	}

	void Set_R(const __int16 R)
	{
		this->R = R;
	}
	void Set_G(const __int16 G)
	{
		this->G = G;
	}

	void Set_B(const __int16 B)
	{
		this->B = B;
	}

	const __int16 Get_R() const
	{
		return this->R;
	}
	const __int16 Get_G() const
	{
		return this->G;
	}
	const __int16 Get_B() const
	{
		return this->B;
	}

	~Pixel()
	{
		this->R = 0;
		this->G = 0;
		this->B = 0;
	}
};

void Save_To_PPM(const _STD vector<_STD vector<Pixel>>& vec, const char * file_name);
void initial_vector(_STD vector<_STD vector<Pixel>>& vec);
void erase_vector(_STD vector<_STD vector<Pixel>>& vec);


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	_STD vector<_STD vector<Pixel>> Matrix(500);

	initial_vector(Matrix);

	size_t my_counter{};
	size_t my_counter2{};
	while (my_counter <= 1)
	{
		my_counter2 = 1;
		erase_vector(Matrix);
		if (my_counter == 0)	//without bias
		{
			while (my_counter2 <= 6)
			{
				erase_vector(Matrix);
				float weights[4]{};
				float y{};
				initial_weights(weights, 4);
				switch (my_counter2)
				{
					//first neural
				case 1:
				{
					/*for (size_t i = 0; i < 500; ++i)
					{
						for (size_t j = 0; j < 500; ++j)
						{
							float sum{};
							sum += normalized_point(i, 0, 500, (-5), 5) * weights[0];
							sum += normalized_point(j, 0, 500, (-5), 5) * weights[1];
							y = f1(sum);

							if (y == 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
							else
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
						}
					}
					Save_To_PPM(Matrix, "progowaI_bezbiasu.ppm");*/
				}
				break;
				case 2:
				{
					/*for (size_t i = 0; i < 500; ++i)
					{
						for (size_t j = 0; j < 500; ++j)
						{
							float sum{};
							sum += normalized_point(i, 0, 500, (-5), 5) * weights[0];
							sum += normalized_point(j, 0, 500, (-5), 5) * weights[1];
							y = f2(sum);

							if (y < -2)
							{
								Matrix[i][j].Set_R(8);
								Matrix[i][j].Set_G(37);
								Matrix[i][j].Set_B(103);
							}
							else if (y >= -2 && y < 0)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0 && y <= 2)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= -2 && y <= 0)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "liniowaI_bezbiasu.ppm");*/
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

							if (y >= 0 && y < 0.25)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.25 && y < 0.5)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0.5 && y < 0.75)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.75 && y <= 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "sigmoidalnaI_bezbiasu.ppm");
				}
				break;
				//second neural
				case 4:
				{
					//for (size_t i = 0; i < 500; ++i)
					//{
					//	for (size_t j = 0; j < 500; ++j)
					//	{
					//		float sum1{};
					//		float sum2{};
					//		float sum3{};

					//		sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
					//		sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

					//		sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
					//		sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

					//		sum3 += f1(sum1) * weights[0];
					//		sum3 += f1(sum2) * weights[1];

					//		y = f1(sum3);

					//		if (y == 1)
					//		{
					//			Matrix[i][j].Set_R(255);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(0);
					//		}
					//		else
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(255);
					//		}
					//	}
					//}
					//Save_To_PPM(Matrix, "progowaII_bezbiasu.ppm");
				}
				break;
				case 5:
				{
					//for (size_t i = 0; i < 500; ++i)
					//{
					//	for (size_t j = 0; j < 500; ++j)
					//	{
					//		float sum1{};
					//		float sum2{};
					//		float sum3{};

					//		sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
					//		sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

					//		sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
					//		sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

					//		sum3 += f2(sum1) * weights[0];
					//		sum3 += f2(sum2) * weights[1];

					//		y = f2(sum3);
					//		if (y < -2)
					//		{
					//			Matrix[i][j].Set_R(8);
					//			Matrix[i][j].Set_G(37);
					//			Matrix[i][j].Set_B(103);
					//		}
					//		else if (y >= -2 && y < 0)
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(255);
					//		}
					//		else if (y >= 0 && y <= 2)
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(255);
					//			Matrix[i][j].Set_B(0);
					//		}
					//		else if (y >= -2 && y <= 0)
					//		{
					//			Matrix[i][j].Set_R(255);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(0);
					//		}
					//	}
					//}
					//Save_To_PPM(Matrix, "liniowaII_bezbiasu.ppm");
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

							sum3 += f3(sum1) * weights[0];
							sum3 += f3(sum2) * weights[1];

							y = f3(sum3);

							if (y >= 0 && y < 0.25)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.25 && y < 0.5)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0.5 && y < 0.75)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.75 && y <= 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "sigmoidalnaII_bezbiasu.ppm");
				}
				break;

				default:	_STD cout << "An error occured with choice" << NEW_LINE;
					break;
				}

				++my_counter2;
			}

		}
		else  //with bias
		{
			while (my_counter2 <= 6)
			{
				erase_vector(Matrix);
				float weights[5]{};
				float y{};
				initial_weights(weights, 5);
				switch (my_counter2)
				{
					//first neural
				case 1:
				{
					/*for (size_t i = 0; i < 500; ++i)
					{
						for (size_t j = 0; j < 500; ++j)
						{
							float sum{};
							sum += 1;
							sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
							sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
							y = f1(sum);

							if (y == 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
							else
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
						}
					}
					Save_To_PPM(Matrix, "progowaI_zbiasem.ppm");*/
				}
				break;
				case 2:
				{
					/*for (size_t i = 0; i < 500; ++i)
					{
						for (size_t j = 0; j < 500; ++j)
						{
							float sum{};
							sum += 1;
							sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
							sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
							y = f2(sum);

							if (y < -2)
							{
								Matrix[i][j].Set_R(8);
								Matrix[i][j].Set_G(37);
								Matrix[i][j].Set_B(103);
							}
							else if (y >= -2 && y < 0)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0 && y <= 2)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= -2 && y <= 0)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "liniowaI_zbiasem.ppm");*/
				}
				break;
				case 3:
				{
					for (size_t i = 0; i < 500; ++i)
					{
						for (size_t j = 0; j < 500; ++j)
						{
							float sum{};
							sum += 1;
							sum += normalized_point(i, 0, 500, (-5), 5) * weights[1];
							sum += normalized_point(j, 0, 500, (-5), 5) * weights[2];
							y = f3(sum);

							if (y >= 0 && y < 0.25)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.25 && y < 0.5)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0.5 && y < 0.75)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.75 && y <= 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "sigmoidalnaI_zbiasem.ppm");
				}
				break;
				//second neural
				case 4:
				{
					//for (size_t i = 0; i < 500; ++i)
					//{
					//	for (size_t j = 0; j < 500; ++j)
					//	{
					//		float sum1{};
					//		float sum2{};
					//		float sum3{};

					//		sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
					//		sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

					//		sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
					//		sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

					//		sum1 += 1;
					//		sum2 += 1;

					//		sum3 += f1(sum1) * weights[0];
					//		sum3 += f1(sum2) * weights[1];
					//		sum3 += 1;

					//		y = f1(sum3);

					//		if (y == 1)
					//		{
					//			Matrix[i][j].Set_R(255);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(0);
					//		}
					//		else
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(255);
					//		}
					//	}
					//}
					//Save_To_PPM(Matrix, "progowaII_zbiasem.ppm");
				}
				break;
				case 5:
				{
					//for (size_t i = 0; i < 500; ++i)
					//{
					//	for (size_t j = 0; j < 500; ++j)
					//	{
					//		float sum1{};
					//		float sum2{};
					//		float sum3{};

					//		sum1 += normalized_point(i, 0, 500, (-5), 5) * weights[0];	//w 1 1 1
					//		sum2 += normalized_point(i, 0, 500, (-5), 5) * weights[2];	//w 1 2 1

					//		sum1 += normalized_point(j, 0, 500, (-5), 5) * weights[1];	//w 1 1 2
					//		sum2 += normalized_point(j, 0, 500, (-5), 5) * weights[3];	//w 1 2 2 

					//		sum1 += 1;
					//		sum2 += 1;

					//		sum3 += f2(sum1) * weights[0];
					//		sum3 += f2(sum2) * weights[1];
					//		sum3 += 1;

					//		y = f2(sum3);

					//		if (y < -2)
					//		{
					//			Matrix[i][j].Set_R(8);
					//			Matrix[i][j].Set_G(37);
					//			Matrix[i][j].Set_B(103);
					//		}
					//		else if (y >= -2 && y < 0)
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(255);
					//		}
					//		else if (y >= 0 && y <= 2)
					//		{
					//			Matrix[i][j].Set_R(0);
					//			Matrix[i][j].Set_G(255);
					//			Matrix[i][j].Set_B(0);
					//		}
					//		else if (y >= -2 && y <= 0)
					//		{
					//			Matrix[i][j].Set_R(255);
					//			Matrix[i][j].Set_G(0);
					//			Matrix[i][j].Set_B(0);
					//		}
					//	}
					//}
					//Save_To_PPM(Matrix, "liniowaII_zbiasem.ppm");
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

							sum3 += f3(sum1) * weights[0];
							sum3 += f3(sum2) * weights[1];
							sum3 += 1;

							y = f3(sum3);

							if (y >= 0 && y < 0.25)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.25 && y < 0.5)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(255);
							}
							else if (y >= 0.5 && y < 0.75)
							{
								Matrix[i][j].Set_R(0);
								Matrix[i][j].Set_G(255);
								Matrix[i][j].Set_B(0);
							}
							else if (y >= 0.75 && y <= 1)
							{
								Matrix[i][j].Set_R(255);
								Matrix[i][j].Set_G(0);
								Matrix[i][j].Set_B(0);
							}
						}
					}
					Save_To_PPM(Matrix, "sigmoidalnaII_zbiasem.ppm");
				}
				break;

				default:	_STD cout << "An error occured with choice" << NEW_LINE;
					break;
				}
				++my_counter2;
			}
		}

		++my_counter;
	}

	system("pause");
	return 0;
}


const float f1(const float value)
//progowa
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
//liniowa
{
	return value;
}

const float f3(const float value)
//sigmoidalna
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

void initial_vector(::std::vector<::std::vector<Pixel>>& vec)
{
	for (typename _STD vector<_STD vector<Pixel>>::iterator vec_iterator = vec.begin(); vec_iterator != vec.end(); ++vec_iterator)
	{
		vec_iterator->resize(500);
	}
}

void erase_vector(::std::vector<::std::vector<Pixel>>& vec)
{
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		for (auto iter_second = iter->begin(); iter_second != iter->end(); ++iter_second)
		{
			iter_second->Set_R(NULL);
			iter_second->Set_G(NULL);
			iter_second->Set_B(NULL);
		}
	}
}

void Save_To_PPM(const::std::vector<::std::vector<Pixel>>& vec, const char * file_name)
{
	std::fstream file_out;
	file_out.open(file_name, _STD ios_base::out);
	if (file_out.good() == false)
	{
		exit(0);
	}
	else
	{
		file_out << "P3";
		file_out << '\n';
		file_out << "# Created by Damian Andrysiak";
		file_out << '\n';
		file_out << vec.size();
		file_out << ' ';
		file_out << vec[0].size();
		file_out << '\n';
		file_out << 255;
		file_out << '\n';

		for (auto iter = vec.begin(); iter != vec.end(); ++iter)
		{
			for (auto iter_second = iter->begin(); iter_second != iter->end(); ++iter_second)
			{
				file_out << iter_second->Get_R();
				file_out << ' ';
				file_out << iter_second->Get_G();
				file_out << ' ';
				file_out << iter_second->Get_B();
				file_out << ' ';
			}

			file_out << NEW_LINE;
		}
	}

	file_out.close();
}