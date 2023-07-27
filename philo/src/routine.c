/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:29 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:28:52 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (start_routine(philo))
		return ;
	while (1)
	{	
		if (life_of_philo(philo))
			break ;
		pthread_mutex_lock(&philo->prog->death_mutex);
		if (philo->prog->dead > 0)
		{
			pthread_mutex_unlock(&philo->prog->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->prog->death_mutex);
	}
}

int	life_of_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->forks[philo->left_fork]);
	philo_has_fork(philo);
	pthread_mutex_lock(&philo->prog->forks[philo->right_fork]);
	philo_has_fork(philo);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	if (philo->prog->max_meals > 0 && finish_eating(philo))
		return (1);
	pthread_mutex_unlock(&philo->eat_mutex);
	philo_eats(philo);
	yousleep(philo->prog, philo->prog->time_to_eat);
	pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
	philo_sleeps(philo);
	yousleep(philo->prog, philo->prog->time_to_sleep);
	philo_thinks(philo);
	return (0);
}

int	finish_eating(t_philo *philo)
{
	if (philo->meals_eaten >= philo->prog->max_meals)
	{
		pthread_mutex_lock(&philo->prog->finished_mutex);
		philo->prog->finished++;
		pthread_mutex_unlock(&philo->prog->finished_mutex);
		philo->finished++;
		pthread_mutex_unlock(&philo->eat_mutex);
		philo_eats(philo);
		yousleep(philo->prog, philo->prog->time_to_eat);
		pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
		return (1);
	}
	return (0);
}

int	start_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->bouncer);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(&philo->prog->bouncer);
	philo_thinks(philo);
	if (philo->id % 2 == 0)
	{
		yousleep(philo->prog, philo->prog->time_to_eat * 0.1);
	}
	if (philo->left_fork == philo->right_fork)
	{
		philo_has_fork(philo);
		return (1);
	}
	return (0);
}
