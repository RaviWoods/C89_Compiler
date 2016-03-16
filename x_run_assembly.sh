FILES="assembly_test/*.s"

for f in $FILES
do
	printf "--------------------- $f START ------------------\n"
	mips-linux-gnu-gcc -static $f assembly_test/tester/mips_test
	qemu-mips assembly_test/tester/mips_test
	printf "--------------------- $f END ------------------\n"

done

