#include <stdio.h>

int f(int a, int b);

int main () {
	int i = 11;
	int j = 42;
	int x = f(i,j);
	printf("a = %i, b = %i\n", i,j);
	printf("%i\n", x);
	return 0;
}
