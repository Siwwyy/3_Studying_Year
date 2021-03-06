#ifndef _DJIKSTRA_HPP_
#define _DJIKSTRA_HPP_
#pragma once


/*
 *			   Copyright (c) by Damian Andrysiak. All rights reserved.
 *					I hope that alghoritm will make right work
 *							Greetings for everyone!
*/

#include <iostream>
#include <vector>
#include <math.h>

//#define NEW_LINE '\n'

//CLASS OF _Djikstra_Element, for inserting values

class _Djikstra_Element
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	int Verticle;
	int Cost;
	int Edge;
	bool visited_or_not;
	//////////////////////////////////
	int* Connections;
	size_t _Connections_size;
	//////////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////////////////////////////////////////////////////
	/*
		KONSTRUKTORY PUBLIC
	*/
	_Djikstra_Element();
	_Djikstra_Element(const int Verticle, const int Cost, const int Edge);
	_Djikstra_Element(const _Djikstra_Element& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/

	//////////////////////////////////////////////////////////////////////////////
	/*
		SETTERY PUBLIC
	*/
	void set_connections_size(const size_t _Connections_size);
	void set_connection(const int value, const size_t counter);
	void set_way(const int destination, const int way_lenght);
	void set_verticle(const int verticle);
	void set_cost(const int cost);
	void set_edge(const int edge);
	void set_visited_or_not(const bool visited_or_not);
	void print_connections() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		OPERATORY PUBLIC
	*/
	//JEDNOARGUMENTOWE
	_Djikstra_Element& operator=(const _Djikstra_Element& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		GETTERY PUBLIC
	*/
	int get_verticle() const;
	int get_cost() const;
	int get_edge() const;
	bool get_visited_or_not() const;
	size_t get_connections_size() const;
	int& get_connections_array(const size_t counter) const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Djikstra_Element();
};

//CLASS OF _Djikstra

class _Djikstra
{
private:
	//////////////////////////////////////////////////////////////////////////////
	/*
		ZMIENNE PRIVATE
	*/
	/////////////////////////////////////////////////////////////////////////
	_Djikstra_Element* Graph;
	size_t _Graph_lenght;
	/////////////////////////////////////////////////////////////////////////
	_Djikstra_Element* Djikstra_Matrix;
	size_t _Djikstra_Matrix_lenght;
	//////////////////////////////////////////////////////////////////////////////
	int* Visited_Nodes;
	size_t _Visited_Nodes_lenght;
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
	_Djikstra();
	_Djikstra(const size_t _Graph_lenght);
	_Djikstra(const _Djikstra& Object);
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void push(const int value, const int destination, const int way_lenght);
	void push_directions(const int from, const int to, const int way_lenght);
	void minimal_spanning_tree_creator(const int the_beginning);
	void get_results();
	void print_graph() const;
	void print_djikstra_matrix() const;
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
	_Djikstra& operator=(const _Djikstra& Object);
	//DWUARGUMENTOWE
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Djikstra();
};

//////////////////////////////////////////////////////////////////////////////

//FUNCTION FOR INSERTING VALUES FROM file_in
void inserter_DJIKSTRA(const _STD vector<__int32>& file_content);
//////////////////////////////////////////////////////////////////////////////

#endif /* _DJIKSTRA_HPP_ */