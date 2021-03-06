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

//CLASS OF _Kruskal_Element, for inserting values

class _Kruskal_Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	int Verticle;
	int Edge;
	int Cost;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Kruskal_Element();
	_Kruskal_Element(const int Verticle, const int Cost, const int Edge);
	_Kruskal_Element(_STD initializer_list<int> _Initializer);
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
	const bool operator==(const _Kruskal_Element& Object) const;
	const bool operator<(const _Kruskal_Element& Object) const;
	friend _STD ostream& operator<<(_STD ostream& _Lhs, const _Kruskal_Element& _Rhs);
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

//CLASS OF _Kruskal

class _Kruskal
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	_STD multiset<_Kruskal_Element> Graph;
	//////////////////////////////////////////////////////////////////////////////
	_STD vector<_Kruskal_Element> MST;
	//////////////////////////////////////////////////////////////////////////////
	_STD vector<_STD set<__int32>> Set;
	//////////////////////////////////////////////////////////////////////////////
	std::vector<std::pair<std::pair<int, int>, int>> Destinations;
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PRIVATE
	*/
	void find_way(const int from, const int to, const int way_lenght);
	const bool Is_in_Same_Set(const int& _Left, const int& _Right);
	const bool Merge(const __int32& _Left, const __int32& _Right);
	const __int32 Find_Element(const int& _Elem) const;
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
	void Print_Graph() const;
	void Print_MST() const;
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

