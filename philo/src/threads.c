/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:20:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/23 15:54:08 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_table(t_prog *prog)
{
	int	i;

	i = 0;
	prog->forks = malloc(sizeof (pthread_mutex_t) * prog->settings->number_of_philosophers);
	pthread_mutex_init(&prog->bouncer, NULL);
	pthread_mutex_lock(&prog->bouncer);
	while (i < prog->settings->number_of_philosophers)
	{
		pthread_create(&prog->philo[i].tid, NULL, philo_routine, \
		&prog->philo[i]);
		pthread_mutex_init(&prog->forks[i], NULL);
		prog->philo->left_fork = &prog->forks[i];
		prog->philo->right_fork = &prog->forks[i + 1 % prog->settings->number_of_philosophers];
		prog->philo[i].prog = prog;
		prog->philo[i].max_meals = prog->settings->max_meals;
		prog->philo[i].meals_eaten = 0;
		prog->philo[i].id = i + 1;
		prog->philo[i].state = HUNGRY;
		printf("Philosopher #%d has entered the room\n", prog->philo[i].id);
		i++;
	}
	pthread_mutex_unlock(&prog->bouncer);
}

void	clear_table(t_prog *prog)
{
	int i;

	i = 0;
	while (i < prog->settings->number_of_philosophers)
	{
		pthread_join(prog->philo[i].tid, NULL);
		pthread_mutex_destroy(&prog->forks[i]);
		printf("Philosopher #%d just farted and left the room, bastard.\n", prog->philo[i].id);
		i++;
	}
}
