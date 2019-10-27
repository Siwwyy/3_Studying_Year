#include <windows.h>
#include <iostream>

#include "Include/Cuda_Kernel.cuh"

int main(int argc, char* argv[])
{
	My_Kernel::Kernel(20);

	_STD cin.get();
	return 0;
}