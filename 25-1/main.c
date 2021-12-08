#include <stdio.h>
#include <string.h>
int main(void)
{
	char buf[20] = "hello world\n";
	char buffer[20];
	memcpy(buf + 1, buf, 13);
	strncpy(buffer,"Nice",5);
	printf(buf);
	printf(buffer+4);
	return 0;
}
