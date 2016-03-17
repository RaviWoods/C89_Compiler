#ifndef __ASTPARAM__
#define __ASTPARAM__

#include "headers.hpp"

class Parameter : public Node {
private:
	std::string type;
	std::string id;

public:
	Parameter(std::string type_in, std::string id_in) : type(type_in), id(id_in) {};


	std::string getId() {
		return id;
	}
};

#endif
