int f(int a,int b)
{
  int x = 10;
  int y = 2;
  a += x;
  a += y*b<<200%5;
  return (a+=b);
}
