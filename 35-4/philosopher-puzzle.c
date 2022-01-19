#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 5

// philosophers and chopsticks,
// // chopsticks[0] 是 philosophers[0],即B的左边筷子,
// // chopsticks[1] 是 philosophers[1],即B的右边筷子,
pthread_t philosophers[NUM];
pthread_mutex_t chopsticks[NUM];
int chopstick_owner[NUM]={-1,-1,-1,-1,-1};

void *a_philosopher_s_action(void *arg)//每个哲学家每次执行的函数体
{
	int index = (int)arg;// index 从0到4。代表筷子1~筷子5。
	int index_next = (index+1)%NUM;
	pthread_mutex_t *chopstick_left = &chopsticks[index];
	pthread_mutex_t *chopstick_right = &chopsticks[index_next];
	int i;

	while (1) 
	{
		printf("chopstick owners: \n");
		for (i = 0; i < NUM; i++) 
		{
			printf("\t%d : %d\n", i+1, chopstick_owner[i]);
		}//在每个人开始动手之前，打印一下筷子的所属情况。

		usleep(rand()%10);//哲学家思考消耗一段时间
		// prepare eating
		// 拿左手边筷子
		pthread_mutex_lock(chopstick_left);
		chopstick_owner[index] = index;//成功拿到左手边筷子，那就记录这个筷子归属于第index个哲学家。
		printf("Philosopher %c fetches chopstick %d\n", index%5+'B', index+1);
		// 拿右手边筷子
		if (0 != pthread_mutex_trylock(chopstick_right))//假如没拿到右手边筷子。
		{
			pthread_mutex_unlock(chopstick_left);//那就立即把左手边筷子也放下。
			chopstick_owner[index] = -1;//标注左手边这个筷子无主
			printf("Philosopher %c releases chopstick %d\n", index%5+'B', index+1);
			continue;//跳过while循环中的后续代码一轮。
		}
		chopstick_owner[index_next] = index;//成功拿到右手边筷子，那就记录这个筷子归属于第index个哲学家
		printf("Philosopher %c fetches chopstick %d\n", index%5+'B', index_next+1);
		// eating
		usleep(rand()%10);//哲学家吃饭消耗一段时间
		// finish eating
		pthread_mutex_unlock(chopstick_left);//放下左手边筷子
		chopstick_owner[index] = -1;//标注左手边这个筷子无主
		pthread_mutex_unlock(chopstick_right);//放下右手边筷子
		chopstick_owner[index_next] = -1;//标注右手边这个筷子无主
		printf("Philosopher %c releases chopstick %d %d\n", index%5+'B', index+1, index_next+1);
	}
}

int main(void)
{
	int i;
	int index[NUM];

	for (i = 0; i < NUM; i++) 
	{
		chopstick_owner[i] = -1;
		pthread_create(&philosophers[i], NULL, a_philosopher_s_action, (void*)i);
	}
	for (i = 0; i < NUM; i++) 
	{
		pthread_join(philosophers[i], NULL);
	}
	return 0;
}
