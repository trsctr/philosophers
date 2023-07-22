#include <stdio.h>
#include <pthread.h>

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_locks
{
	pthread_mutex_t lock1;
	pthread_mutex_t lock2;
	unsigned int	count;
} t_locks;

void *thread1_routine(void *data)
{
	pthread_t	tid;
	t_locks		*locks;
	int			i = 0;
	tid = pthread_self();
	locks = (t_locks *)data;
	while(i++ < 10)
	{	printf("%sThread [%ld]: wants lock l%s\n", YELLOW, tid, NC);
		pthread_mutex_lock(&locks->lock1);
		printf("%sThread [%ld]: owns lock 1%s\n", BYELLOW, tid, NC);
		printf("%sThread [%ld]: wants lock 2%s\n", YELLOW, tid, NC);
		pthread_mutex_lock(&locks->lock2);
		printf("%sThread [%ld]: owns lock 2%s\n", BYELLOW, tid, NC);
		locks->count++;
		printf("%sThread [%ld]: added one to count, value is now %u%s\n", RED, tid, locks->count, NC);
		usleep(i * 1000);
		printf("%sThread [%ld]: unlocking lock 2%s\n", BYELLOW, tid, NC);
		pthread_mutex_unlock(&locks->lock2);
		printf("%sThread [%ld]: unlocking lock 1%s\n", BYELLOW, tid, NC);
		pthread_mutex_unlock(&locks->lock1);
	}
	return(NULL);
}

void *thread2_routine(void *data)
{
	pthread_t	tid;
	t_locks		*locks;

	tid = pthread_self();
	locks = (t_locks *)data;
	printf("%sThread [%ld]: wants lock l%s\n", YELLOW, tid, NC);
	pthread_mutex_lock(&locks->lock1);
	printf("%sThread [%ld]: owns lock 1%s\n", BYELLOW, tid, NC);
	printf("%sThread [%ld]: wants lock 2%s\n", YELLOW, tid, NC);
	pthread_mutex_lock(&locks->lock2);
	printf("%sThread [%ld]: owns lock 2%s\n", BYELLOW, tid, NC);
	usleep(8000);
	locks->count += 1;
	
	printf("%sThread [%ld]: unlocking lock 2%s\n", BYELLOW, tid, NC);
	pthread_mutex_unlock(&locks->lock2);
	printf("%sThread [%ld]: unlocking lock 1%s\n", BYELLOW, tid, NC);
	pthread_mutex_unlock(&locks->lock1);
	printf("%sThread [%ld]: finished%s\n", YELLOW, tid, NC);
	return(NULL);
}

int main(void)
{
	pthread_t	th[600];
	t_locks		locks;
	int			i = 0;
	locks.count = 0;
	pthread_mutex_init(&locks.lock1, NULL);
	pthread_mutex_init(&locks.lock2, NULL);
	while (i < 600)
	{
		pthread_create(&th[i], NULL, thread1_routine, &locks);
		printf("Main: Created #%d thread [%ld]\n", i, th[i]);
		i++;
	}
	i = 0;
	while (i < 600)
	{
		pthread_join(th[i], NULL);
		printf("Main: Joined #%d thread[%ld]\n", i, th[i]);
		i++;
	}
	if(locks.count == 6000)
		printf("%sMain: OK. Total count is %d %s\n", GREEN, locks.count, NC);
	else
		printf("%sMain: FAIL. Total count is %u %s\n", RED, locks.count, NC);
	pthread_mutex_destroy(&locks.lock1);
	pthread_mutex_destroy(&locks.lock2);
	return(0);
}
