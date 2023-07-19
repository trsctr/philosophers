/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:25:02 by trsctr            #+#    #+#             */
/*   Updated: 2023/07/19 13:25:46 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	bad_arguments(void)
{
	printf("Invalid amount of arguments!\n");
	printf("Example: ./philo number_of_philosophers time_to_die_in_ms ");
	printf("time_to_eat_in_ms time_to_sleep_in_ms ");
	printf("[optional: how_many_times_each_philosopher_must_eat]\n");
}
