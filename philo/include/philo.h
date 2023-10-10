/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:19 by oandelin          #+#    #+#             */
/*   Updated: 2023/10/10 19:22:56 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

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

void			print_msg(char *message, t_ulonglong timestamp, int id);
void			philo_has_fork(t_philo *philo);
void			philo_eats(t_philo *philo);
void			philo_thinks(t_philo *philo);
void			philo_sleeps(t_philo *philo);
void			philo_dies(t_philo *philo);
void			bad_arguments(int errorcode);

// INIT

int				initializer(t_prog *prog, int argc, char **argv);
int				save_settings(t_prog *prog, int argc, char **argv);
int				init_arrays(t_prog *prog);
int				init_mutexes(t_prog *prog);
void			init_philo(t_prog *prog, int i);
void			set_table(t_prog *prog);

// PARTY TIME

void			philo_routine(void *data);
int				start_routine(t_philo *philo);
int				life_of_philo(t_philo *philo);
int				finish_eating(t_philo *philo);
void			monitor(t_prog *prog);
int				deathwatch(t_philo *philo);

// EXIT & CLEANUP

void			end_party(t_prog *prog);
void			clean_table(t_prog *prog);

// UTILS

int				philo_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_usleep(t_prog *prog, t_ulonglong duration);
t_ulonglong		get_time(void);
t_ulonglong		get_timestamp(t_prog *prog);
void			struct_cleaner(t_prog *prog);

#endif