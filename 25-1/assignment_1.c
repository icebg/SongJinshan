#include<stdio.h>
#include<stdlib.h>
char * mystrtok(char *str,const char *delim);
char * mystrtok_r(char *str,const char *delim,char **saveptr);
int main( int argc , char *argv[])
{
	char str[] = "root:x::0:root:/root:/bin/bash:";
	char *token;

	token = mystrtok(str, ":");
	printf("%s\n", token);
	while ( (token = mystrtok(NULL, ":")) != NULL)
		printf("%s\n", token);

	//-------------------------------------------------------------------------------------
	char *str1, *str2,  *subtoken;
	char *saveptr1, *saveptr2;
	int j;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s string delim subdelim\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = mystrtok_r(str1, argv[2], &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = mystrtok_r(str2, argv[3], &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(0);
}

char * mystrtok(char *str,const char *delim)
{
	char * head = str;
	static char *current = NULL;

	if( str != NULL )
		current = str;
	else
		head = current;

	if( !*current )
		return NULL;

	while( *current!='\0' && *current != *delim )
	{
		current++;
	}

	while( *current == *delim )// not "if". Because  "while()" can handle the situation: [lianxu fengefu]
	{
		*current='\0';
		current++;
	}
	return head;
}

char * mystrtok_r(char *str,const char *delim,char **saveptr)
{
	char * head = str;

	if( !str )
		return NULL;
	else if( !*str )
		return NULL;

	while( *str!='\0' && *str != *delim )
	{
		str++;
	}

	while( *str == *delim )// not "if". Because  "while()" can handle the situation: [lianxu fengefu]
	{
		*str='\0';
		str++;
	}
	*saveptr = str;
	return head;
}
