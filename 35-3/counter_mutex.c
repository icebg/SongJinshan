#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NLOOP 5000

int counter;                /* incremented by threads */
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
//定义一个线程互斥锁。(默认属性初始化)
void *doit(void *);

int main(int argc, char **argv)
{
	pthread_t tidA, tidB;

	pthread_create(&tidA, NULL, doit, NULL);
	pthread_create(&tidB, NULL, doit, NULL);

	/* wait for both threads to terminate */
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);

	return 0;
}

void *doit(void *vptr)//线程执行的函数体
{
	int     i, val;

	/*
	 * Each thread fetches, prints, and increments the counter NLOOP times.
	 * The value of the counter should increase monotonically.
	 */

	for (i = 0; i < NLOOP; i++) 
	{
		pthread_mutex_lock(&counter_mutex);//获得锁

		val = counter;
		printf("%x: %d\n", (unsigned int)pthread_self(), val + 1);
		counter = val + 1;

		pthread_mutex_unlock(&counter_mutex);//释放锁
	}

	return NULL;
}
