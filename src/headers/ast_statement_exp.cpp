
#include "headers.hpp"


ExpStatement::print() {
	std::stringstream ss;
	ss << "EXP_STAT {" << "\n";
	if(e!=NULL) {
		ss << e->print() << "\n";
	}
	ss << "}" << "\n";
	return ss.str();
}

ExpStatement::cprint() {
	std::stringstream ss;
	if(e!=NULL) {
		ss << e->cprint();
	}
	ss << ";\n";
	return ss.str();
}