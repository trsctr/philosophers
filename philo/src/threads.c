/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:20:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 18:22:59 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->settings->number_of_philosophers)
	{
		pthread_create(&prog->philo[i].tid, NULL, philo_routine, \
		&prog->philo[i]);
		prog->philo[i].prog = prog;
		prog->philo[i].max_meals = prog->settings->max_meals;
		prog->philo[i].meals_eaten = 0;
		prog->philo[i].id = i + 1;
		prog->philo[i].state = HUNGRY;
		printf("Philosopher #%d has entered the room\n", prog->philo[i].id);
		i++;
	}
}

void	join_threads(t_prog *prog)
{
	int i;

	i = 0;
	while (i < prog->settings->number_of_philosophers)
	{
		pthread_join(prog->philo[i].tid, NULL);
		printf("Philosopher #%d just farted and left the room, bastard.\n", prog->philo[i].id);
		i++;
	}
}
