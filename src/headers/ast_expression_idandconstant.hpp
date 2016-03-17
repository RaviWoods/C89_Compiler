#ifndef __ASTIDANDCONST__
#define __ASTIDANDCONST__

#include "headers.hpp"


class ConstantValue : public Expression {
private:
	int value;
public:
	ConstantValue(int value_in) :
	value(value_in)
	{};


};

class Identifier : public Expression {
private:
	std::string name;
public:
	Identifier(std::string name_in) : 
	name(name_in)
	{};


};

#endif