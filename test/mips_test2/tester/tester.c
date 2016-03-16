#include <stdio.h>

int f(int a, int b);

int main () {
	int i,j;
	for(i = 0; i<=2; i++) {
	for(j = 0; j<=2; j++) {
		x = f(i,j);
		printf("a = %i, b = %i\n", i,j);
		printf("%i\n", x);
	}
	return 0;
}
