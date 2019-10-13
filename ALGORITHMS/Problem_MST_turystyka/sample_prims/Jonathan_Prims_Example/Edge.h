#ifndef EDGE_HPP
#define EDGE_HPP
#include <iostream>
#include <vector>

class Edge {
	std::vector<char> nodes_;
	int weight_ = 0;

public:
	// will only ever have two elements, so this is a cheap copy
	std::vector<char> GetNodes() const; 
	int GetWeight() const;
	void Print();
	Edge(char node1, char node2, int weight);
};

bool operator< (Edge const &left, Edge const &right);
#endif