#include "headers.hpp"

ConstantValue::print() {
	std::stringstream ss;
	ss << value;
	return ss.str();
}

ConstantValue::cprint() {
	std::stringstream ss;
	ss << value;
	return ss.str();
}
ConstantValue::codeprint(Context& cont) {
	std::stringstream ss;
	ss << "li $9, " << value << "\n";
	ss << "sw  $9, 0($sp)" << "\n";
	ss << "addiu $sp, $sp, -4\n";
	cont.currentStackOffset--;
	return ss.str();
}

Identifier::cprint() {
	std::stringstream ss;
	ss << name;
	return ss.str();
}

Identifier::print() {
	std::stringstream ss;
	ss << name;
	return ss.str();
}