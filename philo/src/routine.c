/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:30:36 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 18:36:28 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *) data;
	philo->last_meal = get_time();
	while (1)
	{
		philo->last_meal = get_time();
		philo->meals_eaten++;
		philo_is_eating(philo->last_meal, philo->id);
		usleep(philo->prog->settings->time_to_eat * 1000);
		if (philo->meals_eaten == philo->max_meals)
			break;
		philo_is_sleeping(get_time(), philo->id);
		usleep(philo->prog->settings->time_to_sleep * 1000);
		philo_is_thinking(get_time(), philo->id);
		if(get_time() - philo->last_meal > philo->prog->settings->time_to_die)
		{
			philo_died(get_time(), philo->id);
			break;
		}
	}
	// while(philosopher->state != DEAD && counter < prog->settings->time_to_die)
	// {
	// 	if(philosopher->state == SLEEPING)
	// 		think();
	// 	if(philosopher->state == HUNGRY && left_fork_is_free)
	// 		take_left_fork();
	// 	if(has_left_fork && right_fork_is_free);
	// 		take_right_fork();
	// 	if(philosopher->state == HUNGRY && has_forks);
	// 		eat();
	// 	if()
	
	return (NULL);
}
