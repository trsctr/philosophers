/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:05:54 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/28 16:49:02 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief custom atoi function to convert command line arguments to integers
 * accepts only numbers and returns 0 to the save_settings function if 
 * the given string contains anything else than numbers, or if the number
 * exceeds INT_MAX
 * 
 * @param str command line argument
 * @return int command line argument converted to an integer, or 0 if the
 * argument is invalid
 */
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
	if (res > INT_MAX)
		return (0);
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
		return (0);
	else
		return (res);
}

/**
 * @brief checks if given character is a digit
 * 
 * @param c 
 * @return int 1 if character is a digit. 0 if it is not.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * @brief gets current time and converts it from seconds and microseconds
 * to milliseconds
 * 
 * @return t_ulonglong unsigned long long value of current time in milliseconds
 */
t_ulonglong	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (t_ulonglong)1000) + (time.tv_usec / 1000));
}

/**
 * @brief uses get_time() function to return timestamp which is the difference
 * between current time and the starting time which is set when threads have
 * been initialized
 * 
 * @param prog 
 * @return t_ulonglong 
 */
t_ulonglong	get_timestamp(t_prog *prog)
{
	return (get_time() - prog->start_time);
}

/**
 * @brief custom sleep function as usleep is inaccurate when dealing with
 * larger values. gets the duration of the sleep in milliseconds in arguments.
 * gets start time by using get_time and then enters a while loop where it stays
 * as long as the difference between current time and starting time of the
 * sleep is smaller than the duration specified in arguments
 * during the loop it also checks if any philosopher has died, and exits the loop
 * if that happens. in the end of the loop it sleeps for half a millisecond
 * to avoid constant checking of the dead value
 * 
 * @param prog main struct which contains mutexes main data
 * @param duration duration of the sleep in milliseconds
 */
void	ft_usleep(t_prog *prog, t_ulonglong duration)
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
		pthread_mutex_lock(&prog->finished_mutex);
		if (prog->finished >= prog->number_of_philos)
		{
			pthread_mutex_unlock(&prog->finished_mutex);
			break ;
		}
		pthread_mutex_unlock(&prog->finished_mutex);
		usleep(500);
	}
}
