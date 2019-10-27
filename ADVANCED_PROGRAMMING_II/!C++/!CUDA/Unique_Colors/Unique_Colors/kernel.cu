#include "cuda_runtime_api.h"
#ifndef __CUDACC__
#define __CUDACC__
#endif

#include "Functions.cuh"

#include <windows.h>
#include <iostream>



////////////////////////////////////////////////////
//GPU

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'


int main(int argc, char* argv[])
{



	system("pause");
	return 0;
}