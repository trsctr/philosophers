/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:14:52 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/28 16:50:01 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief monitoring function monitors the statuses of each philosopher.
 * it sets an infinite loop, exits if deathwatch function returns anything else
 * than 0, which would mean a philosopher has died, or if all philosophers
 * have reached max_meals. finished_mutex is locked prior to checking the
 * finished value to avoid race condition
 * 
 * @param prog 
 */
void	monitor(t_prog *prog)
{
	int	i;

	ft_usleep(prog, prog->time_to_die);
	while (1)
	{
		i = 0;
		while (i < prog->number_of_philos)
		{
			if (deathwatch(prog->philos[i]))
				return ;
			pthread_mutex_lock(&prog->finished_mutex);
			if (prog->finished >= prog->number_of_philos)
			{
				pthread_mutex_unlock(&prog->finished_mutex);
				return ;
			}
			pthread_mutex_unlock(&prog->finished_mutex);
			i++;
		}
		usleep(1000);
	}
}

/**
 * @brief deathwatch checks if a philosopher has starved
 * it lock's eat_mutex and death_mutex to avoid data race,
 * and current time and the time of philosophers last meal
 * if the difference exceeds time_to_die, the philosopher has
 * not finished eating, or the philosopher is the only one in
 * the table, it updates dead value in the main struct, prints
 * status update, unlocks mutexes and returns 1 to tell
 * the monitoring routine to exit the loop
 * if everything is alright, it unlocks the mutexes and returns 0.
 * 
 * @param philo current philosophers struct
 * @return int 0 if all is good, 1 if philosopher is starved
 */
int	deathwatch(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	pthread_mutex_lock(&philo->prog->death_mutex);
	if ((get_time() - philo->last_meal > philo->prog->time_to_die
			&& philo->finished == 0) || philo->prog->number_of_philos == 1)
	{
		philo->prog->dead++;
		philo_dies(philo);
		pthread_mutex_unlock(&philo->eat_mutex);
		pthread_mutex_unlock(&philo->prog->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->prog->death_mutex);
	pthread_mutex_unlock(&philo->eat_mutex);
	return (0);
}
