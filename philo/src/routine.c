/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:29 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 21:42:00 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->prog->bouncer);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(&philo->prog->bouncer);
	if (philo->id % 2 == 0)
	{
		philo_thinks(philo);
		usleep(philo->prog->time_to_eat);
	}
	while (1)
	{	
		pthread_mutex_lock(&philo->prog->forks[philo->left_fork]);
		philo_has_fork(philo);
		pthread_mutex_lock(&philo->prog->forks[philo->right_fork]);
		philo_has_fork(philo);
		pthread_mutex_lock(&philo->eat_mutex);
		philo->last_meal = get_time();
		philo->meals_eaten++;
		if (philo->meals_eaten >= philo->prog->max_meals && philo->prog->max_meals > 0)
		{
			pthread_mutex_lock(&philo->prog->finished_mutex);
			philo->prog->finished++;
			pthread_mutex_unlock(&philo->prog->finished_mutex);
			philo->finished++;
			pthread_mutex_unlock(&philo->eat_mutex);
			philo_eats(philo);
			usleep(philo->prog->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
			pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
			print_message("has finished eating", get_timestamp(philo->prog), philo->id, CYAN);
			break ;
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		philo_eats(philo);
		usleep(philo->prog->time_to_eat * 1000);
		philo_sleeps(philo);
		pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
		usleep(philo->prog->time_to_sleep * 1000);
		philo_thinks(philo);
		pthread_mutex_lock(&philo->prog->death_mutex);
		if (philo->prog->dead > 0)
		{
			pthread_mutex_unlock(&philo->prog->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->prog->death_mutex);
	}
}

