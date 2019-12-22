//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <random>
//#include <stack>
//
//#define NEW_LINE '\n'
//
//void Print_Matrix(const bool matrix[10][10]);
//void DFS(bool matrix[10][10]);
//
//int main(int argc, char* argv[])
//{
//	using _STD cout;
//	using _STD endl;
//
//	bool matrix[10][10]
//	{ 
//		{0,1,0,1,0,0,0,0,0,0},//1
//		{1,0,1,0,1,0,1,1,0,0},//2
//		{0,1,0,1,0,0,0,0,1,1},//3
//		{1,0,1,0,0,0,0,0,0,0},//4
//		{0,1,0,0,0,1,1,1,0,0},//5
//		{0,0,0,0,1,0,0,0,0,0},//6
//		{0,1,0,0,1,0,0,1,0,0},//7
//		{0,1,0,0,1,0,1,0,0,0},//8
//		{0,0,1,0,0,0,0,0,0,0},//9
//		{0,0,1,0,0,0,0,0,0,0},//10
//	};
//
//	Print_Matrix(matrix);
//	_STD cout << "=======================" << NEW_LINE;
//	DFS(matrix);
//	_STD cout << "=======================" << NEW_LINE;
//	Print_Matrix(matrix);
//
//	system("pause");
//	return 0;
//}
//
//void Print_Matrix(const bool matrix[10][10])
//{
//	for (size_t i = 0; i < 7; ++i)
//	{
//		for (size_t j = 0; j < 7; ++j)
//		{
//			_STD cout << matrix[i][j] << ' ';
//		}
//		_STD cout << NEW_LINE;
//	}
//}
//
//void DFS(bool matrix[10][10])
//{
//	_STD stack<bool> dfs_stack{};
//	__int16 dfs_visited[10]{};
//	__int16 dfs_visited_second[10]{};
//	size_t dfs_visited_second_counter{};
//	size_t connection_counter{};
//	size_t dfs_visited_counter{};
//	size_t vertex_position{};
//
//	//Choose starting vertex
//	//In this case I choose first nr 1, initial step
//	dfs_visited_counter = 0;
//	dfs_visited[dfs_visited_counter] = 1;
//	dfs_visited_second[dfs_visited_second_counter] = 1;
//	++dfs_visited_second_counter;
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		for (size_t j = 0; j < 10; ++j)
//		{
//			if (matrix[vertex_position][j] == 1)
//			{
//				++connection_counter;
//				matrix[vertex_position][j] = 0;
//				vertex_position = j;
//				break;
//			}
//		}
//		if (connection_counter > 0)
//		{
//			dfs_stack.push(dfs_visited[dfs_visited_counter]);
//			dfs_visited_counter = vertex_position;
//			dfs_visited[dfs_visited_counter] = (vertex_position + 1);
//			dfs_visited_second[dfs_visited_second_counter] = (vertex_position + 1);
//			++dfs_visited_second_counter;
//		}
//		else
//		{
//			dfs_stack.top() = dfs_visited_counter;
//		}
//		connection_counter = NULL;
//	}
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		_STD cout << dfs_visited_second[i] << " ";
//	}
//	_STD cout << NEW_LINE;
//}
/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <math.h>

//CLASS OF _MST_ELEMENT, for inserting values

