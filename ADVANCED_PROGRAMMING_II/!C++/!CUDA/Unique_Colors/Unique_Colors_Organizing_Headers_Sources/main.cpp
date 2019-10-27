#include <windows.h>
#include <iostream>

#include "Include/Cuda_Kernel.cuh"

int main(int argc, char* argv[])
{
	My_Kernel::Kernel(20);
	//My_Kernel::Print_String("My temporary string is printed via GPU!");

	_STD cin.get();
	return 0;
}