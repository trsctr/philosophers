/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:39 by oandelin          #+#    #+#             */
/*   Updated: 2023/10/10 19:23:04 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief Initializes the main struct, arrays and mutexes and saves settings
 * 
 * @param prog the main struct
 * @param argc argument count
 * @param argv command line arguments
 * @return int 0 if successful, -1 if unsuccessful
 */
int	initializer(t_prog *prog, int argc, char **argv)
{
	prog->finished = 0;
	prog->dead = 0;
	prog->start_time = 0;
	if (save_settings(prog, argc, argv) < 0)
	{
		bad_arguments(1);
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

/**
 * @brief Converts command line arguments to ints or unsigned long long values
 * using custom atoi function, and saves them to the main struct
 * last argument is optional, if it's not given in command line, max_meals
 * is set to -1.
 * 
 * @param prog the main struct
 * @param argc argument count
 * @param argv command line arguments
 * @return int 0 if successful, -1 if failed
 */
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

/**
 * @brief Initializes the philosopher and fork arrays in main struct
 * and allocates memory * based on the parameters given in command line arguments
 * 
 * @param prog main struct
 * @return int 0 if succesful, -1 if unsuccessful
 */
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

/**
 * @brief initializes bouncer, death and finished -mutexes, 
 * as well as fork mutexes and eat mutexes for each philosopher
 * 
 * @param prog struct
 * @return int 0 if succesful, -1 if unsuccesful
 */
int	init_mutexes(t_prog *prog)
{
	int	counter;

	counter = 0;
	if (pthread_mutex_init(&prog->bouncer, NULL) != 0
		|| pthread_mutex_init(&prog->death_mutex, NULL) != 0
		|| pthread_mutex_init(&prog->finished_mutex, NULL) != 0)
	{
		printf("Mutex initialization failed!\n");
		return (-1);
	}
	while (counter < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->forks[counter], NULL) != 0
			|| pthread_mutex_init(&prog->philos[counter]->eat_mutex, NULL) != 0)
		{
			printf("Mutex initialization failed!\n");
			return (-1);
		}
		counter++;
	}
	return (0);
}

/**
 * @brief initializes values for each philosopher in the array
 * 
 * @param prog main struct which contains the philosopher array
 * @param i number of the philosopher to be initialized
 */
void	init_philo(t_prog *prog, int i)
{
	prog->philos[i]->id = i + 1;
	prog->philos[i]->left_fork = i;
	prog->philos[i]->right_fork = (i + 1) % prog->number_of_philos;
	prog->philos[i]->meals_eaten = 0;
	prog->philos[i]->last_meal = 0;
	prog->philos[i]->prog = prog;
}
