#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	for(int i=0;i<600;++i)
	{
		if( !WIFSIGNALED(i) )
			printf("no! : %d\n",i);
	}
	exit(0);
}

