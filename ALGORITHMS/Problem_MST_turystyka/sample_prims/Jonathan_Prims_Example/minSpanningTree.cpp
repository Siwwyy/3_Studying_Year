#include "minSpanningTree.h"
#include <cstdio>
#include <string>
SpanningTree::SpanningTree(int num_nodes, AdjacencyList const &adjacency) : num_nodes_(num_nodes), adjacency_(adjacency) {
	if (num_nodes <= 1) {
		std::cerr << "Warning: empty spanning tree created.\n";
	}
	weight_ = 0;
}

EdgeSet const *SpanningTree::GetOptimalEdgeList() const {
	if (edge_set_.empty()) {
		std::cerr << "Warning: min spanning tree either hasn't been built or doesn't exist.  Returning empty set.\n";
	} 
	return &edge_set_;
}

int SpanningTree::GetWeight() const {
	return weight_;
}

bool SpanningTree::SubtreeIncludesNode(char node) const {
	return nodes_in_subtree_.find(node) != nodes_in_subtree_.end();
}

//must add to node set, edge set, and expand prospective new edges
void SpanningTree::AddEdgeToSubtree(Edge const &edge, std::priority_queue<Edge> *edge_queue, EdgeSet *prospective_edge_set) {
	edge_set_.insert(edge);
	weight_ -= edge.GetWeight();

	auto nodes = edge.GetNodes();
	char toExpand = SubtreeIncludesNode(nodes[0]) ? nodes[1] : nodes[0];
	nodes_in_subtree_.insert(toExpand);

	for (Edge new_edge : adjacency_.find(toExpand)->second) {
		if (prospective_edge_set->find(new_edge) == prospective_edge_set->end()) {
			edge_queue->push(new_edge);
			prospective_edge_set->insert(new_edge);
		}
	}
}

/* Since Prim's algorithm maintains a connected subtree of the graph, and a
 * tree has exactly one path from each node to each other node, if a prospective
 * edge is between two nodes already in the subtree, it is a second path between
 * those two nodes and so creates a cycle.
 */
bool SpanningTree::MakesACycle(Edge const &prospective_edge) const {
	auto nodes = prospective_edge.GetNodes();
	return SubtreeIncludesNode(nodes[0]) && SubtreeIncludesNode(nodes[1]);
}

bool SpanningTree::BuildMinSpanningTree() {
	//uses Prim's algorithm to build a minimum spanning tree.  
	//returns true if the graph contains a minimial or minimum spanning tree, 
	//returns false if not (ie it isn't a connected graph)
	if (edge_set_.size() > 0) {
		std::cerr << "Min spanning tree has already been built!\n";
		return true;
	}

	int num_edges_left = num_nodes_ - 1;

	//start by adding node A to the empty subtree
	nodes_in_subtree_.insert('A');

	auto first_edges = adjacency_.find('A')->second;
	EdgeSet prospective_edge_set(first_edges.begin(), first_edges.end());
	std::priority_queue<Edge> edge_queue(first_edges.begin(), first_edges.end());

	while(num_edges_left > 0) {
		if (edge_queue.empty()) {
			std::cerr << "No spanning tree exists.";
			return false;
		}

		//pop returns void and top is a peek
		Edge prospective_edge = edge_queue.top();
		edge_queue.pop();
		prospective_edge_set.erase(prospective_edge);

		if(!MakesACycle(prospective_edge)) {
			--num_edges_left;
			AddEdgeToSubtree(prospective_edge, &edge_queue, &prospective_edge_set);
		}
	}
	return true;
}

void AddToEdgeList(char row, char col, std::string const &weight, std::vector<Edge> &edges_from_row) {
	edges_from_row.push_back(Edge(row, col, -std::stoi(weight)));
}

int ReadInputOrDie(int argc, std::string argv, AdjacencyList *adjacency) {
	//if (argc < EXPECTED_NUM_INPUTS) {
	//	throw std::runtime_error("Not enough arguments, needs a filename of adjacency matrix");
	//}

	std::string filename(argv);
	std::ifstream input_file(filename);
	//system("pause");
	int num_nodes;

	if(input_file) {
		input_file >> num_nodes;
		input_file.get();

		//read adjacency matrix
		char row = 'A', col;

		//we must read in edges in both direction to account for order of access
		for (std::string line; std::getline(input_file, line); ) {
			std::stringstream weight_stream(line);
			col = 'A';
			std::vector<Edge> edges_from_row;
			
			for (std::string weight; std::getline(weight_stream, weight, ','); ) {
				if (weight == NO_EDGE) {
					col++;
					continue;
				} else if (col >= 'A' + num_nodes) {
					throw std::runtime_error("Too many columns in adjacency matrix.");
				}
				AddToEdgeList(row, col, weight, edges_from_row);
				col++;
			}

			if (col < 'A' + num_nodes - 1) {
				//system("pause");
				throw std::runtime_error("Too few columns in adjacency matrix or improperly formatted file.");
			}
			//system("pause");
			(*adjacency)[row] = edges_from_row;
			row++;
		}
	} else {
		//system("pause");
		throw std::runtime_error("File not found.");
		//system("pause");
	}
	return num_nodes;
	//system("pause");
}