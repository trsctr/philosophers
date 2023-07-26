/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:36:50 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 21:25:41 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_message("is eating", get_timestamp(philo->prog), philo->id, BYELLOW);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_has_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if (philo->prog->dead == 0)
		print_message("has taken a fork", get_timestamp(philo->prog), philo->id, GREEN);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_sleeps(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if(philo->prog->dead == 0)
		print_message("is sleeping", get_timestamp(philo->prog), philo->id, PURPLE);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}

void	philo_thinks(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->death_mutex);
	if(philo->prog->dead == 0)
		print_message("is thinking", get_timestamp(philo->prog), philo->id, BLUE);
	pthread_mutex_unlock(&philo->prog->death_mutex);
}
void	print_message(char *message, t_ulonglong timestamp, int id, char *color)
{
	printf("%s%llu %d %s %s\n", color, timestamp, id, message, NC);
}