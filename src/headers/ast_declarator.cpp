#include "headers.hpp"

Declarator::print() {
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

Declarator::cprint() {
	
	std::stringstream ss;
	ss << type << " " << id << " ";
	if(e!=NULL) {
		ss << "= " << e->cprint();
	}
	ss << ";\n";
	return ss.str();
}
Declarator::codeprint(Context& cont) {
	if(e==NULL) {
		std::stringstream ss;
		ss << "addiu $sp, $sp, -4\n";
		cont.variableMap[id] = cont.currentStackOffset;
		cont.currentStackOffset++;
		return ss.str();
	}
}