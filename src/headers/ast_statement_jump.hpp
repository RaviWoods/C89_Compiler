#ifndef __ASTJUMPSTAT__
#define __ASTJUMPSTAT__

#include "headers.hpp"


class JumpStatement : public Statement { 
private:
	Expression* e;
	std::string keyword;
public:
	JumpStatement(std::string keyword_in, Expression* e_in) : keyword(keyword_in), e(e_in) {};


};


#endif