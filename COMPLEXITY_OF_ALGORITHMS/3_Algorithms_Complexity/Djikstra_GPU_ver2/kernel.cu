#include "device_launch_parameters.h"
#ifndef __CUDACC__
#define __CUDACC__
#endif

#include "cuda_runtime.h"
#include "device_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <functional>

////////////////////////////////////////////////////
//GPU

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'


class _Djikstra_Element
{
private:
	__int32* Verticle;
	__int32* Edge;
	__int32* Cost;
public:
	__host__ _Djikstra_Element();
	__host__ _Djikstra_Element(_STD initializer_list<__int32> _Initializer);
	__host__ _Djikstra_Element(const _Djikstra_Element & Object);


	__host__ ~_Djikstra_Element();
};

//MAIN LANUCH FUNCTION
void inserter();

/*
	CPU FUNCTIONS
*/
void Print_Graph(const __int32* const* const Graph, size_t size);
/////////////////////////////////////////////////////////////////////////




/*
	GLOBAL VALUES ON CPU
*/
/////////////////////////////////////////////////////////////////////////
__int32** Graph;	//all connections
size_t Graph_size;
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
	inserter();

	for (size_t i = 0; i < Graph_size; ++i)
	{
		delete[] Graph[i];
	}
	delete[] Graph;
	system("pause");
	return 0;
}


void inserter()
{
	int m = 0;			//amount of cities
	int d = 0;			//amount of ways
	int c1 = 0;			//number of city
	int c2 = 0;			//number of city
	int p = 0;			//amount of max passengers between one course
	int s = 0;			//the beginning of way
	int e = 0;			//the end of way
	int t = 0;			//amount of max passengers to move by bus
	while (true)
	{
		std::cin >> m;
		std::cin >> d;
		Graph_size = m;
		//Construct(m);
		Graph = new __int32* [m];
		for (size_t i = 0; i < Graph_size; ++i)
		{
			Graph[i] = new __int32[m];
			for (size_t j = 0; j < Graph_size; ++j)
			{
				Graph[i][j] = NULL;
			}
		}
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			//Push(c1, c2, p);
			//Push(c2, c1, p);
			Graph[(c1 - 1)][(c2 - 1)] = p;
			Graph[(c2 - 1)][(c1 - 1)] = p;
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		Print_Graph(Graph, Graph_size);
		//system("pause");
		//exit(0);
		while (true)
		{
			std::cin >> s;
			std::cin >> e;
			if (s != 0 && e != 0)
			{
				std::cin >> t;
				//Push_Directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				
				//Get_Results();
				
				///////////////////////////////////////////////
				//system("pause");
				//exit(0);
				break;
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
		break;
	}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	CPU FUNCTIONS
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


void Print_Graph(const __int32* const* const Graph, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			_STD cout << Graph[i][j] << ' ';
		}
		_STD cout << NEW_LINE;
	}
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Djikstra_Element METHODS
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


__host__ _Djikstra_Element::_Djikstra_Element()
{
	cudaMalloc((void**)&Verticle, sizeof(__int32));
	cudaMalloc((void**)&Edge, sizeof(__int32));
	cudaMalloc((void**)&Cost, sizeof(__int32));
}

__host__ _Djikstra_Element::_Djikstra_Element(_STD initializer_list<__int32> _Initializer)
{
	if (_Initializer.size() == 3)
	{
		cudaMalloc((void**)&Verticle, sizeof(__int32));
		cudaMalloc((void**)&Edge, sizeof(__int32));
		cudaMalloc((void**)&Cost, sizeof(__int32));
		cudaMemset(Verticle, (*_Initializer.begin()), sizeof(__int32));
		cudaMemset(Edge, (*(_Initializer.begin() + 1)), sizeof(__int32));
		cudaMemset(Cost, (*(_Initializer.begin() + 2)), sizeof(__int32));
	}
}

__host__ _Djikstra_Element::~_Djikstra_Element()
{
	cudaFree(Verticle);
	cudaFree(Edge);
	cudaFree(Cost);
}