/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:05:54 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 17:59:05 by oandelin         ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*blk;
	size_t	total;

	if (!count || !size)
		return (ft_calloc(1, 1));
	total = size * count;
	if (total / count != size)
		return (NULL);
	blk = malloc(total);
	if (!blk)
		return (NULL);
	ft_bzero(blk, total);
	return (blk);
}

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *) b;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
	return (b);
}

t_ulonglong	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec / 1000) + (current_time.tv_usec * 1000));
}