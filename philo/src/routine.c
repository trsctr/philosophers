/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:30:36 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 19:02:17 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) data;

	//printf("philo %d routine running\n", philo->id);

 	// pthread_mutex_lock(&philo->prog->bouncer);
	// 	 usleep(4200);
 	// pthread_mutex_unlock(&philo->prog->bouncer);
// 	if (philo->id % 2 == 0)
// 		usleep(666);
	printf("%d\n\n\n", philo->left_fork);
 	philo->last_meal = get_time();
 	while (1)
 	{
 		pthread_mutex_lock(&philo->prog->forks[philo->left_fork]);
 		print_message("took left fork", get_time(), philo->id, GREEN);
 		pthread_mutex_lock(&philo->prog->forks[philo->right_fork]);
 		print_message("took right fork", get_time(), philo->id, GREEN);
 		philo_has_fork(get_time(), philo->id);
		pthread_mutex_lock(&philo->philomutex);
 		philo->meals_eaten++;
		philo->last_meal = get_time();
		philo_eats(philo);
		usleep(philo->prog->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->prog->forks[philo->right_fork]);
 		printf("%sphilo %d gave away right fork%s\n", GREEN, philo->id, NC);
 		pthread_mutex_unlock(&philo->prog->forks[philo->left_fork]);
 		printf("%sphilo %d gave away left fork%s\n", GREEN, philo->id, NC);
		pthread_mutex_unlock(&philo->philomutex);
	
		
// //		if (philo->meals_eaten == philo->max_meals)
// //			break ;
		philo_is_sleeping(get_time(), philo->id);
		usleep(philo->prog->time_to_sleep * 1000);
		philo_is_thinking(get_time(), philo->id);
// //		if (get_time() - philo->last_meal > philo->prog->settings->time_to_die)
// //		{
// //			philo_died(get_time(), philo->id);
// //			break ;
	}
// // 	// while(philosopher->state != DEAD && counter < prog->settings->time_to_die)
// // 	// {
// // 	// 	if(philosopher->state == SLEEPING)
// // 	// 		think();
// // 	// 	if(philosopher->state == HUNGRY && left_fork_is_free)
// // 	// 		take_left_fork();
// // 	// 	if(has_left_fork && right_fork_is_free);
// // 	// 		take_right_fork();
// // 	// 	if(philosopher->state == HUNGRY && has_forks);
// // 	// 		eat();
// // 	// 	if()
	
 	return (NULL);
	 }
