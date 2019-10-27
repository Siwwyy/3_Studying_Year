#ifndef _CUDA_KERNEL_CUH_
#define _CUDA_KERNEL_CUH_
#pragma once


namespace My_Kernel
{

	void Kernel(const __int32 & repeat_amount);
	void Print_String(const char * my_string);
	const size_t Get_String_Length(const char* const __string);

}

#endif /* _CUDA_KERNEL_CUH_ */