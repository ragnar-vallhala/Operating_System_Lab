#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("Process ID of Parent: %d\n",getpid());
	int id = fork();
	if(id==0)
	{
		printf("Process ID of Child(P1):%d\n",getpid());
		printf("Parent ID of Child P1:%d\n",getppid());
	}
	else
	{
		wait(NULL);
		printf("ID of P's Child (P1):%d\n",id);
	}
	return 0;
}
