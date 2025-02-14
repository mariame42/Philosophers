/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:02:01 by meid              #+#    #+#             */
/*   Updated: 2025/02/14 20:11:57 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
void philo(t_info *info)
{
    (void)info;
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
    
    // philo(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
}