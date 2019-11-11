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
#include <vector>
#define STOPWATCH_ON
#include "StopWatch.h"

////////////////////////////////////////////////////
//GPU

#define HostToDevice cudaMemcpyHostToDevice
#define DeviceToHost cudaMemcpyDeviceToHost
#define OK cudaSuccess
#define NEW_LINE '\n'

#define SIZE 5


//CLASS OF _Djikstra_Element, for inserting values

class _Djikstra_Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	int Verticle;
	int Cost;
	int Edge;
	//////////////////////////////////
	int* Connections;
	size_t _Connections_size;
	//////////////////////////////////
	//GPU CASE
	int* Verticle_GPU;
	int* Cost_GPU;
	int* Edge_GPU;
	int* Connections_GPU;
	size_t* _Connections_size_GPU;
	//////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	__host__  _Djikstra_Element();
	__host__  _Djikstra_Element(const int Verticle, const int Cost, const int Edge);
	__host__  _Djikstra_Element(const _Djikstra_Element& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	__host__ __device__  void set_connections_size(const size_t _Connections_size);
	__host__ __device__  void set_connection(const int value, const size_t counter);
	__host__ __device__  void set_way(const int destination, const int way_lenght);
	__host__ __device__  void set_verticle(const int verticle);
	__host__ __device__  void set_cost(const int cost);
	__host__ __device__  void set_edge(const int edge);
	__host__ __device__  void set_visited_or_not(const bool visited_or_not);
	__device__  void set_verticle_GPU(const int verticle);
	__device__  void set_edge_GPU(const int edge);
	__device__  void set_cost_GPU(const int cost);
	__device__  void print_connections_GPU() const;
	__host__  void print_connections() const;
	__host__ void Copy_Values_From_CPU_To_GPU();
	__host__ void Copy_Values_From_GPU_To_CPU();
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	__host__ __device__  _Djikstra_Element& operator=(const _Djikstra_Element& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	__host__ __device__  int get_verticle() const;
	__host__ __device__  int get_cost() const;
	__host__ __device__  int get_edge() const;
	__host__ __device__  bool get_visited_or_not() const;
	__host__ __device__  int& get_connections_array(const size_t counter) const;
	__host__ __device__  size_t get_connections_size() const;
	__device__  size_t get_connections_size_GPU() const;
	__device__  int& get_connections_array_GPU(const size_t counter) const;
	__device__  int get_verticle_GPU() const;
	__device__  int get_cost_GPU() const;
	__device__  int get_edge_GPU() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	__host__  virtual ~_Djikstra_Element();
};

//MAIN LANUCH FUNCTION
void inserter();

/*
	GLOBAL VALUES ON CPU
*/
/////////////////////////////////////////////////////////////////////////
_Djikstra_Element* Graph;
size_t _Graph_lenght;
/////////////////////////////////////////////////////////////////////////
_Djikstra_Element* Djikstra_Matrix;
size_t _Djikstra_Matrix_lenght;
//////////////////////////////////////////////////////////////////////////////
std::vector<std::pair<std::pair<int, int>, int>> Destinations;
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//SELF FUNCTIONS
void Construct(const size_t _Graph_lenght);
void Push(const int value, const int destination, const int way_lenght);
void Push_Directions(const int from, const int to, const int way_lenght);
void Get_Results();
void Find_Way(const int from, const int to, const int way_lenght);
void Copy_Values_From_CPU_To_GPU_In_Class();
void Copy_Values_From_GPU_To_CPU_In_Class();
//GPU FUNCTION
__global__ void Minimal_Spanning_Tree_Creator(_Djikstra_Element* Graph_GPU, const size_t* const _Graph_lenght_GPU, _Djikstra_Element* _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU);
//////////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
	inserter();
	return 0;
}


