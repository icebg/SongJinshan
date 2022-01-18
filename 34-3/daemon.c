#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void daemonize(void)
{
	pid_t  pid;

	/*
	 * Become a session leader to lose controlling TTY.
	 */
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	} else if (pid != 0) /* parent quit*/
		exit(0);
	setsid();

	/*
	 * Change the current working directory to the root.
	 */
	if (chdir("/") < 0) {
		perror("chdir");
		exit(1);
	} 

	/*
	 * Attach file descriptors 0, 1, and 2 to /dev/null.
	 */
	close(0);
	open("/dev/null", O_RDWR);// 0 represents /dev/null */
	dup2(0, 1);/* 1 represents /dev/null */
	dup2(0, 2);/* 2 represents /dev/null */
}

int main(void)
{
	daemonize();
	while(1);
}
