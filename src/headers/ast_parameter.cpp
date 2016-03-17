#include "headers.hpp"

Parameter::print() {
	std::stringstream ss;
	ss << "PARAM" << " " << type << " " << id;
	return ss.str();
}

Parameter::cprint() {
	std::stringstream ss;
	ss << type << " " << id;
	return ss.str();
}