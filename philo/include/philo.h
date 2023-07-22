/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/22 18:45:02 by oandelin         ###   ########.fr       */
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

typedef struct s_prog	t_prog;

typedef struct s_settings{
	int					number_of_philosophers;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					max_meals;
}	t_settings;

typedef struct s_philosopher{
	int					id;
	int					state;
	int					meals_eaten;
	int					max_meals;
	unsigned long long	last_meal;
	t_prog				*prog;
	pthread_t			tid;
	pthread_mutex_t		*forks;
}	t_philosopher;

typedef struct s_prog{
	t_philosopher		philo[200];
	t_settings			*settings;
	int					finished;
	unsigned long long	big_bang;
	// mutex monitoring scriptia varten;
}	t_prog;


// OUTPUT

void	philo_is_thinking(unsigned long long timestamp, int philo_id);
void	philo_has_fork(unsigned long long timestamp, int philo_id);
void	philo_is_eating(unsigned long long timestamp, int philo_id);
void	philo_is_sleeping(unsigned long long timestamp, int philo_id);
void	philo_died(unsigned long long timestamp, int philo_id);
void	bad_arguments(void);

// UTILS

unsigned long long	get_time(void);
int					philo_atoi(const char *str);
int					ft_isdigit(int c);
int					save_settings(t_settings *settings, int argc, char **argv);
void				init(t_prog **prog);
void				*ft_calloc(size_t count, size_t size);
void				*ft_bzero(void *b, size_t len);
t_settings			*init_settings(void);

// THREADS N SHIT

void	create_threads(t_prog *prog);
void	join_threads(t_prog *prog);
void	*philo_routine(void *data);

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