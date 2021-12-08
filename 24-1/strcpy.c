#include<stdio.h>
char * strcpy(char *,const char *);
int main()
{
	char out[10];
	strcpy(out,"hello");
	printf("%s\n",out);
	return 0;
}
char * strcpy(char *dest,const char *src)
{
	while ( *dest++ = *src++);
	return dest;
}

