//Node.h
//==========================
//Include Guard
#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_
//=========================
// Include Declarations
#include <iostream>
#include <vector>
using namespace std;
//=========================
class Node {
	private:
		int cost_to_node; 
		int est_to_goal;
		int total;
		int last_move; //what move discovered me?
		vector<vector<int>> matrix; //holds state
	public:
		Node(int ctn, vector<vector<int>> m, int last);
		//getters and setters of the node class variables
		void set_Estimate(int etg);
		int get_Estimate();
		void get_Matrix(vector<vector<int>>& m);
		int get_Total();
		int get_Cost_To_Node();
		int get_Prev_Move();
		bool operator==(Node& n); //allows us to have simple method
		// for comparison of node. only checks if states are equal
		friend ostream& operator<<(ostream& os, const Node& n);	
};

#endif
