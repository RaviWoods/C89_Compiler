FILES="assembly_test/*.c"

for f in $FILES
do
	fname=$(basename $f .c)
	mips-linux-gnu-gcc  -S $f -o assembly_test/assembly_$fname.s
done
