/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:05:54 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/27 18:16:10 by oandelin         ###   ########.fr       */
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
		return (0);
	}
	while (ft_isdigit(str[i]))
	{
		dig = str[i] - 48;
		res = res * 10 + dig;
		i++;
	}
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
		return (0);
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

t_ulonglong	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (t_ulonglong)1000) + (time.tv_usec / 1000));
}

t_ulonglong	get_timestamp(t_prog *prog)
{
	return (get_time() - prog->start_time);
}

void	yousleep(t_prog *prog, t_ulonglong duration)
{
	t_ulonglong	start;

	start = get_time();
	while (get_time() - start < duration)
	{
		pthread_mutex_lock(&prog->death_mutex);
		if (prog->dead > 0)
		{
			pthread_mutex_unlock(&prog->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&prog->death_mutex);
		usleep(500);
	}
}
