FILES=prec_*.c

var1=3

for f in $FILES;
do

	printf "\n-----$f START-----\n"
	cp $f "new/file99$var1.c"
	printf "\n-----$f END-----\n"
	let "var1=var1+1"
done