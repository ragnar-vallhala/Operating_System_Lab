#include<unistd.h>
#include <fcntl.h>
#include<stdio.h>
int main()
{
	char buffer[20];
	int n = read(0,buffer,20);
	int descripter = creat("file.txt",S_IRUSR|S_IWUSR);
	write(descripter,buffer,n);
	printf("%d charatcters read from stdin and written to file.txt.",n);
	return 0;
}
