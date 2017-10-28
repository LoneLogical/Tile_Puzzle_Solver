//Eval.cpp

//==================
#include <vector>
#include <stdlib.h>

#include "eval.h"
#include "node.h"
//==================


int Misplaced::evaluate(Node* state, int n) {

	vector<vector<int>> matr;
	state->get_Matrix(matr);

	int count = 0;
	int row, col, val;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			val = matr.at(i).at(j);
			if (val == 0) {
				// Alter table slightlty for better computation
				// change blank tile to number of n squared
				val = n * n;
			}
			row = (val - 1) / n;
			col = (val - 1) % n;
			if ( (row != i) || (col != j) ) {
				count++;
			}
		}
	}

	return count;
}


int Manhattan::evaluate(Node* state, int n) {

	vector<vector<int>> matr;
	state->get_Matrix(matr);

	int sum = 0;
	int prop_row, prop_col, val;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			val = matr.at(i).at(j);
			if (val == 0) {
				val = n * n;
			}
			prop_row = (val - 1) / n;
			prop_col = (val - 1) % n;

			sum += abs(prop_row - i) + abs(prop_col - j);

		}
	}

	return sum;
}

	




