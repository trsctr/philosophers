/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:36:50 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 21:35:46 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief prints status change in format "timestamp philo_id is eating"
 * uses print_msg to print the message and get_timestamp to get the timestamp.
 * before printing the function checks if any philosopher has died.
 * this is made to avoid printing any statuses after a death of a philosopher.
 * death mutex is unlocked to avoid data race
 * 
 * @param philo 
 */
void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is eating", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

/**
 * @brief prints status change in format "timestamp philo_id has taken a fork"
 * uses print_msg to print the message and get_timestamp to get the timestamp.
 * before printing the function checks if any philosopher has died.
 * this is made to avoid printing any statuses after a death of a philosopher.
 * death mutex is unlocked to avoid data race
 * 
 * @param philo 
 */
void	philo_has_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("has taken a fork", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

/**
 * @brief prints status change in format "timestamp philo_id is sleeping"
 * uses print_msg to print the message and get_timestamp to get the timestamp.
 * before printing the function checks if any philosopher has died.
 * this is made to avoid printing any statuses after a death of a philosopher.
 * death mutex is unlocked to avoid data race
 * 
 * @param philo 
 */
void	philo_sleeps(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is sleeping", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

/**
 * @brief prints status change in format "timestamp philo_id is thinking"
 * uses print_msg to print the message and get_timestamp to get the timestamp.
 * before printing the function checks if any philosopher has died.
 * this is made to avoid printing any statuses after a death of a philosopher.
 * death mutex is unlocked to avoid data race
 * 
 * @param philo 
 */
void	philo_thinks(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_msg("is thinking", get_timestamp(philo->prog), philo->id);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

/**
 * @brief prints status change in format "timestamp philo_id died"
 * uses print_msg to print the message and get_timestamp to get the timestamp.
 * 
 * @param philo 
 */
void	philo_dies(t_philo *philo)
{
	print_msg("died", get_timestamp(philo->prog), philo->id);
}
