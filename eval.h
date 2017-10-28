//Eval.h
#ifndef EVAL_H
#define EVAL_H
//==================
// Forward Declarations
class Node;

//==================
// Include Declarations

//==================


class Eval {
	public:
		Eval() {};
		virtual int evaluate(Node* state, int n) = 0;
		
};


class Misplaced : public Eval {
	public:
		Misplaced() {};
		virtual int evaluate(Node* state, int n);

};

class Manhattan : public Eval {
	public:
		Manhattan() {};
		virtual int evaluate(Node* state, int n);

};


#endif

