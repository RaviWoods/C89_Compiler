/********** ALLOWED **********/
int foo1(int a, int b) {
	return 0;
}

/********** ALLOWED **********/
foo2(int a, int b) {
	return 0;
}

/********** NOT ALLOWED **********/
int a = 10;
int b = 20;

int foo3(a,b) {
	return 1;
}

/********** ALLOWED **********/
foo4(int a, int b, ...) {
	return 0;
}

/********** NOT ALLOWED **********/
int foo5 {
	return 0;
}

/********** NOT ALLOWED **********/
int foo6 [] {
	return 0;
}

int main() {
	return 0;
}