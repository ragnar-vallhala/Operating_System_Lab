#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>


void* add(void* args)
{
      int a,b;
      printf("First variable for addition: ");
      scanf("%d",&a);
      printf("Second variable for addition: ");
      scanf("%d",&b);
      int *res = (int*)malloc(sizeof(int));
      *res = a+b; 
      return (void*)res;
}


void* sub(void* args)
{
      int a,b;
      printf("First variable for subtraction: ");
      scanf("%d",&a);
      printf("Second variable for subtraction: ");
      scanf("%d",&b);
      int *res = (int*)malloc(sizeof(int));
      *res = a-b; 
      return (void*)res;
}

void * result(void* args)
{
  int* nums = (int*)args;
  int* result = (int*)malloc(sizeof(int));
  *result = nums[0] + nums[1];
  return (void*) result;
}

int main()
{
      pthread_t p1,p2,last;
      
      int rc;

      printf("Starting the main program.\n");

      rc = pthread_create(&p1,NULL,add,NULL);  assert(rc==0);
      rc = pthread_create(&p2,NULL,sub,NULL);  assert(rc==0);

      void *res1, *res2, *res3;
  
      rc = pthread_join(p1,&res1); assert(rc==0);
      rc = pthread_join(p2,&res2); assert(rc==0);
      
      int nums[2] = {*(int*)res1, *(int*)res2};

      rc = pthread_create(&last,NULL,result,nums);  assert(rc==0);
      rc = pthread_join(last,&res3); assert(rc==0);
      
      printf("The final result is %d\n",*(int*)res3);

      free(res1);
      free(res2);
      free(res3);
      
      return 0;
}
