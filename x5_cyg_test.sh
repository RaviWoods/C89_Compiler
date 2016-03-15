printf "\n--------------------$f START--------------------\n"
cat file.c
printf "\n"
make
cat file.c  |  ./bin/c_parser > parsed_file.c
gcc -std=c89 tester.c file.c  -o ./1;
./1 > fileout.txt;
if g++ -std=c89 tester.c parsed_file.c  -o ./2; then
	./2 > parser_fileout.txt;
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	if cmp fileout.txt parser_fileout.txt >/dev/null 2>&1
	then
		echo "IDENTICAL";
	else 
		echo "DIFFERENT"
	fi
else 
	echo "FAILURE ON parsed_file"
	cat parsed_fileout.txt
fi
printf "\n--------------------$f END----------------------\n"