/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:39:42 by meid              #+#    #+#             */
/*   Updated: 2025/03/16 12:35:17 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long long *make_pihlo_array(unsigned long long philo_num, unsigned long long i)
{
    unsigned long long *array;

    array = malloc(sizeof(unsigned long long) * philo_num);
    if (!array)
        return (NULL);
    while (i < philo_num)
    {
        if (i == 0 || i == philo_num - 1)
            array[i] = philo_num;
        else if (i % 2 == 0)
            array[i] = i + 2;
        else if (i % 2 != 0)
            array[i] = i + 1;
        i++;
    }
    return (array);
}

pthread_mutex_t *make_mutex_array(int philo_num, int i)
{
    pthread_mutex_t *mutex;

    mutex = malloc(sizeof(pthread_mutex_t) * philo_num);
    if (!mutex)
        return (NULL);
    while (i < philo_num)
    {
        pthread_mutex_init(&mutex[i], NULL);   
        i++;
    }
    return (mutex);
}

t_philo *philo_struct_array(t_info *info, int num_of_philos, int i)
{
    t_philo *philos = malloc(sizeof(t_philo) *(num_of_philos));
    if (!philos)
        return (NULL);
    while (i < num_of_philos)
    {
        philos[i].philo_id = i + 1;
        philos[i].left_fork = i;
        philos[i].right_fork = (i + 1) % num_of_philos;
        philos[i].eat_times = 0;
        philos[i].p_info = info;
        philos[i].last_eat = current_time_ms();
        i++;
    }
    return (philos);
}