/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:57 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 23:14:57 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_table(t_prog *prog)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&prog->bouncer);
	while (i < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->philos[i]->eat_mutex, NULL) != 0)
			printf("Failed to init eat_mutex for philo %d\n", i);
		init_philo(prog, i);
		if (pthread_create(&prog->philos[i]->tid, NULL,
				(void *) philo_routine, prog->philos[i]) != 0)
		{
			printf("Failed to create thread for philo %d\n", i);
			prog->dead++;
			pthread_mutex_unlock(&prog->bouncer);
			return ;
		}
		i++;
	}
	prog->start_time = get_time();
	pthread_mutex_unlock(&prog->bouncer);
	deathwatch(prog);
}


void	end_party(t_prog *prog)
{
	int	i;

	i = prog->number_of_philos - 1;
	while (i >= 0)
	{
		pthread_join(prog->philos[i]->tid, NULL);
	 	i--;
	}
	clean_table(prog);
}

void	clean_table(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->philos)
	{
		while (i < prog->number_of_philos)
		{
			pthread_mutex_destroy(&prog->philos[i]->eat_mutex);
			if (prog->philos[i])
				free(prog->philos[i]);
			i++;
		}
		if (prog->philos)
			free(prog->philos);
		i = 0;
	}
	pthread_mutex_destroy(&prog->finished_mutex);
	pthread_mutex_destroy(&prog->death_mutex);
	pthread_mutex_destroy(&prog->bouncer);
	while (i <prog->number_of_philos)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		i++;
	}
	if (prog->forks)
		free(prog->forks);
}

void	deathwatch(t_prog *prog)
{
	int i;

	usleep(prog->time_to_die * 500);
	while (1)
	{
		i = 0;
		while (i < prog->number_of_philos)
		{
			pthread_mutex_lock(&prog->philos[i]->eat_mutex);
			pthread_mutex_lock(&prog->death_mutex);
			if (get_time() - prog->philos[i]->last_meal > prog->time_to_die && prog->philos[i]->finished == 0)
			{
				prog->dead++;
				print_message("died", get_timestamp(prog), prog->philos[i]->id, RED);
				pthread_mutex_unlock(&prog->philos[i]->eat_mutex);
				pthread_mutex_unlock(&prog->death_mutex);
				return ;
			}
			pthread_mutex_unlock(&prog->death_mutex);
			pthread_mutex_unlock(&prog->philos[i]->eat_mutex);
			pthread_mutex_lock(&prog->finished_mutex);
			if (prog->finished >= prog->number_of_philos)
			{
				pthread_mutex_unlock(&prog->finished_mutex);
				return ;
			}
			pthread_mutex_unlock(&prog->finished_mutex);
			i++;
		}
	}
}
// void monitor(void *data)
// {
	
// }