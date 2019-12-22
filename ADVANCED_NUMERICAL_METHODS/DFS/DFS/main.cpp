#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <stack>

#define NEW_LINE '\n'

void Print_Matrix(const bool matrix[10][10]);
void DFS(bool matrix[10][10]);

int main(int argc, char* argv[])
{
	using _STD cout;
	using _STD endl;

	bool matrix[10][10]
	{ 
		{0,1,0,1,0,0,0,0,0,0},//1
		{1,0,1,0,1,0,1,1,0,0},//2
		{0,1,0,1,0,0,0,0,1,1},//3
		{1,0,1,0,0,0,0,0,0,0},//4
		{0,1,0,0,0,1,1,1,0,0},//5
		{0,0,0,0,1,0,0,0,0,0},//6
		{0,1,0,0,1,0,0,1,0,0},//7
		{0,1,0,0,1,0,1,0,0,0},//8
		{0,0,1,0,0,0,0,0,0,0},//9
		{0,0,1,0,0,0,0,0,0,0},//10
	};

	Print_Matrix(matrix);
	_STD cout << "=======================" << NEW_LINE;
	DFS(matrix);
	_STD cout << "=======================" << NEW_LINE;
	Print_Matrix(matrix);

	system("pause");
	return 0;
}

void Print_Matrix(const bool matrix[10][10])
{
	for (size_t i = 0; i < 7; ++i)
	{
		for (size_t j = 0; j < 7; ++j)
		{
			_STD cout << matrix[i][j] << ' ';
		}
		_STD cout << NEW_LINE;
	}
}

void DFS(bool matrix[10][10])
{
	_STD stack<bool> dfs_stack{};
	__int16 dfs_visited[10]{};
	__int16 dfs_visited_second[10]{};
	size_t dfs_visited_second_counter{};
	size_t connection_counter{};
	size_t dfs_visited_counter{};
	size_t vertex_position{};

	//Choose starting vertex
	//In this case I choose first nr 1, initial step
	dfs_visited_counter = 0;
	dfs_visited[dfs_visited_counter] = 1;
	dfs_visited_second[dfs_visited_second_counter] = 1;
	++dfs_visited_second_counter;

	for (size_t i = 0; i < 10; ++i)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			if (matrix[vertex_position][j] == 1)
			{
				++connection_counter;
				matrix[vertex_position][j] = 0;
				vertex_position = j;
				break;
			}
		}
		if (connection_counter > 0)
		{
			dfs_stack.push(dfs_visited[dfs_visited_counter]);
			dfs_visited_counter = vertex_position;
			dfs_visited[dfs_visited_counter] = (vertex_position + 1);
			dfs_visited_second[dfs_visited_second_counter] = (vertex_position + 1);
			++dfs_visited_second_counter;
		}
		else
		{
			dfs_stack.top() = dfs_visited_counter;
		}
		connection_counter = NULL;
	}

	for (size_t i = 0; i < 10; ++i)
	{
		_STD cout << dfs_visited_second[i] << " ";
	}
	_STD cout << NEW_LINE;
}
