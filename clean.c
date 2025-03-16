/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:53:42 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 18:06:42 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clear_mutex(pthread_mutex_t *mutex, int philo_num, int i)
{
    while (i < philo_num)
    {
        pthread_mutex_destroy(&mutex[i]);   
        i++;
    }
    free(mutex);
}

void clean_up(t_info *info, int flag)
{
    clear_mutex(info->fork_mutex, info->number_of_philosophers, 0);
    // clear_mutex(info->sleep, info->number_of_philosophers, 0);
    // clear_mutex(info->eat, info->number_of_philosophers, 0);
    if (flag >= 1)
    {
        if (info->th)
        {
            free(info->th);
            info->th = NULL;
        }
        if (info->checker)
        {
            free(info->checker);
            info->checker = NULL;       
        }
    }
}
