#include<unistd.h>
#include<stdio.h>
int main()
{
	int n=3;
	while(n--)
	{
		if(fork()==0)
		{
			printf("Child %d process id: %d\n",3-n,getpid());
		}
		else
		{
			break;
		}
	}
	return 0;
}
