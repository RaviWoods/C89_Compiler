#!/bin/bash

rm test/mips_test/tmpfin.txt
rm test/mips_test/tmporig.txt
rm -rf test/mips_test/assembly
mkdir test/mips_test/assembly
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
	if ! gcc test/mips_test/tester.c $f -o ./1; then
		echo "UH OH"
		exit
	fi
	./1 > test/mips_test/tmporig.txt;
	fname=$(basename $f .c)
	if ! mips-linux-gnu-gcc -S test/mips_test/tester.c -o test/mips_test/tester.s; then
		echo "UH OH"
		exit
	fi
	if ! cat $f |  ./bin/c_parser > test/mips_test/assembly/$fname.s; then
		printf "\n-----$f PARSER ERROR-----\n"
		cat $f 
 		printf "\n-----$f PARSER ERROR-----\n"
 		exit
	fi
	if ! mips-linux-gnu-gcc  -static test/mips_test/assembly/$fname.s test/mips_test/tester.s -o test/mips_test/tester >/dev/null 2>&1; then
		printf "\n-----$f COMPILE ERROR-----\n"
		cat $f 
 		printf "\n-----$f COMPILE ERROR-----\n"
		echo "See assembly? [y/n]"
		read text
		if [ "$text" == "y" ]; then
			cat test/mips_test/assembly/$fname.s
			exit
		fi
		exit
	fi
	qemu-mips test/mips_test/tester > test/mips_test/tmpfin.txt
	if cmp test/mips_test/tmpfin.txt test/mips_test/tmporig.txt >/dev/null 2>&1; then
		echo "$f correct"
		#sdiff test/mips_test/tmporig.txt test/mips_test/tmpfin.txt 
	else 
		printf "\n-----$f DIFF ERROR-----\n"
		cat $f
 		printf "\n-----$f DIFF ERROR-----\n"
 		echo "See assembly? [y/n]"
		read text
		if [ "$text" == "y" ]; then
			cat test/mips_test/assembly/$fname.s
		fi

		echo "See diff? [y/n]"
		read text
		if [ "$text" == "y" ]; then
			sdiff test/mips_test/tmporig.txt test/mips_test/tmpfin.txt > test/mips_test/tmpdiff.txt
			less test/mips_test/tmpdiff.txt
		fi
		exit
	fi
	printf "\n---------------End of $f----------------\n"
done

echo "ALL DONE"

