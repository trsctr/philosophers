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

	tid = pthread_self();
	locks = (t_locks *)data;
	printf("%sThread [%ld]: wants lock l%s\n", YELLOW, tid, NC);
	pthread_mutex_lock(&locks->lock1);
	printf("%sThread [%ld]: owns lock 1%s\n", BYELLOW, tid, NC);
	usleep(6000);
	printf("%sThread [%ld]: wants lock 2%s\n", YELLOW, tid, NC);
	pthread_mutex_lock(&locks->lock2);
	printf("%sThread [%ld]: owns lock 2%s\n", BYELLOW, tid, NC);
	
	locks->count += 1;
	
	printf("%sThread [%ld]: unlocking lock 2%s\n", BYELLOW, tid, NC);
	pthread_mutex_unlock(&locks->lock2);
	printf("%sThread [%ld]: unlocking lock 1%s\n", BYELLOW, tid, NC);
	pthread_mutex_unlock(&locks->lock1);
	printf("%sThread [%ld]: finished%s\n", YELLOW, tid, NC);
	usleep(3000);
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
	usleep(800);
	return(NULL);
}

int main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	t_locks		locks;

	locks.count = 0;
	pthread_mutex_init(&locks.lock1, NULL);
	pthread_mutex_init(&locks.lock2, NULL);
	pthread_create(&tid1, NULL, thread1_routine, &locks);
	printf("Main: Created first thread [%ld]\n", tid1);
	pthread_create(&tid2, NULL, thread2_routine, &locks);
	printf("Main: Created second thread [%ld]\n", tid2);
	pthread_join(tid1, NULL);
	printf("Main: Joined first thread[%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Joined first thread[%ld]\n", tid2);
	if(locks.count == 2)
		printf("%sMain: OK. Total count is %d %s\n", GREEN, locks.count, NC);
	else
		printf("%sMain: FAIL. Total count is %u %s\n", RED, locks.count, NC);
	pthread_mutex_destroy(&locks.lock1);
	pthread_mutex_destroy(&locks.lock2);
	return(0);
}
