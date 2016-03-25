int f(int a, int b) {
	int x = 10;
	while (x != 0) {
		++a;
		x--;
	}
	return a++;
}