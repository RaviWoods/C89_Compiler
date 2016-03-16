cp file.s working_file.s
mips-linux-gnu-gcc  -static file.s -o file
qemu-mips file
echo $?