void inserter()
{
	int m = 0;			//amount of cities
	int d = 0;			//amount of ways
	int c1 = 0;			//number of city
	int c2 = 0;			//number of city
	int p = 0;			//amount of max passengers between one course
	int s = 0;			//the beginning of way
	int e = 0;			//the end of way
	int t = 0;			//amount of max passengers to move by bus
	while (true)
	{
		std::cin >> m;
		std::cin >> d;
		Construct(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			Push(c1, c2, p);
			Push(c2, c1, p);
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		Copy_Values_From_CPU_To_GPU_In_Class();	//copy values in Djikstra Graph from CPU to GPU
		while (true)
		{
			std::cin >> s;
			std::cin >> e;
			if (s != 0 && e != 0)
			{
				std::cin >> t;
				Push_Directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				//START_STOPWATCH
				Get_Results();
				//STOP_STOPWATCH
				///////////////////////////////////////////////
				system("pause");
				exit(0);
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
	}
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	SELF FUNCTIONS
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


void Construct(const size_t _Graph_lenght)
{
	//Initialize basically those values and arrays at the beginning
	::_Graph_lenght = _Graph_lenght;	//:: means I am invoking a global variable
	::_Djikstra_Matrix_lenght = _Graph_lenght;	//:: means I am invoking a global variable
	Graph = new _Djikstra_Element[::_Graph_lenght];
	Djikstra_Matrix = new _Djikstra_Element[_Djikstra_Matrix_lenght];
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		Graph[i].set_connections_size(_Graph_lenght);
		Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
	}
}

void Push(const int value, const int destination, const int way_lenght)
{
	Graph[(value - 1)].set_way(destination, way_lenght);
}

void Push_Directions(const int from, const int to, const int way_lenght)
{
	Destinations.emplace_back(_STD make_pair(std::make_pair(from, to), way_lenght));
}

void Get_Results()
{
	for (typename std::vector<std::pair<std::pair<int, int>, int>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		Find_Way(vec_iterator->first.first, vec_iterator->first.second, vec_iterator->second);
	}
}

void Find_Way(const int from, const int to, const int way_lenght)
{
	if (from == to)
	{
		std::cout << '0' << '\n';
	}
	else
	{
		int current_verticle = 0;
		int destination_verticle = 0;
		int from_ = 0;
		int to_ = 0;

		if (from < to)
		{
			from_ = from;
			to_ = to;
		}
		else
		{
			from_ = to;
			to_ = from;
		}
		destination_verticle = from_;
		current_verticle = to_;


		//GPU FUNCTIONS
		/////////////////////////////////////////////////////////////////////////
		_Djikstra_Element* Graph_GPU;
		size_t* _Graph_lenght_GPU;
		cudaMalloc((void**)&Graph_GPU, _Graph_lenght * sizeof(_Djikstra_Element));
		cudaMalloc((void**)&_Graph_lenght_GPU, sizeof(size_t));
		/////////////////////////////////////////////////////////////////////////
		_Djikstra_Element* Djikstra_Matrix_GPU;
		size_t* _Djikstra_Matrix_lenght_GPU;
		cudaMalloc((void**)&Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght * sizeof(_Djikstra_Element));
		cudaMalloc((void**)&_Djikstra_Matrix_lenght_GPU, sizeof(size_t));
		//////////////////////////////////////////////////////////////////////////////


		//COPYING FROM CPU TO GPU
		//COPY GRAPH 
		cudaMemcpy(Graph_GPU, Graph, _Graph_lenght * sizeof(_Djikstra_Element), HostToDevice);
		cudaMemcpy(_Graph_lenght_GPU, &_Graph_lenght, sizeof(size_t), HostToDevice);
		//////////////////////////////////////////////////////////////////////////////
		//COPY Djikstra Matrix 
		cudaMemcpy(Djikstra_Matrix_GPU, Djikstra_Matrix, _Djikstra_Matrix_lenght * sizeof(_Djikstra_Element), HostToDevice);
		cudaMemcpy(_Djikstra_Matrix_lenght_GPU, &_Djikstra_Matrix_lenght, sizeof(size_t), HostToDevice);
		//////////////////////////////////////////////////////////////////////////////

		//HERE PASTE ALL OF FUN BETWEEN CPU AND GPU !
		dim3 blocks(_Djikstra_Matrix_lenght);
		dim3 threads(_Djikstra_Matrix_lenght);
		START_STOPWATCH
		Minimal_Spanning_Tree_Creator <<< blocks, threads >> > (Graph_GPU, _Graph_lenght_GPU, Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght_GPU);	//create Djikstra for this case
		//cudaDeviceSynchronize();
		STOP_STOPWATCH

		Copy_Values_From_GPU_To_CPU_In_Class();

		_STD cout << "Road through: ";
		for (int i = ::_Djikstra_Matrix_lenght - 1; i >= 0; --i)
		{
			if (Djikstra_Matrix[i].get_verticle() == destination_verticle)
			{
				_STD cout << Djikstra_Matrix[i].get_verticle();
				break;
			}
			else if (Djikstra_Matrix[i].get_verticle() == current_verticle)
			{
				current_verticle = Djikstra_Matrix[i].get_edge();
				_STD cout << Djikstra_Matrix[i].get_verticle() << " -> ";
			}
		}
		_STD cout << NEW_LINE;
		_STD cout << NEW_LINE;
		/*
			MEMORY FREE
		*/
		cudaFree(Graph_GPU);
		cudaFree(_Graph_lenght_GPU);

		cudaFree(Djikstra_Matrix_GPU);
		cudaFree(_Djikstra_Matrix_lenght_GPU);
	}
}

void Copy_Values_From_CPU_To_GPU_In_Class()
{
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		Graph[i].Copy_Values_From_CPU_To_GPU();
		Djikstra_Matrix[i].Copy_Values_From_CPU_To_GPU();
	}
}

void Copy_Values_From_GPU_To_CPU_In_Class()
{
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		Djikstra_Matrix[i].Copy_Values_From_GPU_To_CPU();
	}
}

//GPU FUNCTION
__global__ void Minimal_Spanning_Tree_Creator(_Djikstra_Element* Graph_GPU, const size_t* const _Graph_lenght_GPU, _Djikstra_Element* _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU)
{
	int verticle = blockIdx.x;
	int id_x = threadIdx.x;
	_Djikstra_Matrix_GPU[verticle].set_cost_GPU(999999999);

	if (Graph_GPU[verticle].get_connections_array_GPU(id_x) > 0)
	{
		if (id_x < (*_Graph_lenght_GPU))
		{
			if (_Djikstra_Matrix_GPU[verticle].get_cost_GPU() > Graph_GPU[verticle].get_connections_array_GPU(id_x))
			{
				_Djikstra_Matrix_GPU[verticle].set_cost_GPU(Graph_GPU[verticle].get_connections_array_GPU(id_x));
				_Djikstra_Matrix_GPU[verticle].set_edge_GPU((id_x + 1));
			}
		}
	}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Djikstra_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


__host__ _Djikstra_Element::_Djikstra_Element() :
	_Connections_size(0),
	Verticle(0),
	Cost(0),
	Edge(0)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

__host__ _Djikstra_Element::_Djikstra_Element(const int Verticle, const int Cost, const int Edge) :
	_Connections_size(0),
	Verticle(Verticle),
	Cost(Cost),
	Edge(Edge)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

__host__ _Djikstra_Element::_Djikstra_Element(const _Djikstra_Element& Object) :
	_Connections_size(Object._Connections_size),
	Verticle(Object.Verticle),
	Cost(Object.Cost),
	Edge(Object.Edge)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

__host__ __device__ void _Djikstra_Element::set_connections_size(const size_t _Connections_size)
{
	if (this->_Connections_size != 0)
	{
		delete[] this->Connections;
	}
	this->_Connections_size = _Connections_size;
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

__host__ __device__ void _Djikstra_Element::set_connection(const int value, const size_t counter)
{
	this->Connections[counter] = value;
}

__host__ __device__ void _Djikstra_Element::set_way(const int destination, const int way_lenght)
{
	this->Connections[(destination - 1)] = way_lenght;
}

__host__ __device__ void _Djikstra_Element::set_verticle(const int verticle)
{
	this->Verticle = verticle;
}

__host__ __device__ void _Djikstra_Element::set_cost(const int cost)
{
	this->Cost = cost;
}

__host__ __device__ void _Djikstra_Element::set_edge(const int edge)
{
	this->Edge = edge;
}

__device__ void _Djikstra_Element::set_verticle_GPU(const int verticle)
{
	*(this->Verticle_GPU) = verticle;
}

__device__ void _Djikstra_Element::set_cost_GPU(const int cost)
{
	*(this->Cost_GPU) = cost;
}

__device__ void _Djikstra_Element::set_edge_GPU(const int edge)
{
	*(this->Edge_GPU) = edge;
}

__host__ void _Djikstra_Element::print_connections() const
{
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		printf("%d ", Connections[i]);
	}
	printf("\n");
}

__host__ void _Djikstra_Element::Copy_Values_From_CPU_To_GPU()
{
	//CudaMalloc
	cudaMalloc((void**)&this->Connections_GPU, this->_Connections_size * sizeof(int));
	cudaMalloc((void**)&_Connections_size_GPU, sizeof(size_t));
	cudaMalloc((void**)&Verticle_GPU, sizeof(int));
	cudaMalloc((void**)&Edge_GPU, sizeof(int));
	cudaMalloc((void**)&Cost_GPU, sizeof(size_t));

	//CudaMemoryCopy from CPU to GPU
	cudaMemcpy(this->Connections_GPU, this->Connections, this->_Connections_size * sizeof(int), HostToDevice);
	cudaMemcpy(this->_Connections_size_GPU, &this->_Connections_size, sizeof(size_t), HostToDevice);
	cudaMemcpy(Verticle_GPU, &this->Verticle, sizeof(int), HostToDevice);
	cudaMemcpy(Edge_GPU, &this->Edge, sizeof(int), HostToDevice);
	cudaMemcpy(Cost_GPU, &this->Cost, sizeof(int), HostToDevice);
}

__host__ void _Djikstra_Element::Copy_Values_From_GPU_To_CPU()
{
	cudaMemcpy(&Verticle, this->Verticle_GPU, sizeof(int), DeviceToHost);
	cudaMemcpy(&Edge, this->Edge_GPU, sizeof(int), DeviceToHost);
	cudaMemcpy(&Cost, this->Cost_GPU, sizeof(int), DeviceToHost);
}

__device__ void _Djikstra_Element::print_connections_GPU() const
{
	for (size_t i = 0; i < *(this->_Connections_size_GPU); ++i)
	{
		printf("%d ", Connections_GPU[i]);
	}
	printf("\n");
}

__host__ __device__ _Djikstra_Element& _Djikstra_Element::operator=(const _Djikstra_Element& Object)
{
	if (this != &Object)
	{
		this->Verticle = Object.Verticle;
		this->Cost = Object.Cost;
		this->Edge = Object.Edge;
		this->_Connections_size = Object._Connections_size;
		delete[] this->Connections;
		this->Connections = new int[this->_Connections_size];
		for (size_t i = 0; i < this->_Connections_size; ++i)
		{
			this->Connections[i] = 0;
		}
	}
	return *this;
}

__host__ __device__ int _Djikstra_Element::get_verticle() const
{
	return this->Verticle;
}

__host__ __device__ int _Djikstra_Element::get_cost() const
{
	return this->Cost;
}

__host__ __device__ int _Djikstra_Element::get_edge() const
{
	return this->Edge;
}

__device__ int _Djikstra_Element::get_verticle_GPU() const
{
	return *(this->Verticle_GPU);
}

__device__ int _Djikstra_Element::get_cost_GPU() const
{
	return *(this->Cost_GPU);
}

__device__ int _Djikstra_Element::get_edge_GPU() const
{
	return *(this->Edge_GPU);
}

__host__ __device__ size_t _Djikstra_Element::get_connections_size() const
{
	return this->_Connections_size;
}

__device__ size_t _Djikstra_Element::get_connections_size_GPU() const
{
	return *(this->_Connections_size_GPU);
}

__device__ int& _Djikstra_Element::get_connections_array_GPU(const size_t counter) const
{
	return this->Connections_GPU[counter];
}

__host__ __device__ int& _Djikstra_Element::get_connections_array(const size_t counter) const
{
	return this->Connections[counter];
}

__host__ _Djikstra_Element::~_Djikstra_Element()
{
	delete[] this->Connections;
	_Connections_size = 0;
	Edge = 0;
	Cost = 0;
	Verticle = 0;
	//UNINITIALIZE GPU MEMORY
	cudaFree(Connections_GPU);
	cudaFree(Verticle_GPU);
	cudaFree(Edge_GPU);
	cudaFree(Cost_GPU);
}