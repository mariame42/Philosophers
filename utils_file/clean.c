/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:38:47 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 09:55:38 by meid             ###   ########.fr       */
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
	printf("1\n");
	free(info->philos);
	printf("2\n");
	free(info->forks);
	printf("3\n");
	if (flag >= 1)
	{
		if (info->th)
		{
			printf("4\n");
			free(info->th);
			info->th = NULL;
		}
		if (info->checker)
		{
			printf("5\n");
			info->checker = NULL;
			printf("6\n");
		}
	}
}
// free(info->checker);