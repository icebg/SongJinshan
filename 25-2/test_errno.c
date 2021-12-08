#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	int i;
	for(i=0;i<128;i++)
	{
		fputs(strerror(i),stderr);
		printf("\n");
	}

	return 0;
}
