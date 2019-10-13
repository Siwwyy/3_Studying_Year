/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <math.h>

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
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Djikstra_Element();
	_Djikstra_Element(const int Verticle, const int Cost, const int Edge);
	_Djikstra_Element(const _Djikstra_Element& Object);
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
	_Djikstra_Element& operator=(const _Djikstra_Element& Object);
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
	virtual ~_Djikstra_Element();
};

//CLASS OF _Djikstra

class _Djikstra
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
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
	/*
		FUNKCJE PRIVATE
	*/
	
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Djikstra();
	_Djikstra(const size_t _Graph_lenght);
	_Djikstra(const _Djikstra& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push(const int value, const int destination, const int way_lenght);
	void push_directions(const int from, const int to, const int way_lenght);
	//void minimal_spanning_tree_creator(const int the_beginning);
	//void get_results();
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
	_Djikstra& operator=(const _Djikstra& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Djikstra();
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
		_Djikstra* Djikstra_Object = new _Djikstra(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			Djikstra_Object->push(c1, c2, (-1) * p);
			Djikstra_Object->push(c2, c1, (-1) * p);
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
				Djikstra_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				//Djikstra_Object->get_results();
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
	_MST_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Djikstra_Element::_Djikstra_Element() :
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

_Djikstra_Element::_Djikstra_Element(const int Verticle, const int Cost, const int Edge) :
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

_Djikstra_Element::_Djikstra_Element(const _Djikstra_Element& Object) :
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

void _Djikstra_Element::set_connections_size(const size_t _Connections_size)
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

void _Djikstra_Element::set_connection(const int value, const size_t counter)
{
	this->Connections[counter] = value;
}

void _Djikstra_Element::set_way(const int destination, const int way_lenght)
{
	this->Connections[(destination - 1)] = way_lenght;
}

void _Djikstra_Element::set_verticle(const int verticle)
{
	this->Verticle = verticle;
}

void _Djikstra_Element::set_cost(const int cost)
{
	this->Cost = cost;
}

void _Djikstra_Element::set_edge(const int edge)
{
	this->Edge = edge;
}

_Djikstra_Element& _Djikstra_Element::operator=(const _Djikstra_Element& Object)
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

int _Djikstra_Element::get_verticle() const
{
	return this->Verticle;
}

int _Djikstra_Element::get_cost() const
{
	return this->Cost;
}

int _Djikstra_Element::get_edge() const
{
	return this->Edge;
}

size_t _Djikstra_Element::get_connections_size() const
{
	return this->_Connections_size;
}

int& _Djikstra_Element::get_connections_array(const size_t counter) const
{
	return this->Connections[counter];
}

_Djikstra_Element::~_Djikstra_Element()
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


_Djikstra::_Djikstra() :
	_Graph_lenght(0),
	_Djikstra_Matrix_lenght(0)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
}

_Djikstra::_Djikstra(const size_t _Graph_lenght) :
	_Graph_lenght(_Graph_lenght),
	_Djikstra_Matrix_lenght(_Graph_lenght)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Djikstra_Matrix[i].set_cost(0);
		this->Djikstra_Matrix[i].set_edge(0);
	}
}

_Djikstra::_Djikstra(const _Djikstra& Object) :
	_Graph_lenght(Object._Graph_lenght),
	_Djikstra_Matrix_lenght(Object._Djikstra_Matrix_lenght)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Djikstra_Matrix[i].set_cost(0);
		this->Djikstra_Matrix[i].set_edge(0);
	}
}

void _Djikstra::push(const int value, const int destination, const int way_lenght)
{
	this->Graph[(value - 1)].set_way(destination, way_lenght);
}

void _Djikstra::push_directions(const int from, const int to, const int way_lenght)
{
	Destinations.emplace_back(_STD make_pair(std::make_pair(from, to), way_lenght));
}

_Djikstra& _Djikstra::operator=(const _Djikstra& Object)
{
	if (this != &Object)
	{
		this->_Graph_lenght = Object._Graph_lenght;
		this->_Djikstra_Matrix_lenght = Object._Djikstra_Matrix_lenght;
		delete[] this->Graph;
		delete[] this->Djikstra_Matrix;
		this->Destinations.clear();
		this->Graph = new _Djikstra_Element[this->_Graph_lenght];
		this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
		for (size_t i = 0; i < this->_Graph_lenght; ++i)
		{
			this->Graph[i].set_connections_size(this->_Graph_lenght);
			this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
			this->Djikstra_Matrix[i].set_cost(0);
			this->Djikstra_Matrix[i].set_edge(0);
			this->Destinations.emplace_back(_STD make_pair(_STD make_pair(Object.Destinations[i].first.first, Object.Destinations[i].first.second), Object.Destinations[i].second));
		}
	}
	return *this;
}

_Djikstra::~_Djikstra()
{
	delete[] Graph;
	delete[] Djikstra_Matrix;
	Destinations.clear();
	_Graph_lenght = 0;
	_Djikstra_Matrix_lenght = 0;
}