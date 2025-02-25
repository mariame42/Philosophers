/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:39:42 by meid              #+#    #+#             */
/*   Updated: 2025/02/25 19:39:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int *make_neutral_array(int philo_num, int i)
{
    int *array;

    array = malloc(sizeof(int) * philo_num);
    if (!array)
        return (NULL);
    while (i < philo_num)
    {
        array[i] = -1;   
        i++;
    }
    return (array);
}

int *make_pihlo_array(int philo_num, int i)
{
    int *array;

    array = malloc(sizeof(int) * philo_num);
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