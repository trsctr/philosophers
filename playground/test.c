#include <stdio.h>
#include <pthread.h>

#define TIMES_TO_COUNT 21000

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

void *thread_routine(void *data)
{
	pthread_t 		tid;
	unsigned int	*count;
	unsigned int	i = 0;

	tid = pthread_self();
	count = (unsigned int *) data;
	printf("%sThread [%ld]: Count at start: %u.%s\n", YELLOW, tid, *count, NC);
	while(i < TIMES_TO_COUNT)
	{
		(*count)++;
		i++;
		if(*count % 2123 == 0)
			printf("%s[%ld]Count: %s%u%s\n", YELLOW, tid, RED, *count, NC);
		usleep(i / 20);
	}
	printf("%sThread [%ld]: Final count = %u.%s\n",	BYELLOW, tid, *count, NC);
	return (NULL);
}

int main (void)
{
	pthread_t tid1;
	pthread_t tid2;
	unsigned int count = 0;

	printf("Main: Expected count is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
	pthread_create(&tid1, NULL, thread_routine, &count);
	printf("Main: we has first thread [%ld]\n", tid1);
	pthread_create(&tid2, NULL, thread_routine, &count);
	printf("Main: we can has second thread [%ld]\n", tid2);
	pthread_join(tid1, NULL);
	printf("Main: Joining first thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Joining 2nd thread [%ld]\n", tid2);
	if (count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERROR ! Total count is %u%s\n", RED, count, NC);
	else
		printf("%sMain: OK. Total count is %u%s\n", GREEN, count, NC);
	return(0);
}