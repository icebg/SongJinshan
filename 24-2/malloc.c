#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count=0,i= 1024;
	long long x =100*1024*1024;
	int *p=NULL;
	while(i--)
	{
		if( (p=malloc(x)) == NULL)
		{
			perror(" out of memeroy\n");
			return -1;
		}
		else
		{
			*p=0;
			count++;
			printf("%d times allocated, 100M each time\n",count);
			//each time 1G
		}
	}

	exit(0);
}
