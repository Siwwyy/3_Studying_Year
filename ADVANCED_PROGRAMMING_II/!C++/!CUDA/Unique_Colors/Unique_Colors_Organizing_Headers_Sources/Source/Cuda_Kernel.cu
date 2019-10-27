#include "../Include/cuda_kernel.cuh"

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

////////////////////////////////////////////////////


							//const pointer to const size_t
__global__ void Hello_World(const size_t* const loop_repeat)
{
	//int id_x = blockIdx.x;	//for blocks (copies of blocks)
	int id_x = blockDim.x * blockIdx.x + threadIdx.x;
	while (id_x < static_cast<int>(*loop_repeat))
	{
		printf("HELLO WORLD!%c", NEW_LINE);
		//id_x += gridDim.x;	//for blocks
		id_x += blockDim.x * gridDim.x;
	}
	__syncthreads();
}

void My_Kernel::Kernel(const __int32 & repeat_amount)
{
	//GPU MEMORY ALLOCATION
	size_t * loop_repeat{};
	cudaMalloc((void**)&loop_repeat, sizeof(size_t*));

	//COPY VALUE FROM CPU(RAM) TO GPU
	cudaMemcpy(loop_repeat, &repeat_amount, sizeof(__int32), HostToDevice);

	dim3 grid_size(repeat_amount);
	dim3 block_size(repeat_amount);

	Hello_World<<<1, block_size>>>(loop_repeat);
	cudaError_t final_error = cudaDeviceSynchronize();	//for synchronization e.g Hello_World then printf
	if (final_error == cudaSuccess)
	{
		printf("%cKernel executed successfully with code: %d !%\n", NEW_LINE, final_error);
	}
	else
	{
		printf("%cKernel executed with code error: %d !\n", NEW_LINE, final_error);
	}
}