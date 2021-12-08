/* main.c */
#include <stdio.h>
void push(char);
char pop(void);
int is_empty(void);
extern int top;
int main(void)
{
	push('a');
	push('b');
	push('c');
	printf("%d\n", top);
	while(!is_empty())
		putchar(pop());
	putchar('\n');
	printf("%d\n", top);
	return 0;
}
