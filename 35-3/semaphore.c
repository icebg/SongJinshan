#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM 5
int queue[NUM];//数组形式的队列。
sem_t blank_number, product_number;//定义两个信号量变量。

void *producer(void *arg) 
{
	int p = 0;//局部变量p，在当前函数体内，维护 队列头的位置
	while (1) 
	{
		sem_wait(&blank_number);      //若blank_number为0，线程挂起等待；
		//若blank_number为正，就获得资源,且把blank_number的值减一。
		queue[p] = rand() % 1000 + 1; //把位置p(最初是0)的元素设置为1到1000的随机数
		printf("Produce %d\n", queue[p]);
		sem_post(&product_number);    //释放资源，使product_number的值加1
		p = (p+1)%NUM;                //环形队列，位置p往右边移动一格
		sleep(rand()%5);
	}
}

void *consumer(void *arg) 
{
	int c = 0;//局部变量c，在当前函数体内，维护 队列尾的位置
	while (1) 
	{
		sem_wait(&product_number);    //若product_number为0，线程挂起等待；
		//若product_number为正，就获得资源,且把product_number的值减一。
		printf("Consume %d\n", queue[c]);
		queue[c] = 0;                 //把位置c(最初是0)的元素设置为0。
		sem_post(&blank_number);      //释放资源，使blank_number的值加1
		c = (c+1)%NUM;                //环形队列，位置c往右边移动一格
		sleep(rand()%5);
	}
}

int main(int argc, char *argv[]) 
{
	pthread_t pid, cid;  

	sem_init(&blank_number, 0, NUM);//初始化blank_number这个全局semaphore变量，可用资源数为NUM。
	sem_init(&product_number, 0, 0);//初始化blank_number这个全局semaphore变量，可用资源数为0。
	pthread_create(&pid, NULL, producer, NULL);//创建线程,执行函数体producer
	pthread_create(&cid, NULL, consumer, NULL);//创建线程,执行函数体consumer
	pthread_join(pid, NULL);//终止线程pid
	pthread_join(cid, NULL);//终止线程cid
	sem_destroy(&blank_number);//释放与信号量blank_number相关的资源
	sem_destroy(&product_number);//释放与信号量product_number相关的资源
	return 0;
}
