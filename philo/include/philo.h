/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/23 15:50:32 by oandelin         ###   ########.fr       */
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
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philosopher;

typedef struct s_prog{
	t_philosopher		philo[200];
	t_settings			*settings;
	pthread_mutex_t		*forks;
	int					finished;
	unsigned long long	big_bang;
	pthread_mutex_t		bouncer;
	// mutex monitoring scriptia varten;
}	t_prog;


// OUTPUT

void	print_message(char *message, unsigned long long timestamp, int id, char *color);
void	philo_eats(t_philosopher *philo);
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