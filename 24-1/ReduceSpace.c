#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SPACE_FLAG (*src == '\n' || *src == ' ' || *src == '\t' || *src == '\r')
char *shrink_space(char *dest, const char *src, size_t n);
int main()
{
	char *src, dest[256];
	src="     hello  world          its a gr\teat test!   \n    genius haha \t \r  lastline";
	shrink_space(dest,src,64);
	printf("%s",dest);
	printf("\n%d\n",strlen(dest));
	exit(0);
}
char *shrink_space(char *dest, const char *src, size_t n)
{ 
	char * dest1 = dest;
	int i =0, enable_flag=1;
	while(*src != '\0')
	{
		while( !SPACE_FLAG )
		{

			if( !enable_flag ) // not space ,so go on.
				enable_flag=1;
			*dest1++ = *src++;
			i++;
			if( i == n )
			{
				*dest1='\0';
				return dest;
			}
		}
		if( enable_flag ) // is space
		{
			enable_flag=0;
			*dest1++ = ' ';
			i++;
			if( i == n )
			{
				*dest1='\0';
				return dest;
			}
		}
		else src++; // is pace ,but enable is closed
	}
	return dest;
}
