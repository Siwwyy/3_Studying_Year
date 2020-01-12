#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'
#define e 2.71828182

const float f(const float value);
void Initialize_Inputs(bool inputs[4][3]);
void Print_Inputs(const bool inputs[4][3]);
void Print_Weights(const float weights[6]);


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	float learning_cofficient = 0.5f;
	constexpr float E_max = 0.003f;
	float E = 1.f;
	size_t c{ 0 };
	constexpr size_t C_max = 200;
	float weights[6]{};
	bool inputs[4][3]{};

	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
	std::uniform_real_distribution<int> choice(0,3);	//<> means it is a int

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	
	//inputs initialization
	Initialize_Inputs(inputs);
	Print_Inputs(inputs);

	//weight's initialization
	for (size_t i = 0; i < 6; ++i)
	{
		weights[i] = dis(generator);
	}
	Print_Weights(weights);

	bool if_break = false;
	while (c < C_max && if_break == false) 
	{
		//choice
		size_t choice_{ choice(generator) };
		//I LAYER
		float y11{};	//1
		float y12{};	//2

		y11 += 1;	//adding bias
		y12 += 1;	//adding bias

		y11 += static_cast<float>(inputs[choice_][0] * weights[0]);	//w 1 1 1
		y11 += static_cast<float>(inputs[choice_][1] * weights[2]);	//w 1 1 2

		y12 += static_cast<float>(inputs[choice_][0] * weights[1]);	//w 1 2 1
		y12 += static_cast<float>(inputs[choice_][1] * weights[3]);	//w 1 2 2 

		//Update the values by sigmoid function
		y11 = f(y11);
		y12 = f(y12);

		//II LAYER
		float y21{};
		
		y21 += 1;	//adding bias

		y21 += static_cast<float>(inputs[choice_][0] * weights[4]);	//w 2 1 1
		y21 += static_cast<float>(inputs[choice_][1] * weights[5]);	//w 2 1 2

		y21 = f(y21);

		//Update measurement error
		E += static_cast<float>((0.5f) * pow((inputs[choice_][2] - y21), 2));

		if (E > E_max)
		{
			//remember about counting the deltas!
			
		}
		else
		{
			if_break = true;
		}

		++c;
	}


	system("pause");
	return 0;
}

const float f(const float value)
{
	return static_cast<float>(1.0f / (1.0f + static_cast<float>(pow((1.0f / e), value))));
}

void Initialize_Inputs(bool inputs[4][3])
{
	_STD fstream file_in;
	file_in.open("file.in", std::ios_base::in | std::ios_base::binary);

	if (file_in.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		for (size_t i = 0; i < 4; ++i)
		{
			for (size_t j = 0; j < 3; ++j)
			{
				file_in >> inputs[i][j];
			}
		}
	}

	file_in.close();
}

void Print_Inputs(const bool inputs[4][3])
{
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			_STD cout << inputs[i][j] << ' ';
		}
		_STD cout << NEW_LINE;
	}
}

void Print_Weights(const float weights[6])
{
	for (size_t i = 0; i < 6; ++i)
	{
		_STD cout << weights[i] << ' ';
	}
	_STD cout << NEW_LINE;
}
