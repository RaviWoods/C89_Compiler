#ifndef __ASTASSIGEXP__
#define __ASTASSIGEXP__

#include "headers.hpp"


class AssignmentExp : public Expression { 
private:
	Expression* left;
	std::string op;
	Expression* right;
	
public:
	AssignmentExp(Expression *left_in, const std::string &op_in, Expression *right_in) : 
	left(left_in), op(op_in) , right(right_in)
	{};


};

#endif