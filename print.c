/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:18:26 by meid              #+#    #+#             */
/*   Updated: 2025/02/25 18:59:22 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
        printf("\033[38;2;255;165;0m Orange %s\033[0m\n", msg);
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
        printf("\033[33m Yellow %s\033[0m\n", msg);
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
        printf("\033[34mdie\033[0m %s\n", DYING);
}

void print_info(t_info *info)
{
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
}

void print_array(int *array, int i)
{
    while(array[i])
    {
        printf("array[%d] = %d\n", i, array[i]);
        i++;
    }
}