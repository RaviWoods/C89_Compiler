#include <stdio.h>

int f(int a, int b);

int main () {
	int i = 0;
	int j = 0;
	for(i = 0; i <=10; i++) {
		for(j = 0; j <=10; j++) {
			int x = f(i,j);
			printf("a = %i, b = %i\n", i,j);
			printf("%i\n", x);
		}
	}
	return 0;
}
