#include "../Include/Cuda_Kernel.cuh"

////////////////////////////////////////////////////
//GPU

#include "device_launch_parameters.h"
#ifndef __CUDACC__
#define __CUDACC__
#endif

#include "cuda_runtime.h"
#include "device_functions.h"

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'
#define SIZE 10

////////////////////////////////////////////////////
//CPU

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

////////////////////////////////////////////////////


//__global__ void Get_String_Length(const char* const __string, size_t* length);
__global__ void Hello_World(const size_t* const loop_repeat);	//const pointer to const size_t
__global__ void Print(const char* const __string, const size_t* const loop_repeat);	//const pointer to const size_t



///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
	FUNCTIONS BODY
*/
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


__global__ void Hello_World(const size_t* const loop_repeat)
{
	//int id_x = blockIdx.x;	//for blocks (copies of blocks)
	//printf("%d\n", *loop_repeat);
	int id_x = blockDim.x * blockIdx.x + threadIdx.x;
	while (id_x < static_cast<int>(*loop_repeat))
	{
		printf("HELLO WORLD!%c", NEW_LINE);
		//id_x += gridDim.x;	//for blocks
		id_x += blockDim.x * gridDim.x;
	}
	__syncthreads();
}

__global__ void Print(const char* const __string, const size_t* const loop_repeat)
{
	int id_x = threadIdx.x + blockIdx.x * blockDim.x;
	while (id_x < static_cast<int>(*loop_repeat))
	{
		//remember, threads execute in unpredictable order !
		printf("%c", __string[id_x]);
		__syncthreads();
		id_x += blockDim.x * gridDim.x;
	}
	//int id_x = threadIdx.x + blockIdx.x * blockDim.x;
	//int warp_ID = threadIdx.x >> 5;
	//while (id_x < static_cast<int>(*loop_repeat))
	//{
	//	if (warp_ID == 0)
	//		printf("%c", __string[id_x]);
	//	__syncthreads();
	//	if (warp_ID == 1)
	//		printf("%c", __string[id_x]);
	//	__syncthreads();
	//	id_x += blockDim.x * gridDim.x;
	//}
}

void My_Kernel::Kernel(const __int32& repeat_amount)
{
	//GPU MEMORY ALLOCATION
	size_t* loop_repeat{};
	cudaMalloc((void**)&loop_repeat, sizeof(size_t));

	//COPY VALUE FROM CPU(RAM) TO GPU
	cudaMemcpy(loop_repeat, &repeat_amount, sizeof(__int32), HostToDevice);

	dim3 grid_size(repeat_amount);
	dim3 block_size(repeat_amount);

	Hello_World << <1, block_size >> > (loop_repeat);
	cudaError_t final_error = cudaDeviceSynchronize();	//for synchronization e.g Hello_World then printf
	if (final_error == cudaSuccess)
	{
		printf("%cKernel executed successfully with code: %d !%\n", NEW_LINE, final_error);
	}
	else
	{
		printf("%cKernel executed with code error: %d !\n", NEW_LINE, final_error);
	}

	cudaFree(loop_repeat);
}

void My_Kernel::Print_String(const char * my_string)
{
	size_t temp{};
	temp = Get_String_Length(my_string);	//get the string length
	//GPU MEMORY ALLOCATION
	size_t* my_string_length{};
	cudaMalloc((void**)&my_string_length, sizeof(size_t));
	//COPY VALUE FROM CPU(RAM) TO GPU
	cudaMemcpy(my_string_length, &temp, sizeof(size_t), HostToDevice);

	char* string_GPU{};
	cudaMalloc((void**)&string_GPU, (temp) * sizeof(char));

	//COPY VALUE FROM CPU(RAM) TO GPU
	cudaMemcpy(string_GPU, my_string, (temp) * sizeof(char), HostToDevice);

	dim3 grid_size(1);
	dim3 block_size((temp));


	Print <<< grid_size, temp >>> (string_GPU, my_string_length);
	cudaError_t final_error = cudaDeviceSynchronize();	//for synchronization e.g Hello_World then printf
	if (final_error == cudaSuccess)
	{
		printf("%cKernel executed successfully with code: %d !%\n", NEW_LINE, final_error);
	}
	else
	{
		printf("%cKernel executed with code error: %d !\n", NEW_LINE, final_error);
	}

	cudaFree(my_string_length);
	cudaFree(string_GPU);
}

const size_t My_Kernel::Get_String_Length(const char* const __string)
{
	size_t string_length{};
	while (__string[string_length] != '\0')
	{
		++(string_length);
	}
	return string_length;
}