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


const std::vector<std::list<int32_t>> Set_Connections_BA_Method(const size_t size);
void Display_Graph(const std::vector<std::list<int32_t>>& people);
const float Get_CC_Coefficient(const std::vector<std::list<int32_t>>& people);
void BFS(const std::vector<std::list<int32_t>>& people, int v, std::vector<bool>& visited, std::vector<int32_t>& way_length);

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;

	size_t amount_of_cases{};
	std::cin >> amount_of_cases;

	size_t* array_sizes = new size_t[amount_of_cases];
	for (size_t i = 0; i < amount_of_cases; ++i)
	{
		std::cin >> array_sizes[i];
	}

	for (size_t i = 0; i < amount_of_cases; ++i)
	{
		std::vector<std::list<int32_t>> my_list = Set_Connections_BA_Method(array_sizes[i]);
		//Display_Graph(my_list);
		std::cout << "Clustering Coefficient " << Get_CC_Coefficient(my_list) << NEW_LINE;

		std::vector<bool> visited(false);
		std::vector<int32_t> way_length(false);
		visited.resize(my_list.size());
		way_length.resize(my_list.size());
		//std::cout << "Visited: ";
		BFS(my_list, 0, visited, way_length);
		//std::cout << NEW_LINE;

		std::cout << "Diameter: " << *std::max_element(way_length.begin(), way_length.end());
		std::cout << NEW_LINE;
		std::cout << "Radius: " << *std::max_element(way_length.begin(), std::max_element(way_length.begin(), way_length.end()));
		std::cout << NEW_LINE;
	}
	delete[] array_sizes;
	return 0;
}

const std::vector<std::list<int32_t>> Set_Connections_BA_Method(const size_t N)
{
	using namespace std::chrono_literals;
	std::mt19937 generator(time(nullptr));
	////Initialize basic graph with 2 connections
	////ki -> amout of connections at each vertex
	////kc -> amout of all connections

	//const size_t N{ };
	//basic initialization
	std::vector<std::list<int32_t>> people(2);
	//basic initialization
	people.resize(2);
	people[0].push_back(1);
	people[1].push_back(0);
	//////////////////////////////////////////


	int32_t number_of_edges{ 1 };
	float kc{ };
	float probability{ };
	while (people.size() < N)
	{
		/*system("cls");
		Display_Graph(people);
		std::this_thread::sleep_for(1s);*/
		int32_t sum{};

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
			std::bernoulli_distribution prob(probability);
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
	//system("cls");
	return people;
}

void Display_Graph(const std::vector<std::list<int32_t>>& people)
{
	for (size_t i = 0; i < people.size(); ++i)
	{
		std::cout << "Vertex: " << i << " Connections: ";
		for (std::list<int32_t>::const_iterator it = people[i].begin(); it != people[i].end(); ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << NEW_LINE;
	}
}

const float Get_CC_Coefficient(const std::vector<std::list<int32_t>>& people)
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

void BFS(const::std::vector<::std::list<int32_t>>& people, int v, ::std::vector<bool>& visited, ::std::vector<int32_t>& way_length)
{
	visited[v] = true;
	//std::cout << v << " ";

	for (auto& i : people[v])
	{
		if (i && visited[i] == false)
		{
			way_length[v]++;
			BFS(people, i, visited, way_length);
		}
	}
}