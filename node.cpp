//Node.cpp
//================
// Forward Declarations
//==================
// Include Declarations
#include <iostream>
#include <vector>

#include "node.h"
//==================


Node::Node(int ctn, vector<vector<int>> m) {
	cost_to_node = ctn;
	matrix = m;
}

void Node::set_Estimate(int etg) {
	est_to_goal = etg;
	total = est_to_goal + cost_to_node;
	return;
}

int Node::get_Estimate() {
	return est_to_goal;
}

void Node::get_Matrix(vector<vector<int>>& m) {
	m = matrix;
	return;
}

int Node::get_Total() {
	return total;
}

int Node::get_Cost_To_Node() {
	return cost_to_node;
}

ostream& operator<<(ostream& os, const Node& n) {

	for (int i = 0; i < n.matrix.size(); i++) {
		for (int j = 0; j < n.matrix.size(); j++) {
			os << ' ' << n.matrix.at(i).at(j);
		}
		os << endl;
	}

	return os;
}

//end file
