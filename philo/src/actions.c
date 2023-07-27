/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:36:50 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:46:03 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is eating", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_has_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("has taken a fork", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_sleeps(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is sleeping", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_thinks(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is thinking", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_dies(t_philo *philo)
{
	print_msg("died", get_timestamp(philo->prog), philo->id);
}
