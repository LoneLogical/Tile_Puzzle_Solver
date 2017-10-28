//Node.h
//==========================
//Include Guard
#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_
//==========================
// Forward Declarations

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
		vector<vector<int>> matrix;

	public:
		Node(int ctn, vector<vector<int>> m);
		
		void set_Estimate(int etg);
		int get_Estimate();
		void get_Matrix(vector<vector<int>>& m);
		int get_Total();
		int get_Cost_To_Node();
		friend ostream& operator<<(ostream& os, const Node& n);	

};



#endif
