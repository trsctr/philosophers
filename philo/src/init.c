/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:39 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 21:36:25 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	initializer(t_prog *prog, int argc, char **argv)
{
	prog->finished = 0;
	prog->dead = 0;
	prog->start_time = 0;
	if (save_settings(prog, argc, argv) < 0)
	{
		printf("your input is bad and you should feel bad\n");
		return (-1);
	}
	if (init_arrays(prog) < 0)
	{
		printf("failed to allocate memory");
		return (-1);
	}
	if (init_mutexes(prog) < 0)
		return (-1);
	return (0);
}

int	save_settings(t_prog *prog, int argc, char **argv)
{
	prog->number_of_philos = philo_atoi(argv[1]);
	if (prog->number_of_philos < 1)
		return (-1);
	prog->time_to_die = (t_ulonglong) philo_atoi(argv[2]);
	if (prog->time_to_die < 1)
		return (-1);
	prog->time_to_eat = (t_ulonglong) philo_atoi(argv[3]);
	if (prog->time_to_eat < 1)
		return (-1);
	prog->time_to_sleep = (t_ulonglong) philo_atoi(argv[4]);
	if (prog->time_to_sleep < 1)
		return (-1);
	if (argc == 6)
	{
		prog->max_meals = philo_atoi(argv[5]);
		if (prog->max_meals == 0)
			return (-1);
	}
	else
		prog->max_meals = -1;
	return (0);
}

int	init_arrays(t_prog *prog)
{
	int	counter;

	counter = 0;
	prog->philos = malloc(sizeof(t_philo) * prog->number_of_philos);
	if (!prog->philos)
		return (-1);
	while (counter < prog->number_of_philos)
	{
		prog->philos[counter] = malloc(sizeof(t_philo));
		if (!prog->philos[counter])
			return (-1);
		counter++;
	}
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->number_of_philos);
	if (!prog->forks)
		return (-1);
	return (0);
}


int	init_mutexes(t_prog *prog)
{
	int	counter;

	counter = 0;
	if (pthread_mutex_init(&prog->bouncer, NULL) != 0)
		printf("Failed to initialize bouncer mutex!\n");
	if (pthread_mutex_init(&prog->death_mutex, NULL) != 0)
		printf("Failed to initialize death mutex!\n");
	if (pthread_mutex_init(&prog->finished_mutex, NULL) != 0)
		printf("Failed to initialize finished mutex!\n");
	while (counter < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->forks[counter], NULL) != 0)
			printf("Failed to initialize mutex for fork #%d", counter);
		counter++;
	}
	return (0);
}

void	init_philo(t_prog *prog, int i)
{
	prog->philos[i]->id = i + 1;
	prog->philos[i]->left_fork = i;
	prog->philos[i]->right_fork = i + 1 % prog->number_of_philos;
	prog->philos[i]->meals_eaten = 0;
	prog->philos[i]->last_meal = 0;
	prog->philos[i]->prog = prog;

}
