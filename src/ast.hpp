#ifndef __AST__
#define __AST__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
class Node {
public:
	virtual ~Node() 
	{};
};

class Expression : public Node {
public:
	virtual std::string print();
};

class BinaryExpression : public Expression { 
private:
	Expression* left;
	std::string op;
	Expression* right;
	
public:
	BinaryExpression(Expression *left_in, const std::string &op_in, Expression *right_in) : 
	left(left_in), op(op_in) , right(right_in)
	{};

	std::string print() {
		std::stringstream ss;
		ss << left->print() << op << right->print();
		return ss.str();
	}
};

class Identifier : public Expression {
private:
	std::string name;
public:
	Identifier(std::string name_in) : 
	name(name_in)
	{};

	std::string print() {
		return name;
	}
};

class ConstantValue : public Expression {
private:
	int value;
public:
	ConstantValue(int value_in) :
	value(value_in)
	{};

	std::string print() {
		std::stringstream ss;
		ss << value;
		return ss.str();
	}
};

#endif