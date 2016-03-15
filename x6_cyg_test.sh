#!/bin/bash

FILES="cfiles/*.c"

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	if ! gcc -std=c89 tester.c $f -o ./1; then
		exit
	fi
	./1 > fileout.txt;
	make
	fname=$(basename $f .c)
	echo 'This is a test' > $fname.txt
	cat $f |  ./bin/c_parser > $fname_file.c
	if ! gcc -std=c89 tester.c $fname_file.c  -o ./2; then
		cat $fname_file.c > $fname_err.txt
	fi
	./2 > parser_fileout.txt;
	if cmp fileout.txt parser_fileout.txt >/dev/null 2>&1; then
		echo "IDENTICAL";
	else 
		sdiff fileout.txt parser_fileout.txt > $fname_err.txt
	fi

	printf "\n--------------------$f END----------------------\n"
	done
