//Search Algorithm Cpp
//===================
// Forward Declare

//===================
//Include Declare
#include <queue>
#include <algorithm>
#include <fstream>

#include "search_alg.h"
//===================

//Search Class

Search::Search(vector<vector<int>> matr, int n) {
	grid_size = n; 
	time_complex = 0; //num of nodes expanded
	mem_complex = 0; //max size of the priority queue
	//make a node with (cost = 0, input matrix, and no prev move) 
	current = new Node(0, matr, 0);
	hash_size = 30011; //large prime number for size of hash table
	hashtable = new list<Node*>[hash_size];
	//to test how well the hash function works
	hash_cnt.resize(hash_size, 0);
}

bool Search::is_Empty() {
	return prior_queue.empty();
}

void Search::expand_Node() {
	//current should have been popped from prior queue
	vector<vector<int>> matr;
	current->get_Matrix(matr); //grab current's state
	//what was the direction of last move? up, down, right or left?
	int prev = current->get_Prev_Move(); 

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
	//move blank space up -- UP == 1
	// as long as previous wasnt down
	if ( (row > 0)  && (prev != 2) ) { 
		update.at(row).at(col) = update.at(row - 1).at(col);
		update.at(row - 1).at(col) = 0;
		//create new node using updated matr and incremented count
		next_move = new Node(ctn + 1, update, 1);
		//pass along to push function	
		push_Node(next_move);		
		//reset update back to matr
		update = matr;
	}
	//move blank space down -- DOWN == 2
	// as long as prev wasnt up
	if ( (row < grid_size - 1) && (prev != 1) ) {
		update.at(row).at(col) = update.at(row + 1).at(col);
		update.at(row + 1).at(col) = 0;
		next_move = new Node(ctn + 1, update, 2);
		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}
	//move blank space right -- RIGHT == 3
	// as long as prev wasnt left
	if ( (col < grid_size - 1) && (prev != 4) ) {
		update.at(row).at(col) = update.at(row).at(col + 1);
		update.at(row).at(col + 1) = 0;
		next_move = new Node(ctn + 1, update, 3);
		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}
	//move blank space left -- LEFT == 4
	// as long as prev wasn't right
	if ( (col > 0) && (prev != 3) ) {
		update.at(row).at(col) = update.at(row).at(col - 1);
		update.at(row).at(col - 1) = 0;
		next_move = new Node(ctn + 1, update, 4);
		push_Node(next_move);
		//reset update back to matr
		update = matr;
	}

	return;
}

void Search::print_Stats(bool failed) {

	cout << "To solve this problem, the search algorithm expanded a total of "
		<< time_complex << " nodes. " << endl;
	cout << "The maximum number of nodes in the queue at any one time was "
		<< mem_complex << " nodes. " << endl;
	
	if (!failed) {
		cout << "The depth of the goal node was " << current->get_Cost_To_Node() << endl;
	}

	ofstream ofs("hash_cnt.txt");
	double cnt1 = 0;
	for (int i = 0; i < hash_size; i++) {
		if (hashtable[i].size() > 0) { 
			ofs << i << ") " << hashtable[i].size() << endl;
			cnt1 = cnt1 + 1;
		}
	}

	ofs << "cnt: " << cnt1;
	ofs << "frac: " << cnt1 / hash_size << endl;

	ofs.close();

	return;
}

void Search::remove_Front() {
	//check how big the current priority queue is for stats
	int curr_size = prior_queue.size();
	mem_complex = max(mem_complex, curr_size);
	//get top of priority queue
	current = prior_queue.top();
	prior_queue.pop();
	time_complex++; //increment number of nodes expanded

	cout << "The best state to expand with a g(n) = " << current->get_Cost_To_Node();
	cout << " and h(n) = " << current->get_Estimate() << " is ..." << endl;

	cout << *current << endl;

	cout << "    ...expanding node." << endl;

	return;
}

int Search::hash_function(Node* n) {
	vector<vector<int>> matr;
	n->get_Matrix(matr); //grab state from the node

	int hash = 0; 
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			//mixes value of tile, the position in the grid,
			//   and what order they were seen in
			hash = (grid_size * grid_size) * hash + matr.at(i).at(j);
		}
	}
	// don't need too many buckets, so mod by some large prime number
	return (hash % hash_size);
}

bool Search::is_Repeated(Node* n) {
	int hash_val = hash_function(n); //get hash value
	// create iterator for the linked list and container for holding nodes
	Node* compare = NULL;
	list<Node*>::iterator iter = hashtable[hash_val].begin();
	//iterate through the bucket
	while ( iter != hashtable[hash_val].end() ) {
		compare = *iter;
		if ( *n == *compare) {
			// == operator overloaded to check if states were equal
			return true;
		}
		iter++;
	}
	return false;
}

void Search::push_Hash(Node* n) {
	// once you found a state that has yet to be seen
	int hash_val = hash_function(n);
	//update the hash table
	hashtable[hash_val].push_back(n);
	return;
}

Search::~Search() {}; //poor programming on my part
	
//=====================================================================
// Uniform Cost Search

Uni_Cost::Uni_Cost(vector<vector<int>> matr, int n) : Search(matr, n) {
	heuristic = new Misplaced();
}

void Uni_Cost::make_Queue() {
	//set heuristic to zero because this is uniform cost
	current->set_Estimate(0);
	//push beginning node onto the priority queue
	prior_queue.push(current);
	//add state to hash table
	push_Hash(current);
	//reset current
	current = NULL;
	return;
}

bool Uni_Cost::is_Goal_State() {
	// ask heuristic obj to evaluate current state	
	int count = heuristic->evaluate(current, grid_size);
	if (count == 0) { //count of 0 means no misplaced tiles
		cout << "Found Goal State!" << endl;
		return true;
	}
	else {
		return false;
	}
}

void Uni_Cost::push_Node(Node* n) {
	//detect if repeated state
	if ( !is_Repeated(n) ) {
		// not repeated -> push onto queue
		//set estimate to zero because no heuristic
		n->set_Estimate(0);
		prior_queue.push(n);
		push_Hash(n);
	}
	return;
}

Uni_Cost::~Uni_Cost() {};

//====================================================================
// A_Star Search

A_Star::A_Star(vector<vector<int>> matr, int n, Eval* e) : Search(matr, n) {
	//used strategy pattern, can choose heuristic at runtime
	heuristic = e;
}

void A_Star::make_Queue() {
	// calculate heuristic for first node
	int est = heuristic->evaluate(current, grid_size);
	current->set_Estimate(est);
	//push beginning node onto the priority queue
	prior_queue.push(current);
	push_Hash(current);
	//reset current
	current = NULL;
	return;
}

bool A_Star::is_Goal_State() {
	//already computed heurisitc, ask if node's eval is 0	
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
	if ( !is_Repeated(n) ) {
		//not repeated ->push onto queue
		//find estimate using heuristic
		int est = heuristic->evaluate(n, grid_size);
		//pass estimate to the new node
		n->set_Estimate(est);
		//push onto the queue
		prior_queue.push(n);
		push_Hash(n);
	}
	return;
}


A_Star::~A_Star() {};

//end search_alg.cpp
