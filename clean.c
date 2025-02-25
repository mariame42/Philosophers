/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:53:42 by meid              #+#    #+#             */
/*   Updated: 2025/02/25 20:17:01 by meid             ###   ########.fr       */
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
    free(info->th);
}
