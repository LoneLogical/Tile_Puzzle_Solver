// General Search Algorithm 



//==============================




//==============================


void general_search(vector<vector<int>> state);


int main() {

	//take in matrix and make sure correct sizing

	//find algorithm and heuristic to use

	//create search object
	Search* search();
	//feed to general_search function

	return 0;
}


void general_search(Search* search) {
	
	search->make_Queue();
	
	bool finished = false; 
	bool failed = false;

	while (!finished) {

		if ( search->is_Empty() ) {
			failed = true;
			finished = true;
		}
		else {
			
			search->pop_Node();
			
			if ( search->is_Goal_State() ) {
				//reached goal
				finished = true;

			}
			else {
				search->expand_Node();
			}
		}			

	}



	return;
}






//end general Search file
//============================================
