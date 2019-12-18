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
#include <random>

////////////////////////////////////////////////////
//GPU

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'

#define SIZE 5

__global__ void Bubble_Sort_GPU(__int32 * array_GPU, const size_t * const size);


int main(int argc, char* argv[])
{
	//CPU VARIABLES
	constexpr size_t size = 10;
	__int32* array_to_sort = new __int32[size];

	//GPU VARIABLES
	size_t* size_GPU{};
	cudaMalloc(&size_GPU, sizeof(__int32));
	cudaMemcpy(size_GPU, &size, sizeof(__int32), HostToDevice);
	__int32* array_to_sort_GPU{};
	cudaMalloc(&array_to_sort_GPU, sizeof(__int32) * (size));


	std::default_random_engine generator;
	std::uniform_int_distribution<> dis(-100, 100);			//zakres naszego losowania


	//FILL CPU ARRAY AND THEN COPY INTO GPU ARRAY
	for (size_t i = 0; i < size; ++i)
	{
		array_to_sort[i] = dis(generator);
	}
	//DISPLAY FILLED UP ARRAY
	for (size_t i = 0; i < size; ++i)
	{
		_STD cout << array_to_sort[i] << " ";
	}
	_STD cout << NEW_LINE;

	cudaMemcpy(array_to_sort_GPU, array_to_sort, (size)*sizeof(__int32), HostToDevice);


	Bubble_Sort_GPU << <1, size>> > (array_to_sort_GPU, 10);

	
	//COPY SORTED ARRAY BACK TO THE CPU
	cudaMemcpy(array_to_sort, array_to_sort_GPU, (size) * sizeof(__int32), DeviceToHost);

	//DISPLAY SORTED ARRAY
	for (size_t i = 0; i < size; ++i)
	{
		_STD cout << array_to_sort[i] << " ";
	}


	//DEALLOCATE CPU MEMORY
	delete[] array_to_sort;

	//DEALLOCATE GPU MEMORY
	cudaFree(size_GPU);
	cudaFree(array_to_sort_GPU);

	system("pause");
	return 0;
}

__global__ void Bubble_Sort_GPU(__int32* array_GPU, const size_t* const size)
{
	size_t id_x = threadIdx.x + blockIdx.x * blockDim.x;

	while (id_x < ((*size) - 1))
	{
		if (array_GPU[id_x] > array_GPU[id_x + 1])
		{
			__int32 temp{};
			temp = array_GPU[id_x];
			array_GPU[id_x] = array_GPU[id_x + 1];
			array_GPU[id_x + 1] = temp;
		}
	}
}
