
FILES="test/mips_test2/*.c"

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"
	make
	fname=$(basename $f .c)
	printf "START OF ASSEMBLY"
	printf "\n---------------\n"
	cat $f  |  ./bin/c_parser > test/mips_test2/assembly/$fname.s
	mips-linux-gnu-gcc  -S test/mips_test2/tester/tester.c -o test/mips_test2/tester/tester.s
	mips-linux-gnu-gcc  -static test/mips_test2/assembly/$fname.s test/mips_test2/tester/tester.s -o test/mips_test2/mips_test
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	qemu-mips test/mips_test2/mips_test
	printf "\n--------------------$f END----------------------\n"
done
