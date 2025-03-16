/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:04:38 by meid              #+#    #+#             */
/*   Updated: 2025/03/16 13:22:41 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int philo_status(t_philo *philo, char *msg)
{
    unsigned long long time;

    time = current_time_ms() - philo->p_info->begin_time;
    pthread_mutex_lock(&philo->p_info->print_mutex);
    if (ft_strcmp(msg, "die"))
        printf("%s%llu %llu %s %s\n", BLUE, time, philo->philo_id, DIE, RESET);
    if (check_death(philo->p_info) == 0)
        return(pthread_mutex_unlock(&philo->p_info->print_mutex), 1);
    if (ft_strcmp(msg, "sleep"))
        printf("%s%llu %llu %s %s\n", BLUE, time, philo->philo_id, SLEEP, RESET);
    if (ft_strcmp(msg, "eat"))
        printf("%s%llu %llu %s %s\n", BLUE, time, philo->philo_id, EAT, RESET);
    if (ft_strcmp(msg, "think"))
        printf("%s%llu %llu %s %s\n", BLUE, time, philo->philo_id, THINK, RESET);
    pthread_mutex_unlock(&philo->p_info->print_mutex);
    return (0);
}
