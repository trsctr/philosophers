/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:57 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:19:26 by oandelin         ###   ########.fr       */
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
	monitor(prog);
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
		i = 0;
		if (prog->philos)
			free(prog->philos);
	}
	pthread_mutex_destroy(&prog->finished_mutex);
	pthread_mutex_destroy(&prog->death_mutex);
	pthread_mutex_destroy(&prog->bouncer);
	while (i < prog->number_of_philos)
		pthread_mutex_destroy(&prog->forks[i++]);
	if (prog->forks)
		free(prog->forks);
}
