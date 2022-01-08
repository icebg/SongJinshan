#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void printsigset(const sigset_t *set)
{
	int i;
	for (i = 1; i < 64; i++)//from 1 to 31
		if (sigismember(set, i) == 1)
			putchar('1');//if the number is in set , print '1'
		else
			putchar('0');//if the number isn't in set , print '0'
	puts("");
}

int main(void)
{
	sigset_t s, p;
	sigemptyset(&s);//initial the s
	sigaddset(&s, SIGINT);// add SIGINT into s
	sigprocmask(SIG_BLOCK,&s,NULL);//block the SIGINT of present process 
	while (1) 
	{
		sigpending(&p);//read the present process's current pendingsets
		printsigset(&p);//print the current pending-bitmap of signal 1 to 31.
		sleep(1);
	}
	return 0;
}
