/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:42:10 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/17 13:53:34 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_is_thinking(int timestamp, int philo_id)
{
	printf("%d %d is thinking", timestamp, philo_id);
}

void	philo_has_fork(int timestamp, int philo_id)
{
	printf("%d %d has taken a fork", timestamp, philo_id);
}

void	philo_is_eating(int timestamp, int philo_id)
{
	printf("%d %d is eating", timestamp, philo_id);
}

void	philo_is_sleeping(int timestamp, int philo_id)
{
	printf("%d %d is sleeping", timestamp, philo_id);
}

void	philo_died(int timestamp, int philo_id)
{
	printf("%d %d died", timestamp, philo_id);
}