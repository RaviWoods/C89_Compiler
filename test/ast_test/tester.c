#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int f(int a, int b);

int main(int argc, char *argv[])
{

  int r=f(5,7);
  fprintf(stdout, "%d, %d, %d\n", 5,7,r);

  return 0;
}
