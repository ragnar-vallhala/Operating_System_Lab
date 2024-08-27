#include<unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/stat.h>
int main()
{
	char buffer[20];
	int n = read(0,buffer,20);
	int descripter = open("file.txt",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if(descripter==-1)
	{
		printf("Failed to open the file");
		return 1;
	}
	write(descripter,buffer,n);
	printf("%d charatcters read from stdin and written to file.txt.",n);
	return 0;
}
