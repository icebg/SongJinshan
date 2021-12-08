#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	char c;
	char ch;
	scanf("%d",&i); 
	scanf("%c",&c);
	scanf("%c",&ch);
	printf("%d;%c;%c\n",i,c,ch);
	/*
	   for(i=0;i<9;i++)
	   {
	   c=getchar();
	   printf("[its:]%c\n",c);
	   }
	   */

	exit(0);
}
