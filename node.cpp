//Node.cpp

//================


//==================
#include "node.h"


//==================


Node::Node(int ctn, vector<vector<int>>& m) {
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

int Node::get_Total() {
	return cost_to_node;
}





//end file
