/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/17 16:13:40 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>


enum	e_state {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
	DEAD = 4
};

typedef struct s_settings{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}	t_settings;


// OUTPUT

void	philo_is_thinking(int timestamp, int philo_id);
void	philo_has_fork(int timestamp, int philo_id);
void	philo_is_eating(int timestamp, int philo_id);
void	philo_is_sleeping(int timestamp, int philo_id);
void	philo_died(int timestamp, int philo_id);


// UTILS

int		philo_atoi(const char *str);
int		ft_isdigit(int c);
int	save_settings(t_settings *settings, int argc, char **argv);
t_settings *init_settings(void);


#endif
/*
External functs.
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
Libft authorized
No
Description
Philosophers with threads and mutexes*/