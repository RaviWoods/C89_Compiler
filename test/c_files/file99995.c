int f(int a,int b)
{
	int x = 5;
	{
		int x = 10;
		x += 1;
	}
	x -=1;
	return x;
}