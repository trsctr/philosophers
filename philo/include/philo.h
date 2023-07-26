/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/26 21:34:39 by oandelin         ###   ########.fr       */
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
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[1;36m"

enum	e_state {
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3,
	DEAD = 4
};

typedef unsigned long long	t_ulonglong;
typedef struct s_prog		t_prog;

typedef struct s_philo{
	int					id;
	int					meals_eaten;
	t_ulonglong			last_meal;
	int					finished;
	int					left_fork;
	int					right_fork;
	pthread_t			tid;
	t_prog				*prog;
	pthread_mutex_t		eat_mutex;
}	t_philo;

typedef struct s_prog{
	t_philo				**philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		bouncer;
	t_ulonglong			start_time;
	int					number_of_philos;
	t_ulonglong			time_to_die;
	t_ulonglong			time_to_eat;
	t_ulonglong			time_to_sleep;
	int					max_meals;
	pthread_mutex_t		death_mutex;
	int					dead;
	pthread_mutex_t		finished_mutex;
	int					finished;
}	t_prog;


// OUTPUT

void	print_message(char *message, t_ulonglong timestamp, int id, char *color);
void	philo_eats(t_philo *philo);
void	philo_has_fork(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_thinks(t_philo *philo);
void	bad_arguments(void);

// UTILS

int			philo_atoi(const char *str);
int			ft_isdigit(int c);
t_ulonglong	get_time(void);
t_ulonglong get_timestamp(t_prog *prog);


// INIT

int		initializer(t_prog *prog, int argc, char **argv);
int		save_settings(t_prog *prog, int argc, char **argv);
int		init_arrays(t_prog *prog);
int		init_mutexes(t_prog *prog);
void	init_philo(t_prog *prog, int i);

// THREADS N SHIT

void	set_table(t_prog *prog);
void	philo_routine(void *data);
void	deathwatch(t_prog *prog);

// EXIT & CLEANUP

void	end_party(t_prog *prog);
void	clean_table(t_prog *prog);

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