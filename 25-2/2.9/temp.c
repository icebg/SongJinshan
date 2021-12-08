#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int a={-1};
int b=2,c,d,e,f,g;
int main()
{
	printf("pid is %d\n:",getpid());
	printf("&a is %p\n:",&a);
	printf("&c is %p\n:",&c);
	printf("&g is %p\n:",&g);
	printf("&d is %p\n:",&d);
	printf("&e is %p\n:",&e);
	printf("&f is %p\n:",&f);
	getchar();
	return 0;
}
