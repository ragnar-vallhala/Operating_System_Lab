#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	int pid1,pid2;
	pid1 = fork();
	if(pid1!=0)
	{
		pid2=fork();
	}

	if(pid1==0 || pid2==0)
	{
		printf("Child process id: %d\n",getpid());
		sleep(5);  //simualting a task
	}
	if(pid1!=0 && pid2!=0)
	{
		wait(pid1,NULL,0);
		wait(pid2,NULL,0);
		printf("My children finshed work\n");
	}

	return 0;
}
