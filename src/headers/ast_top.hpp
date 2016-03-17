#ifndef __ASTTOPLEVEL__
#define __ASTTOPLEVEL__

#include "headers.hpp"
class Context {
public:
	int currentStackOffset;
	std::map <std::string, int> variableMap;
	Context() {
		currentStackOffset = 0;
	}
};

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



#endif

