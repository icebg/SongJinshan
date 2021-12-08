int main(void)
{
	void push(char);
	char pop(void);
	int is_empty(void);
	extern int top;
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
