/*
 *  Here I used a mutex variable from the pthread library. This variable
 *  provide us functionality to lock certain region of the code. When we lock a region only
 *  one thread is allowed to enter the block. This eliminates the problem that two threads
 *  load the same value. As second thread can't enter untill the first one has written the
 *  incremented value back to the variable.
 */


#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;
pthread_mutex_t mutex;

void *mythread (void *arg)
{
  printf("%s: begin\n", (char *) arg);
  int i;
  for (i = 0; i < 1000000; i++)
  {
    pthread_mutex_lock(&mutex);
    counter = counter + 1;
    pthread_mutex_unlock(&mutex);
  }
  printf("%s: done\n", (char *) arg);
  return NULL;
}

int main (int argc, char *argvll)
{
  pthread_t p1,p2;
  pthread_mutex_init(&mutex, NULL);
  printf("Main:: Begin (counter = %d)\n",counter);
  pthread_create(&p1, NULL, mythread,"A");
  pthread_create(&p2, NULL, mythread,"B");


  pthread_join(p1,NULL);
  pthread_join(p2,NULL);

  printf ("Main: done with both (counter = %d)\n", counter) ;
  
  return 0;
}
