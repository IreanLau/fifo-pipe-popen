/*************************************************************************
	> File Name: fifo.c
	> Author: Xixi
	> Mail: 985632368@qq.com 
	> Created Time: Sat 14 Nov 2015 10:52:39 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#define _PATH_ "/home/lau/project/11_14命名管道/FIFO/fifo.tmp" 
int main(int argc,char* argv[])
{
	char *msg="hello";
	umask(0);
	if( mkfifo(_PATH_,S_IFIFO | 0666) == 0)
	{//success
		int fd=open(_PATH_,O_WRONLY);
		if(fd<0)
		{
			perror("open");
			exit(2);
		}
		int count =10;
		while(count--)
		{
			write(fd,msg,strlen(msg));
			sleep(1);
		}
		close(fd);
	}
	else
	{
		perror("mkfifo");
		exit(1);
	}
	return 0;

}

