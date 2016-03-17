#!/bin/bash

FILES="test/mips_test/csource/*.c"
for f in $FILES
do
	if ! gcc -std=c89 test/mips_test/tester.c $f -o ./1; then
		echo "UH OH"
		exit
	fi
	./1 > test/ast_test/tmporig.txt;
	make
	fname=$(basename $f .c)
	if ! mips-linux-gnu-gcc -S test/mips_test/tester.c -o test/mips_test/tester.s; then
		echo "UH OH"
		exit
	fi
	cat $f |  ./bin/c_parser > test/mips_test/assembly/$fname.s
	if ! mips-linux-gnu-gcc  -static test/mips_test/assembly/$fname.s test/mips_test/tester.s -o test/mips_test/mips_test >/dev/null 2>&1; then
		printf "\n-----$f COMPILE ERROR-----\n"
		cat $f 
 		printf "\n-----$f COMPILE ERROR-----\n"
		exit
	fi
	qemu-mips test/mips_test/mips_testfile > test/ast_test/tmpfin.txt
	if cmp test/ast_test/tmpfin.txt test/ast_test/tmporig.txt >/dev/null 2>&1; then
		echo "$f correct"
	else 
		printf "\n-----$f DIFF ERROR-----\n"
		cat $f 
 		printf "\n-----$f DIFF ERROR-----\n"
 		exit
	fi
done



