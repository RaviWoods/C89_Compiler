#ifndef __AST__
#define __AST__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>

class Node {
public:
	virtual ~Node() 
	{};
	virtual std::string print()=0;
	virtual std::string cprint()=0;
};

class Statement : public Node {};
class Expression : public Node {};

class Function : public Node {

};


class Declarator : public Node {
private:
	std::string type;
	Expression* id;
	Expression* e;

public:
	Declarator(std::string type_in, Expression* id_in, Expression* e_in) : type(type_in), id(id_in), e(e_in) {};

	std::string print() {
		std::stringstream ss;
		ss << "DECL {" << "\n";
		ss << type << "\n";
		ss << id->print() << "\n";
		if(e!=NULL) {
			ss << e->print() << "\n";
		}
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		
		std::stringstream ss;
		ss << type << " " << id->cprint() << " ";
		if(e!=NULL) {
			ss << "= " << e->cprint();
		}
		ss << ";\n";
		return ss.str();
	}
};


class CompoundStat : public Node {
private:
	std::list<Statement*> slist;
	std::list<Declarator*> dlist;
public:
	CompoundStat() {};
	addToList(Statement* stat_in, Declarator* dec_in) {
		if (stat_in != NULL) {
			slist.push_front(stat_in);
		} 
		if (dec_in != NULL) {
			dlist.push_front(dec_in);
		}
	}
	std::string print() {
		std::stringstream ss;
		ss << "COMPOUND_STAT {" << "\n";
		for (std::list<Statement*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->print());   			
    		}		
		} 
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->print());   			
    		}		
		} 
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		for (std::list<Statement*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->cprint());   			
    		}
		}
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->cprint());   			
    		}
		}
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

	std::string cprint() {
		std::stringstream ss;
		ss << name;
		return ss.str();
	}

	std::string print() {
		std::stringstream ss;
		ss << name;
		return ss.str();
	}
};



class ExpStatement : public Statement { 
private:
	Expression* e;
	
public:
	ExpStatement(Expression* e_in) : e(e_in) {};

	std::string print() {
		std::stringstream ss;
		ss << "EXP_STAT {" << "\n";
		if(e!=NULL) {
			ss << e->print() << "\n";
		}
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		if(e!=NULL) {
			ss << e->cprint();
		}
		ss << ";\n";
		return ss.str();
	}
};


class JumpStatement : public Statement { 
private:
	Expression* e;
	std::string keyword;
public:
	JumpStatement(std::string keyword_in, Expression* e_in) : keyword(keyword_in), e(e_in) {};

	std::string print() {
		std::stringstream ss;
		ss << "JUMP_STAT {" << "\n";
		ss <<  keyword << "\n";
		if(e!=NULL) {
			ss << e->print() << "\n";
		}
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss <<  keyword << " ";
		if(e!=NULL) {
			ss << e->cprint();
		}
		ss << ";\n";
		return ss.str();
	}
};


class AssignmentExp : public Expression { 
private:
	Expression* left;
	std::string op;
	Expression* right;
	
public:
	AssignmentExp(Expression *left_in, const std::string &op_in, Expression *right_in) : 
	left(left_in), op(op_in) , right(right_in)
	{};

	std::string print() {
		std::stringstream ss;
		ss << "ASSIGN_EXP {" << "\n";
		ss << left->print() << "\n";
		ss << op << "\n";
		ss <<  right->print() << "\n";
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss << "(" << left->cprint() << op << right->cprint() << ")";
		return ss.str();
	}
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
		ss << op << "\n";
		ss <<  right->print() << "\n";
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss << "(" << left->cprint() << op << right->cprint() << ")";
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

	std::string cprint() {
		std::stringstream ss;
		ss << value;
		return ss.str();
	}
};

#endif