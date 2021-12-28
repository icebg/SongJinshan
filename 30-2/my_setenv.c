#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("PATH=%s\n", getenv("PATH"));
	setenv("PATH", "hello", 1);//1 means rewrite-allowed.
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
