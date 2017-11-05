//Node.cpp
//==================
// Include Declarations
#include <iostream>
#include <vector>
#include "node.h"
//==================

Node::Node(int ctn, vector<vector<int>> m, int last_move) {
	cost_to_node = ctn; //its parent cost + 1
	matrix = m; 
	this->last_move = last_move;
}

void Node::set_Estimate(int etg) {
	est_to_goal = etg;
	total = est_to_goal + cost_to_node;
	return;
}

int Node::get_Estimate() {
	return est_to_goal;
}

int Node::get_Prev_Move() {
	return last_move;
}

void Node::get_Matrix(vector<vector<int>>& m) {
	m = matrix; //pass by reference function
	return;
}

int Node::get_Total() {
	return total;
}

int Node::get_Cost_To_Node() {
	return cost_to_node;
}

bool Node::operator==(Node& n) {
	vector<vector<int>> matr2;
	n.get_Matrix(matr2);
	int grid_size = matrix.size(); //how big are the grids?
	//checks if each entry of A is equal to corresponding B
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			if ( matrix.at(i).at(j) != matr2.at(i).at(j) ) {
				return false; //something didn't match
			}
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Node& n) {
	int val; //makes outputting states simpler in meat of code
	for (unsigned int i = 0; i < n.matrix.size(); i++) {
		for (unsigned int j = 0; j < n.matrix.size(); j++) {
			val =  n.matrix.at(i).at(j);
			if (val == 0) {
				os << " b";
			}
			else {
				os << ' ' << val;
			}
		}
		os << endl;
	}
	return os;
}

//end node.cpp
