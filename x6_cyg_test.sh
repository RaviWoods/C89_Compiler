#!/bin/bash

FILES="test/ast_test/csource/*.c"
rm test/ast_test/tmporig.txt 2> /dev/null
rm test/ast_test/tmpparse.txt 2> /dev/null
rm test/ast_test/diffileerror.txt 2> /dev/null
rm test/ast_test/compilefileerror.txt 2> /dev/null
echo "" > test/ast_test/tmporig.txt
echo "" > test/ast_test/tmpparse.txt
echo "" > test/ast_test/diffileerror.txt
echo "" > test/ast_test/compilefileerror.txt
fileNo=0
compileFileNo=0
diffFileNo=0
correctFileNo=0
for f in $FILES
do
	fileNo=`expr $fileNo + 1`;
	printf "\n--------------------$f START--------------------\n"
	if ! gcc -std=c89 test/ast_test/tester.c $f -o ./1; then
		echo "UH OH"
		exit
	fi
	./1 > test/ast_test/tmporig.txt;
	make
	fname=$(basename $f .c)
	cat $f |  ./bin/c_parser > test/ast_test/parsed_csource/parsed_$fname.c
	if ! gcc -std=c89 test/ast_test/tester.c test/ast_test/parsed_csource/parsed_$fname.c  -o ./2 >/dev/null 2>&1; then
		cat test/ast_test/parsed_csource/parsed_$fname.c > test/ast_test/error_files/err_compile_$fname.txt
		echo $fname >> test/ast_test/compilefileerror.txt;
		compileFileNo=`expr $compileFileNo + 1`;
		printf "\n-----$f COMPILE ERROR-----\n"
		cat $f 
 		printf "\n-----$f COMPILE ERROR-----\n"
		printf "\n--------------------$f END----------------------\n"
		continue
	fi
	./2 > test/ast_test/tmpparse.txt;
	if cmp test/ast_test/tmpparse.txt test/ast_test/tmporig.txt >/dev/null 2>&1; then
		correctFileNo=`expr $correctFileNo + 1`;

	else 
		diffFileNo=`expr $diffFileNo + 1`;
		sdiff test/ast_test/tmpparse.txt test/ast_test/tmporig.txt
		printf "\n-----$f DIFF ERROR-----\n"
		cat $f 
 		printf "\n-----$f DIFF ERROR-----\n"
		echo $fname >> test/ast_test/diffileerror.txt
	fi
	printf "\n--------------------$f END----------------------\n"
done
echo "fileNo = $fileNo" 
echo "compileFileNo = $compileFileNo" 
echo "diffFileNo = $diffFileNo" 
echo "correctFileNo = $correctFileNo" 


