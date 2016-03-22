FILES=prec_*.c

for f in $FILES;
do
	printf "\n-----$f START-----\n"
	cat $f
	printf "\n-----$f END-----\n"
done