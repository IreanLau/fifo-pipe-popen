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
//#include<unistd.h>
#define _PATH_ \
	"/home/lau/project/11_14命名管道/FIFO/fifo.tmp" 
#define _SIZE_ 256
int main(int argc,char* argv[])
{
	int fd=open(_PATH_,O_RDONLY);
		if(fd<0)
		{
			perror("open");
			exit(1);
		}
		char buf[_SIZE_];
		while(1)
		{
			memset(buf,'\0',sizeof(buf));
			ssize_t s = read(fd,buf,sizeof(buf)-1);
			if(s==0)
			{printf("quit\n");
			break;
			}
			else if(s>0){
			buf[s]='\0';
			printf("reader:%s \n",buf);}
			else
			{perror("read");
			exit(2);}
		}
	close(fd);
	return 0;

}

