//Eval.h
#ifndef EVAL_H
#define EVAL_H
//==================
// Forward Declarations
class Node;
//==================
// Eval is a base class with single function to evaluate node
class Eval {
	public:
		Eval() {};
		virtual int evaluate(Node* state, int n) = 0;
		
};
// Using strategy pattern by creating objects for two functions
//	that perform similar tasks in two ways
//	allows user to choose heuristic at runtime
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

