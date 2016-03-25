int f(int a, int b) {
	int x = 10;
	do {
		++a;
		x--;
	} while(x!=9);
	a++;
	return a;
}