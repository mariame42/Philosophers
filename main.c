/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:02:01 by meid              #+#    #+#             */
/*   Updated: 2025/02/18 12:12:09 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philofunction(void *arg)
{
    int i = *(int*)arg;
    printf("\033[33m philo :%d is: \033[0m", i);
    print_emoji("eat");
    printf("\n");
    return (NULL);
} 

t_info fill_some_info(int ac, char **av)
{
    (void)ac;
    t_info i;
    i.number_of_philosophers = ft_atoi(av[1]);
    i.time_to_die = ft_atoi(av[2]);
    i.time_to_eat = ft_atoi(av[3]);
    i.time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
       i.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        i.number_of_times_each_philosopher_must_eat = -1;
    return (i);
    
}

int philo(t_info *info)
{
    pthread_t *th = malloc(sizeof(pthread_t) * info->number_of_philosophers);
    if (!th)
        return (1);
    int i = 0;
    int flag = 0; 
    while(i < info->number_of_philosophers)
    {
        int *index = malloc(sizeof(int));
        if (!index)
        {
            perror("malloc failed");
            return 1;
        }
        *index = i;
        if (flag == 0)
        {
            pthread_create(&th[i], NULL, &philofunction, index);
            flag = 1;
        }
        else if (flag == 1)
        {
            pthread_create(&th[i], NULL, &philofunction, index);
            flag = 0;
        }
        i++;
    }
    i = 0;
    while(i < info->number_of_philosophers)
    {
        pthread_join(th[i], NULL);// the return value of a function we can resive it here
        i++;
    }
    return (0);
}


int main(int ac, char **av)
{
    t_info info;
    (void)av;
    if (ac < 5)
        return (print_with_color("the program should have 4 to 5 arguments", "red"), 1);
    if (check_is_valid(av))
        return (print_with_color("numeric argument required", "red"), 1);
    info = fill_some_info(ac, av);
    if (check_logic_num(ac, &info))
        return (1);
    print_info(&info);
    print_emoji("eat");
    print_emoji("sleep");
    print_emoji("die");
    if (philo(&info))
        return (print_with_color("error in philo", "red"), 1);
}