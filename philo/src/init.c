/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:39 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 17:36:47 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init(t_prog **prog)
{
	*prog = ft_calloc(1, sizeof(t_prog));
}

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	else
		return (settings);
}

int	save_settings(t_settings *settings, int argc, char **argv)
{
	settings->number_of_philosophers = philo_atoi(argv[1]);
	if (settings->number_of_philosophers < 0)
		return (-1);
	settings->time_to_die = (unsigned long long) philo_atoi(argv[2]);
	if (settings->time_to_die < 0)
		return (-1);
	settings->time_to_eat = (unsigned long long) philo_atoi(argv[3]);
	if (settings->time_to_die < 0)
		return (-1);	
	settings->time_to_sleep = (unsigned long long) philo_atoi(argv[4]);
	if (settings->time_to_die < 0)
		return (-1);	
	if (argc == 6)
		settings->max_meals = philo_atoi(argv[5]);
	else
		settings->max_meals = 0;
	if (settings->max_meals < 0)
		return (-1);
	return (0);
}

