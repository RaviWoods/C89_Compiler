#ifndef __ASTFUNCDEF__
#define __ASTFUNCDEF__

#include "headers.hpp"
#include "ast_parameter.hpp"
#include "ast_statement_compound.hpp"

class FuncDef : public Node {
private:
	std::string returnType;
	std::string name;
	Parameter* param1;
	Parameter* param2;
	CompoundStatement* cs;
public:
	FuncDef(std::string returnType_in, std::string name_in, Parameter* param1_in, Parameter* param2_in, CompoundStatement* cs_in) :
	returnType(returnType_in), name(name_in), param1(param1_in), param2(param2_in), cs(cs_in)
	{};


};


#endif