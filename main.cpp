// General Search Algorithm 
//==============================
#include <iostream>
#include <vector>
#include <sstream>

#include "node.h"
#include "eval.h"
#include "search_alg.h"
//==============================

using namespace std;


void general_search(Search* search);


int main() {

	vector<vector<int>> init;
	vector<int> tmp;
	int puzzle, grid_size;
	Search* search = NULL;

	cout << "Welcome to Andrew Whitaker's 8 puzzle solver" << endl;
	cout << "	Type '1' to use the default puzzle or '2' to enter your own." << endl;
	cin >> puzzle;

	if (puzzle == 1) { //hard code the default
		tmp = {1, 2, 3};
		init.push_back(tmp);
		tmp = {4, 0, 6};
		init.push_back(tmp);
		tmp = {7, 5, 8};
		init.push_back(tmp);
		grid_size = 3;
	}
	else if (puzzle == 2) {
		//only allows for a 3x3 matrix at the moment
		int tile;
		string input;
		stringstream ss;

		cout << "Enter your puzzle, use a zero to represent the blank." << endl;
		cout << "Enter the first row, use space between numbers." << endl;

		cin.ignore(1000, '\n');
		getline(cin, input);
		ss.str(input);
		
		for (int i = 0; i < 3; i++) {
			ss >> tile;
			tmp.push_back(tile);
		}
		init.push_back(tmp);
		tmp.clear();
		ss.clear();

		cout << "Enter the second row, use space between numbers." << endl;
		
		getline(cin, input);
		ss.str(input);
		
		for (int i = 0; i < 3; i++) {
			ss >> tile;
			tmp.push_back(tile);
		}
		init.push_back(tmp);
		tmp.clear();
		ss.clear();

		cout << "Enter the third row, use space between numbers." << endl;
		
		getline(cin, input);
		ss.str(input);
		
		for (int i = 0; i < 3; i++) {
			ss >> tile;
			tmp.push_back(tile);
		}
		init.push_back(tmp);
		tmp.clear();
		ss.clear();

		grid_size = 3;

	}
	else {
		cout << "ERROR: incorrect input." << endl;
		return 1;
	}

	//find algorithm and heuristic to use
	cout << "Enter your choice of algorithm." << endl;
	cout << "  1) Uniform Cost Search" << endl;
	cout << "  2) A* using Misplaced Tiles heuristic." << endl;
	cout << "  3) A* using Manhattan Distance heuristic." << endl;
	cin >> puzzle;

	if (puzzle == 1) {
		search = new Uni_Cost(init, grid_size);
	}
	else if (puzzle == 2) {
		Eval* eval = new Misplaced();
		search = new A_Star(init, grid_size, eval);
	}
	else if (puzzle == 3) {
		Eval* eval = new Manhattan();
		search = new A_Star(init, grid_size, eval);
	}
	else {
		cout << "ERROR: Incorrect input." << endl;
	}

	//feed to general_search function
	general_search(search);

	return 0;
}


void general_search(Search* search) {
	//tell search obj to make the queue by pushing the original state
	search->make_Queue();
	
	bool finished = false; 

	while (!finished) {
		//check if the queue is empty before popping top node
		if ( search->is_Empty() ) {
			finished = true;
			search->print_Stats(true);
		}
		else {
			//grabs front of the queue
			search->remove_Front();
			//cehck if it is the goal state
			if ( search->is_Goal_State() ) {
				//reached goal
				finished = true;
				search->print_Stats(false);
			}
			else { //expand nodes
				search->expand_Node();
			}
		}

	} //while loop close

	return;
}






//end general Search file
//============================================
