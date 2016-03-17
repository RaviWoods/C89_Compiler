FILES="test/c_files/*.c"

make

for f in $FILES
do
	printf "\n--------------------$f START--------------------\n"
	cat $f
	printf "\n"

	fname=$(basename $f .c)
	cat $f  |  ./bin/c_parser > test/mips_test/assembly/$fname.s
	printf "START OF ASSEMBLY"
	printf "\n---------------\n"
	cat test/mips_test/assembly/$fname.s
	printf "\n---------------\n"
	mips-linux-gnu-gcc  -S test/mips_test/tester.c -o test/mips_test/tester.s
	mips-linux-gnu-gcc  -static test/mips_test/assembly/$fname.s test/mips_test/tester.s -o test/mips_test/tester
	printf "START OF OUTPUT"
	printf "\n---------------\n"
	qemu-mips test/mips_test/tester
	printf "\n--------------------$f END----------------------\n"
done
