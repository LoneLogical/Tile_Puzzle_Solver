//Search Algorithm Cpp
//===================
// Forward Declare

//===================
//Include Declare
#include <queue>


#include "search_alg.h"
//===================

//Search Class

Search::Search(vector<vector<int>> matr, int n) {
	grid_size = n;	

	//make a node with the matrix
	current = new Node(0,matr);

}

bool Search::is_Empty() {
	return prior_queue.empty();
}

void Search::expand_Node() {
	//current should have been popped from prior queue
	vector<vector<int>> matr;
	current->get_Matrix(matr);

	//find row and col of blank tile
	int row, col;
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			if ( matr.at(i).at(j) == 0) {
				row = i;
				col = j;
			}
		}
	}

	Node* next_move = NULL;
	int ctn = current->get_Cost_To_Node();
	vector<vector<int>> update = matr;
	//using its location, which operaters are we allowed to perform?
	//move blank space up
	if (row > 0) {
		update.at(row).at(col) = update.at(row - 1).at(col);
		update.at(row - 1).at(col) = 0;
		//create new node using updated matr and incremented count
		next_move = new Node(ctn + 1, update);
		//pass along to push function	
		push_Node(next_move);		
		//reset update back to matr
		update = matr;
	}
	//move blank space down
	if (row < grid_size - 1) {
		update.at(row).at(col) = update.at(row + 1).at(col);
		update.at(row + 1).at(col) = 0;
		next_move = new Node(ctn + 1, update);

		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}
	//move blank space right
	if (col < grid_size - 1) {
		update.at(row).at(col) = update.at(row).at(col + 1);
		update.at(row).at(col + 1) = 0;
		next_move = new Node(ctn + 1, update);

		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}
	//move blank space left
	if (col > 0) {
		update.at(row).at(col) = update.at(row).at(col - 1);
		update.at(row).at(col - 1) = 0;
		next_move = new Node(ctn + 1, update);

		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}


	return;
}

void Search::pop_Node() {
	//get top of priorirt queue
	current = prior_queue.top();
	prior_queue.pop();

	cout << "The best state to expand with a g(n) = " << current->get_Cost_To_Node();
	cout << " and h(n) = " << current->get_Estimate() << " is ..." << endl;

	cout << *current << endl;

	cout << "    ...expanding node." << endl;

	return;
}

Search::~Search() {};
	

// Uniform Cost Search

Uni_Cost::Uni_Cost(vector<vector<int>> matr, int n) : Search(matr, n) {
	heuristic = new Misplaced();
}

void Uni_Cost::make_Queue() {
	//set heuristic to zero because this is uniform cost
	current->set_Estimate(0);
	//push beginning node onto the priority queue
	prior_queue.push(current);
	//reset current
	current = NULL;

	return;
}

bool Uni_Cost::is_Goal_State() {
	
	int count = heuristic->evaluate(current, grid_size);

	if (count == 0) {
		cout << "Found Goal State!" << endl;
		return true;
	}
	else {
		return false;
	}
}

void Uni_Cost::push_Node(Node* n) {
	//evetually, have hash function to detect repeated states
	
	//set estimate to zero because no heuristic
	n->set_Estimate(0);
	prior_queue.push(n);

	return;
}

Uni_Cost::~Uni_Cost() {};

// A_Star Search

A_Star::A_Star(vector<vector<int>> matr, int n, Eval* e) : Search(matr, n) {
	heuristic = e;
}

void A_Star::make_Queue() {
	// calculate heuristic for first node
	int est = heuristic->evaluate(current, grid_size);
	current->set_Estimate(est);
	//push beginning node onto the priority queue
	prior_queue.push(current);
	//reset current
	current = NULL;

	return;
}

bool A_Star::is_Goal_State() {
	
	int est = current->get_Estimate();

	if (est == 0) {
		cout << "Found Goal State!" << endl;
		return true;
	}
	else {
		return false;
	}
}

void A_Star::push_Node(Node* n) {
	//eventually have hash function to detect repeat states

	//find estimate using heuristic
	int est = heuristic->evaluate(n, grid_size);
	//pass estimate to the new node
	n->set_Estimate(est);
	//push onto the queue
	prior_queue.push(n);

	return;
}


A_Star::~A_Star() {};






