FILES=ops_*.c

var1=0

for f in $FILES;
do
let "var1=var1+1"
	printf "\n-----$f START-----\n"
	cp $f "new/file9$var1.c"
	printf "\n-----$f END-----\n"
done