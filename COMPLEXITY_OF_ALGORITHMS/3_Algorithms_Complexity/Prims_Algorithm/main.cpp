/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <math.h>

#define NEW_LINE '\n'

//CLASS OF _MST_ELEMENT, for inserting values

class _MST_Element
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
	int * Connections;
	size_t _Connections_size;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_MST_Element();
	_MST_Element(const int Verticle, const int Cost, const int Edge);
	_MST_Element(const _MST_Element & Object);
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
	_MST_Element & operator=(const _MST_Element & Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	int get_verticle() const;
	int get_cost() const;
	int get_edge() const;
	size_t get_connections_size() const;
	int & get_connections_array(const size_t counter) const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MST_Element();
};

//CLASS OF _MST

class _MST
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	_MST_Element * Graph;
	size_t _Graph_lenght;
	/////////////////////////////////////////////////////////////////////////
	_MST_Element * Prims_Matrix;
	size_t _Prims_Matrix_lenght;
	/////////////////////////////////////////////////////////////////////////
	int * Q;
	size_t _Q_lenght;
	int _Q_counter;
	/////////////////////////////////////////////////////////////////////////
	std::vector<_MST_Element> F;
	//////////////////////////////////////////////////////////////////////////////
	std::vector<std::pair<std::pair<int, int>, int>> Destinations;
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PRIVATE
	*/
	void find_way(const int from, const int to, const int way_lenght);
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_MST();
	_MST(const size_t _Graph_lenght);
	_MST(const _MST & Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push(const int value, const int destination, const int way_lenght);
	void push_directions(const int from, const int to, const int way_lenght);
	void minimal_spanning_tree_creator(const int the_beginning);
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
	_MST & operator=(const _MST & Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_MST();
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
		_MST * MST_Object = new _MST(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			MST_Object->push(c1, c2, (-1)*p);
			MST_Object->push(c2, c1, (-1)*p);
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
				MST_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				MST_Object->get_results();
				///////////////////////////////////////////////
				delete MST_Object;
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


_MST_Element::_MST_Element() :
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

_MST_Element::_MST_Element(const int Verticle, const int Cost, const int Edge) :
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

_MST_Element::_MST_Element(const _MST_Element & Object) :
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

void _MST_Element::set_connections_size(const size_t _Connections_size)
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

void _MST_Element::set_connection(const int value, const size_t counter)
{
	this->Connections[counter] = value;
}

void _MST_Element::set_way(const int destination, const int way_lenght)
{
	this->Connections[(destination - 1)] = way_lenght;
}

void _MST_Element::set_verticle(const int verticle)
{
	this->Verticle = verticle;
}

void _MST_Element::set_cost(const int cost)
{
	this->Cost = cost;
}

void _MST_Element::set_edge(const int edge)
{
	this->Edge = edge;
}

_MST_Element & _MST_Element::operator=(const _MST_Element & Object)
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

int _MST_Element::get_verticle() const
{
	return this->Verticle;
}

int _MST_Element::get_cost() const
{
	return this->Cost;
}

int _MST_Element::get_edge() const
{
	return this->Edge;
}

size_t _MST_Element::get_connections_size() const
{
	return this->_Connections_size;
}

int & _MST_Element::get_connections_array(const size_t counter) const
{
	return this->Connections[counter];
}

_MST_Element::~_MST_Element()
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


_MST::_MST() :
	_Graph_lenght(0),
	_Q_lenght(0),
	_Q_counter(0),
	_Prims_Matrix_lenght(0)
{
	this->Graph = new _MST_Element[this->_Graph_lenght];
	this->Q = new int[this->_Q_lenght];
	this->Prims_Matrix = new _MST_Element[this->_Prims_Matrix_lenght];
}

_MST::_MST(const size_t _Graph_lenght) :
	_Graph_lenght(_Graph_lenght),
	_Q_lenght(_Graph_lenght),
	_Q_counter(0),
	_Prims_Matrix_lenght(_Graph_lenght)
{
	this->Graph = new _MST_Element[this->_Graph_lenght];
	this->Q = new int[this->_Q_lenght];
	this->Prims_Matrix = new _MST_Element[this->_Prims_Matrix_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Q[i] = static_cast<int>((i + 1));
		this->Prims_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Prims_Matrix[i].set_cost(0);
		this->Prims_Matrix[i].set_edge(0);
	}
}

_MST::_MST(const _MST & Object) :
	_Graph_lenght(Object._Graph_lenght),
	_Prims_Matrix_lenght(Object._Prims_Matrix_lenght),
	_Q_lenght(Object._Q_lenght),
	_Q_counter(Object._Q_counter)
{
	this->Graph = new _MST_Element[this->_Graph_lenght];
	this->Q = new int[this->_Q_lenght];
	this->Prims_Matrix = new _MST_Element[this->_Prims_Matrix_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Q[i] = static_cast<int>((i + 1));
		this->Prims_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Prims_Matrix[i].set_cost(0);
		this->Prims_Matrix[i].set_edge(0);
	}
}

void _MST::push(const int value, const int destination, const int way_lenght)
{
	this->Graph[(value - 1)].set_way(destination, way_lenght);
}

void _MST::push_directions(const int from, const int to, const int way_lenght)
{
	Destinations.emplace_back(std::make_pair(std::make_pair(from, to), way_lenght));
}

void _MST::minimal_spanning_tree_creator(const int the_beginning)
{
	//Clear the Prims Matrix
	F.clear();
	for (size_t i = 0; i < _Prims_Matrix_lenght; ++i)
	{
		Prims_Matrix[i].set_cost(0);
		Prims_Matrix[i].set_edge(0);
		Q[i] = static_cast<int>((i + 1));
	}
	_Q_counter = 0;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int current_verticle = (the_beginning - 1);	//choose the beginning (by position in array (nr index))
	int the_smallest_cost = 0;
	int the_smallest_cost_position = 0;
	while (_Q_counter < static_cast<int>(_Q_lenght))
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Deleting from Q
		Q[(current_verticle)] = 0;
		++_Q_counter;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Adding to F (Forest)
		if (Prims_Matrix[(current_verticle)].get_edge() != 0)
		{
			F.emplace_back(_MST_Element(Prims_Matrix[current_verticle].get_verticle(), 0, 0));
			F.emplace_back(_MST_Element(Prims_Matrix[current_verticle].get_verticle(), 0, Prims_Matrix[current_verticle].get_edge()));
		}
		else
		{
			F.emplace_back(_MST_Element(Prims_Matrix[current_verticle].get_verticle(), 0, 0));
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Setting the Prim's Matrix
		for (size_t j = 0; j < Graph[current_verticle].get_connections_size(); ++j)
		{
			if (Graph[current_verticle].get_connections_array(j) != 0 && Q[j] == Prims_Matrix[j].get_verticle())
			{
				if ((Prims_Matrix[j].get_cost() >= Graph[current_verticle].get_connections_array(j)) || (Prims_Matrix[j].get_cost() == 0))
				{
					Prims_Matrix[j].set_cost(Graph[current_verticle].get_connections_array(j));
					Prims_Matrix[j].set_edge((current_verticle + 1));
				}
			}
			else
			{
				continue;
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//Seeking for the smallest element in Prim's Matrix
		for (size_t i = 0; i < _Prims_Matrix_lenght; ++i)
		{
			if (Prims_Matrix[i].get_cost() <= the_smallest_cost && Q[i] == Prims_Matrix[i].get_verticle())
			{
				the_smallest_cost = Prims_Matrix[i].get_cost();
				the_smallest_cost_position = static_cast<int>(i);
			}
		}
		current_verticle = the_smallest_cost_position;
		the_smallest_cost = 0;
		the_smallest_cost_position = 0;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		//End of Loop
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////
}

void _MST::get_results()
{
	for (typename std::vector<std::pair<std::pair<int, int>, int>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		find_way(vec_iterator->first.first, vec_iterator->first.second, vec_iterator->second);
	}
}

void _MST::find_way(const int from, const int to, const int way_lenght)
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
		minimal_spanning_tree_creator(from_);	//create Prims for this case

		_STD cout << "Road through: ";
		for (int i = _Prims_Matrix_lenght - 1; i >= 0; --i)
		{
			if (Prims_Matrix[i].get_verticle() == destination_verticle)
			{
				_STD cout << Prims_Matrix[i].get_verticle();
				break;
			}
			else if (Prims_Matrix[i].get_verticle() == current_verticle)
			{
				current_verticle = Prims_Matrix[i].get_edge();
				_STD cout << Prims_Matrix[i].get_verticle() << " -> ";
			}
		}
		_STD cout << NEW_LINE;
	}
}

_MST & _MST::operator=(const _MST & Object)
{
	if (this != &Object)
	{
		this->_Graph_lenght = Object._Graph_lenght;
		this->_Q_counter = Object._Q_counter;
		this->_Q_lenght = Object._Q_lenght;
		this->_Prims_Matrix_lenght = Object._Prims_Matrix_lenght;
		delete[] this->Graph;
		delete[] this->Q;
		delete[] this->Prims_Matrix;
		this->F.clear();
		this->Graph = new _MST_Element[this->_Graph_lenght];
		this->Q = new int[this->_Q_lenght];
		this->Prims_Matrix = new _MST_Element[this->_Prims_Matrix_lenght];
		for (size_t i = 0; i < this->_Graph_lenght; ++i)
		{
			this->Graph[i].set_connections_size(this->_Graph_lenght);
			this->Q[i] = static_cast<int>((i + 1));
			this->Prims_Matrix[i].set_verticle(static_cast<int>((i + 1)));
			this->Prims_Matrix[i].set_cost(0);
			this->Prims_Matrix[i].set_edge(0);
		}
	}
	return *this;
}

_MST::~_MST()
{
	delete[] Graph;
	delete[] Q;
	delete[] Prims_Matrix;
	F.clear();
	_Graph_lenght = 0;
	_Q_counter = 0;
	_Q_lenght = 0;
	_Prims_Matrix_lenght = 0;
}