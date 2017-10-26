// Search Algorithm Header File
//==========================
// Header Gaurds
#ifndef SEARCH_ALG_H
#define SEARCH_ALG_H
//==========================
// Forward Declare


//==========================
// Include Declare

#include "node.h"
#include "eval.h"

//==========================
// Uniform Cost Search Algorithm Class

struct CompareCost {
	bool operator()(Node* n1, Node* n2) {
		return n1->get_Total() < n2->get_Total();
	}
};

class Search {

	protected:
		Eval* heuristic;
		priority_queue<Node*, vector<Node*>, CompareCost> prior_queue;
		Node* current;
		int grid_size;
	
		virtual void push_Node(Node* n);
		
	public:
		Search(vector<vector<int>> matr, int n);
		virtual bool is_Goal_State();
		virtual bool is_Empty();
		virtual void expand_Node();
		virtual void pop_Node();
		virtual void make_Queue() = 0;

};


class Uni_Cost: public Search {
		
	public:
		Uni_Cost(vector<vector<int>> matr, int n);
		virtual void make_Queue();
		virtual bool is_Goal_State();
};


class A_Star: public Search{
	
	public:
		A_Star(vector<vector<int>> matr, int n, Eval* e);
		virtual void make_Queue();
		virtual bool is_Goal_State();

};











#endif 
