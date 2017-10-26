//Node.h
//==========================
//Include Guard
#ifndef NODE_H
#define NODE_H


//==========================


//=========================
#include <vector>

//=========================

class Node {

	private:
		int cost_to_node;
		int est_to_goal;
		int total;
		vector<vector<int> matrix;

	public:
		Node(int ctn, vector<vector<int>> m);
		
		void set_Estimate(int etg);
		int get_Estimate();
		void get_Matrix(vector<vector<int>>& m);
		int get_Total();
		

};



#endif
