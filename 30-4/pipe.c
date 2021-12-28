#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#define BUFSIZE 4096

int main(void)
{
	char buf[BUFSIZE];
	int n,i=0;
	while(i++ < BUFSIZE)
		buf[i] ='A'+(i-1)%26;
	int fd[2];
	pid_t pid;
	char ch;

	if (pipe(fd) < 0) {
		perror("pipe");
		exit(1);
	}
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(1);
	}
	if (pid > 0) { /* parent */
		close(fd[0]);
		int ret,k=0;
		while( (ret = write(fd[1], "A", 1 )) > 0 ) {}
		//printf("parent's write() returns %d\n",ret);
		wait(NULL);
	} else {       /* child */
		close(fd[1]);
		close(fd[0]);
		int i=0;
		//close(fd[0]);
		/*
		   while( (n = read(fd[0], &ch, 1))>0)
		   {
		   i+=n;
		   write(STDOUT_FILENO, &ch, n);
		//if( i == 3096 )
		//break;
		}
		printf("\nchild's read() returns %d\n",n);
		*/
		sleep(1000);
	}
	return 0;
}
