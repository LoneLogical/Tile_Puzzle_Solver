//Search Algorithm Cpp
//===================


//===================


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

}

void Search::pop_Node() {
	//get top of priorirt queue
	current = prior_queue.top();
	prior_queue.pop();
	
	return;
}

void Search::push_Node() {

}


	

// Uniform Cost Search

Uni_Cost::Uni_Cost(vector<vector<int> matr, int n) : Search(matr, n) {
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
		return true;
	}
	else {
		return false;
	}
}



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
		return true;
	}
	else {
		return false;
	}
}



















































