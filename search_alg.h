// Search Algorithm Header File
//==========================
// Header Gaurds
#ifndef SEARCH_ALG_H
#define SEARCH_ALG_H
//==========================
// Include Declare
#include <queue>
#include <list>
#include "node.h"
#include "eval.h"
//==========================
// Uniform Cost Search Algorithm Class

struct CompareCost { //for the priority queue to compare nodes
	bool operator()(Node* n1, Node* n2) {
		return n1->get_Total() > n2->get_Total();
	}
};

class Search {
	protected:
		Eval* heuristic;
		priority_queue<Node*, vector<Node*>, CompareCost> prior_queue;
		Node* current;
		int grid_size;
		int time_complex;
		int mem_complex;
		list<Node*> * hashtable;
		int hash_size;

		int hash_function(Node* n);
		bool is_Repeated(Node* n);
		void push_Hash(Node* n);
		vector<int> hash_cnt;

	public: //function to be called by general search algorithm
		Search(vector<vector<int>> matr, int n);
		virtual bool is_Empty();
		virtual void expand_Node();
		virtual void remove_Front();
		virtual void print_Stats(bool failed);
		virtual bool is_Goal_State() = 0;
		virtual void push_Node(Node* n) = 0;
		virtual void make_Queue() = 0;
		virtual ~Search();
};
// Uniform Cost and A_Star derive most of their
//	functions from the Parent search class
//	but have some differences
class Uni_Cost: public Search {
	public:
		Uni_Cost(vector<vector<int>> matr, int n);
		virtual void make_Queue();
		virtual bool is_Goal_State();
		virtual void push_Node(Node* n);
		~Uni_Cost();
};

class A_Star: public Search{
	public:
		A_Star(vector<vector<int>> matr, int n, Eval* e);
		virtual void make_Queue();
		virtual bool is_Goal_State();
		virtual void push_Node(Node* n);
		~A_Star();
};


#endif 
