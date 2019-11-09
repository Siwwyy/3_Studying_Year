#include "Kruskal.hpp"

//////////////////////////////////////////////////////
/*
				BODY OF FUNCTIONS
*/
//////////////////////////////////////////////////////

_STD ostream& operator<<(_STD ostream& _Lhs, const _Kruskal_Element& _Rhs)
{
	_Lhs << "V: " << _Rhs.Verticle << " | E:" << _Rhs.Edge << " | C:" << _Rhs.Cost << '\n';
	return _Lhs;
}

void inserter_KRUSKAL(const _STD vector<__int32> & file_content)
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
		_Kruskal* Kruskal_Object = new _Kruskal(m);
		while (d > 0)
		{
			c1 = file_content[counter];
			++counter;
			c2 = file_content[counter];
			++counter;
			p = file_content[counter];
			++counter;
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
			s = file_content[counter];
			++counter;
			e = file_content[counter];
			++counter;
			if (s != 0 && e != 0)
			{
				t = file_content[counter];
				++counter;
				Kruskal_Object->push_directions(s, e, t);
			}
			else
			{
				//here call all needed functions for solve the problem cause if s and e will be equal to 0 problem will be stopped immediately
				///////////////////////////////////////////////
				Kruskal_Object->get_results();
				///////////////////////////////////////////////
				delete Kruskal_Object;
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
	_Kruskal_Element CLASS METHOD'S BODIES
*/
////////////////////////////////////////////////////
////////////////////////////////////////////////////


_Kruskal_Element::_Kruskal_Element() :
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
		minimal_spanning_tree_creator(from_);	//create Djikstra for this case

		_STD cout << "	       Road through: ";
		_STD cout << current_verticle << " -> ";
		for (int i = MST.size() - 1; i >= 0; --i)
		{
			if (MST[i].get_verticle() == destination_verticle)
			{
				_STD cout << MST[i].get_verticle();
				break;
			}
			else if (MST[i].get_edge() == current_verticle)
			{
				current_verticle = MST[i].get_verticle();
				_STD cout << MST[i].get_verticle() << " -> ";
			}
		}
		_STD cout << '\n';
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
	__int32 where{ -1 };
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