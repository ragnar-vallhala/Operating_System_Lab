#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>


void* add(void* args)
{
      int* nums = (int*) args;
      int *res = (int*)malloc(sizeof(int));
      *res = (nums[0]+nums[1]);
      return (void*)res;
}


void* sub(void* args)
{
      int* nums = (int*) args;
      int *res = (int*)malloc(sizeof(int));
      *res = (nums[0]-nums[1]);
      return (void*)res;
}


int main()
{
      pthread_t p1,p2;
      
      int rc;
      int ab[2];
      int cd[2];

      printf("Taking input from user.\n");
      
      printf("Enter two integers for addition: ");
      scanf("%d",ab);
      scanf("%d",ab+1);

      printf("Enter two integers for subtraction: ");
      scanf("%d",cd);
      scanf("%d",cd+1);

      printf("Starting the main program.\n");

      rc = pthread_create(&p1,NULL,add,ab);  assert(rc==0);
      rc = pthread_create(&p2,NULL,sub,cd);  assert(rc==0);

      void *res1, *res2;
  
      rc = pthread_join(p1,&res1); assert(rc==0);
      rc = pthread_join(p2,&res2); assert(rc==0);
      
      printf("The sum of the returned value is %d.\n", *(int*)res1 +*(int*)res2  );
      printf("Exiting the main program.\n");
      
      free(res1);
      free(res2);
      
      return 0;
}
