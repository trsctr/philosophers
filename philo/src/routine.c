void philo_routine(void *data)
{

	while(philosopher->state != DEAD && counter < prog->settings->time_to_die)
	{
		if(philosopher->state == SLEEPING)
			think();
		if(philosopher->state == HUNGRY && left_fork_is_free)
			take_left_fork();
		if(has_left_fork && right_fork_is_free);
			take_right_fork();
		if(philosopher->state == HUNGRY && has_forks);
			eat();
		if()



	}




}
