#ifndef __AST__
#define __AST__

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>
#include <map>

/*TODO: Test aps_11 , base_3 , edge_3 , edge_4 , prec_1 to prec_6*/

/**********************************************************
  _______ ____  _____     _____ _                _____ _____ ______  _____ 
 |__   __/ __ \|  __ \   / ____| |        /\    / ____/ ____|  ____|/ ____|
    | | | |  | | |__) | | |    | |       /  \  | (___| (___ | |__  | (___  
    | | | |  | |  ___/  | |    | |      / /\ \  \___ \\___ \|  __|  \___ \ 
    | | | |__| | |      | |____| |____ / ____ \ ____) |___) | |____ ____) |
    |_|  \____/|_|       \_____|______/_/    \_\_____/_____/|______|_____/ 

Context, Helper Functions, Node, Statement, Expression
**********************************************************/

class Context {
public:
	int currentStackOffset;
	std::map <std::string, int> variableMap;
	Context() {
		currentStackOffset = 0;

	}
};

namespace Helper {
	std::string pushStack(int reg, Context& cont) {
		std::stringstream ss;
		ss << "sw  $" << reg << ", 0($sp)" << "\n";
		ss << "addiu $sp, $sp, -4\n";
		cont.currentStackOffset++;
		return ss.str();
	}
	std::string popStack(int reg, Context& cont) {
		std::stringstream ss;
		ss << "lw  $" << reg << ", 0($sp)" << "\n";
		ss << "addiu $sp, $sp, +4\n";
		cont.currentStackOffset--;
		return ss.str();
	}
	std::string readVar(std::string name, Context& cont) {
		std::stringstream ss;
		int a = cont.variableMap[name];
		int b = cont.currentStackOffset;
		int x = 4*(b-a+1);
		ss << "#ReadVar name\n";
		ss << "lw $9, " << x << "($sp)\n";
		return ss.str();
	}

	std::string writeVar(std::string name, Context& cont) {
		std::stringstream ss;
		int a = cont.variableMap[name];
		int b = cont.currentStackOffset;
		int x = 4*(b-a+1);
		ss << "#WriteVar name\n";
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

/**********************************************************
  _      ______          __  _      ________      ________ _      
 | |    / __ \ \        / / | |    |  ____\ \    / /  ____| |     
 | |   | |  | \ \  /\  / /  | |    | |__   \ \  / /| |__  | |     
 | |   | |  | |\ \/  \/ /   | |    |  __|   \ \/ / |  __| | |     
 | |___| |__| | \  /\  /    | |____| |____   \  /  | |____| |____ 
 |______\____/   \/  \/     |______|______|   \/   |______|______|

Identifier 3
ConstantValue 3
Parameter 2 : NO CODE PRINT
**********************************************************/

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
		ss << "#LoadID " << name << "\n";
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
		ss << "#LoadVal " << value << "\n";
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

	/*TODO: Add Code Print*/

	std::string getId() {
		return id;
	}
};

/**********************************************************
  ________   _______  _____  ______  _____ _____ _____ ____  _   _ 
 |  ____\ \ / /  __ \|  __ \|  ____|/ ____/ ____|_   _/ __ \| \ | |
 | |__   \ V /| |__) | |__) | |__  | (___| (___   | || |  | |  \| |
 |  __|   > < |  ___/|  _  /|  __|  \___ \\___ \  | || |  | | . ` |
 | |____ / . \| |    | | \ \| |____ ____) |___) |_| || |__| | |\  |
 |______/_/ \_\_|    |_|  \_\______|_____/_____/|_____\____/|_| \_|
                                                                  
AssignmentExp 3
BinaryExpression 3 : NOT COMPLETE (MULT)
**********************************************************/

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
			ss << "#AssignExp " << op << "\n";
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

