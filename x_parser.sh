#!/bin/bash

FILES="test/c_files/*.c"

make

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	cat $f  |  ./bin/c_parser
	printf "\n--------------------$f END----------------------\n"
done