//Eval.cpp
//==================
// Include Dependencies
#include <vector>
#include <stdlib.h>

#include "eval.h"
#include "node.h"
//==================

int Misplaced::evaluate(Node* state, int n) {
	//grab the state from the node passed in
	vector<vector<int>> matr;
	state->get_Matrix(matr);
	int count = 0; //counts misplaced tiles
	int row, col, val;
	//iterate through the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			val = matr.at(i).at(j); 
			if (val != 0) { //dont count the blank space
				row = (val - 1) / n; //find proper row
				col = (val - 1) % n;   //and column of this value
				if ( (row != i) || (col != j) ) {
					count++; //didn't match where it actually is
				}
			}
		}
	}
	return count;
}


int Manhattan::evaluate(Node* state, int n) {
	vector<vector<int>> matr;
	state->get_Matrix(matr); //grab state from node
	int sum = 0; //counts total distance
	int prop_row, prop_col, val;
	//iterate through the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			val = matr.at(i).at(j);
			if (val != 0) { //dont count the blank space
				prop_row = (val - 1) / n; //find proper row and
				prop_col = (val - 1) % n; // col of this value
				sum += abs(prop_row - i) + abs(prop_col - j);
	//take abs dist in x and y directions and add them to running total
			}
		}
	}
	return sum;
}

//end eval.cpp
