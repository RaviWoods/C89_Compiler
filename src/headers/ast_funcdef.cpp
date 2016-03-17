#include "headers.hpp"

FuncDef::print() {
	std::stringstream ss;
	ss << returnType << " " << name << "(" << param1->cprint() << ", " << param2->cprint() << ")\n";
	ss << cs->cprint();
	return ss.str();
}

FuncDef::cprint() {
	std::stringstream ss;
	ss << returnType << " " << name << "(" << param1->cprint() << ", " << param2->cprint() << ")\n";
	ss << cs->cprint();
	return ss.str();
}

FuncDef::codeprint(Context& cont) {
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