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

////////////////////////////////////////////////////
//GPU

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'

#define SIZE 4

//CPU FUNCTIONS
void Show_Matrix(const __int32* const* const Matrix);
void Fill_Matrix(__int32* const* const Matrix, const __int32 initial_value);

//GPU FUNCTIONS
__global__ void Show_Matrix_GPU(const __int32* const Matrix);
__global__ void Multiply_Matrices(const __int32* const Matrix_GPU_A, const __int32* const Matrix_GPU_B, __int32* const Matrix_GPU_C);

int main(int argc, char* argv[])
{
	/*
		ALLOCATING NEEDED MEMORY ON CPU (exactly in RAM)
	*/
	__int32** Matrix_CPU_A;
	Matrix_CPU_A = (__int32**)malloc(SIZE * sizeof(__int32*));
	__int32** Matrix_CPU_B;
	Matrix_CPU_B = (__int32**)malloc(SIZE * sizeof(__int32*));
	__int32** Matrix_CPU_C;
	Matrix_CPU_C = (__int32**)malloc(SIZE * sizeof(__int32*));

	for (size_t i = 0; i < SIZE; ++i)
	{
		*(Matrix_CPU_A + i) = (__int32*)malloc(SIZE * sizeof(__int32));
		*(Matrix_CPU_B + i) = (__int32*)malloc(SIZE * sizeof(__int32));
		*(Matrix_CPU_C + i) = (__int32*)malloc(SIZE * sizeof(__int32));
		//Matrix_CPU[i] = (__int32*)malloc(SIZE * sizeof(__int32));
	}
	////////////////////////////////////////////////////

	//FILL MATRIX WITH RANDOM VALUES
	Fill_Matrix(Matrix_CPU_A,5);
	Fill_Matrix(Matrix_CPU_B,5);
	Fill_Matrix(Matrix_CPU_C,0);

	//SHOW FILLED UP ARRAY
	Show_Matrix(Matrix_CPU_A);
	Show_Matrix(Matrix_CPU_B);
	Show_Matrix(Matrix_CPU_C);


	/*
		ALLOCATING NEEDED MEMORY ON GPU
	*/
	__int32* Matrix_GPU_A;
	cudaMalloc((void**)&Matrix_GPU_A, (SIZE * SIZE) * sizeof(__int32));	//GPU interprets 2D array as a flat array !
	__int32* Matrix_GPU_B;
	cudaMalloc((void**)&Matrix_GPU_B, (SIZE * SIZE) * sizeof(__int32));
	__int32* Matrix_GPU_C;
	cudaMalloc((void**)&Matrix_GPU_C, (SIZE * SIZE) * sizeof(__int32));
	////////////////////////////////////////////////////


	//COPY CPU ARRAY TO GPU
	//HANDLE_ERROR(cudaMemcpy(Matrix_GPU, Matrix_CPU, (SIZE * SIZE) * sizeof(__int32), HostToDevice));	//only for statics array from HOST's!

	for (size_t i = 0; i < SIZE; ++i)
	{
		cudaMemcpy(Matrix_GPU_A + i * SIZE, *(Matrix_CPU_A + i), sizeof(__int32) * SIZE, HostToDevice);
		cudaMemcpy(Matrix_GPU_B + i * SIZE, *(Matrix_CPU_B + i), sizeof(__int32) * SIZE, HostToDevice);
		cudaMemcpy(Matrix_GPU_C + i * SIZE, *(Matrix_CPU_C + i), sizeof(__int32) * SIZE, HostToDevice);
	}

	////////////////////////////////////////////////////

	//MULTIPLY THE MATRICES
	//Show_Matrix_GPU << <SIZE, SIZE >> > (Matrix_GPU_A);
	//Show_Matrix_GPU << <SIZE, SIZE >> > (Matrix_GPU_B);
	//Show_Matrix_GPU << <SIZE, SIZE >> > (Matrix_GPU_C);
	Multiply_Matrices <<<1, SIZE>>> (Matrix_GPU_A, Matrix_GPU_B, Matrix_GPU_C);
	//Show_Matrix_GPU <<<SIZE, SIZE>>> (Matrix_GPU_A);
	//Show_Matrix_GPU <<<SIZE, SIZE>>> (Matrix_GPU_B);
	//Show_Matrix_GPU <<<SIZE, SIZE>>> (Matrix_GPU_C);

	_STD cin.get();
	//COPY FROM GPU TO CPU
	//HANDLE_ERROR(cudaMemcpy(Matrix_CPU, Matrix_GPU, (SIZE * SIZE) * sizeof(__int32), DeviceToHost));	//only for statics array

	//copying data from GPU to CPU
	for (size_t i = 0; i < SIZE; ++i)
	{
		cudaMemcpy(*(Matrix_CPU_C + i), Matrix_GPU_C + i * SIZE, sizeof(__int32) * SIZE, DeviceToHost);	//for dynamic allocation, only result matrix
	}
	////////////////////////////////////////////////////


	//SHOW RESULTS
	Show_Matrix(Matrix_CPU_C);

	/*
		FREEING PREVIOUSLY ALOCATED MEMORY
	*/
	//ON CPU
	for (size_t i = 0; i < SIZE; ++i)
	{
		free(*(Matrix_CPU_A + i));
		free(*(Matrix_CPU_B + i));
		free(*(Matrix_CPU_C + i));
	}
	free(Matrix_CPU_A);
	free(Matrix_CPU_B);
	free(Matrix_CPU_C);

	//ON GPU
	cudaFree(Matrix_GPU_A);
	cudaFree(Matrix_GPU_B);
	cudaFree(Matrix_GPU_C);
	////////////////////////////////////////////////////


	system("pause");
	return 0;
}

