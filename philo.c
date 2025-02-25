/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:38:00 by meid              #+#    #+#             */
/*   Updated: 2025/02/25 20:25:35 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philofunction(void *data)
{
    t_info *info = (t_info *)data;
    pthread_mutex_lock(&info->mutex[info->i]);
    printf("\033[33m philo %d \033[0m", info->i);
    print_emoji("eat");
    printf("\n");
    pthread_mutex_unlock(&info->mutex[info->i]);
    return (info);
} 

int philo(t_info *info, int i)
{
    t_info *thread_info;
    info->th = malloc(sizeof(pthread_t) * info->number_of_philosophers);
    if (!info->th)
        return (1);
    while( i < info->number_of_philosophers)
    {
        thread_info = malloc(sizeof(t_info));
        if (!thread_info)
            return (1);
        *thread_info = *info;
        thread_info->i = i;
        if (pthread_create(info->th + i, NULL, &philofunction, thread_info) != 0)
            return (free(thread_info), 1);
        printf("Thread %d has started\n", i);
        i++;
    }
    i = 0;
    while( i < info->number_of_philosophers)
    {
        void *info_to_free;
        printf("%d\n", i);
        if (pthread_join(info->th[i], &info_to_free) != 0)
            return (2);
        free(info_to_free);
        printf("Thread %d has finished execution\n", i);
        i++;
    }
    clean_up(info); // < clean "th" > < into->mutix distroy and free >
    return (0);
}
