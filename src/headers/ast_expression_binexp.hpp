#ifndef __ASTBINEXP__
#define __ASTBINEXP__

#include "headers.hpp"


class BinaryExpression : public Expression { 
private:
	Expression* left;
	std::string op;
	Expression* right;
	
public:
	BinaryExpression(Expression *left_in, const std::string &op_in, Expression *right_in) : 
	left(left_in), op(op_in) , right(right_in)
	{};


};

#endif