/*
 *  This code shows an undeterministic behaviour. The reason for this is the 
 *  code in for loop where we update the global variable counter. The increment is performed
 *  by multiple instructions in the CPU instructions. Tis include loading the value of counter
 *  in a register then adding 1 to it and finally writing it back to the memory.
 *  In the process it may happen that when one thread loads the value interruption
 *  happens and then other thread loads the same value. And finally they both write back same value
 *  skipping one addition.
 *  This may happen many times leading to a value of counter lesser than the expected.
 */



#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread (void *arg)
{
  printf("%s: begin\n", (char *) arg);
  int i;
  for (i = 0; i < 1000000; i++)
  {
    counter = counter + 1;
  }
  printf("%s: done\n", (char *) arg);
  return NULL;
}

int main (int argc, char *argvll)
{
  pthread_t p1,p2;
  printf("Main:: Begin (counter = %d)\n",counter);
  pthread_create(&p1, NULL, mythread,"A");
  pthread_create(&p2, NULL, mythread,"B");


  pthread_join(p1,NULL);
  pthread_join(p2,NULL);

  printf ("Main: done with both (counter = %d)\n", counter) ;
  
  return 0;
}
