#include<unistd.h>
#include<stdio.h>
int main()
{
	char buffer[20];
	int n = read(0,buffer,20);
	write(1,buffer,n);
	printf("%d charatcters read from stdin.",n);
	return 0;
}
