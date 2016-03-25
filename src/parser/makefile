bin/c_compiler: bin/c_parser.tab.o bin/c_parser.yy.o
	g++ -o bin/c_compiler bin/c_parser.tab.o bin/c_parser.yy.o	

bin/c_parser.yy.o: bin/c_parser.yy.cpp bin/c_parser.tab.hpp
	g++ -o bin/c_parser.yy.o -c bin/c_parser.yy.cpp 

bin/c_parser.tab.o: bin/c_parser.tab.cpp bin/c_parser.tab.hpp
	g++ -o bin/c_parser.tab.o -c bin/c_parser.tab.cpp 
	
bin/c_parser.tab.cpp bin/c_parser.tab.hpp: src/c_parser.y src/ast.hpp
    bison -o bin/c_parser.tab.cpp -d src/c_parser.y

bin/c_parser.tab.cpp : src/c_parser.y
	bison -o bin/c_parser.tab.cpp -d -v src/c_parser.y
	
bin/c_parser.yy.cpp: src/c_lexer.l
	flex -o bin/c_parser.yy.cpp src/c_lexer.l

clean:
	rm -f bin/*.cpp bin/*.o bin/c_compiler bin/*.hpp

