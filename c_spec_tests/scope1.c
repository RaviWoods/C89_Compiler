#include <stdio.h>

int main () {
	int a = 10;
	{
		printf("%i\n", a);
		int a = 10;
		printf("%i\n", a);
		a += 1;
		printf("%i\n", a);
	}
	printf("%i\n", a);
	a -=1;
	printf("%i\n", a);
	return 0;
}