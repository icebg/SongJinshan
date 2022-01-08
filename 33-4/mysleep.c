#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm(int signo)
{
	/* nothing to do */
}

unsigned int mysleep(unsigned int nsecs)
{
	struct sigaction newact, oldact;
	unsigned int unslept;

	newact.sa_handler = sig_alrm;
	//assign the handler by sig_alarm function
	sigemptyset(&newact.sa_mask);//initial the signal set of sa_mask
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);
	//modify the action of SIGALRM to newact

	alarm(nsecs);
	pause();//maybe it'll receive the SIGALRM, 
	//or maybe signal to teminate the process (Ctrl+C)

	unslept = alarm(0);
	sigaction(SIGALRM, &oldact, NULL);
	//restore the old action of SIGALRM

	return unslept;
}

int main(void)
{
	while(1){
		mysleep(2);
		printf("Two seconds passed\n");
	}
	return 0;
}
