/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:14:52 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:29:07 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	monitor(t_prog *prog)
{
	int	i;

	yousleep(prog, prog->time_to_die);
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
