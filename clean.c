/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:53:42 by meid              #+#    #+#             */
/*   Updated: 2025/03/07 17:14:27 by meid             ###   ########.fr       */
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

void clean_up(t_info *info)
{
    clear_mutex(info->mutex, info->number_of_philosophers, 0);
    if (info->th)
        free(info->th);
}
