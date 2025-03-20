/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:38:47 by meid              #+#    #+#             */
/*   Updated: 2025/03/20 12:57:04 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clear_mutex(pthread_mutex_t *mutex, int philo_num, int i)
{
	while (i < philo_num)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
}

void	clean_up(t_info *info, int flag)
{
	clear_mutex(info->fork_mutex, info->philos_num, 0);
	free(info->philos);
	free(info->forks);
	if (flag >= 1)
	{
		if (info->th)
		{
			free(info->th);
			info->th = NULL;
		}
	}
}