_STD ostream& operator<<(_STD ostream& _Lhs, const _Kruskal_Element& _Rhs)
{
	_Lhs << "V: " << _Rhs.Verticle << " | E:" << _Rhs.Edge << " | C:" << _Rhs.Cost << NEW_LINE;
	return _Lhs;
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
		_Kruskal* Kruskal_Object = new _Kruskal(m);
		while (d > 0)
		{
			std::cin >> c1;
			std::cin >> c2;
			std::cin >> p;
			//both times cause each road is in both ways
			Kruskal_Object->push(c1, c2, p);
			//Kruskal_Object->push(c2, c1, p);
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
				delete Kruskal_Object;
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
	Edge(0),
	Cost(0)
{

}

_Kruskal_Element::_Kruskal_Element(const int Verticle, const int Cost, const int Edge) :
	Verticle(Verticle),
	Edge(Edge),
	Cost(Cost)
{

}

_Kruskal_Element::_Kruskal_Element(_STD initializer_list<int> _Initializer)
{
	if (_Initializer.size() == 3)
	{
		Verticle = (*_Initializer.begin());
		Edge = (*(_Initializer.begin() + 1));
		Cost = (*(_Initializer.begin() + 2));
	}
	else
	{
		throw _STD runtime_error("TOO FEW PARAMETERS FOR INITIALIZER LIST");
	}
}

_Kruskal_Element::_Kruskal_Element(const _Kruskal_Element& Object) :
	Verticle(Object.Verticle),
	Edge(Object.Edge),
	Cost(Object.Cost)
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

const bool _Kruskal_Element::operator==(const _Kruskal_Element& Object) const
{
	if (this->Verticle == Object.Verticle && this->Edge == Object.Edge && this->Cost == Object.Cost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool _Kruskal_Element::operator<(const _Kruskal_Element& Object) const
{
	if (this->Cost < Object.Cost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int _Kruskal_Element::get_verticle() const
{
	return this->Verticle;
}

int _Kruskal_Element::get_cost() const
{
	return this->Cost;
}

int _Kruskal_Element::get_edge() const
{
	return this->Edge;
}

_Kruskal_Element::~_Kruskal_Element()
{
	this->Verticle = NULL;
	this->Edge = NULL;
	this->Cost = NULL;
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
		//Print_Graph();
		minimal_spanning_tree_creator(from_);	//create Djikstra for this case
		Print_MST();
		bool if_break = false;
		_STD cout << NEW_LINE;
		_STD cout << "	       Road through: ";
		for (int i = MST.size() - 1; i >= 0; --i)
		{
			if (if_break == true)
			{
				break;
			}
			for (int j = MST.size() - 1; j >= 0; --j)
			{
				if (MST[j].get_edge() == current_verticle)
				{
					current_verticle = MST[j].get_verticle();
					_STD cout << MST[j].get_edge() << " -> ";
					if (current_verticle == destination_verticle)
					{
						_STD cout << MST[j].get_verticle();
						if_break = true;
					}
				}
			}
		}
		_STD cout << NEW_LINE;
		system("pause");
	}
}

const bool _Kruskal::Is_in_Same_Set(const int& _Left, const int& _Right)
{
	bool left_is = false;
	bool right_is = false;
	size_t where{};
	for (size_t i = 0; i < Set.size(); ++i)
	{
		for (typename _STD set<__int32>::const_iterator set_iterator = Set[i].begin(); set_iterator != Set[i].end(); ++set_iterator)
		{
			if ((*set_iterator) == _Left)
			{
				left_is = true;
			}
			else if ((*set_iterator) == _Right)
			{
				right_is = true;
			}
		}
		if (left_is == true || right_is == true)
		{
			where = i;
			break;
		}
	}
	if (left_is == true && right_is == true)
	{
		return true;
	}
	else if (left_is == false && right_is == false)
	{
		Set[(static_cast<size_t>(_Left) - 1)].insert(_Left);
		Set[(static_cast<size_t>(_Left) - 1)].insert(_Right);
	}
	else if (left_is == false && right_is == true)
	{
		if (Merge(Find_Element(_Left), Find_Element(_Right)) == false)
		{
			Set[where].insert(_Left);
		}
	}
	else if (left_is == true && right_is == false)
	{
		if (Merge(Find_Element(_Left), Find_Element(_Right)) == false)
		{
			Set[where].insert(_Right);
		}
	}
	return false;
}

const bool _Kruskal::Merge(const __int32& _Left, const __int32& _Right)
{
	if (_Left > 0 && _Right > 0)
	{
		if (Set[_Left].size() > 0 && Set[_Right].size() > 0)
		{
			if ((Set[_Left].size() >= Set[_Right].size()))
			{
				for (typename _STD set<__int32>::const_iterator set_iterator = Set[_Right].begin(); set_iterator != Set[_Right].end(); ++set_iterator)
				{
					Set[_Left].insert((*set_iterator));
				}
				Set[_Right].clear();
				return true;
			}
			else
			{
				for (typename _STD set<__int32>::const_iterator set_iterator = Set[_Left].begin(); set_iterator != Set[_Left].end(); ++set_iterator)
				{
					Set[_Right].insert((*set_iterator));
				}
				Set[_Left].clear();
				return true;
			}
		}
	}
	return false;
}

const __int32 _Kruskal::Find_Element(const int& _Elem) const
{
	__int32 where{-1};
	for (size_t i = 0; i < Set.size(); ++i)
	{
		for (typename _STD set<__int32>::const_iterator set_iterator = Set[i].begin(); set_iterator != Set[i].end(); ++set_iterator)
		{
			if ((*set_iterator) == _Elem)
			{
				where = i;
				return where;
			}
		}
	}
	return where;
}

_Kruskal::_Kruskal()
{
	Set.resize(1);
}

_Kruskal::_Kruskal(const size_t _Graph_lenght)
{
	Set.resize(_Graph_lenght);
}

_Kruskal::_Kruskal(const _Kruskal& Object) 
{
	this->Destinations = Object.Destinations;
	this->Graph = Object.Graph;
}

void _Kruskal::push(const int value, const int destination, const int way_lenght)
{
	Graph.insert({ value,destination,way_lenght });
}

void _Kruskal::push_directions(const int from, const int to, const int way_lenght)
{
	Destinations.emplace_back(_STD make_pair(std::make_pair(from, to), way_lenght));
}

void _Kruskal::minimal_spanning_tree_creator(const int the_beginning)
{
	for (typename _STD multiset<_Kruskal_Element>::const_iterator multiset_iterator = Graph.begin(); multiset_iterator != Graph.end(); ++multiset_iterator)
	{
		if ((Is_in_Same_Set((*multiset_iterator).get_verticle(), (*multiset_iterator).get_edge()) == true))
		{
			continue;
		}
		else
		{
			MST.emplace_back(_Kruskal_Element({ (*multiset_iterator).get_verticle(),(*multiset_iterator).get_edge(),(*multiset_iterator).get_cost() }));
		}
	}
}

void _Kruskal::get_results()
{
	for (typename std::vector<std::pair<std::pair<int, int>, int>>::const_iterator vec_iterator = Destinations.begin(); vec_iterator != Destinations.end(); ++vec_iterator)
	{
		find_way(vec_iterator->first.first, vec_iterator->first.second, vec_iterator->second);
	}
}

void _Kruskal::Print_Graph() const
{
	for (typename _STD multiset<_Kruskal_Element>::const_iterator multiset_iterator = Graph.begin(); multiset_iterator != Graph.end(); ++multiset_iterator)
	{
		operator<<(_STD cout, (*multiset_iterator));
	}
}

void _Kruskal::Print_MST() const
{
	for (typename _STD vector<_Kruskal_Element>::const_iterator vector_iterator = MST.begin(); vector_iterator != MST.end(); ++vector_iterator)
	{
		operator<<(_STD cout, (*vector_iterator));
	}
}

_Kruskal& _Kruskal::operator=(const _Kruskal& Object)
{
	if (this != &Object)
	{
		Destinations.clear();
		Graph.clear();
		Set.clear();
		this->Destinations = Object.Destinations;
		this->Graph = Object.Graph;
	}
	return *this;
}

_Kruskal::~_Kruskal()
{
	Destinations.clear();
	Graph.clear();
	Set.clear();
}