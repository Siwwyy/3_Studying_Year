#include "Djikstra.hpp"

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////


COORD p = { 0, 0 };



void inserter_DJIKSTRA(const std::vector<int32_t>& file_content)
{
	int32_t m = 0;			//amount of cities
	int32_t d = 0;			//amount of ways
	int32_t c1 = 0;			//number of city
	int32_t c2 = 0;			//number of city
	int32_t p = 0;			//amount of max passengers between one course
	int32_t s = 0;			//the beginning of way
	int32_t e = 0;			//the end of way
	int32_t t = 0;			//amount of max passengers to move by bus
	size_t counter{};
	bool if_break = true;
	while (if_break)
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
		while (if_break)
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
				system("pause");
				Djikstra_Object->print_djikstra_matrix();
				///////////////////////////////////////////////
				delete Djikstra_Object;
				if_break = false;
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
	}
}

void inserter_DJIKSTRA(const std::string & file_path)
{
	std::fstream file_in{};
	file_in.open(file_path.c_str(), std::ios_base::in);

	int32_t m = 0;			//amount of cities
	int32_t d = 0;			//amount of ways
	int32_t c1 = 0;			//number of city
	int32_t c2 = 0;			//number of city
	int32_t p = 0;			//amount of max passengers between one course
	int32_t s = 0;			//the beginning of way
	int32_t e = 0;			//the end of way
	int32_t t = 0;			//amount of max passengers to move by bus
	size_t counter{};
	bool if_break = true;
	while (if_break)
	{
		file_in >> m;
		file_in >> d;
		_Djikstra* Djikstra_Object = new _Djikstra(m);
		while (d > 0)
		{
			file_in >> c1;
			file_in >> c2;
			file_in >> p;
			//both times cause each road is in both ways
			Djikstra_Object->push(c1, c2, p);
			Djikstra_Object->push(c2, c1, p);
			counter++;
			--d;
			c1 = 0;
			c2 = 0;
			p = 0;
		}
		while (if_break)
		{
			file_in >> s;
			file_in >> e;
			if (s != 0 && e != 0)
			{
				file_in >> t;
				Djikstra_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				Djikstra_Object->get_results();
				system("pause");
				//Djikstra_Object->print_djikstra_matrix();
				///////////////////////////////////////////////
				delete Djikstra_Object;
				if_break = false;
			}
			s = 0;
			e = 0;
			t = 0;
		}
		d = 0;
		m = 0;
	}
	file_in.close();
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
	this->Connections = new int32_t[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

_Djikstra_Element::_Djikstra_Element(const int32_t Verticle, const int32_t Cost, const int32_t Edge) :
	_Connections_size(0),
	Verticle(Verticle),
	Cost(Cost),
	visited_or_not(false),
	Edge(Edge)
{
	this->Connections = new int32_t[this->_Connections_size];
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
	this->Connections = new int32_t[this->_Connections_size];
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
	this->Connections = new int32_t[this->_Connections_size];
	for (size_t i = 0; i < this->_Connections_size; ++i)
	{
		Connections[i] = 0;
	}
}

void _Djikstra_Element::set_connection(const int32_t value, const size_t counter)
{
	this->Connections[counter] = value;
}

void _Djikstra_Element::set_way(const int32_t destination, const int32_t way_lenght)
{
	//if (destination == 30)
	//{
	//	std::cin.get();
	//}
	this->Connections[(destination - 1)] = way_lenght;
}

void _Djikstra_Element::set_verticle(const int32_t verticle)
{
	this->Verticle = verticle;
}

void _Djikstra_Element::set_cost(const int32_t cost)
{
	this->Cost = cost;
}

void _Djikstra_Element::set_edge(const int32_t edge)
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
		std::cout << Connections[i] << ' ';
		p.X = (p.X + 4);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
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
		this->Connections = new int32_t[this->_Connections_size];
		for (size_t i = 0; i < this->_Connections_size; ++i)
		{
			this->Connections[i] = 0;
		}
	}
	return *this;
}

int32_t _Djikstra_Element::get_verticle() const
{
	return this->Verticle;
}

int32_t _Djikstra_Element::get_cost() const
{
	return this->Cost;
}

int32_t _Djikstra_Element::get_edge() const
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

int32_t& _Djikstra_Element::get_connections_array(const size_t counter) const
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


