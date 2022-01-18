#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thr_fn1(void *arg)
{
	printf("thread 1 returning\n");
	return (void *)1;
}//thread正常return

void *thr_fn2(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void *)2);
}//thread自己主动终止

void *thr_fn3(void *arg)
{
	while(1) {
		printf("thread 3 writing\n");
		sleep(1);
	}
}

int main(void)
{
	pthread_t   tid;
	void        *tret;

	pthread_create(&tid, NULL, thr_fn1, NULL);
	pthread_join(tid, &tret);
	printf("thread 1 exit code %d\n", (int)tret);

	pthread_create(&tid, NULL, thr_fn2, NULL);
	pthread_join(tid, &tret);
	printf("thread 2 exit code %d\n", (int)tret);

	pthread_create(&tid, NULL, thr_fn3, NULL);
	sleep(3);
	pthread_cancel(tid);//thread异常终止(被其他线程cancel)
	pthread_join(tid, &tret);
	printf("thread 3 exit code %d\n", (int)tret);

	return 0;
}
