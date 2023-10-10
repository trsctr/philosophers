/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:34:57 by oandelin          #+#    #+#             */
/*   Updated: 2023/10/10 19:23:03 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief destroys mutexes and frees allocated memory
 * 
 * @param prog main struct
 */
void	clean_table(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->philos)
	{
		while (i < prog->number_of_philos)
		{
			pthread_mutex_destroy(&prog->philos[i]->eat_mutex);
			pthread_mutex_destroy(&prog->forks[i]);
			if (prog->philos[i])
				free(prog->philos[i]);
			i++;
		}
		if (prog->forks)
			free(prog->forks);
		if (prog->philos)
			free(prog->philos);
	}
	pthread_mutex_destroy(&prog->finished_mutex);
	pthread_mutex_destroy(&prog->death_mutex);
	pthread_mutex_destroy(&prog->bouncer);
}

/**
 * @brief frees allocated memory in case initializer function fails
 * 
 * @param prog main struct
 */
void	struct_cleaner(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->number_of_philos)
	{
		if (prog->philos[i])
			free(prog->philos[i]);
		i++;
	}
	if (prog->forks)
		free(prog->forks);
	free (prog->philos);
}
