/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:33:08 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 09:54:10 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long long	current_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return (time.tv_sec * 1000ULL + time.tv_usec / 1000ULL);
}

int	accurate_usleep(unsigned long long sleep_time, t_philo *philo)
{
	unsigned long long	start;

	start = current_time_ms();
	while (current_time_ms() < (start + sleep_time))
	{
		if (check_death(philo->p_info) == 0)
			return (1);
		usleep(500);
	}
	return (0);
}

int	check_death(t_info *info)
{
	int	result;

	pthread_mutex_lock(&info->death_mutex);
	result = info->not_dead;
	pthread_mutex_unlock(&info->death_mutex);
	return (result);
}
