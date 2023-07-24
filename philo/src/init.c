/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:39 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 18:38:55 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_prog	*init_prog(void)
{
	t_prog *prog;
	
	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (NULL);
	else
		prog->philo = NULL;
	return(prog);
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
	if (prog->time_to_die < 1)
		return (-1);	
	prog->time_to_sleep = (t_ulonglong) philo_atoi(argv[4]);
	if (prog->time_to_die < 1)
		return (-1);	
	if (argc == 6)
	{
		prog->max_meals = philo_atoi(argv[5]);
		if (prog->max_meals == 0)
			return (-1);
	}
	else
		prog->max_meals = 0;
	return (0);
}

