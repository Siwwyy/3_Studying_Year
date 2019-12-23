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
#include <stack>
#include <iterator>
#include <unordered_set>
#include <math.h>

#define NEW_LINE '\n'
//CLASS OF _MST_ELEMENT, for inserting values

class _DFS_Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
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
	void Print_Connections() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_connections_size(const size_t _Connections_size);
	void set_connection(const int value, const size_t counter);
	void set_way(const int destination, const int way_lenght);
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
	std::unordered_set<__int32> DFS_Queue;
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PRIVATE
	*/
	void DFS(const __int32 the_beginning);
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
	void Print_Graph() const;
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
			DFS_Object->push(c1, c2, p);
			DFS_Object->push(c2, c1, p);
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
				DFS_Object->Print_Graph();
				_STD cin.get();
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
	_Connections_size(0)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

_DFS_Element::_DFS_Element(const int Verticle, const int Cost, const int Edge) :
	_Connections_size(0)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

_DFS_Element::_DFS_Element(const _DFS_Element& Object) :
	_Connections_size(Object._Connections_size)
{
	this->Connections = new int[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

void _DFS_Element::Print_Connections() const
{
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		_STD cout << Connections[i] << ' ';
	}
	_STD cout << NEW_LINE;
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

_DFS_Element& _DFS_Element::operator=(const _DFS_Element& Object)
{
	if (this != &Object)
	{
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
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_MST CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


void _DFS::DFS(const __int32 the_beginning)
{
	_STD stack<__int32> Temp_Stack{};
	DFS_Queue.insert(the_beginning);

	size_t connections_counter{};
	__int32 current_verticle{ (the_beginning - 1) };
	bool if_break = false;

	while(DFS_Queue.size() < _Graph_lenght)
	{
		if_break = false;
		for (size_t i = 0; i < this->Graph[current_verticle].get_connections_size(); ++i)
		{
			if (Graph[current_verticle].get_connections_array(i) != 0 && i != current_verticle)
			{
				Graph[current_verticle].get_connections_array(i) = 0;
				Graph[i].get_connections_array(current_verticle) = 0;
				Temp_Stack.push(current_verticle);
				current_verticle = i;
				DFS_Queue.insert((current_verticle+1));
				if_break = true;
				break;
			}
		}		
		//_STD cout << "----------------------------------------------" << NEW_LINE;		
		//for (typename _STD unordered_set<__int32>::const_iterator it = DFS_Queue.begin(); it != DFS_Queue.end(); ++it)
		//{
		//	_STD cout << (*it) << ' ';
		//}
		//_STD cout << NEW_LINE;
		//Print_Graph();
		//_STD cout << NEW_LINE;
		//_STD cout << "----------------------------------------------" << NEW_LINE;
		//_STD cin.get();
		if (if_break == false)
		{
			current_verticle = (Temp_Stack.top());
			Temp_Stack.pop();
		}
	}
	for (typename _STD unordered_set<__int32>::const_iterator it = DFS_Queue.begin(); it != DFS_Queue.end(); ++it)
	{
		_STD cout << (*it) << ' ';
	}
	_STD cout << NEW_LINE;
	//for (size_t i = 0; i < DFS_Queue.size(); ++i)
	//{
	//	_STD cout << DFS_Queue[i] << ' ';
	//}
	//_STD cout << NEW_LINE;
}

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

void _DFS::Print_Graph() const
{
	for (size_t i = 0; i < _Graph_lenght; ++i)
	{
		//((*Graph) + (sizeof(_DFS_Element) * i))->Print_Connections();
		(*(Graph + i)).Print_Connections();
		//(Graph + (sizeof(_DFS_Element)) * i)->Print_Connections();
		//(Graph + (sizeof(_DFS_Element)) * i)->Print_Connections();
		//_STD cout << Graph << NEW_LINE;
	}
}

void _DFS::get_results()
{
	for (typename std::vector<std::pair<std::pair<int, int>, int>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		DFS(vec_iterator->first.first);
	}
}

_DFS& _DFS::operator=(const _DFS& Object)
{
	if (this != &Object)
	{
		this->_Graph_lenght = Object._Graph_lenght;
		delete[] this->Graph;
		this->Graph = new _DFS_Element[this->_Graph_lenght];
		Destinations.clear();
		DFS_Queue.clear();
		Destinations = Object.Destinations;
		DFS_Queue = Object.DFS_Queue;
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
	DFS_Queue.clear();
}