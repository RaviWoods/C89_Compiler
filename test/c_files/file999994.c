int f(int a, int b) {
	int x = 10;
	while (!x) {
		++a;
		x--;
	}
	a++;
	return a;
}