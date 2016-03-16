FILES="assembly_test/*.c"

for f in $FILES
	fname=$(basename $f .c)
	mips-linux-gnu-gcc  -S $f -o assembly_$fname.s