class _DFS_Element
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
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_DFS_Element();
	_DFS_Element(const int Verticle, const int Cost, const int Edge);
	_DFS_Element(const _DFS_Element& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_connections_size(const size_t _Connections_size);
	void set_connection(const int value, const size_t counter);
	void set_way(const int destination, const int way_lenght);
	void set_verticle(const int verticle);
	void set_cost(const int cost);
	void set_edge(const int edge);
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_DFS_Element& operator=(const _DFS_Element& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	int get_verticle() const;
	int get_cost() const;
	int get_edge() const;
	size_t get_connections_size() const;
	int& get_connections_array(const size_t counter) const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_DFS_Element();
};

//CLASS OF _DFS

class _DFS
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	_DFS_Element* Graph;
	size_t _Graph_lenght;
	std::vector<std::pair<std::pair<int, int>, int>> Destinations;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_DFS();
	_DFS(const size_t _Graph_lenght);
	_DFS(const _DFS& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push(const int value, const int destination, const int way_lenght);
	void push_directions(const int from, const int to, const int way_lenght);
	void get_results();
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	//////////////////////////////////////////////////////////////////////////////

	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_DFS& operator=(const _DFS& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_DFS();
};

//////////////////////////////////////////////////////////////////////////////

//FUNCTION FOR INSERTING VALUES FROM file_in
void inserter();
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	inserter();
	return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

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
		_DFS* DFS_Object = new _DFS(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			DFS_Object->push(c1, c2, (-1) * p);
			DFS_Object->push(c2, c1, (-1) * p);
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		while (true)
		{
			std::cin >> s;
			std::cin >> e;
			if (s != 0 && e != 0)
			{
				std::cin >> t;
				DFS_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				DFS_Object->get_results();
				///////////////////////////////////////////////
				delete DFS_Object;
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
	_MST_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_DFS_Element::_DFS_Element() :
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

_DFS_Element::_DFS_Element(const int Verticle, const int Cost, const int Edge) :
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

_DFS_Element::_DFS_Element(const _DFS_Element& Object) :
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

void _DFS_Element::set_connections_size(const size_t _Connections_size)
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

void _DFS_Element::set_connection(const int value, const size_t counter)
{
	this->Connections[counter] = value;
}

void _DFS_Element::set_way(const int destination, const int way_lenght)
{
	this->Connections[(destination - 1)] = way_lenght;
}

void _DFS_Element::set_verticle(const int verticle)
{
	this->Verticle = verticle;
}

void _DFS_Element::set_cost(const int cost)
{
	this->Cost = cost;
}

void _DFS_Element::set_edge(const int edge)
{
	this->Edge = edge;
}

_DFS_Element& _DFS_Element::operator=(const _DFS_Element& Object)
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

int _DFS_Element::get_verticle() const
{
	return this->Verticle;
}

int _DFS_Element::get_cost() const
{
	return this->Cost;
}

int _DFS_Element::get_edge() const
{
	return this->Edge;
}

size_t _DFS_Element::get_connections_size() const
{
	return this->_Connections_size;
}

int& _DFS_Element::get_connections_array(const size_t counter) const
{
	return this->Connections[counter];
}

_DFS_Element::~_DFS_Element()
{
	delete[] this->Connections;
	_Connections_size = 0;
	Edge = 0;
	Cost = 0;
	Verticle = 0;
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_MST CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////



_DFS::_DFS() :
	_Graph_lenght(0)
{
	this->Graph = new _DFS_Element[this->_Graph_lenght];
}

_DFS::_DFS(const size_t _Graph_lenght):
	_Graph_lenght(_Graph_lenght)
{
	this->Graph = new _DFS_Element[this->_Graph_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
	}
}

_DFS::_DFS(const _DFS& Object) :
	_Graph_lenght(Object._Graph_lenght)
{
	this->Graph = new _DFS_Element[this->_Graph_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
	}
}

void _DFS::push(const int value, const int destination, const int way_lenght)
{
	this->Graph[(value - 1)].set_way(destination, way_lenght);
}

void _DFS::push_directions(const int from, const int to, const int way_lenght)
{
	Destinations.emplace_back(std::make_pair(std::make_pair(from, to), way_lenght));

}

void _DFS::get_results()
{

}

_DFS& _DFS::operator=(const _DFS& Object)
{
	if (this != &Object)
	{
		this->_Graph_lenght = Object._Graph_lenght;
		delete[] this->Graph;
		this->Graph = new _DFS_Element[this->_Graph_lenght];
		Destinations.clear();
		Destinations = Object.Destinations;
		for (size_t i = 0; i < this->_Graph_lenght; ++i)
		{
			this->Graph[i].set_connections_size(this->_Graph_lenght);
		}
	}
	return *this;
}

_DFS::~_DFS()
{
	delete[] Graph;
	_Graph_lenght = 0;
	Destinations.clear();
}