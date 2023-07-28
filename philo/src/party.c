/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:57 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/28 18:49:32 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function initializes threads/philosophers, runs the routines, 
 * saves the starting time and runs the monitoring function
 * 
 * the "bouncer" mutex is locked before thread creation to ensure none of the
 * philosophers start eating until all the philosophers have arrived
 * 
 * @param prog main struct
 */
void	set_table(t_prog *prog)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&prog->bouncer);
	while (i < prog->number_of_philos)
	{
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

/**
 * @brief ends the party by joining the treads and then runs clean_table
 * which destroys mutexes and frees allocated memory
 * 
 * @param prog main struct
 */
void	end_party(t_prog *prog)
{
	int	i;

	i = prog->number_of_philos - 1;
	while (i >= 0)
	{
		if (pthread_join(prog->philos[i]->tid, NULL) != 0)
			printf("Failed to join thread for philo %d!\n", i);
		i--;
	}
	clean_table(prog);
}
