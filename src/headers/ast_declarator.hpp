#ifndef __ASTDECLARATOR__
#define __ASTDECLARATOR__

#include "headers.hpp"


class Declarator : public Node {
private:
	std::string type;
	std::string id;
	Expression* e;

public:
	Declarator(std::string type_in, std::string id_in, Expression* e_in) : type(type_in), id(id_in), e(e_in) {};


};



#endif