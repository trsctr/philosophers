/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:20:04 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 19:01:23 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void init_philo (t_prog *prog, int i)
{
	prog->philo[i]->prog = prog;
	prog->philo[i]->id = i + 1;
	prog->philo[i]->left_fork = i;
	prog->philo[i]->right_fork = i + 1 % prog->number_of_philos;
	prog->philo[i]->max_meals = prog->max_meals;
	prog->philo[i]->meals_eaten = 0;
	prog->philo[i]->last_meal = 0;
	prog->philo[i]->state = HUNGRY;
}

void	set_table(t_prog *prog)
{
	int	i;

	i = 0;
	if(mutex_init(prog) < 0)
	{
		printf("something went wrong\n");
		return ;
	}
	pthread_mutex_lock(&prog->bouncer);
	prog->philo = malloc(sizeof(t_philosopher) * prog->number_of_philos);
	while (i < prog->number_of_philos)
	{
		prog->philo[i] = malloc(sizeof(t_philosopher));
		pthread_mutex_init(&prog->philo[i]->philomutex, NULL);
		init_philo(prog, i);
	 	pthread_create(&prog->philo[i]->tid, NULL, philo_routine, &prog->philo[i]);
	// 	pthread_mutex_init(&prog->forks[i], NULL);
	// 	prog->philo[i]->left_fork = &prog->forks[i];
	// 	prog->philo[i]->right_fork = &prog->forks[i + 1 % prog->number_of_philos];
	// 	prog->philo[i]->prog = prog;
	// 	prog->philo[i]->max_meals = prog->max_meals;
	// 	prog->philo[i]->meals_eaten = 0;
	// 	prog->philo[i]->id = i + 1;
	// 	prog->philo[i]->state = HUNGRY;
		printf("Philosopher #%d has entered the room\n", prog->philo[i]->id);
	 	i++;
	}
	pthread_mutex_unlock(&prog->bouncer);
}

void	clear_table(t_prog *prog)
{
	int i;

	i = 0;
	while (i < prog->number_of_philos)
	{
		pthread_join(prog->philo[i]->tid, NULL);
		pthread_mutex_destroy(&prog->philo[i]->philomutex);
		pthread_mutex_destroy(&prog->forks[i]);
		printf("Philosopher #%d just farted and left the room, bastard.\n", prog->philo[i]->id);
		i++;
	}
	pthread_mutex_destroy(&prog->bouncer);
}

int	mutex_init(t_prog *prog)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&prog->bouncer, NULL) != 0)
		printf("\nvituiks meni\n");
	prog->forks = malloc(sizeof (pthread_mutex_t) * prog->number_of_philos);
	while (i < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->forks[i], NULL) != 0)
		{
			printf("Failed to initialize mutex for fork %d\n", i);
			return (-1);
		}
		i++;
	}
	return (0);	
}