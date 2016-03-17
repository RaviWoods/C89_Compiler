
#include "headers.hpp"
DecList::addToList(Statement* stat_in) {
		dlist.push_back(stat_in);
		return;
	}

DecList::print() {
	std::stringstream ss;
	//ss << "DEC_LIST {" << "\n";
	for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
		if((*it)!=NULL) {
			ss << ((*it)->print()) << "\n\n";   			
		}		
	} 
	//ss << "}" << "\n";
	return ss.str();
}

DecList::cprint() {
	std::stringstream ss;
	for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
		if((*it)!=NULL) {
			ss << ((*it)->cprint());   			
		}
	}
	return ss.str();
}
DecList::codeprint(Context& cont) {
	std::stringstream ss;
	for (std::list<Declarator*>::iterator it=dlist.begin(); it!=dlist.end(); ++it) {
		if((*it)!=NULL) {
			ss << ((*it)->codeprint(cont));   			
		}
	}
	return ss.str();
}

StatList::addToList(Statement* stat_in) {
		dlist.push_back(stat_in);
		return;
	}

StatList::print() {
		std::stringstream ss;
		//ss << "STAT_LIST {" << "\n";
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->print()) << "\n\n";   			
    		}		
		} 
		//ss << "}" << "\n";
		return ss.str();
	}

StatList::cprint() {
		std::stringstream ss;
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			ss << ((*it)->cprint());   			
    		}
		}
		return ss.str();
	}
	
StatList::codeprint(Context& cont) {
		std::stringstream ss;
		for (std::list<Statement*>::iterator it=slist.begin(); it!=slist.end(); ++it) {
    		if((*it)!=NULL) {
    			//std::cerr << "STAT2" << std::endl;
				ss << ((*it)->codeprint(cont)); 
    		}
		}
		return ss.str();
	}