void Show_Matrix(const __int32* const* const Matrix)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		_STD cout << "| ";
		for (size_t j = 0; j < SIZE; ++j)
		{
			_STD cout << Matrix[i][j] << " | ";
		}
		_STD cout << NEW_LINE;
	}
	_STD cout << NEW_LINE;
}

void Fill_Matrix(__int32* const* const Matrix, const __int32 initial_value)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		for (size_t j = 0; j < SIZE; ++j)
		{
			Matrix[i][j] = initial_value;
		}
	}
}

__global__ void Show_Matrix_GPU(const __int32* const Matrix)
{
	int id_x = threadIdx.x + blockIdx.x * blockDim.x;
	int id_y = threadIdx.y + blockIdx.y * blockDim.y;
	while (id_x < SIZE)
	{
		while (id_y < SIZE)
		{
			printf("| %d ", Matrix[id_y * SIZE + id_x]);
			id_y += blockDim.y * gridDim.y;
		}
		id_x += blockDim.x * gridDim.x;
	}
	printf("\n");
}

__global__ void Multiply_Matrices(const __int32* const Matrix_GPU_A, const __int32* const Matrix_GPU_B, __int32* const Matrix_GPU_C)
{
	int id_x = threadIdx.x + blockIdx.x * blockDim.x;
	int id_y = threadIdx.y + blockIdx.y * blockDim.y;
	__int32 temp{};

	while (id_x < SIZE)
	{
		while (id_y < SIZE)
		{
			printf("A[%d][%d]\n", id_y, id_x);
			id_y += blockDim.y * gridDim.y;
		}
		id_x += blockDim.x * gridDim.x;
	}
	printf("\n");
	//int i{};
	//while (id_x < SIZE)
	//if (id_x < SIZE && id_y < SIZE)
	//{
	//	//while (id_y < SIZE)
	//	//while (i < SIZE)
	//	//{
	//	//	//Matrix_GPU_C[id_y * SIZE + id_x] += Matrix_GPU_A[id_y * SIZE + id_x] * Matrix_GPU_B[id_y * SIZE + id_x];
	//	//	//Matrix_GPU_C[id_y * SIZE + id_x] += Matrix_GPU_A[id_y * SIZE + id_x] * Matrix_GPU_B[id_y * SIZE + id_x];
	//	//	//temp += Matrix_GPU_A[id_y * SIZE + id_x] * Matrix_GPU_B[id_y * SIZE + id_x];
	//	//	//temp += Matrix_GPU_A[id_y * SIZE + id_x] * Matrix_GPU_B[id_y * SIZE + id_x];
	//	//	Matrix_GPU_C[id_x * SIZE + i] += Matrix_GPU_A[id_x * SIZE + i] * Matrix_GPU_B[i * SIZE + id_y];
	//	//	//id_y++;
	//	//	++i;
	//	//}
	//	__int32 temp{};
	//	for (size_t i = 0; i < SIZE; ++i)
	//	{
	//		temp += Matrix_GPU_A[id_x * SIZE + i] * Matrix_GPU_B[i * SIZE + id_y];
	//	}
	//	Matrix_GPU_C[id_x * SIZE + id_y] = temp;
	//	//Matrix_GPU_C[id_x * SIZE + id_y] = temp;
	///*	id_x += blockDim.x * gridDim.x;
	//	id_y += blockDim.y * gridDim.y;*/
	//}
	//int row = blockIdx.y * SIZE + threadIdx.y;
	//int col = blockIdx.x * SIZE + threadIdx.x;


	//	while (row < SIZE && col < SIZE)
	//	{
	//		float product_val = 0;
	//		for(int k = 0; k < SIZE; k++)
	//		{
	//			product_val += Matrix_GPU_A[row * SIZE + k] * Matrix_GPU_B[k * SIZE + col];
	//		}
	//		Matrix_GPU_C[row * SIZE + col] = product_val;
	//		row += blockDim.x * gridDim.x;
	//		col += blockDim.y * gridDim.y;
	//	}

	//if (id_x < SIZE && id_y < SIZE) 
	//{
	//	// each thread computes one element of the block sub-matrix
	//	for (int i = 0; i < SIZE; i++)
	//	{
	//		temp += Matrix_GPU_A[id_x * SIZE + i] * Matrix_GPU_B[i * SIZE + id_y];
	//	}
	//}
	//Matrix_GPU_C[id_x * SIZE + id_y] = temp;
}