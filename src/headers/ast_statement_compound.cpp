#include "headers.hpp"

CompoundStatement::std::string print() {
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
CompoundStatement::std::string cprint() {
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
CompoundStatement::std::string codeprint(Context& cont) {
	std::stringstream ss;
	if (dl != NULL) {
		ss << dl->codeprint(cont);
	}
	if (sl != NULL) {
		ss << sl->codeprint(cont);;
	}
	return ss.str();
}