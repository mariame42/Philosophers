/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:53:48 by meid              #+#    #+#             */
/*   Updated: 2025/03/20 12:59:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_philo *philo, int first, int next)
{
	pthread_mutex_lock(&philo->p_info->fork_mutex[first]);
	pthread_mutex_lock(&philo->p_info->fork_mutex[next]);
	check_order(philo, &first, &next);
	if (philo_status(philo, "fork") || philo_status(philo, "fork")
		|| philo_status(philo, "eat"))
	{
		pthread_mutex_unlock(&philo->p_info->fork_mutex[first]);
		pthread_mutex_unlock(&philo->p_info->fork_mutex[next]);
		return (1);
	}
	if (accurate_usleep(philo->p_info->time_to_eat, philo))
	{
		pthread_mutex_unlock(&philo->p_info->fork_mutex[first]);
		pthread_mutex_unlock(&philo->p_info->fork_mutex[next]);
		return (1);
	}
	pthread_mutex_lock(&philo->p_info->eat_mutex);
	philo->last_eat = current_time_ms();
	philo->eat_times++;
	pthread_mutex_unlock(&philo->p_info->eat_mutex);
	philo->p_info->forks[first] = philo->philo_id;
	philo->p_info->forks[next] = philo->philo_id;
	pthread_mutex_unlock(&philo->p_info->fork_mutex[first]);
	pthread_mutex_unlock(&philo->p_info->fork_mutex[next]);
	return (0);
}

int	sleeping(t_philo *philo)
{
	philo_status(philo, "sleep");
	return (accurate_usleep(philo->p_info->time_to_sleep, philo));
}

int	thinking(t_philo *philo)
{
	return (philo_status(philo, "think"));
}

void	philo_died(t_info *info, int i, int flag)
{
	pthread_mutex_lock(&info->death_mutex);
	info->not_dead = false;
	pthread_mutex_unlock(&info->death_mutex);
	if (flag == 2)
		philo_status(&info->philos[i], "die");
}

void	check_order(t_philo *philo, int *first, int *next)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*next = philo->right_fork;
	}
	else
	{
		*next = philo->left_fork;
		*first = philo->right_fork;
	}
}
