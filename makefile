src/c_parser: src/c_parser.tab.o src/c_parser.yy.o
	g++ -o src/c_parser src/c_parser.tab.o src/c_parser.yy.o	

src/c_parser.yy.o: src/c_parser.yy.cpp src/c_parser.tab.h
	g++ -c src/c_parser.yy.cpp -o src/c_parser.yy.o
	
src/c_parser.tab.o: src/c_parser.tab.cpp src/c_parser.tab.h
	g++ -c src/c_parser.tab.cpp -o src/c_parser.tab.o
	
src/c_parser.tab.h: src/c_parser.y
	bison -o src/c_parser.tab.h -d src/c_parser.y

src/c_parser.tab.cpp : src/c_parser.y
	bison -o src/c_parser.tab.cpp -d src/c_parser.y
	
src/c_parser.yy.cpp: src/c_lexer.l
	flex -o src/c_parser.yy.cpp src/c_lexer.l

clean:
	rm -f bin/*.cpp bin/*.o bin/c_parser bin/*.h