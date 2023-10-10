/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:29 by oandelin          #+#    #+#             */
/*   Updated: 2023/10/10 19:27:37 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief routine function for each philosopher thread
 * first it runs the start_routine function and then sets an infinite loop
 * where it runs life_of_philo function and exits the loop if philosopher dies,
 * someone else dies or the philosopher reaches the max_meals
 * if start_routine returns 1, the function exits before entering the loop
 * this is done to avoid a deadlock situation when there is only one philo
 * 
 * @param data data passed to this function in the thread initialization
 * which in this case is philosophers information and mutexes
 */
void	philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (start_routine(philo))
		return ;
	while (1)
	{
		if (life_of_philo(philo))
			break ;
		pthread_mutex_lock(&philo->prog->death_mutex);
		if (philo->prog->dead > 0)
		{
			pthread_mutex_unlock(&philo->prog->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->prog->death_mutex);
	}
}

/**
 * @brief this function is run at the start of each routine
 * it locks the bouncer mutex and eat mutex and sets time of last meal
 * to current time, thinks for a while and if the philosophers number
 * is even, it waits for a brief moment before continuing to avoid
 * potential deadlocks
 * it also checks if there is only one philosopher by checking if
 * number for the right and left forks are the same. in that case
 * it prints that philsopher as taken the fork and returns 1
 * which will cause the routine to exit and not enter the loop,
 * as entering the loop would cause a deadlock
 * 
 * @param philo current philosophers struct
 * @return int 0 after routine start is finished.
 * 1 if both fork id's are the same to avoid a deadlock situation. 
 */
int	start_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->bouncer);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(&philo->prog->bouncer);
	philo_thinks(philo);
	ft_usleep(philo->prog, philo->prog->time_to_eat * 0.1);
	if (philo->id % 2 == 0)
	{
		ft_usleep(philo->prog, philo->prog->time_to_eat * 0.1);
	}
	if (philo->left_fork == philo->right_fork)
	{
		philo_has_fork(philo);
		return (1);
	}
	return (0);
}

/**
 * @brief philosopher's exciting lifecycle
 * locks fork mutexes if they are available, then locks
 * eat mutex to update last_meal and meals_eaten values
 * unlocks eat_mutex, prints status update with timestamp
 * and eats using custom ft_usleep function for the time_to_eat
 * time specified in command line args
 * routine then releases the fork mutexes, prints "philo sleeps"
 * status update and sleeps for time time specified in 
 * command line args
 * then the philosopher thinks and the thread returns to the
 * while loop in main routine
 * if philosopher reaches the max_meals specified in command line
 * args, function returns 1 to tell the main routine to exit
 * the while loop 
 * 
 * @param philo current philosophers struct
 * @return int 1 if philosopher has eaten enough meals, 0 otherwise
 */
int	life_of_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->prog->forks[philo->left_fork]);
	philo_has_fork(philo);
	pthread_mutex_lock(&philo->prog->forks[philo->right_fork]);
	philo_has_fork(philo);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	if (philo->prog->max_meals > 0 && finish_eating(philo))
		return (1);
	pthread_mutex_unlock(&philo->eat_mutex);
	philo_eats(philo);
	ft_usleep(philo->prog, philo->prog->time_to_eat);
	pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
	philo_sleeps(philo);
	ft_usleep(philo->prog, philo->prog->time_to_sleep);
	philo_thinks(philo);
	return (0);
}

/**
 * @brief checks if philosopher has eaten enough.
 * this function is not run if max_meals has not been specified
 * in the command line arguments
 * 
 * @param philo 
 * @return int 
 */
int	finish_eating(t_philo *philo)
{
	if (philo->meals_eaten >= philo->prog->max_meals)
	{
		pthread_mutex_lock(&philo->prog->finished_mutex);
		philo->prog->finished++;
		pthread_mutex_unlock(&philo->prog->finished_mutex);
		philo->finished++;
		pthread_mutex_unlock(&philo->eat_mutex);
		philo_eats(philo);
		ft_usleep(philo->prog, philo->prog->time_to_eat);
		pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
		return (1);
	}
	return (0);
}
