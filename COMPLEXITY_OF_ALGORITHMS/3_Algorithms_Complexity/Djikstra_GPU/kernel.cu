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
	int * Verticle_GPU;
	int * Cost_GPU;
	int * Edge_GPU;
	int* Connections_GPU;
	size_t * _Connections_size_GPU;
	//////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	__host__ __device__  _Djikstra_Element();
	__host__ __device__  _Djikstra_Element(const int Verticle, const int Cost, const int Edge);
	__host__ __device__  _Djikstra_Element(const _Djikstra_Element& Object);
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
	__device__  int get_verticle_GPU() const;
	__device__  int get_cost_GPU() const;
	__device__  int get_edge_GPU() const;
	__host__ __device__  bool get_visited_or_not() const;
	__host__ __device__  size_t get_connections_size() const;
	__host__ __device__  int& get_connections_array(const size_t counter) const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	__host__ __device__  virtual ~_Djikstra_Element();
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
int* Visited_Nodes;
size_t _Visited_Nodes_lenght;
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
//GPU FUNCTION
__global__ void Print_Graph_GPU(const _Djikstra_Element* const Graph_GPU, const size_t* const _Graph_lenght_GPU);
__global__ void Print_Djikstra_Matrix_GPU(const _Djikstra_Element* const _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU);
__global__ void Print_Visited_Nodes_GPU(const int* const Visited_Nodes_GPU, const size_t* const _Visited_Nodes_lenght_GPU);
__global__ void Minimal_Spanning_Tree_Creator(const int * the_beginning, _Djikstra_Element* Graph_GPU, const size_t* const _Graph_lenght_GPU, _Djikstra_Element* _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU, int* Visited_Nodes_GPU, const size_t* const _Visited_Nodes_lenght_GPU);
//////////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
	inserter();
	//cudaDeviceProp prop;
	//cudaGetDeviceProperties(&prop, 0);
	//printf(" --- Memory Information for device %d ---\n");
	//printf("Total global mem: %ld\n", prop.totalGlobalMem);
	//printf("Total constant Mem: %ld\n", prop.totalConstMem);
	//printf("Max mem pitch: %ld\n", prop.memPitch);
	//printf("Texture Alignment: %ld\n", prop.textureAlignment);

	//printf(" --- MP Information for device %d ---\n");
	//printf("Multiprocessor count: %d\n",
	//	prop.multiProcessorCount);
	//printf("Shared mem per mp: %ld\n", prop.sharedMemPerBlock);
	//printf("Registers per mp: %d\n", prop.regsPerBlock);
	//printf("Threads in warp: %d\n", prop.warpSize);
	//printf("Max threads per block: %d\n",
	//	prop.maxThreadsPerBlock);
	//printf("Max thread dimensions: (%d, %d, %d)\n",
	//	prop.maxThreadsDim[0], prop.maxThreadsDim[1],
	//	prop.maxThreadsDim[2]);
	//printf("Max grid dimensions: (%d, %d, %d)\n",
	//	prop.maxGridSize[0], prop.maxGridSize[1],
	//	prop.maxGridSize[2]);
	//printf("\n");


	system("pause");
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
		//_Djikstra* Djikstra_Object = new _Djikstra(m);
		Construct(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			//Djikstra_Object->push(c1, c2, p);
			Push(c1, c2, p);
			//Djikstra_Object->push(c2, c1, p);
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
				//Djikstra_Object->push_directions(s, e, t);
				Push_Directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				//Djikstra_Object->get_results();
				Get_Results();
				///////////////////////////////////////////////
				//delete Djikstra_Object;
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
	::_Visited_Nodes_lenght = _Graph_lenght;	//:: means I am invoking a global variable
	Graph = new _Djikstra_Element[::_Graph_lenght];
	Djikstra_Matrix = new _Djikstra_Element[_Djikstra_Matrix_lenght];
	Visited_Nodes = new int[_Visited_Nodes_lenght];
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		Graph[i].set_connections_size(_Graph_lenght);
		Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		Djikstra_Matrix[i].set_cost(0);
		Djikstra_Matrix[i].set_edge(0);
		Visited_Nodes[i] = (-1);
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
		size_t * _Graph_lenght_GPU;
		cudaMalloc((void**)&Graph_GPU, _Graph_lenght * sizeof(_Djikstra_Element));
		cudaMalloc((void**)&_Graph_lenght_GPU, sizeof(size_t));
		/////////////////////////////////////////////////////////////////////////
		_Djikstra_Element* Djikstra_Matrix_GPU;
		size_t * _Djikstra_Matrix_lenght_GPU;
		cudaMalloc((void**)&Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght * sizeof(_Djikstra_Element));
		cudaMalloc((void**)&_Djikstra_Matrix_lenght_GPU, sizeof(size_t));
		//////////////////////////////////////////////////////////////////////////////
		int* Visited_Nodes_GPU;
		size_t * _Visited_Nodes_lenght_GPU;
		cudaMalloc((void**)&Visited_Nodes_GPU, _Visited_Nodes_lenght * sizeof(int));
		cudaMalloc((void**)&_Visited_Nodes_lenght_GPU, sizeof(size_t));
		//////////////////////////////////////////////////////////////////////////////
		int * from_GPU{};
		cudaMalloc((void**)&from_GPU, sizeof(int));
		cudaMemset(&from_GPU, 1, sizeof(int));
		cudaMemcpy(from_GPU, &from_, sizeof(int), HostToDevice);
		//////////////////////////////////////////////////////////////////////////////
		
		for (size_t i = 0; i < _Djikstra_Matrix_lenght; ++i)
		{
			Djikstra_Matrix[i].set_cost(-1);	//means its a infinity
			Djikstra_Matrix[i].set_edge(0);
			Visited_Nodes[i] = (-1);
		}



		//COPYING FROM CPU TO GPU
		//COPY GRAPH 
		cudaMemcpy(Graph_GPU, Graph, _Graph_lenght * sizeof(_Djikstra_Element), HostToDevice);
		cudaMemcpy(_Graph_lenght_GPU, &_Graph_lenght, sizeof(size_t), HostToDevice);		
		//////////////////////////////////////////////////////////////////////////////
		//COPY Djikstra Matrix 
		cudaMemcpy(Djikstra_Matrix_GPU, Djikstra_Matrix, _Djikstra_Matrix_lenght * sizeof(_Djikstra_Element), HostToDevice);
		cudaMemcpy(_Djikstra_Matrix_lenght_GPU, &_Djikstra_Matrix_lenght, sizeof(size_t), HostToDevice);	
		//////////////////////////////////////////////////////////////////////////////
		//COPY Visited Nodes 
		cudaMemcpy(Visited_Nodes_GPU, Visited_Nodes, _Visited_Nodes_lenght * sizeof(_Djikstra_Element), HostToDevice);
		cudaMemcpy(_Visited_Nodes_lenght_GPU, &_Visited_Nodes_lenght, sizeof(size_t), HostToDevice);
		//////////////////////////////////////////////////////////////////////////////

		//HERE PASTE ALL OF FUN BETWEEN CPU AND GPU !
		dim3 blocks(1);
		dim3 threads(512);
		//printf("\n");
		Minimal_Spanning_Tree_Creator <<<1, 1>>> (from_GPU, Graph_GPU, _Graph_lenght_GPU, Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght_GPU, Visited_Nodes_GPU, _Visited_Nodes_lenght_GPU);	//create Djikstra for this case
		//cudaDeviceSynchronize();
		//cudaDeviceSynchronize();
		//cudaDeviceSynchronize();
		//cudaDeviceSynchronize();
		//cudaDeviceSynchronize();
		//printf("\n");
		//printf("\n");
		//Print_Graph_GPU<<<blocks,1>>>(Graph_GPU, _Graph_lenght_GPU);	//works
		//cudaDeviceSynchronize();
		//printf("\n");
		//printf("\n");
		//Print_Djikstra_Matrix_GPU <<<blocks, 1 >>>(Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght_GPU);	//works
		//cudaDeviceSynchronize();
		//printf("\n");
		//printf("\n");
		//Print_Visited_Nodes_GPU <<<blocks, 1 >>>(Visited_Nodes_GPU, _Visited_Nodes_lenght_GPU);	//works
		//cudaDeviceSynchronize();
		//printf("\n");
		//printf("\n");
		//cudaDeviceSynchronize();
		//printf("\n");
		//Print_Visited_Nodes_GPU << <blocks, 1 >> > (Visited_Nodes_GPU, _Visited_Nodes_lenght_GPU);	//works
		//cudaDeviceSynchronize();
		//printf("\n");
		_STD cin.get();


		//COPYING FROM GPU TO CPU
		//COPY GRAPH 
		cudaMemcpy(Graph, Graph_GPU , _Graph_lenght * sizeof(_Djikstra_Element), DeviceToHost);
		//////////////////////////////////////////////////////////////////////////////
		//COPY Djikstra Matrix 
		cudaMemcpy(Djikstra_Matrix, Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght * sizeof(_Djikstra_Element), DeviceToHost);
		//////////////////////////////////////////////////////////////////////////////
		//COPY Visited Nodes 
		cudaMemcpy(Visited_Nodes, Visited_Nodes_GPU, _Visited_Nodes_lenght * sizeof(int), DeviceToHost);
		//////////////////////////////////////////////////////////////////////////////

		_STD cout << Visited_Nodes[0] << ' ' << Visited_Nodes[1] << ' ' << Visited_Nodes[2] << ' ' <<  Visited_Nodes[3] << ' ' << Visited_Nodes[4] << ' ' << Visited_Nodes[5] << ' ' << Visited_Nodes[6] << NEW_LINE;
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
		system("pause");


		/*
			MEMORY FREE
		*/
		cudaFree(Graph_GPU);
		cudaFree(_Graph_lenght_GPU);

		cudaFree(Djikstra_Matrix_GPU);
		cudaFree(_Djikstra_Matrix_lenght_GPU);

		cudaFree(Visited_Nodes_GPU);
		cudaFree(_Visited_Nodes_lenght_GPU);

		cudaFree(from_GPU);
	}
}

