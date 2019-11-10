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
void Print_Graph(const __int32* const* const Graph, const size_t size);
/////////////////////////////////////////////////////////////////////////

/*
	GPU FUNCTIONS
*/
__global__ void Print_Graph_GPU(const __int32* const* const Graph, const size_t * const size);
/////////////////////////////////////////////////////////////////////////


/*
	GLOBAL VALUES ON CPU
*/
/////////////////////////////////////////////////////////////////////////
__int32** Graph;	//all connections
size_t Graph_size;
/////////////////////////////////////////////////////////////////////////
__int32** Graph_GPU;
size_t* Graph_size_GPU;
/////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
	inserter();

	for (size_t i = 0; i < Graph_size; ++i)
	{
		delete[] Graph[i];
	}
	delete[] Graph;
	cudaFree(Graph_GPU);
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
		Graph = new __int32*[m];
		cudaMalloc((void**)&Graph_GPU, (m * m) * sizeof(__int32));	//GPU interprets 2D array as a flat array !
		cudaMalloc((void**)&Graph_size_GPU, sizeof(__int32));	//GPU interprets 2D array as a flat array !
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
				for (size_t i = 0; i < Graph_size; ++i)
				{
					cudaMemcpy(Graph_GPU + i * Graph_size, *(Graph + i), sizeof(__int32) * Graph_size, HostToDevice);
					//_STD cout << **(Graph + i) << NEW_LINE;
				}
				cudaMemcpy(Graph_size_GPU, &Graph_size, sizeof(__int32), HostToDevice);
				Print_Graph(Graph, Graph_size);
				dim3 threads(Graph_size, Graph_size);
				Print_Graph_GPU<<<1, 1>>>(Graph_GPU, Graph_size_GPU);
				cudaDeviceSynchronize();
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


void Print_Graph(const __int32* const* const Graph, const size_t size)
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

__global__ void Print_Graph_GPU(const __int32* const* const Graph, const size_t* const size)
{
	int id_x = threadIdx.x + blockIdx.x * blockDim.x;
	int id_y = threadIdx.y + blockIdx.y * blockDim.y;
//	while (id_x < *(size) && id_y < *(size))
//	{
//		printf("%d |", Graph[id_y * (*(size)) + id_x]);
///*		if (id_x % *(size) == 0 || id_y % *(size) == 0)
//		{
//			printf("\n");
//		}*/
//		id_x += blockDim.x * gridDim.x;
//		id_y += blockDim.y * gridDim.y;
//	}
	for (size_t i = 0; i < ((*size)* (*size)); ++i)
	{
		printf("%d |", Graph[i]);
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
	cudaMemset(Verticle, NULL, sizeof(__int32));
	cudaMemset(Edge, NULL, sizeof(__int32));
	cudaMemset(Cost, NULL, sizeof(__int32));
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