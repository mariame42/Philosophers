/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:26:17 by meid              #+#    #+#             */
/*   Updated: 2025/02/14 20:17:51 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_is_valid(char **av)
{
    int i = 0;
    int j = 1;
    while (av[j])
    {
        i = 0;
        while (av[j][i] && av[j][i] == ' ')
            i++;
        if (av[j][i] == '\0')
            return (1);
        if (av[j][i] == '+' || av[j][i] == '-')
             i++;
        while (av[j][i] && (av[j][i] >= '0' && av[j][i] <= '9'))
            i++;
        if (av[j][i] != '\0')
            return (1);    
        j++;       
    }
    return (0);
}

int check_logic_num(int ac, t_info *info)
{
    if (info->number_of_philosophers < 1)
        return(print_with_color("At least one philosopher must be present at the table", "red"), 1);
    if (info->time_to_die < 0 || info->time_to_sleep < 0 || info->time_to_eat < 0)
        return(print_with_color("doesn't make sense for the time to be negative", "red"), 1);
    if (ac == 6 && info->number_of_times_each_philosopher_must_eat < 0)
        return(print_with_color("number_of_times_each_philosopher_must_eat should be a postive num", "red"), 1);
    return (0);
}