void Copy_Values_From_CPU_To_GPU_In_Class()
{
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		Graph[i].Copy_Values_From_CPU_To_GPU();
	}
}

__global__ void Print_Graph_GPU(const _Djikstra_Element* const Graph_GPU, const size_t* const _Graph_lenght_GPU)
{
	int id_x = threadIdx.x + blockDim.x * gridDim.x;
	while (id_x < *(_Graph_lenght_GPU))
	{
		Graph_GPU[id_x].print_connections_GPU();
		id_x += blockDim.x * gridDim.x;
	}
}

__global__ void Print_Djikstra_Matrix_GPU(const _Djikstra_Element* const _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU)
{
	int id_x = blockIdx.x;
	while (id_x < *(_Djikstra_Matrix_lenght_GPU))
	{
		printf("V: %d E: %d C: %d\n", _Djikstra_Matrix_GPU[id_x].get_verticle_GPU(), _Djikstra_Matrix_GPU[id_x].get_edge_GPU(), _Djikstra_Matrix_GPU[id_x].get_cost_GPU());
		id_x += blockDim.x * gridDim.x;
	}
}

__global__  void Print_Visited_Nodes_GPU(const int* const Visited_Nodes_GPU, const size_t* const _Visited_Nodes_lenght_GPU)
{
	int id_x = threadIdx.x + blockDim.x * gridDim.x;
	while (id_x < *(_Visited_Nodes_lenght_GPU))
	{
		printf(" Visited: %d ", Visited_Nodes_GPU[id_x]);
		id_x += blockDim.x * gridDim.x;
	}
}


