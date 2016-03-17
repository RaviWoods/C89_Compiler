#ifndef __ASTEXPSTAT__
#define __ASTEXPSTAT__

#include "headers.hpp"

class ExpStatement : public Statement { 
private:
	Expression* e;
	
public:
	ExpStatement(Expression* e_in) : e(e_in) {};


};


#endif