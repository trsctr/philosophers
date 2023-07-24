/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:36:50 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 17:57:12 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philosopher *philo)
{
	print_message("is eating", philo->last_meal, philo->id, BYELLOW);
}

void	print_message(char *message, t_ulonglong timestamp, int id, char *color)
{
	printf("%s%llu %d %s %s\n", color, timestamp, id, message, NC);
}