#!/bin/bash

FILETYPE=txt

FILENAME=simple

INPUT=test/input/${FILENAME}.${FILETYPE}
OUTPUT=test/output/${FILENAME}.${FILETYPE}
GOT=test/got/${FILENAME}.${FILETYPE}
touch ${GOT}


if [ -f ${INPUT} ]
then
	make
	cat ${INPUT}  |  ./bin/c_parser  >  ${GOT}
else
	echo ${INPUT}
	echo "WRONG INPUT NAME"
	rm ${GOT}
	exit 1
fi

if [ -s ${GOT} ]
then	
	if [ -f ${OUTPUT} ]
	then
   		sdiff --ignore-all-space ${GOT} ${OUTPUT}
		exit 1
	else 
		echo "WRONG OUTPUT NAME"	
		rm ${GOT}
		exit 0
	fi
else
	echo "NO PROGRAM OUTPUT"
	rm ${GOT}
	exit 0
fi

 


