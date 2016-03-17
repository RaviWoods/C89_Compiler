#include "headers.hpp"

AssignmentExp::print() {
	std::stringstream ss;
	ss << "ASSIGN_EXP {" << "\n";
	ss << left->print() << "\n";
	ss << op << "\n";
	ss <<  right->print() << "\n";
	ss << "}" << "\n";
	return ss.str();
}

AssignmentExp::cprint() {
	std::stringstream ss;
	ss << "(" << left->cprint() << op << right->cprint() << ")";
	return ss.str();
}