#include "minSpanningTree.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <windows.h>

int main(int argc, char *argv) try {
	AdjacencyList adjacency;
	system("pause");
	const char *a = "file.in";
	int num_nodes = ReadInputOrDie(argc, "file.in", &adjacency);
	system("pause");
	std::cout << "Graph read from file: \n";
	for (auto begin = adjacency.begin(); begin != adjacency.end(); begin++) {
		for (Edge edge : begin->second) {
			auto nodes = edge.GetNodes();
			//don't print duplicates
			if (nodes[1] > nodes[0]) {
				edge.Print();
			}
		}
	}system("pause");

	std::cout << "Minimum Spanning Tree:\n";
	SpanningTree mst(num_nodes, adjacency);
	if (mst.BuildMinSpanningTree()) {
		for (Edge edge : *mst.GetOptimalEdgeList()) {
			edge.Print();
		}
	}
	std::cout << "MST Weight: " << mst.GetWeight() << "\n";
}
catch (std::exception &e) {
	std::cerr << "Error: " << e.what() << "\n";
	return -1;
} 
catch (...) {
	std::cerr << "unknown error\n";
	return -1;

	system("pause");
}