#!/bin/bash

FILETYPE=txt

FILENAME=basictest

INPUT=test/input/${FILENAME}.${FILETYPE}



if [ -f ${INPUT} ]
then
	make
	printf "\n----------START----------\n"
	cat ${INPUT}  |  ./bin/c_lexer
	printf "\n----------END----------\n"
else
	echo ${INPUT}
	echo "WRONG INPUT NAME"
	exit 1
fi

 


