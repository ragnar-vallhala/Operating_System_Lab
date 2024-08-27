#include<unistd.h>
#include<stdio.h>
int main()
{
	int n = write(1,"Hello World\n",12);
	printf("%d charatcters written to the stdout.",n);
	return 0;
}
