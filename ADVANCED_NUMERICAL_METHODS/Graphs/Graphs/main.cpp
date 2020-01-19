#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <map>
#include <list>
#include <chrono>
#include <cstdint>
#include <algorithm>
#include <thread>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <time.h>

#define NEW_LINE '\n'


const _STD vector<_STD list<__int32>> Set_Connections_BA_Method();
void Display_Graph(const _STD vector<_STD list<__int32>>& people);
const float Get_CC_Coefficient(const _STD vector<_STD list<__int32>>& people);
void graphBFS(const _STD vector<_STD list<__int32>>& people, int v, _STD vector<bool>& visited, _STD vector<int32_t>& way_length);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;


	_STD vector<_STD list<__int32>> my_list = Set_Connections_BA_Method();
	Display_Graph(my_list);
	_STD cout << "CC Coefficient " << Get_CC_Coefficient(my_list) << NEW_LINE;

	_STD vector<bool> visited(false);
	_STD vector<int32_t> way_length(false);
	visited.resize(my_list.size());
	way_length.resize(my_list.size());
	_STD cout << "Visited: ";
	graphBFS(my_list, 0, visited, way_length);
	_STD cout << NEW_LINE;

	_STD cout << "Diameter: " << *std::max_element(way_length.begin(), way_length.end());
	_STD cout << NEW_LINE;
	_STD cout << "Radius: " << *std::max_element(way_length.begin(), std::max_element(way_length.begin(), way_length.end()));
	_STD cout << NEW_LINE;

	system("pause");
	return 0;
}

const _STD vector<_STD list<__int32>> Set_Connections_BA_Method()
{
	_STD mt19937 generator(time(nullptr));
	////Initialize basic graph with 2 connections
	////ki -> amout of connections at each vertex
	////kc -> amout of all connections

	const size_t N{20};
	//basic initialization
	_STD vector<_STD list<__int32>> people(2);
	//basic initialization
	people.resize(2);
	people[0].push_back(1);
	people[1].push_back(0);
	//////////////////////////////////////////


	__int32 number_of_edges{ 1 };
	float kc{ };
	float probability{ };
	while (people.size() < N)
	{
		__int32 sum{};

		for (size_t i = 0; i < people.size(); ++i)
		{
			sum += people[i].size();
		}
		kc = static_cast<float>(0.5f * sum);

		bool added = false;
		//add new vertex
		people.emplace_back();
		//connect with kind of probability to other vertices
		for (size_t i = 0; i < people.size() - 1; ++i)
		{
			probability = static_cast<float>(people[i].size() / kc);
			_STD bernoulli_distribution prob(probability);
			bool temp = prob(generator);
			if (temp)
			{
				people[people.size() - 1].push_front(i);
				people[i].push_front(people.size() - 1);
				added = true;
			}
		}
		if (added == false)
		{
			people[people.size() - 1].push_front(0);
		}
	}

	return people;
}

void Display_Graph(const _STD vector<_STD list<__int32>>& people)
{
	for (size_t i = 0; i < people.size(); ++i)
	{
		_STD cout << "Vertex: " << i << " Connections: ";
		for (std::list<__int32>::const_iterator it = people[i].begin(); it != people[i].end(); ++it)
		{
			_STD cout << *it << ' ';
		}
		_STD cout << NEW_LINE;
	}
}

const float Get_CC_Coefficient(const _STD vector<_STD list<__int32>>& people)
{
	float CC_Coefficient{};
	uint32_t amount_of_edges{};
	float temp{};

	for (size_t i = 0; i < people.size(); ++i)
	{
		amount_of_edges += people[i].size();
	}
	temp = static_cast<float>(((people.size() * (people.size() - 1)) / 2));

	CC_Coefficient = static_cast<float>(amount_of_edges /temp);

	return float(CC_Coefficient);
}

void graphBFS(const::std::vector<::std::list<__int32>>& people, int v, ::std::vector<bool>& visited, ::std::vector<int32_t>& way_length)
{
	visited[v] = true;
	_STD cout << v << " ";

	for (auto& i : people[v])
	{
		if (i && visited[i] == false)
		{
			way_length[v]++;
			graphBFS(people, i, visited, way_length);

		}
	}
}