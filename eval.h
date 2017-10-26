//Eval.h
#ifndef EVAL_H
#define EVAL_H
//==================


//==================
#include <vector>

//==================


class Eval {
	
	protected:
		
	public:
		Eval() {};
		virtual int evaluate(vector<vector<int>> matr, int n) = 0;
		
};


class Misplaced : public Eval {

	public:
		Misplaced() {};
		virtual int evaluate(vector<vector<int>> matr, int n);

};

class Manhattan : public Eval {

	public:
		Manhattan() {};
		virtual int evaluate(vector<vector<int>> matr, int n);

};


#endif

