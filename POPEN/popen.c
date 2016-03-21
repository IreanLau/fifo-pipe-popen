/*************************************************************************
	> File Name: POPEN.c
	> Author: Xixi
	> Mail: 985632368@qq.com 
	> Created Time: Sat 14 Nov 2015 04:36:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char* argv[])
{
	FILE* fp=popen("ls -al","r");
	if(fp==NULL)
	{
		perror("open");
		exit(1);
	}
	else
	{
		char buf[256];
		size_t s = fread(buf,1,sizeof(buf),fp);
		if(s<0)
		{
			perror("fread");
			exit(3);
		}
		else{
		buf[s]='\0';
		printf("%s \n",buf);
		}
	}
	pclose(fp);
	return 0;
}

