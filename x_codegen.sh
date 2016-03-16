#!/bin/bash

FILES="test/mips_test/csource/*.c"
rm test/ast_test/tmporig.txt 2> /dev/null
rm test/ast_test/tmpfin.txt 2> /dev/null
echo "" > test/ast_test/tmporig.txt
echo "" > test/ast_test/tmpfin.txt
fileNo=0
compileFileNo=0
diffFileNo=0
correctFileNo=0
for f in $FILES
do
	fileNo=`expr $fileNo + 1`;
	printf "\n--------------------$f START--------------------\n"
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
	cat $f |  ./bin/c_parser > test/mips_test/mips_source/mips_$fname.s
	if ! mips-linux-gnu-gcc  -static test/mips_test/mips_csource/mips_$fname.s test/mips_test/tester.s -o test/mips_test/mips_testfile >/dev/null 2>&1; then
		compileFileNo=`expr $compileFileNo + 1`;
		printf "\n-----$f COMPILE ERROR-----\n"
		cat $f 
 		printf "\n-----$f COMPILE ERROR-----\n"
		printf "\n--------------------$f END----------------------\n"
		continue
	fi
	qemu-mips test/mips_test/mips_testfile > test/ast_test/tmpfin.txt
	if cmp test/ast_test/tmpfin.txt test/ast_test/tmporig.txt >/dev/null 2>&1; then
		correctFileNo=`expr $correctFileNo + 1`;
	else 
		diffFileNo=`expr $diffFileNo + 1`;
		printf "\n-----$f DIFF ERROR-----\n"
		cat $f 
 		printf "\n-----$f DIFF ERROR-----\n"
	fi
	printf "\n--------------------$f END----------------------\n"
done
echo "fileNo = $fileNo" 
echo "correctFileNo = $correctFileNo" 
echo "compileFileNo = $compileFileNo" 
echo "diffFileNo = $diffFileNo" 


