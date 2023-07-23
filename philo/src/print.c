/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:36:50 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/23 14:03:19 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philosopher *philo)
{
	print_message("is eating", philo->last_meal, philo->id, BYELLOW);
}

void	print_message(char *message, unsigned long long timestamp, int id, char *color)
{
	printf("%s%llu %d %s %s\n", color, timestamp, id, message, NC);
}