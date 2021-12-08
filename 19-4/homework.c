#include<stdio.h>
#include<stdlib.h>
typedef union
{
	unsigned int n;
	unsigned char byte[4];
} demo_type;
int main()
{
	demo_type a = {0x5683};
	if( a.byte[0]==0x83 && a.byte[1]==0x56 )
	printf("small order\n");
	else if( a.byte[1]==0x83 && a.byte[0]==0x56 )
	printf("big order\n");
	exit(0);
}
