#!/bin/bash

FILES="test/input/*.txt"

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	make
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	cat $f  |  ./bin/c_parser
	printf "\n--------------------$f END----------------------\n"
done