/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:02:19 by meid              #+#    #+#             */
/*   Updated: 2025/03/07 17:02:38 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "libft/libft.h"
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free
#include <string.h>     // memset
#include <unistd.h>     // write, usleep
#include <sys/time.h>   // gettimeofday
#include <pthread.h>    // pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

#define GREEN  "\033[0;32m"
#define BLUE   "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET  "\033[0m"
#define NOODLES   "🍜"
#define FRIES     "🍟"
#define BURGER    "🍔"
#define DYING     "💀"
#define SLEEPY    "😴"

struct s_philos; 

typedef struct s_info{
    int *forks;
    int *pihlo_id;
    int *state_tracking; // 1 eatng 2 sleep 3 thinking 4 die
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
    int flag_for_arg5;
    int i;
    unsigned long long first_time;
    struct s_philos *philos;
    // int *current_index;
    pthread_t *th;
    pthread_mutex_t *mutex;
}           t_info;

typedef struct s_philos{
    int philo_id;
    int left_fork;
    int right_fork;
    int eat_num;
    pthread_t thread;
    t_info *info;
}               t_philo;

//---------------------------philo--------------------------------//

//-----------clean.c-----------//
void clean_up(t_info *info);

//-----------print.c-----------//
void print_with_color(char *msg, char *color);
void print_emoji(char *msg);
void print_info(t_info *info);
void print_array(int *array, int i);
void print_philo_status(unsigned long long time, int philo_num, char *msg);

//-----------parsing.c-----------//
int check_is_valid(char **av);
int check_logic_num(int ac, t_info *info);

//-----------parsing.c-----------//
int *make_pihlo_array(int philo_num, int i);
int *make_neutral_array(int philo_num, int i);
pthread_mutex_t *make_mutex_array(int philo_num, int i);
t_philo *philo_struct_array(t_info *info, int num_of_philos, int i);

//-----------philo.c-----------//
int philo(t_info *info, int i);

//-----------utils.c-----------//
unsigned long long current_time(void);

#endif
