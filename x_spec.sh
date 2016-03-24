#!/bin/bash

FILES="c_spec_tests/*.c"
echo "Specific? [y/n]"
read text
if [ "$text" == "y" ]; then
	echo "Which?"
	read filename
	FILES="c_spec_tests/$filename.c"
fi
for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	gcc -std=c90 $f -o ./1;
	./1;
	printf "\n--------------------$f END----------------------\n"
done