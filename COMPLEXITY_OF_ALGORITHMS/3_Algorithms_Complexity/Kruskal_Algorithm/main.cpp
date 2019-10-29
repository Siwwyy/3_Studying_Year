/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

#define NEW_LINE '\n'

//CLASS OF _MST_ELEMENT, for inserting values

class _Kruskal_Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	int Verticle;
	int Cost;
	int Edge;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Kruskal_Element();
	_Kruskal_Element(const int Verticle, const int Cost, const int Edge);
	_Kruskal_Element(const _Kruskal_Element& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_verticle(const int verticle);
	void set_cost(const int cost);
	void set_edge(const int edge);
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_Kruskal_Element& operator=(const _Kruskal_Element& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	int get_verticle() const;
	int get_cost() const;
	int get_edge() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Kruskal_Element();
};

//CLASS OF _MST

class _Kruskal
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	_STD set<_Kruskal_Element> Graph;
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
	_Kruskal();
	_Kruskal(const size_t _Graph_lenght);
	_Kruskal(const _Kruskal& Object);
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
	_Kruskal& operator=(const _Kruskal& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Kruskal();
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
		_Kruskal* Kruskal_Object = new _Kruskal;
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			Kruskal_Object->push(c1, c2, (-1) * p);
			Kruskal_Object->push(c2, c1, (-1) * p);
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
				Kruskal_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				Kruskal_Object->get_results();
				///////////////////////////////////////////////
				//delete MST_Object;
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
	_Kruskal_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Kruskal_Element::_Kruskal_Element():
	Verticle(0),
	Cost(0),
	Edge(0)
{

}

_Kruskal_Element::_Kruskal_Element(const int Verticle, const int Cost, const int Edge) :
	Verticle(Verticle),
	Cost(Cost),
	Edge(Edge)
{

}

_Kruskal_Element::_Kruskal_Element(const _Kruskal_Element& Object) :
	Verticle(Object.Verticle),
	Cost(Object.Cost),
	Edge(Object.Edge)
{

}

void _Kruskal_Element::set_verticle(const int verticle)
{
	this->Verticle = verticle;
}

void _Kruskal_Element::set_cost(const int cost)
{
	this->Cost = cost;
}

void _Kruskal_Element::set_edge(const int edge)
{
	this->Edge = edge;
}

_Kruskal_Element& _Kruskal_Element::operator=(const _Kruskal_Element& Object)
{
	if (this != &Object)
	{
		this->Verticle = Object.Verticle;
		this->Cost = Object.Cost;
		this->Edge = Object.Edge;
	}
	return *this;
}

int _Kruskal_Element::get_verticle() const
{
	return 0;
}

int _Kruskal_Element::get_cost() const
{
	return 0;
}

int _Kruskal_Element::get_edge() const
{
	return 0;
}

_Kruskal_Element::~_Kruskal_Element()
{

}


////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
	_Kruskal CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


void _Kruskal::find_way(const int from, const int to, const int way_lenght)
{

}

_Kruskal::_Kruskal()
{

}

_Kruskal::_Kruskal(const size_t _Graph_lenght)
{

}

_Kruskal::_Kruskal(const _Kruskal& Object)
{

}

void _Kruskal::push(const int value, const int destination, const int way_lenght)
{

}

void _Kruskal::push_directions(const int from, const int to, const int way_lenght)
{

}

void _Kruskal::minimal_spanning_tree_creator(const int the_beginning)
{

}

void _Kruskal::get_results()
{

}

_Kruskal& _Kruskal::operator=(const _Kruskal& Object)
{
	if (this != &Object)
	{

	}
	return *this;
}

_Kruskal::~_Kruskal()
{

}