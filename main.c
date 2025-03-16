/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:02:01 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 10:26:17 by meid             ###   ########.fr       */
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
    i.forks = make_pihlo_array(i.number_of_philosophers, 0);
    // i.state_tracking = make_neutral_array(i.number_of_philosophers, 0);
    i.th = NULL;
    i.fork_mutex = make_mutex_array(i.number_of_philosophers, 0);
	pthread_mutex_init(&i.eat_mutex, NULL);
	pthread_mutex_init(&i.print_mutex, NULL);
	pthread_mutex_init(&i.death_mutex, NULL);
    i.i = 0;
    print_array(i.forks, 0);
    // print_array(i.state_tracking, 0);
    i.philos = philo_struct_array(&i, i.number_of_philosophers, 0);
    i.first_time = current_time();
    i.not_dead = true;
    return (i);
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
    if (philo(&info, 0))
        return (print_with_color("error in philo", "red"), 1);
}