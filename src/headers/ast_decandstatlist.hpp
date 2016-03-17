#ifndef __ASTLISTS__
#define __ASTLISTS__

#include "headers.hpp"
#include "ast_declarator.hpp"

class DecList : public Node {
private:
	std::list<Declarator*> dlist;
public:
	DecList() {};
	void addToList(Declarator* dec_in) {
	}

};

class StatList : public Node {
private:
	std::list<Statement*> slist;
public:
	StatList() {};
	void addToList(Statement* stat_in) {}



};

#endif