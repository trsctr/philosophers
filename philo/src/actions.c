/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:42:10 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 18:32:09 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_is_thinking(unsigned long long timestamp, int philo_id)
{
	printf("%llu %d is thinking\n", timestamp, philo_id);
}

void	philo_has_fork(unsigned long long  timestamp, int philo_id)
{
	printf("%llu %d has taken a fork\n", timestamp, philo_id);
}

void	philo_is_eating(unsigned long long timestamp, int philo_id)
{
	printf("%llu %d is eating\n", timestamp, philo_id);
}

void	philo_is_sleeping(unsigned long long timestamp, int philo_id)
{
	printf("%llu %d is sleeping\n", timestamp, philo_id);
}

void	philo_died(unsigned long long timestamp, int philo_id)
{
	printf("%llu %d died\n", timestamp, philo_id);
}