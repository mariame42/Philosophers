/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:47:12 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 18:21:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) != 0)
        return 0;
    return (time.tv_sec * 1000ULL + time.tv_usec / 1000ULL);
}


int	accurate_usleep(unsigned long long time, t_philo *philo)
{
	const unsigned long long	start = current_time();

	while (current_time() < (start + time))
	{
		if (check_death(philo->p_info) == 0)
			return (printf("he dead in usleep: %d\n", philo->philo_id), 1);
		usleep(500);
	}
	return (0);
}

int	check_death(t_info *info)
{
	int result;

	pthread_mutex_lock(&info->death_mutex);
	result = info->not_dead;
	pthread_mutex_unlock(&info->death_mutex);
	return (result);
}

int check_eats(t_info *info)
{
    int i = 0;
    while (i < info->number_of_philosophers)
	{
		if (info->philos[i].eat_num >= info->number_of_times_each_philosopher_must_eat)
			return (1);
		i++;
	}
	return (0);
}

void	philo_died(t_info *info, int i, int flag)
{
	pthread_mutex_lock(&info->death_mutex);
	info->not_dead = false;
	pthread_mutex_unlock(&info->death_mutex);
	if (flag == 2)
		print_philo_status(&info->philos[i], "die");
	pthread_mutex_unlock(&info->eat_mutex);
}