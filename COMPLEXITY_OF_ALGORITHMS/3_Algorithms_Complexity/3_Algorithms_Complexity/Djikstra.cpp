#include "Djikstra.hpp"

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

void inserter_DJIKSTRA(const _STD vector<__int32>& file_content)
{
	int m = 0;			//amount of cities
	int d = 0;			//amount of ways
	int c1 = 0;			//number of city
	int c2 = 0;			//number of city
	int p = 0;			//amount of max passengers between one course
	int s = 0;			//the beginning of way
	int e = 0;			//the end of way
	int t = 0;			//amount of max passengers to move by bus
	size_t counter{};
	while (true)
	{
		m = file_content[counter];
		++counter;
		d = file_content[counter];
		++counter;
		_Djikstra* Djikstra_Object = new _Djikstra(m);
		while (d > 0)
		{
			c1 = file_content[counter];
			++counter;
			c2 = file_content[counter];
			++counter;
			p = file_content[counter];
			++counter;
			//both times cause each road is in both ways
			Djikstra_Object->push(c1, c2, p);
			Djikstra_Object->push(c2, c1, p);
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		while (true)
		{
			s = file_content[counter];
			++counter;
			e = file_content[counter];
			++counter;
			if (s != 0 && e != 0)
			{
				t = file_content[counter];
				++counter;
				Djikstra_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				Djikstra_Object->get_results();
				///////////////////////////////////////////////
				delete Djikstra_Object;
				//exit(0);
				break;
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
		break;
	}
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Djikstra_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Djikstra_Element::_Djikstra_Element() :
	_Connections_size(0),
	Verticle(0),
	Cost(0),
	visited_or_not(false),
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
	visited_or_not(false),
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
	visited_or_not(false),
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

void _Djikstra_Element::set_visited_or_not(const bool visited_or_not)
{
	this->visited_or_not = visited_or_not;
}

void _Djikstra_Element::print_connections() const
{
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		_STD cout << Connections[i] << ' ';
	}
}

_Djikstra_Element& _Djikstra_Element::operator=(const _Djikstra_Element& Object)
{
	if (this != &Object)
	{
		this->Verticle = Object.Verticle;
		this->Cost = Object.Cost;
		this->Edge = Object.Edge;
		this->visited_or_not = false;
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

bool _Djikstra_Element::get_visited_or_not() const
{
	return this->visited_or_not;
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
	visited_or_not = false;
	Verticle = 0;
}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Djikstra CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


void _Djikstra::find_way(const int from, const int to, const int way_lenght)
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
		minimal_spanning_tree_creator(from_);	//create Djikstra for this case
		_STD cout << "Road through: ";
		for (int i = _Djikstra_Matrix_lenght - 1; i >= 0; --i)
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
		_STD cout << '\n';
	}
}

_Djikstra::_Djikstra() :
	_Graph_lenght(0),
	_Visited_Nodes_lenght(0),
	_Djikstra_Matrix_lenght(0)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	this->Visited_Nodes = new int[this->_Visited_Nodes_lenght];
}

_Djikstra::_Djikstra(const size_t _Graph_lenght) :
	_Graph_lenght(_Graph_lenght),
	_Visited_Nodes_lenght(_Graph_lenght),
	_Djikstra_Matrix_lenght(_Graph_lenght)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	this->Visited_Nodes = new int[this->_Visited_Nodes_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Djikstra_Matrix[i].set_cost(0);
		this->Djikstra_Matrix[i].set_edge(0);
		this->Visited_Nodes[i] = (-1);
	}
}

_Djikstra::_Djikstra(const _Djikstra& Object) :
	_Graph_lenght(Object._Graph_lenght),
	_Visited_Nodes_lenght(Object._Visited_Nodes_lenght),
	_Djikstra_Matrix_lenght(Object._Djikstra_Matrix_lenght)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	this->Visited_Nodes = new int[this->_Visited_Nodes_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
		this->Djikstra_Matrix[i].set_cost(-1);
		this->Djikstra_Matrix[i].set_edge(0);
		this->Visited_Nodes[i] = static_cast<int>((-1));
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

void _Djikstra::minimal_spanning_tree_creator(const int the_beginning)
{
	for (size_t i = 0; i < _Djikstra_Matrix_lenght; ++i)
	{
		Djikstra_Matrix[i].set_cost(-1);	//means its a infinity
		Djikstra_Matrix[i].set_edge(0);
		Visited_Nodes[i] = (-1);
	}

	int current_verticle = (the_beginning - 1);	//choose the beginning (by position in array (nr index))
	int the_smallest_cost = 999999999;
	int the_smallest_cost_position = 0;

	Djikstra_Matrix[current_verticle].set_cost(0);
	Djikstra_Matrix[current_verticle].set_edge((current_verticle + 1));

	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		Visited_Nodes[current_verticle] = (current_verticle + 1);

		for (size_t j = 0; j < Graph[current_verticle].get_connections_size(); ++j)
		{
			if (Graph[current_verticle].get_connections_array(j) != 0 && Visited_Nodes[j] != (j + 1))
			{
				if ((Djikstra_Matrix[j].get_cost() == -1) || ((Djikstra_Matrix[current_verticle].get_cost() + Graph[current_verticle].get_connections_array(j)) <= Djikstra_Matrix[j].get_cost()))
				{
					Djikstra_Matrix[j].set_cost(Djikstra_Matrix[current_verticle].get_cost() + Graph[current_verticle].get_connections_array(j));
					Djikstra_Matrix[j].set_edge((current_verticle + 1));
				}
			}
		}
		//Seeking for the smallest element in Djikstra's Matrix
		for (size_t j = 0; j < _Djikstra_Matrix_lenght; ++j)
		{
			if ((Djikstra_Matrix[j].get_cost() <= the_smallest_cost && Djikstra_Matrix[j].get_cost() != (-1)) && Visited_Nodes[j] != (j + 1))
			{
				the_smallest_cost = Djikstra_Matrix[j].get_cost();
				current_verticle = static_cast<int>(j);
			}
		}
		the_smallest_cost = 999999999;
	}
}

void _Djikstra::get_results()
{
	for (typename std::vector<std::pair<std::pair<int, int>, int>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		find_way(vec_iterator->first.first, vec_iterator->first.second, vec_iterator->second);
	}
}

void _Djikstra::print_graph() const
{
	_STD cout << "  ";
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		_STD cout << (i + 1) << " ";
	}
	_STD cout << '\n';
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		_STD cout << (i + 1) << ' ';
		Graph[i].print_connections();
		_STD cout << '\n';
	}
	_STD cout << '\n';
}

