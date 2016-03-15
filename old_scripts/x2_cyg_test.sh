#!/bin/bash

FILENAME=hard1

INPUT=test/input/${FILENAME}.txt



if [ -f ${INPUT} ]
then
	make
	printf "\n----------START----------\n"
	cat ${INPUT}  |  ./bin/c_parser
	printf "\n----------END----------\n"
else
	echo ${INPUT}
	echo "WRONG INPUT NAME"
	exit 1
fi

