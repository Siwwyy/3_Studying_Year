#ifndef _PIXEL_CUH_
#define _PIXEL_CUH_
#pragma once

#include "cuda_runtime.h"
#include "cuda_runtime_api.h"
#ifndef __CUDACC__
#define __CUDACC__
#endif
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Pixel
{
private:
	/*
		PRIVATE VARIABLES
	*/
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char color_range;
	//////////////////////////////////////////////////////////////////////////////
protected:
	/*
		PROTECTED VARIABLES
	*/

	//////////////////////////////////////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY
	*/
	__device__ Pixel();
	__device__ explicit Pixel(const unsigned char R, const unsigned char G, const unsigned char B);
	__device__ Pixel(const Pixel& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	__device__ void Show_Object() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY
	*/
	__device__ void Set_R(const unsigned char R);
	__device__ void Set_G(const unsigned char G);
	__device__ void Set_B(const unsigned char B);
	__device__ void Set_Color_Range(const int Color_Range);
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY
	*/
	__device__ const unsigned char Get_R() const;
	__device__ const unsigned char Get_G() const;
	__device__ const unsigned char Get_B() const;
	__device__ const int Get_Color_Range() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY
	*/
	//JEDNOARGUMENTOWE
	__device__ Pixel& operator=(const Pixel& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	__device__ virtual ~Pixel();
	//////////////////////////////////////////////////////////////////////////////
};
#endif /* _PIXEL_CUH_ */