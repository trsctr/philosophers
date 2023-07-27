/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:25:02 by trsctr            #+#    #+#             */
/*   Updated: 2023/07/27 18:46:35 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	bad_arguments(int errorcode)
{
	if (errorcode == 1)
	{
		printf("Invalid argument(s)!\n");
		printf("Only numbers are accepted. Given values must be above zero.\n");
		printf("Example: ./philo 2 210 100 100 2\n");
	}
	else
	{
		printf("Invalid amount of arguments!\n");
		printf("Example: ./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[optional: how_many_times_each_philosopher_must_eat]\n");
		printf("Time values must be milliseconds\n");
	}
}

void	print_msg(char *message, t_ulonglong timestamp, int id)
{
	printf("%llu %d %s\n", timestamp, id, message);
}
