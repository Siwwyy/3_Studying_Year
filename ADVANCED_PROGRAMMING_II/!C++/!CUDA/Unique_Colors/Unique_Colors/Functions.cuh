#ifndef _FUNCTIONS_CUH_
#define _FUNCTIONS_CUH_
#pragma once

/*
	DEFINES
*/
#define NEW_LINE '\n'

#include "cuda_runtime.h"
#include "cuda_runtime_api.h"
//#ifndef __CUDACC__
//#define __CUDACC__
//#endif
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Picture.cuh"


void Read_File(const _STD string& file_path);


#endif /* _FUNCTIONS_CUH_ */