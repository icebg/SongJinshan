#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#define M 1024  
#define N 100  

const char match_char[] = {';', '[', '='};  

/*鍖归厤鍏抽敭瀛楃*/  
/*杩斿洖鍏抽敭瀛楃鍦ㄨ〃涓殑涓嬫爣锛宯甯﹀洖鍏抽敭瀛楃鍦ㄥ瓧绗︿覆涓殑涓嬫爣*/  
int match(const char *str, int *n)  
{  
	int i = 0, len = sizeof(match_char)/sizeof(match_char[0]);  
	const char *p;  

	for(i; i < len; i++)  
	{  
		p = str;  
		*n = 0;  
		while(*p != '/0')  
		{  
			if(match_char[i] == *p)  
				return i;  
			p++;  
			(*n)++;  
		}  
	}  

	return -1;  
}  

void semicolon(char *buf, FILE *out)  
{  
	fprintf(out, "<!-- %s -->/n", buf + 1);  
}  

char * brackets(char *buf, FILE *out)  
{  
	int len = strlen(buf);  

	*(buf + len - 1) = '/0';  

	fprintf(out, "<%s>/n", buf + 1, buf + 1);  

	return buf + 1;  
}  

void equal(char *allbuf, FILE *out, int n)  
{  
	int i = 0;  
	char halfbuf[M/2];  

	for(i;  (allbuf[i] != ' ') && (allbuf[i] != '   ') && (i < n); i++)  
	{  
		halfbuf[i] = allbuf[i];  
	}  

	allbuf = &allbuf[n+1];  
	halfbuf[i] = '/0';  

	while(*allbuf == ' '|| *allbuf == ' ')  
		allbuf++;  

	fprintf(out, "  <%s>%s</%s>/n", halfbuf, allbuf, halfbuf);  
}
#endif
