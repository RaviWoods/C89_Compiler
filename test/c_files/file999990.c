int f(int a,int b)
{
	int x = 10;
	{
		x += 10;
		{
			int x = 5;
			x += 1;
		}
		x+= 2;
	}
	{
		x += 200;
		int x = 20;
		x += 5;
	}
	return x;
}