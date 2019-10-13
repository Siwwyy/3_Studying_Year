#include "Edge.h"
std::vector<char> Edge::GetNodes() const {
	return nodes_;
}

int Edge::GetWeight() const {
	return weight_;
}

void Edge::Print() 
{
	std::cout << nodes_[0] << "-- " << (weight_ < 0 ? -weight_ : weight_) << " --" << nodes_[1] << "\n";
}

Edge::Edge(char node1, char node2, int weight) : nodes_{node1, node2} {
	if (node1 == node2) {
		throw std::runtime_error("Invalid edge: no loops allowed");
	}
	weight_ = weight;
}

bool operator< (Edge const &left, Edge const &right) {
	return std::make_pair(left.GetWeight(), left.GetNodes()) < std::make_pair(right.GetWeight(), right.GetNodes());
}