	std::string codeprint(Context& cont) {
		std::stringstream ss;
		ss << "#BinExp " << op << "\n";
		ss << left->codeprint(cont) << "\n";
		ss << Helper::pushStack(8,cont) << "\n";

		ss << right->codeprint(cont) << "\n";
		ss << Helper::pushStack(8,cont) << "\n";

		ss << Helper::popStack(5,cont) << "\n";
		ss << Helper::popStack(6,cont) << "\n";

		ss << "addu $5,$8, $0\n";
		if(op=="+") {
			ss << "addu $8,$6, $5\n";
		} else if(op=="-") {
			ss << "subu $8,$6, $5\n";
		} else if(op=="&") {
			ss << "and $8,$6, $5\n";
		} else if(op=="^") {
			ss << "xor $8,$6, $5\n";
		} else if(op=="|") {
			ss << "or $8,$6, $5\n";
		} else if(op=="*") {
			ss << "mul $8,$6, $5\n";
		} else if(op=="<") {
			ss << "slt $8,$6, $5\n";
		} else if(op==">") {
			ss << "slt $8,$5, $6\n";
		} else if(op==">=") {
			ss << "sge $8,$6, $5\n";
		} else if(op=="<=") {
			ss << "sle $8,$6, $5\n";
		} else if(op=="==") {
			ss << "seq $8,$6, $5\n";
		} else if(op=="!=") {
			ss << "sne $8,$6, $5\n";
		} 
		/*TODO: ADD MULT*/
		return ss.str();
	}
};

/**********************************************************
  _____  ______ _____ _      ______ _____         _______ ____  _____  
 |  __ \|  ____/ ____| |    |  ____|  __ \     /\|__   __/ __ \|  __ \ 
 | |  | | |__ | |    | |    | |__  | |__) |   /  \  | | | |  | | |__) |
 | |  | |  __|| |    | |    |  __| |  _  /   / /\ \ | | | |  | |  _  / 
 | |__| | |___| |____| |____| |____| | \ \  / ____ \| | | |__| | | \ \ 
 |_____/|______\_____|______|______|_|  \_\/_/    \_\_|  \____/|_|  \_\                                                           

Declarator 3
**********************************************************/

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
		ss << "#Declarator " << id << "\n";
		ss << e->codeprint(cont) << "\n";
		ss << Helper::pushStack(8,cont) << "\n";
		cont.variableMap[id] = cont.currentStackOffset;
		return ss.str();
	}

};

/*********************************************************
   _____ _______    _______ _____ 
  / ____|__   __|/\|__   __/ ____|
 | (___    | |  /  \  | | | (___  
  \___ \   | | / /\ \ | |  \___ \ 
  ____) |  | |/ ____ \| |  ____) |
 |_____/   |_/_/    \_\_| |_____/ 

ExpStatement 3
JumpStatement 3                                         

**********************************************************/


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
		ss << "#return\n";
		if (e!=NULL) {
			ss << e->codeprint(cont);	
		} else {
			ss << "addu $8, $0, $0\n";
		}	
		ss << "addu $2, $8, $0\n";
		ss << "j  $31\n";
		ss << "nop\n";
		return ss.str();
	}
};


/*********************************************************
   _____  _____ ____  _____  ______ 
  / ____|/ ____/ __ \|  __ \|  ____|
 | (___ | |   | |  | | |__) | |__   
  \___ \| |   | |  | |  ___/|  __|  
  ____) | |___| |__| | |    | |____ 
 |_____/ \_____\____/|_|    |______|

DecList 3
StatList 3
CompoundStatement 3
**********************************************************/


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
		ss << "#CompoundStat\n";
		if (dl != NULL) {
			ss << dl->codeprint(cont);
		}
		if (sl != NULL) {
			ss << sl->codeprint(cont);;
		}
		return ss.str();
	}
};

/*********************************************************
  ______ _    _ _   _  _____ _____  ______ ______ 
 |  ____| |  | | \ | |/ ____|  __ \|  ____|  ____|
 | |__  | |  | |  \| | |    | |  | | |__  | |__   
 |  __| | |  | | . ` | |    | |  | |  __| |  __|  
 | |    | |__| | |\  | |____| |__| | |____| |     
 |_|     \____/|_| \_|\_____|_____/|______|_|  

FuncDef 3 : MORE THAN ONE PARAM
**********************************************************/

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
		/*TODO: Add more than 2 params*/
		ss << "#Function with Params: " << param1->getId() << " " <<  param2->getId() << "\n";
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

