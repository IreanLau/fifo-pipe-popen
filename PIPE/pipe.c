/*************************************************************************
	> File Name: pipe.c
	> Author: Xixi
	> Mail: 985632368@qq.com 
	> Created Time: Sat 14 Nov 2015 10:05:41 AM CST
 ************************************************************************/

#include<stdio.h>
//#include<sys.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd[2];
	int ret=pipe(fd);
	if(-1 == ret)
	{
		perror("pipe");
		exit(1);
	}

	pid_t id =fork();
	if(id<0)
	{
		perror("fork");
		exit(2);//
	}
	else if(id == 0)
	{
		close(fd[0]);//写  关闭读端
		char* msg="hello";
		while(1)
		{
			write(fd[1],msg,strlen(msg));
			sleep(1);
		}

	}
	else
	{
		close(fd[1]);
		int count=10;
		char buf[256];
		while(count)
		{
			memset(buf,'\0',sizeof(buf));

			ssize_t size = read(fd[0],buf,sizeof(buf));
			if(size>0){
			buf[size]='\0';
			printf("%s\n",buf);
			}

			count--;
		}

		close(fd[0]);

		int status=0;
		pid_t ret=waitpid(id,&status,0);
		if(ret == id)
		{
		printf("code : %d ,sig : %d\n",\
				(status>>8)&0xff,status&0xff);
		}
	}
	printf("hello pipe\n");
	return 0;
}

