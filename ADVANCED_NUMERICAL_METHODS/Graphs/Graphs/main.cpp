#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <map>
#include <fstream>

#define NEW_LINE '\n'

void Set_Connections(bool Graph[100][100]);
void Print_Graph(bool Graph[100][100]);


int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;

	bool Graph[100][100]{ false };

	//Print_Graph(Graph);
	Set_Connections(Graph);
	//Print_Graph(Graph);

	_STD fstream file_out{};
	file_out.open("out.csv", _STD ios_base::out);
	_STD map<int, int> histo{};
	size_t sum{};
	for (size_t i = 0; i < 100; ++i)
	{
		size_t counter{};
		_STD cout << (i + 1) << ' ';
		for (size_t j = 0; j < 100; ++j)
		{
			if (Graph[i][j] == true)
			{
				_STD cout << "=";
				counter++;
			}
	/*		else
			{
				_STD cout << "+";
			}*/
		}
		sum += counter;
		histo[counter]++;
		_STD cout << " " << counter;
		//file_out << counter << NEW_LINE;
		_STD cout << NEW_LINE;
	}

	for (typename _STD map<int, int>::iterator map_iterator = histo.begin(); map_iterator != histo.end(); ++map_iterator)
	{
		file_out << map_iterator->first << ',' << map_iterator->second << NEW_LINE;
	}


	_STD cout << "Average: " << static_cast<float>(sum/100.f) << NEW_LINE;
	file_out << "Average: ," << static_cast<float>(sum/100.f) << NEW_LINE;

	file_out.close();

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
