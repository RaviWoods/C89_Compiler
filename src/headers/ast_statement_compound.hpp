#ifndef __ASTCOMPOUND__
#define __ASTCOMPOUND__

#include "headers.hpp"


class CompoundStatement : public Statement {
private:
	StatList* sl;
	DecList* dl;
public:
	CompoundStatement(StatList* sl_in, DecList* dl_in) : sl(sl_in), dl(dl_in) {}

};







#endif