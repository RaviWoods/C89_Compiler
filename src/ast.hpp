#ifndef __AST__
#define __AST__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>
#include <map>

class Context {
public:
	int currentStackOffset;
	std::map <std::string, int> variableMap;
	Context() {
		currentStackOffset = 0;

	}
};

namespace Helper {
	std::string storeOnStack(int reg, Context& cont) {
		std::stringstream ss;
		ss << "sw  $" << reg << ", 0($sp)" << "\n";
		ss << "addiu $sp, $sp, -4\n";
		cont.currentStackOffset++;
		return ss.str();
	}
	std::string readVar(std::string name, Context& cont) {
		std::stringstream ss;
		int a = cont.variableMap[name];
		int b = cont.currentStackOffset;
		int x = 4*(b-a+1);
		ss << "lw $9, " << x << "($sp)\n";
		return ss.str();
	}

	std::string writeVar(std::string name, Context& cont) {
		std::stringstream ss;
		int a = cont.variableMap[name];
		int b = cont.currentStackOffset;
		int x = 4*(b-a);
		ss << "sw $9, " << x << "($sp)\n";
		return ss.str();
	}
}

class Node {
public:
	virtual ~Node() 
	{};
	virtual std::string print()=0;
	virtual std::string cprint()=0;
	virtual std::string codeprint(Context& cont) {
		return "#NOT IMPLEMENTED YET\n";
	}
};

class Statement : public Node {};
class Expression : public Node {
public:
	virtual std::string codeprint(Context& cont) {
		return "#NOT IMPLEMENTED YET\n";
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

	std::string codeprint(Context& cont) {
		std::stringstream ss;
		ss << Helper::readVar(name,cont);
		ss << "addu $8,$9, $0\n";
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
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		ss << "li $8, " << value << "\n";
		return ss.str();
	}
};

class Parameter : public Node {
private:
	std::string type;
	std::string id;

public:
	Parameter(std::string type_in, std::string id_in) : type(type_in), id(id_in) {};

	std::string print() {
		std::stringstream ss;
		ss << "PARAM" << " " << type << " " << id;
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss << type << " " << id;
		return ss.str();
	}
	std::string getId() {
		return id;
	}
};

class Declarator : public Node {
private:
	std::string type;
	std::string id;
	Expression* e;

public:
	Declarator(std::string type_in, std::string id_in, Expression* e_in) : type(type_in), id(id_in), e(e_in) {};

	std::string print() {
		std::stringstream ss;
		ss << "DECL {" << "\n";
		ss << type << "\n";
		ss << id << "\n";
		ss << "=" << "\n";
		if(e!=NULL) {
			ss << e->print() << "\n";
		}
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		
		std::stringstream ss;
		ss << type << " " << id << " ";
		if(e!=NULL) {
			ss << "= " << e->cprint();
		}
		ss << ";\n";
		return ss.str();

	}
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		cont.variableMap[id] = cont.currentStackOffset;
		ss << e->codeprint(cont) << "\n";
		ss << Helper::storeOnStack(8,cont) << "\n";
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
	std::string codeprint(Context& cont) {
		if (e!=NULL) {
			std::string x = e->codeprint(cont);
			return x;			
		}
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
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		ss << e->codeprint(cont);
		ss << "addu $2, $8, $0\n";
		ss << "j  $31\n";
		ss << "nop\n";
		return ss.str();
	}
};


class AssignmentExp : public Expression { 
private:
	std::string left;
	std::string op;
	Expression* right;
	
public:
	AssignmentExp(std::string left_in, const std::string &op_in, Expression *right_in) : 
	left(left_in), op(op_in) , right(right_in)
	{};

	std::string print() {
		std::stringstream ss;
		ss << "ASSIGN_EXP {" << "\n";
		ss << left << "\n";
		ss << op << "\n";
		ss <<  right->print() << "\n";
		ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss << "(" << left << op << right->cprint() << ")";
		return ss.str();
	}

	std::string codeprint(Context& cont) {
		if(right!=NULL) {
			std::stringstream ss;
			ss << right->codeprint(cont) << "\n";
			ss << "addu $9, $8, $0\n";
			ss << Helper::writeVar(left, cont);
			return ss.str();
		}
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




class DecList : public Node {
private:
	std::list<Declarator*> dlist;
public:
	DecList() {};
	void addToList(Declarator* dec_in) {
		dlist.push_back(dec_in);
		return;
	}
	std::string print() {
		std::stringstream ss;
		//ss << "DEC_LIST {" << "\n";
		for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->print()) << "\n\n";   			
    		}		
		} 
		//ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->cprint());   			
    		}
		}
		return ss.str();
	}
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->codeprint(cont));   			
    		}
		}
		return ss.str();
	}
};

class StatList : public Node {
private:
	std::list<Statement*> slist;
public:
	StatList() {};
	void addToList(Statement* stat_in) {
		slist.push_back(stat_in);
		return;
	}
	std::string print() {
		std::stringstream ss;
		//ss << "STAT_LIST {" << "\n";
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->print()) << "\n\n";   			
    		}		
		} 
		//ss << "}" << "\n";
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->cprint());   			
    		}
		}
		return ss.str();
	}
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			//std::cerr << "STAT2" << std::endl;
				ss << ((*it)->codeprint(cont)); 
    		}
		}
		return ss.str();
	}
};

class CompoundStatement : public Statement {
private:
	StatList* sl;
	DecList* dl;
public:
	CompoundStatement(StatList* sl_in, DecList* dl_in) : sl(sl_in), dl(dl_in) {}
	std::string print() {
		std::stringstream ss;
		ss << "{" << "\n\n\n";
		if(dl!=NULL) {
			ss << dl->print();
		}
		if(sl!=NULL) {
			ss << sl->print();
		}
		ss << "}" << "\n";
		return ss.str();
	}
	std::string cprint() {
		std::stringstream ss;
		ss << "{\n";
		if(dl!=NULL) {
			ss << dl->cprint();
		}
		if(sl!=NULL) {
			ss << sl->cprint();
		}
		ss << "}\n";
		return ss.str();
	}
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		if (dl != NULL) {
			ss << dl->codeprint(cont);
		}
		if (sl != NULL) {
			ss << sl->codeprint(cont);;
		}
		return ss.str();
	}
};

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

	std::string print() {
		std::stringstream ss;
		ss << returnType << " " << name << "(" << param1->print() << ", " << param2->print() << ")\n";
		ss << cs->print();
		return ss.str();
	}

	std::string cprint() {
		std::stringstream ss;
		ss << returnType << " " << name << "(" << param1->cprint() << ", " << param2->cprint() << ")\n";
		ss << cs->cprint();
		return ss.str();
	}
	std::string codeprint(Context& cont) {
		std::stringstream ss;
		ss << ".text\n" << ".align 2\n";
		ss << ".globl  " << name << "\n";
		ss << ".ent  " << name << "\n";
		ss << ".type  " << name << ", @function" << "\n";
		ss << name << ":\n";
		cont.variableMap[param1->getId()] = 1;
		cont.variableMap[param2->getId()] = 2;
		for(int i = 4; i <= 7; i++) {
			ss << "sw  $" << i << ", 0($sp)" << "\n";
			ss << "addiu $sp, $sp, -4\n";
			cont.currentStackOffset++;
		}
		ss << cs->codeprint(cont);
		return ss.str();
	}
};

#endif

