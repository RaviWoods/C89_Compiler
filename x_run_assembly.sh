#!/bin/bash

FILES="test/mips_test2/*.c"
DIR = "test/mips_test2"

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	make
	fname=$(basename $f .c)
	printf "START OF ASSEMBLY"
	printf "\n---------------\n"
	cat $f  |  ./bin/c_parser > $DIR/assembly/$fname.s
	mips-linux-gnu-gcc  -S $DIR/tester/tester.c -o $DIR/tester/tester.s
	mips-linux-gnu-gcc  -static $DIR/assembly/$fname.s $DIR/tester/tester.s -o $DIR/mips_test
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	qemu-mips $DIR/mips_test
	printf "\n--------------------$f END----------------------\n"
done
