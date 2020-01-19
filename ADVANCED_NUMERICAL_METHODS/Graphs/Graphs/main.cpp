#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <map>
#include <list>
#include <fstream>
#include <time.h>

#define NEW_LINE '\n'

void Set_Connections(bool Graph[100][100]);
void Print_Graph(bool Graph[100][100]);
void Set_Connections_BA_Method();
const __int32 vertex_connections(bool Graph[100]);
//void Display_Graph(const _STD vector<_STD pair<_STD vector<__int32>, __int32>>& people);
void Display_Graph(const _STD vector<_STD list<__int32>>& people);

//class Vertex
//{
//private:
//
//public:
//	Vertex();
//	~Vertex();
//};

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;

	bool Graph[100][100]{ false };

	Set_Connections_BA_Method();


	////Print_Graph(Graph);
	//Set_Connections(Graph);
	////Print_Graph(Graph);

	//_STD fstream file_out{};
	//file_out.open("out.csv", _STD ios_base::out);
	//_STD map<int, int> histo{};
	//size_t sum{};
	//for (size_t i = 0; i < 100; ++i)
	//{
	//	size_t counter{};
	//	_STD cout << (i + 1) << ' ';
	//	for (size_t j = 0; j < 100; ++j)
	//	{
	//		if (Graph[i][j] == true)
	//		{
	//			_STD cout << "=";
	//			counter++;
	//		}
	///*		else
	//		{
	//			_STD cout << "+";
	//		}*/
	//	}
	//	sum += counter;
	//	histo[counter]++;
	//	_STD cout << " " << counter;
	//	//file_out << counter << NEW_LINE;
	//	_STD cout << NEW_LINE;
	//}

	//for (typename _STD map<int, int>::iterator map_iterator = histo.begin(); map_iterator != histo.end(); ++map_iterator)
	//{
	//	file_out << map_iterator->first << ',' << map_iterator->second << NEW_LINE;
	//}


	//_STD cout << "Average: " << static_cast<float>(sum/100.f) << NEW_LINE;
	//file_out << "Average: ," << static_cast<float>(sum/100.f) << NEW_LINE;

	//file_out.close();

	system("pause");
	return 0;
}

void Set_Connections(bool Graph[100][100])
{
	std::random_device rd;
	std::mt19937 gen(rd());
	double weights[]{ 2,0,1,0 };
	std::discrete_distribution<> d(std::begin(weights), std::end(weights));
	for (size_t i = 0; i < 100; ++i)
	{
		for (size_t j = 0; j < 100; ++j)
		{
			Graph[i][j] = d(gen);
		}
	}
}

void Print_Graph(bool Graph[100][100])
{
	for (size_t i = 0; i < 100; ++i)
	{
		for (size_t j = 0; j < 100; ++j)
		{
			_STD cout << Graph[i][j] << " ";
		}
		_STD cout << NEW_LINE;
	}
}

void Set_Connections_BA_Method()
{
	_STD mt19937 generator(time(nullptr));
	////Initialize basic graph with 2 connections
	////ki -> amout of connections at each vertex
	////kc -> amout of all connections

	const size_t N{20};
	_STD vector<_STD list<__int32>> people(2);
	//basic initialization
	people[0].push_back(1);
	people[1].push_back(0);
	//////////////////////////////////////////


	__int32 number_of_edges{ 1 };
	float kc{ };
	int tempsad{ };
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
			//_STD cout << probability << ' ';
			if (temp)
			{
				people[people.size() - 1].push_front(i);
				added = true;
			}
		}
		//_STD cout <<  NEW_LINE;
		if (added == false)
		{
			people[people.size() - 1].push_front(0);
		}


		system("cls");
		Display_Graph(people);
		system("pause");
	}



	//for (size_t i = 0; i < people.size(); ++i)
	//	{
	//		size_t cos = people[i].size();
	//		probability = static_cast<float>(cos / kc);
	//		//_STD cout << probability << NEW_LINE;
	//		_STD bernoulli_distribution prob(probability);
	//		bool temp = prob(generator);
	//		if (temp)
	//		{
	//			size_t temp{ people.size() };
	//			people.emplace_back(people.size());
	//			people[temp].push_back(i);
	//			++number_of_edges;
	//		}
	//	}





	//_STD vector<_STD pair<_STD vector<__int32>, __int32>> people(2);
	////basic initialization
	//people[0].first.emplace_back(1);
	//people[0].second = 1;
	//people[1].first.emplace_back(0);
	//people[1].second = 1;
	///////////////////////////////////


	//float kc{ };
	//int32_t sum{};
	//float probability{ };
	//while (people.size() < N)
	//{
	//	////count ki of each vertex
	//	//for (size_t i = 0; i < people.size(); ++i)
	//	//{
	//	//	people[i].second = people[i].first.size();
	//	//}
	//	//////////////////////////////////////////////////////////////////

	//	//count total kc
	//	for (size_t i = 0; i < people.size(); ++i)
	//	{
	//		sum += people[i].second;
	//	}
	//	kc = static_cast<float>(0.5f * sum);
	//	//////////////////////////////////////////////////////////////////
	//	//for (size_t i = 0; i < people.size(); ++i)
	//	//{
	//	//	probability = static_cast<float>(people[i].second / kc);
	//	//	_STD cout << probability << NEW_LINE;
	//	//}

	//	//Adding new vertex with kind of probability
	//	for (size_t i = 0; i < people.size(); ++i)
	//	{
	//		//count ki of each vertex
	//		for (size_t j = 0; j < people.size(); ++j)
	//		{
	//			people[j].second = people[j].first.size();
	//		}
	//		//probability = static_cast<float>(people[i].second / kc);
	//		////_STD cout << probability << NEW_LINE;
	//		//_STD bernoulli_distribution prob(probability);
	//		//bool temp = prob(generator);
	//		//if (temp)
	//		//{
	//		//	people.emplace_back(_STD make_pair(i,0));
	//		//	/*people[i].first.emplace_back(people.size());*/
	//		//}
	//	}

	//	Display_Graph(people);
	//	_STD cin.get();
	//	sum = 0;
	//}


}

const __int32 vertex_connections(bool Graph[100])
{
	__int32 connections{};

	for (size_t i = 0; i < 100; ++i)
	{
		if (Graph[i] == true)
		{
			connections++;
		}
	}
	return connections;
}

//void Display_Graph(const::std::vector<::std::pair<::std::vector<__int32>, __int32>>& people)
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

//Vertex::Vertex()
//{
//}
//
//Vertex::~Vertex()
//{
//}
