/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:18:26 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 17:27:11 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_philo_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->p_info->print_mutex);
    if (ft_strcmp(msg, "die"))
    {
        printf("\033[34min %llu ms %d is \033[00m", current_time() - philo->p_info->first_time, philo->philo_id);
        print_emoji(msg);
    }
    if (check_death(philo->p_info) == 0)
        return(pthread_mutex_unlock(&philo->p_info->print_mutex), 1);
    return (printf("\033[34min %llu ms %d is \033[00m", current_time() - philo->p_info->first_time, philo->philo_id),
        print_emoji(msg), pthread_mutex_unlock(&philo->p_info->print_mutex), 0);
}

void print_with_color_2(char *msg, char *color)
{
    if (ft_strcmp(color, "bright yellow"))
        printf("\033[93m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright blue"))
        printf("\033[94m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright magenta"))
        printf("\033[95m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright cyan"))
        printf("\033[96m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright white"))
        printf("\033[97m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "orange"))
        printf("\033[38;2;255;165;0m%s\033[0m\n", msg);
}

void print_with_color(char *msg, char *color)
{
    if (ft_strcmp(color, "black"))
        printf("\033[30m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "red"))
        printf("\033[31m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "green"))
        printf("\033[32m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "yellow"))
        printf("\033[33m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "blue"))
        printf("\033[34m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "Magenta"))
        printf("\033[35m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "cyan"))
        printf("\033[36m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "white"))
        printf("\033[37m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright black"))
        printf("\033[90m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright red"))
        printf("\033[91m%s\033[0m\n", msg);
    else if (ft_strcmp(color, "bright green"))
        printf("\033[92m%s\033[0m\n", msg);
    else
        print_with_color_2(msg, color);
}

void print_emoji(char *msg)
{
    if (ft_strcmp(msg, "eat"))
        printf("\033[34meating\033[0m %s %s %s\n", NOODLES, FRIES, BURGER);
    else if (ft_strcmp(msg, "sleep"))
        printf("\033[34msleaping\033[0m %s\n", SLEEPY);
    else if (ft_strcmp(msg, "die"))
        printf("\033[34mdied\033[0m %s\n", DYING);
    else if (ft_strcmp(msg, "think"))
        printf("\033[34mthink\033[0m %s\n", THINK);
    else if (ft_strcmp(msg, "fork"))
        printf("\033[34mfork\033[0m %s\n", FORK);
}

void print_info(t_info *info)
{
    int i = 0;
    print_with_color("info->number_of_philosophers", "green");
    char *num = ft_itoa(info->number_of_philosophers);
    print_with_color(num, "green");
    free(num);
    print_with_color("info->time_to_die", "green");
    num = ft_itoa(info->time_to_die);
    print_with_color(num, "green");
    free(num);
    print_with_color("info->time_to_eat", "green");
    num = ft_itoa(info->time_to_eat);
    print_with_color(num, "green");
    free(num);
    print_with_color("info->time_to_sleep", "green");
    num = ft_itoa(info->time_to_sleep);
    print_with_color(num, "green");
    free(num);
    if (info->number_of_times_each_philosopher_must_eat != -1)
    {
        print_with_color("info->number_of_times_each_philosopher_must_eat", "green");
        num = ft_itoa(info->number_of_times_each_philosopher_must_eat);
        print_with_color(num, "green");
    }
    print_with_color("forks array", "orange");
    while(i < info->number_of_philosophers)
    {
        printf("forks[%d] = %d\n", i, info->forks[i]);
        i++;
    }
    i = 0;
    print_with_color("....................................", "green");
    while (i < info->number_of_philosophers)
    {
        printf("info->philos[i].philo_id: %d\n", info->philos[i].philo_id);
		printf("info->philos[i].left_fork: %d\n", info->philos[i].left_fork);
		printf("info->philos[i].right_fork: %d\n", info->philos[i].right_fork);
		printf("info->philos[i].eat_num: %d\n", info->philos[i].eat_num);
        print_with_color("....................................", "green");
        i++;
    }
}

void print_array(int *array, int i)
{
    while(array[i])
    {
        printf("array[%d] = %d\n", i, array[i]);
        i++;
    }
}

void print_which_fork_did_he_use(unsigned long long time, t_philo *current)
{
    printf("in %llu ms %d pick forks num %d : %d\n", current_time() - time, current->philo_id, current->left_fork, current->right_fork);
}