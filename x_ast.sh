#!/bin/bash

rm test/mips_test/tmpfin.txt
rm test/mips_test/tmporig.txt
rm -rf test/ast_test/c_output
mkdir test/ast_test/c_output
make
clear
FILES="test/c_files/*.c"
echo "Specific? [y/n]"
read text
if [ "$text" == "y" ]; then
	echo "Which?"
	read filename
	FILES="test/c_files/$filename.c"
fi
for f in $FILES
do
	if ! gcc test/ast_test/tester.c $f -o ./1; then
		echo "UH OH"
		exit
	fi
	./1 > test/ast_test/tmporig.txt;
	fname=$(basename $f .c)
	if ! cat $f |  ./bin/c_parser > test/ast_test/c_output/$fname.c; then
		printf "\n-----$f PARSER ERROR-----\n"
		cat $f 
 		printf "\n-----$f PARSER ERROR-----\n"
 		exit
	fi
	if ! gcc test/ast_test/tester.c test/ast_test/c_output/$fname.c -o ./2 >/dev/null 2>&1; then
		printf "\n-----$f COMPILE ERROR-----\n"
		cat $f 
 		printf "\n-----$f COMPILE ERROR-----\n"
		echo "See c output? [y/n]"
		read text
		if [ "$text" == "y" ]; then
			cat test/ast_test/c_output/$fname.c
			exit
		fi
		exit
	fi
	./2 > test/ast_test/tmpfin.txt
	if cmp test/ast_test/tmpfin.txt test/ast_test/tmporig.txt >/dev/null 2>&1; then
		echo "$f correct"
		#sdiff test/mips_test/tmporig.txt test/mips_test/tmpfin.txt 
	else 
		printf "\n-----$f DIFF ERROR-----\n"
		cat $f
 		printf "\n-----$f DIFF ERROR-----\n"
		echo "See diff? [y/n]"
		read text
		if [ "$text" == "y" ]; then
			sdiff test/ast_test/tmpfin.txt test/ast_test/tmporig.txt
		fi
		exit
	fi
	printf "\n---------------End of $f----------------\n"
done

