/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:10:09 by meid              #+#    #+#             */
/*   Updated: 2025/03/20 11:45:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libraries
# include "libft/libft.h"
# include <pthread.h>  // pthread_create, pthread_detach, pthread_join,
# include <stdbool.h>  //bool
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep
// pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// color
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

// mode
# define EAT "is eating"
# define FORK "has taken a fork"
# define DIE "died"
# define SLEEP "is sleeping"
# define THINK "is thinking"

// structs
struct	s_philos;

typedef struct s_info
{
	bool				not_dead;
	unsigned long long	philos_num;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	minimum_eat;
	unsigned long long	*forks;
	unsigned long long	begin_time;
	struct s_philos		*philos;
	pthread_t			*th;
	pthread_t			checker;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		print_mutex;
}						t_info;

typedef struct s_philos
{
	unsigned long long	philo_id;
	unsigned long long	left_fork;
	unsigned long long	right_fork;
	unsigned long long	eat_times;
	unsigned long long	last_eat;
	pthread_t			thread;
	t_info				*p_info;
}						t_philo;

//---------------------------info_struct--------------------------------//

//---------------------args_check.c---------------------//
int						args_check(int ac, char **av, int i, int j);

//---------------------fill_info.c---------------------//
int						fill_some_info(t_info *i, int ac, char **av);

//---------------------create_arrays.c---------------------//
unsigned long long		*make_pihlo_array(unsigned long long philo_num,
							unsigned long long i);
pthread_mutex_t			*make_mutex_array(int philo_num, int i);
t_philo					*philo_struct_array(t_info *info, int num_of_philos,
							int i);

//---------------------------philo_life--------------------------------//

//---------------------philo.c---------------------//
int						philo_life_circle(t_info *info, unsigned long long i);
void					check_order(t_philo *philo, int *first, int *next);

//---------------------philo_act.c---------------------//
int						eating(t_philo *philo, int first, int next);
int						sleeping(t_philo *philo);
int						thinking(t_philo *philo);
void					philo_died(t_info *info, int i, int flag);

//---------------------------utils_file--------------------------------//

//---------------------utils.c---------------------//
unsigned long long		current_time_ms(void);
int						accurate_usleep(unsigned long long time,
							t_philo *philo);
int						check_death(t_info *info);

//---------------------clean.c---------------------//
void					clean_up(t_info *info, int flag);

//---------------------print.c---------------------//
int						philo_status(t_philo *philo, char *msg);

#endif
