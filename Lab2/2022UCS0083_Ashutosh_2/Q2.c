#include<unistd.h>
#include<stdio.h>
int main()
{
	int n=3;
	while(n--)
	{
		if(fork()==0)
		{
			printf("Child %d process id: %d\n",n,getpid());
			break;
		}
	}
	return 0;
}
