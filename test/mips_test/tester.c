#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int f(int a, int b, int c);

void signal_handler(int signo)
{
  printf("Error (within MIPS program): received signal number %d\n", signo);
  exit(1);
}

int main(int argc, char *argv[])
{
  signal(SIGINT, signal_handler);
  signal(SIGILL, signal_handler);
  signal(SIGSEGV, signal_handler);
  signal(SIGFPE, signal_handler);

  fprintf(stdout, "DriverBegin (MIPS driver program starting)\n");
  fflush(stdout);

   int vs[]={0,-1,-2,-7,-11,-255,-256,-257,-65535,-65536,-65537,-0x7FFFFF,1,2,7,11,255,256,257,65535,65536,65537,0x7FFFFF};
   int ns=sizeof(vs)/sizeof(vs[0]);

   for(int i=0;i<ns;i++){
     for(int j=0;j<ns;j++){
       int r=f(vs[i],vs[j],(vs[i]*2));
       fprintf(stdout, "%s%d, %d, %d: %d\n", argv[1], vs[i],vs[j], (vs[i]*2),r);
       fflush(stdout);
     }
   }

   fprintf(stdout, "DriverFinished (MIPS driver program finishing)\n");
   fflush(stdout);
   return 0;
}