//GPU FUNCTION
__global__ void Minimal_Spanning_Tree_Creator(const int* the_beginning, _Djikstra_Element* Graph_GPU, const size_t* const _Graph_lenght_GPU, _Djikstra_Element* _Djikstra_Matrix_GPU, const size_t* const _Djikstra_Matrix_lenght_GPU, int* Visited_Nodes_GPU, const size_t* const _Visited_Nodes_lenght_GPU)
{
	//printf("%d \n", *the_beginning);
	int id_x = threadIdx.x + blockDim.x * gridDim.x;
	
//	cudaDeviceSynchronize();
	//Print_Djikstra_Matrix_GPU(_Djikstra_Matrix_GPU, _Djikstra_Matrix_lenght_GPU);
	//cudaDeviceSynchronize();
	//Print_Visited_Nodes_GPU(Visited_Nodes, _Visited_Nodes_lenght);

	//int current_verticle = ((*the_beginning) - 1);	//choose the beginning (by position in array (nr index))
	//int the_smallest_cost = 999999999;
	//int the_smallest_cost_position = 0;


	while (id_x < (*_Visited_Nodes_lenght_GPU))
	{
		Visited_Nodes_GPU[id_x] = (1);
		id_x += blockDim.x * gridDim.x;
	}

	/*_Djikstra_Matrix_GPU[current_verticle].set_cost_GPU(0);
	_Djikstra_Matrix_GPU[current_verticle].set_edge_GPU((current_verticle + 1));*/
	//for (size_t i = 0; i < (*_Graph_lenght_GPU); ++i)
	//{
	//	

	//	//for (size_t j = 0; j < Graph_GPU[current_verticle].get_connections_size(); ++j)
	//	//{
	//	//	if (Graph_GPU[current_verticle].get_connections_array(j) != 0 && Visited_Nodes_GPU[j] != (j + 1))
	//	//	{
	//	//		if ((_Djikstra_Matrix_GPU[j].get_cost() == -1) || ((_Djikstra_Matrix_GPU[current_verticle].get_cost() + Graph_GPU[current_verticle].get_connections_array(j)) <= _Djikstra_Matrix_GPU[j].get_cost()))
	//	//		{
	//	//			_Djikstra_Matrix_GPU[j].set_cost(_Djikstra_Matrix_GPU[current_verticle].get_cost() + Graph_GPU[current_verticle].get_connections_array(j));
	//	//			_Djikstra_Matrix_GPU[j].set_edge((current_verticle + 1));
	//	//		}
	//	//	}
	//	//}
	//	////Seeking for the smallest element in Djikstra's Matrix
	//	//for (size_t j = 0; j < (*_Djikstra_Matrix_lenght_GPU); ++j)
	//	//{
	//	//	if ((_Djikstra_Matrix_GPU[j].get_cost() <= the_smallest_cost && _Djikstra_Matrix_GPU[j].get_cost() != (-1)) && Visited_Nodes_GPU[j] != (j + 1))
	//	//	{
	//	//		the_smallest_cost = _Djikstra_Matrix_GPU[j].get_cost();
	//	//		current_verticle = static_cast<int>(j);
	//	//	}
	//	//}
	//	//the_smallest_cost = 999999999;
	//}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Djikstra_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


__host__ __device__ _Djikstra_Element::_Djikstra_Element() :
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

__host__ __device__ _Djikstra_Element::_Djikstra_Element(const int Verticle, const int Cost, const int Edge) :
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

__host__ __device__ _Djikstra_Element::_Djikstra_Element(const _Djikstra_Element& Object) :
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
	cudaMemset(&Verticle_GPU, 0, sizeof(int));
	cudaMemset(&Edge_GPU, 0, sizeof(int));
	cudaMemset(&Cost_GPU, 0, sizeof(int));

	//CudaMemoryCopy from CPU to GPU
	cudaMemcpy(this->Connections_GPU, this->Connections, this->_Connections_size * sizeof(int), HostToDevice);
	cudaMemcpy(this->_Connections_size_GPU, &this->_Connections_size, sizeof(size_t), HostToDevice);
	cudaMemcpy(Verticle_GPU, &this->Verticle, sizeof(int), HostToDevice);
	cudaMemcpy(Edge_GPU, &this->Edge, sizeof(int), HostToDevice);
	cudaMemcpy(Cost_GPU, &this->Cost, sizeof(int), HostToDevice);
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

__host__ __device__ int& _Djikstra_Element::get_connections_array(const size_t counter) const
{
	return this->Connections[counter];
}

__host__ __device__ _Djikstra_Element::~_Djikstra_Element()
{
	delete[] this->Connections;
	_Connections_size = 0;
	Edge = 0;
	Cost = 0;
	Verticle = 0;

	//UNINITIALIZE GPU MEMORY
	/*extern "C"
	{
		cudaFree(this->Connections_GPU);
		cudaFree(this->_Connections_size_GPU);
	}*/
}