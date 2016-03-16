FILES="assembly_test/*.s"

for f in $FILES
do
	mips-linux-gnu-gcc  -S assembly_test/tester/tester.c -o assembly_test/tester/tester.s
	mips-linux-gnu-gcc  -static $f assembly_test/tester/tester.s -o assembly_test/tester/mips_test
	qemu-mips assembly_test/tester/mips_test
done