void _Djikstra::print_djikstra_matrix() const
{
	for (size_t i = 0; i < this->_Djikstra_Matrix_lenght; ++i)
	{
		_STD cout << "V: " << Djikstra_Matrix[i].get_verticle() << " E:" << Djikstra_Matrix[i].get_edge() << " C:" << Djikstra_Matrix[i].get_cost();
		_STD cout << '\n';
	}
	_STD cout << '\n';
}

_Djikstra& _Djikstra::operator=(const _Djikstra& Object)
{
	if (this != &Object)
	{
		this->_Graph_lenght = Object._Graph_lenght;
		this->_Djikstra_Matrix_lenght = Object._Djikstra_Matrix_lenght;
		this->_Visited_Nodes_lenght = Object._Visited_Nodes_lenght;
		delete[] this->Graph;
		delete[] this->Djikstra_Matrix;
		delete[] this->Visited_Nodes;
		this->Destinations.clear();
		this->Graph = new _Djikstra_Element[this->_Graph_lenght];
		this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
		this->Visited_Nodes = new int[this->_Visited_Nodes_lenght];
		for (size_t i = 0; i < this->_Graph_lenght; ++i)
		{
			this->Graph[i].set_connections_size(this->_Graph_lenght);
			this->Djikstra_Matrix[i].set_verticle(static_cast<int>((i + 1)));
			this->Djikstra_Matrix[i].set_cost(0);
			this->Djikstra_Matrix[i].set_edge(0);
			this->Visited_Nodes[i] = (-1);
		}
	}
	return *this;
}

_Djikstra::~_Djikstra()
{
	delete[] Graph;
	delete[] Djikstra_Matrix;
	delete[] Visited_Nodes;
	Destinations.clear();
	_Graph_lenght = 0;
	_Graph_lenght = 0;
	_Visited_Nodes_lenght = 0;
}