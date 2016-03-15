#!/bin/bash

FILES="c_spec_tests/*.c"

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	make
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	g++ -std=c90 $f -o ./1;
	./1;
	printf "\n--------------------$f END----------------------\n"
done