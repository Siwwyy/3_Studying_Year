#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <iomanip>
#include <math.h>
#include <windows.h>

#define NEW_LINE '\n'
#define e 2.71828182

const float f(const float value);
const float df(const float value);
void Initialize_Inputs(__int16 inputs[4][3]);
void Print_Inputs(const __int16 inputs[4][3]);
void Print_Weights(const float weights[9]);
void Save_Weights(const float weights[9]);
void Predict_Value(const float inputs[3], const float weights[9]);


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;
	using _STD cin;

	float learning_cofficient = 0.8f;
	constexpr float E_max = 0.003f;
	float E = 0.f;
	size_t c{ 0 };
	constexpr size_t C_max = 200;	//amount of iterations
	float weights[9]{};
	__int16 inputs[4][3]{};
	bool T[]{0,1,1,0};

	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
	//std::uniform_real_distribution<int> choice(0,3);	//<> means it is a int

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	
	//inputs initialization
	Initialize_Inputs(inputs);
	//Print_Inputs(inputs);

	//weight's initialization
	for (size_t i = 0; i < 9; ++i)
	{
		weights[i] = dis(generator);
	}
	//Print_Weights(weights);

	bool if_break = true;
	while (if_break)
	{
		for (size_t choice = 0; choice < 4; ++choice)
		{
			///////////////////////////
			//FIRST LAYER
			float neuron_I1{};
			float neuron_I2{};
			//SECOND LAYER
			float neuron_II1{};
			///////////////////////////

			neuron_I1 += inputs[choice][0] * weights[0];	//w 1 1 1	//first layer, to which neuron, from which input
			neuron_I1 += inputs[choice][1] * weights[1];	//w 1 1 2
			neuron_I1 += inputs[choice][2] * weights[4];	//w 1 1 3	//bias


			neuron_I2 += inputs[choice][1] * weights[2];	//w 1 2 1
			neuron_I2 += inputs[choice][0] * weights[3];	//w 1 2 2
			neuron_I2 += inputs[choice][2] * weights[5];	//w 1 2 3	//bias


			float temp_neuron_I1{ neuron_I1 };
			float temp_neuron_I2{ neuron_I2 };

			neuron_I1 = f(neuron_I1);
			neuron_I2 = f(neuron_I2);


			neuron_II1 += neuron_I1 * weights[6];	//w 2 1 1
			neuron_II1 += neuron_I2 * weights[7];	//w 2 1 2
			neuron_II1 += inputs[choice][2] * weights[8];	//w 2 1 3 //bias


			float temp_neuron_II1{ neuron_II1 };

			neuron_II1 = f(neuron_II1);

			//Counting error 
			float sigma21{};

			float simga11{};
			float sigma12{};

			sigma21 = (T[choice] - neuron_II1) * df(temp_neuron_II1);

			simga11 = sigma21 * weights[6] * df(temp_neuron_I1);
			sigma12 = sigma21 * weights[7] * df(temp_neuron_I2);

			//Update weights
			weights[0] += learning_cofficient * simga11 * inputs[choice][0];	//w 1 1 1 
			weights[1] += learning_cofficient * simga11 * inputs[choice][1];
			weights[4] += learning_cofficient * simga11 * inputs[choice][2];


			weights[2] += learning_cofficient * sigma12 * inputs[choice][1];
			weights[3] += learning_cofficient * sigma12 * inputs[choice][0];
			weights[5] += learning_cofficient * sigma12 * inputs[choice][2];


			weights[6] += learning_cofficient * sigma21 * neuron_I1;
			weights[7] += learning_cofficient * sigma21 * neuron_I2;
			weights[8] += learning_cofficient * sigma21 * inputs[choice][2];


			//Counting E
			E += static_cast<float>((0.5f) * pow((T[choice] - neuron_II1), 2));
			//_STD cout << E << NEW_LINE;
		}
		if (E < E_max)
		{
			if_break = false;
		}
		else
		{
			E = 0;
		}
		//Print_Weights(weights);
		//system("pause");
		++c;
	}

	//Save_Weights(weights);
	float temp_input[]{ -1,-1,1 };
	Predict_Value(temp_input, weights);

	system("pause");
	return 0;
}

const float f(const float value)
{
	return static_cast<float>(1.0f / (1.0f + static_cast<float>(pow((1.0f / e), value))));
}

const float df(const float value)
{
	return static_cast<float>((1 * exp(-1 * value)) / pow(1 + exp(-1 * value), 2));
}

void Initialize_Inputs(__int16 inputs[4][3])
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

void Print_Inputs(const __int16 inputs[4][3])
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

void Save_Weights(const float weights[9])
{
	_STD fstream file_out;
	file_out.open("learned.out", std::ios_base::out);

	if (file_out.good() == false)
	{
		_STD cerr << "[WARRNING:0001] Invalid file_path\n";
	}
	else
	{
		for (size_t i = 0; i < 9; ++i)
		{
			//_STD cout << _STD setprecision(10) << weights[i] << NEW_LINE;
			//printf("%0.12f\n", weights[i]);
			file_out << weights[i] << '\n';
		}
	}

	file_out.close();
}

void Predict_Value(const float inputs[3], const float weights[9])
{
	bool T[]{ 0,1 };
	///////////////////////////
	//FIRST LAYER
	float neuron_I1{};
	float neuron_I2{};
	//SECOND LAYER
	float neuron_II1{};
	///////////////////////////
	//przekaz liczby zaburzone

	neuron_I1 += inputs[0] * weights[0];	//w 1 1 1	//first layer, to which neuron, from which input
	neuron_I1 += inputs[1] * weights[1];	//w 1 1 2
	neuron_I1 += inputs[2] * weights[4];	//w 1 1 3	//bias


	neuron_I2 += inputs[1] * weights[2];	//w 1 2 1
	neuron_I2 += inputs[0] * weights[3];	//w 1 2 2
	neuron_I2 += inputs[2] * weights[5];	//w 1 2 3	//bias

	neuron_I1 = f(neuron_I1);
	neuron_I2 = f(neuron_I2);


	neuron_II1 += neuron_I1 * weights[6];	//w 2 1 1
	neuron_II1 += neuron_I2 * weights[7];	//w 2 1 2
	neuron_II1 += inputs[2] * weights[8];	//w 2 1 3 //bias

	neuron_II1 = f(neuron_II1);

	if (neuron_II1 > 0.5f && neuron_II1 <= 1.0f)
	{
		_STD cout << "In my opinion the result is closer to: " << "1" << NEW_LINE;
	}
	else
	{
		_STD cout << "In my opinion the result is closer to: " << "0" << NEW_LINE;
	}
}

void Print_Weights(const float weights[9])
{
	for (size_t i = 0; i < 9; ++i)
	{
		_STD cout << weights[i] << ' ';
	}
	_STD cout << NEW_LINE;
}