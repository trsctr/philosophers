/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:05:54 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/18 12:22:06 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_atoi(const char *str)
{
	int		i;
	long	res;
	long	dig;

	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		return (-1);
	}
	while (ft_isdigit(str[i]))
	{
		dig = str[i] - 48;
		res = res * 10 + dig;
		i++;
	}
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
		return (-1);
	else
		return (res);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	else
		return (settings);
}

int	save_settings(t_settings *settings, int argc, char **argv)
{
	settings->number_of_philosophers = philo_atoi(argv[1]);
	if (settings->number_of_philosophers < 0)
		return (-1);
	settings->time_to_die = philo_atoi(argv[2]);
	if (settings->time_to_die < 0)
		return (-1);
	settings->time_to_eat = philo_atoi(argv[3]);
	if (settings->time_to_die < 0)
		return (-1);	
	settings->time_to_sleep = philo_atoi(argv[4]);
	if (settings->time_to_die < 0)
		return (-1);	
	if (argc == 6)
		settings->max_meals = philo_atoi(argv[5]);
	else
		settings->max_meals = 0;
	if (settings->max_meals < 0)
		return (-1);
	return (0);
}
