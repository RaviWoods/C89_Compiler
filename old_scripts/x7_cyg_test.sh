mips-linux-gnu-gcc  -S file.c -o file.s
mips-linux-gnu-gcc  -S tester.c -o tester.s
mips-linux-gnu-gcc  -static file.s tester.s -o mips_test
qemu-mips mips_test
