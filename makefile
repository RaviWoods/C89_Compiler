bin/c_lexer : src/c_lexer.yy.cpp
	g++ $< -o $@

src/c_lexer.yy.cpp : src/c_lexer.l
	flex -o $@ $<

clean :
	rm src/c_lexer.yy.c
	rm bin/c_lexer