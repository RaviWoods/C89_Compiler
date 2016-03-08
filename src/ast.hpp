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
	virtual std::string print()=0;
private:
};

class Expression : public Node {
public:
	virtual std::string print()=0;
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
		ss << "BIN_EXP {" << "\n";
		ss << left->print() << "\n";
		ss << op << "\n\n";
		ss <<  right->print() << "\n";
		ss << "}" << "\n";
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
		std::stringstream ss;
		ss << name;
		return ss.str();
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