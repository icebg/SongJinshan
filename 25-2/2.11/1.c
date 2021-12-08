//编程读写一个文件test.txt，每隔1秒向文件中写入一行记录
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <unistd.h>
int main()
{
	FILE * fp;
	if( (fp=fopen("text.txt","a+")) == NULL)
	{
		perror("open file text.txt");
		exit(1);
	}   
	time_t rawtime;
	struct tm *p;
	long n=0;
	int line_lenth=0;
	char buff[64];
	//char buff[64];
	/*下面这段代码使用来判断test.txt里面已经存在多少个行了*/
	/*
	   while((c = getc(fp)) != EOF)
	   if(c == '\n')
	   n++;
	   */
	fgets(buff,sizeof(buff),fp); //first line's characters
	line_lenth = strlen(buff);	//length of	each line
	fseek(fp, 0, SEEK_END);
	printf("size of this file:%ld\n",ftell(fp));
	printf("last line_number:%ld\n",n=ftell(fp)/line_lenth);
	printf("length of each line:%d\n",line_lenth);
	while(1)
	{
		time(&rawtime);
		p = localtime(&rawtime);
		if(fprintf(fp,"%09ld %2d-%2d-%d %2d:%2d:%2d\n",n+1,p->tm_year + 1900,p->tm_mon+1,p->tm_mday,p->tm_hour+16,p->tm_min,p->tm_sec) < 0)
			printf("write error!\n");
		fflush(fp);
		fprintf(stdout,"%09ld %2d-%2d-%d %2d:%2d:%2d\n",n+1,p->tm_year + 1900,p->tm_mon+1,p->tm_mday,p->tm_hour+16,p->tm_min,p->tm_sec);    
		n++;
		sleep(1);
	}
	fclose(fp);
	return 0;
}
