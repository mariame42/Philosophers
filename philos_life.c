/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:38:51 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 17:33:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating(t_philo *philo, int first, int next)
{
    pthread_mutex_lock(&philo->p_info->fork_mutex[first]);
	pthread_mutex_lock(&philo->p_info->fork_mutex[next]);
    check_order(philo, &first, &next);

    if (print_philo_status(philo, "fork") || print_philo_status(philo, "fork")
        || print_philo_status(philo, "eat") 
            || accurate_usleep(philo->p_info->time_to_eat, philo))
        return (check_order(philo, &first, &next),    
            pthread_mutex_lock(&philo->p_info->fork_mutex[first]),  
                pthread_mutex_lock(&philo->p_info->fork_mutex[next]), 1);
    pthread_mutex_lock(&philo->p_info->eat_mutex);
    philo->last_eat = current_time();
    philo->eat_num++;
    pthread_mutex_unlock(&philo->p_info->eat_mutex);
    check_order(philo, &first, &next);
    pthread_mutex_unlock(&philo->p_info->fork_mutex[first]);
	pthread_mutex_unlock(&philo->p_info->fork_mutex[next]);
    return (0);
}

int sleeping(t_philo *philo)
{
    return (print_philo_status(philo, "sleep") 
        && accurate_usleep(philo->p_info->time_to_sleep, philo));
}

int thinking(t_philo *philo)
{
    return (print_philo_status(philo, "think"));
}