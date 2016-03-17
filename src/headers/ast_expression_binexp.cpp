#include "headers.hpp"

BinaryExpression::print() {
	std::stringstream ss;
	ss << "BIN_EXP {" << "\n";
	ss << left->print() << "\n";
	ss << op << "\n";
	ss <<  right->print() << "\n";
	ss << "}" << "\n";
	return ss.str();
}

BinaryExpression::cprint() {
	std::stringstream ss;
	ss << "(" << left->cprint() << op << right->cprint() << ")";
	return ss.str();
}