void _Djikstra::find_way(const int32_t from, const int32_t to, const int32_t way_lenght)
{
	if (from == to)
	{
		std::cout << '0' << '\n';
	}
	else
	{
		int32_t current_verticle = 0;
		int32_t destination_verticle = 0;
		int32_t from_ = 0;
		int32_t to_ = 0;

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
		std::cout << "	       Road through: ";
		for (int32_t i = _Djikstra_Matrix_lenght - 1; i >= 0; --i)
		{
			if (Djikstra_Matrix[i].get_verticle() == destination_verticle)
			{
				std::cout << Djikstra_Matrix[i].get_verticle();
				break;
			}
			else if (Djikstra_Matrix[i].get_verticle() == current_verticle)
			{
				current_verticle = Djikstra_Matrix[i].get_edge();
				std::cout << Djikstra_Matrix[i].get_verticle() << " -> ";
			}
		}
		std::cout << '\n';
		system("pause");
	}
}

_Djikstra::_Djikstra() :
	_Graph_lenght(0),
	_Visited_Nodes_lenght(0),
	_Djikstra_Matrix_lenght(0)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	this->Visited_Nodes = new int32_t[this->_Visited_Nodes_lenght];
}

_Djikstra::_Djikstra(const size_t _Graph_lenght) :
	_Graph_lenght(_Graph_lenght),
	_Visited_Nodes_lenght(_Graph_lenght),
	_Djikstra_Matrix_lenght(_Graph_lenght)
{
	this->Graph = new _Djikstra_Element[this->_Graph_lenght];
	this->Djikstra_Matrix = new _Djikstra_Element[this->_Djikstra_Matrix_lenght];
	this->Visited_Nodes = new int32_t[this->_Visited_Nodes_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int32_t>((i + 1)));
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
	this->Visited_Nodes = new int32_t[this->_Visited_Nodes_lenght];
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		this->Graph[i].set_connections_size(this->_Graph_lenght);
		this->Djikstra_Matrix[i].set_verticle(static_cast<int32_t>((i + 1)));
		this->Djikstra_Matrix[i].set_cost(-1);
		this->Djikstra_Matrix[i].set_edge(0);
		this->Visited_Nodes[i] = static_cast<int32_t>((-1));
	}
}

void _Djikstra::push(const int32_t value, const int32_t destination, const int32_t way_lenght)
{
	this->Graph[(value - 1)].set_way(destination, way_lenght);
}

void _Djikstra::push_directions(const int32_t from, const int32_t to, const int32_t way_lenght)
{
	Destinations.emplace_back(std::make_pair(std::make_pair(from, to), way_lenght));
}

void _Djikstra::minimal_spanning_tree_creator(const int32_t the_beginning)
{
	for (size_t i = 0; i < _Djikstra_Matrix_lenght; ++i)
	{
		Djikstra_Matrix[i].set_cost(-1);	//means its a infinity
		Djikstra_Matrix[i].set_edge(0);
		Visited_Nodes[i] = (-1);
	}

	int32_t current_verticle = (the_beginning - 1);	//choose the beginning (by position in array (nr index))
	int32_t the_smallest_cost = 999999999;
	int32_t the_smallest_cost_position = 0;

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
				current_verticle = static_cast<int32_t>(j);
			}
		}
		the_smallest_cost = 999999999;
	}
}

void _Djikstra::get_results()
{
	print_graph();
	system("pause");
	for (typename std::vector<std::pair<std::pair<int32_t, int32_t>, int32_t>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		find_way(vec_iterator->first.first, vec_iterator->first.second, vec_iterator->second);
	}
}

void _Djikstra::print_graph() const
{
	p.Y = 40;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	std::cout << "  ";
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		std::cout << (i + 1) << " ";
	}
	std::cout << '\n';
	for (size_t i = 0; i < this->_Graph_lenght; ++i)
	{
		p.Y = i+41;
		p.X = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << (i + 1) << ' ';
		p.X = 27;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		Graph[i].print_connections();
		//std::cout << '\n';
		//system("pause");
		std::cout << '\n';
	}
	std::cout << '\n';
}

void _Djikstra::print_djikstra_matrix() const
{
	for (size_t i = 0; i < this->_Djikstra_Matrix_lenght; ++i)
	{
		std::cout << "V: " << Djikstra_Matrix[i].get_verticle() << " E:" << Djikstra_Matrix[i].get_edge() << " C:" << Djikstra_Matrix[i].get_cost();
		std::cout << '\n';
	}
	std::cout << '\n';
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
		this->Visited_Nodes = new int32_t[this->_Visited_Nodes_lenght];
		for (size_t i = 0; i < this->_Graph_lenght; ++i)
		{
			this->Graph[i].set_connections_size(this->_Graph_lenght);
			this->Djikstra_Matrix[i].set_verticle(static_cast<int32_t>((i + 1)));
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