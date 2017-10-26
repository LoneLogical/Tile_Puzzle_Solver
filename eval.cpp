//Eval.cpp

//==================


//==================


int Misplaced::evaluate(vector<vector<int>> matr, int n) {

	int count = 0;
	int row,col;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			row = (matr.at(i,j) - 1) / n;
			col = (matr.at(i,j) - 1) % n;
			if ( (row != i) || (col != j) ) {
				count++;
			}
		}
	}

	return count;
}


int Manhattan::evaluate(vector<vector<int>> matr, int n) {

	int sum = 0;
	int prop_row, prop_col, val;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			val = matr(i,j);
			prop_row = (val - 1) / n;
			prop_col = (val - 1) % n;

			sum += abs(prop_row - i) + abs(prop_col - j);

		}
	}

	return sum;
}

	




