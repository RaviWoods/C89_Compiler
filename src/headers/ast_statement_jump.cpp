#include "headers.hpp"

JumpStatement::print() {
	std::stringstream ss;
	ss << "JUMP_STAT {" << "\n";
	ss <<  keyword << "\n";
	if(e!=NULL) {
		ss << e->print() << "\n";
	}
	ss << "}" << "\n";
	return ss.str();
}

JumpStatement::cprint() {
	std::stringstream ss;
	ss <<  keyword << " ";
	if(e!=NULL) {
		ss << e->cprint();
	}
	ss << ";\n";
	return ss.str();
}
JumpStatement::codeprint(Context& cont) {
	std::stringstream ss;
	ss << e->codeprint(cont);
	ss << "sw  $9, 0($sp)\n";
	ss << "addiu $sp, $sp, -4\n";
	cont.currentStackOffset--; 
	ss << "addu $2, $9, $0\n";
	ss << "j  $31\n";
	ss << "nop\n";
	return ss.str();
}