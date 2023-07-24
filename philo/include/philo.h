/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/24 18:44:20 by oandelin         ###   ########.fr       */
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
# define NC	"\e[0m"
# define YELLOW	"\e[33m"
# define BYELLOW	"\e[1;33m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

enum	e_state {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
	DEAD = 4
};

typedef unsigned long long	t_ulonglong;
typedef struct s_prog		t_prog;

typedef struct s_philosopher{
	int					id;
	int					state;
	int					meals_eaten;
	int					max_meals;
	t_ulonglong			last_meal;
	int					left_fork;
	int					right_fork;
	pthread_t			tid;
	t_prog				*prog;
	pthread_mutex_t		philomutex;
	}	t_philosopher;

typedef struct s_prog{
	t_philosopher		**philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		bouncer;
	int					number_of_philos;
	t_ulonglong			time_to_die;
	t_ulonglong			time_to_eat;
	t_ulonglong			time_to_sleep;
	int					max_meals;
	int					finished;
	int					dead;
	t_ulonglong			start_time;
	// mutex monitoring scriptia varten;
}	t_prog;


// OUTPUT

void	print_message(char *message, t_ulonglong timestamp, int id, char *color);
void	philo_eats(t_philosopher *philo);
void	philo_is_thinking(t_ulonglong timestamp, int philo_id);
void	philo_has_fork(t_ulonglong timestamp, int philo_id);
void	philo_is_eating(t_ulonglong timestamp, int philo_id);
void	philo_is_sleeping(t_ulonglong timestamp, int philo_id);
void	philo_died(t_ulonglong timestamp, int philo_id);
void	bad_arguments(void);

// UTILS

t_ulonglong			get_time(void);
int					philo_atoi(const char *str);
int					ft_isdigit(int c);
int					save_settings(t_prog *prog, int argc, char **argv);
void				*ft_calloc(size_t count, size_t size);
void				*ft_bzero(void *b, size_t len);


// INIT
t_prog	*init_prog(void);
int	mutex_init(t_prog *prog);

// THREADS N SHIT

void	set_table(t_prog *prog);
void	clear_table(t_prog *prog);
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