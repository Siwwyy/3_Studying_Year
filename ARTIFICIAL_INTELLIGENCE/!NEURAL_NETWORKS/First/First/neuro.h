#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <cmath>

class neuro
{
	int A[7][5] = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1} };
	int C[7][5] = {
		{1,1,1,1,1},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,1,1,1,1} };
	int A_t = 0;
	int C_t = 1;
	float E_max;
	float E;
	float w_u;
	float W[7][5];
	float Y;
	float result;
public:
	neuro();
	neuro(float E_max_, float w_u_);
	~neuro();
	void generate_w();
	void magix();
	void net(int num);
	void fix_A();
	void fix_C();
	void generate_file(std::string file_name);
	void test_output(int num);
	void get_answer(char letter);
	void set_from_file(std::string file_name);
};

