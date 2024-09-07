#include<stdio.h>
#include <assert.h>
#include <pthread.h>


void* foo(void* args)
{
      printf("%s\n", (char*) args);
      return NULL;
}


int main()
{
      pthread_t p1,p2;
      int rc;
      printf("Starting the main program.\n");
      rc = pthread_create(&p1,NULL,foo,"Hello from thread1!");  assert(rc==0);
      rc = pthread_create(&p2,NULL,foo,"Hello from thread2!");  assert(rc==0);
      rc = pthread_join(p1,NULL); assert(rc==0);
      rc = pthread_join(p2,NULL); assert(rc==0);
      printf("Exiting the main program.\n");
      return 0;
}
