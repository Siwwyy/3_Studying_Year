#include "neuro.h"



neuro::neuro()
{
	set_from_file("learned_values.txt");
}

neuro::neuro(float E_max_, float w_u_)
{
	E_max = E_max_;
	w_u = w_u_;
	Y = 0;
	generate_w();
}


neuro::~neuro()
{
}

void neuro::generate_w()
{
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			W[i][j] = rand() % (3) - 1;
			//std::cout << W[i][j] << "\n";
		}
	}
}

void neuro::magix()
{
	float D;
	E = 0;
	char letter;
	for (int i = 0; i < 100; i++) {
		D = rand() / double(RAND_MAX);
		if (D < 0.5) {
			net(1);
			letter = 'a';
		}
		else {
			net(2);
			letter = 'c';
		}
		std::cout << i << ": " << E << "\n";
		std::cout << i << ": " << letter << " " << D << ": " << result << "\n";
	}
	generate_file("learned_values.txt");
}

void neuro::net(int num)
{
	if (num == 1) {
		Y = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				Y += W[i][j] * A[i][j];
			}
		}
		result = 1.0 / (1 + exp(-Y));
		E += 0.5*(pow((A_t - result), 2));
		if (E > E_max) {
			fix_A();
			w_u *= 0.95;
		}
	}
	if (num == 2) {
		Y = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				Y += W[i][j] * C[i][j];
			}
		}
		result = 1.0 / (1 + exp(-Y));
		E += 0.5*(pow((C_t - result), 2));
		if (E > E_max) {
			fix_C();
			w_u *= 0.95;
		}
	}
}

void neuro::fix_A()
{
	float mod = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			mod = -((A_t - result) * (1 - result) * result * A[i][j]);
			W[i][j] = W[i][j] - w_u * mod;
		}
	}
}

void neuro::fix_C()
{
	float mod = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			mod = -((C_t - result) * (1 - result) * result * C[i][j]);
			W[i][j] = W[i][j] - w_u * mod;
		}
	}
}

void neuro::generate_file(std::string file_name)
{
	std::ofstream file;
	file.open(file_name);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			file << W[i][j] << "\n";
		}
	}
	file.close();
}

void neuro::test_output(int num)
{
	for (int i = 0; i < num; i++) {
		std::cout << "Wybierz znak: a, c\n";
		char ch;
		std::cin >> ch;
		get_answer(ch);
	}
}

void neuro::get_answer(char letter)
{
	if (letter == 'a') {
		Y = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				Y += W[i][j] * A[i][j];
			}
		}
		result = 1.0 / (1 + exp(-Y));
	}
	else if (letter == 'c') {
		Y = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				Y += W[i][j] * C[i][j];
			}
		}
		result = 1.0 / (1 + exp(-Y));
	}
	std::cout << "It is: " << result << "\n";
}

void neuro::set_from_file(std::string file_name)
{
	std::ifstream file;
	file.open(file_name);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			file >> W[i][j];
		}
	}
	file.close();
}
