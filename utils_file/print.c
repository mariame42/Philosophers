/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:04:38 by meid              #+#    #+#             */
/*   Updated: 2025/03/20 11:50:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_status(t_philo *philo, char *msg)
{
	unsigned long long	time;

	time = current_time_ms() - philo->p_info->begin_time;
	pthread_mutex_lock(&philo->p_info->print_mutex);
	if (ft_strcmp(msg, "die"))
		printf("%llu %llu %s\n", time, philo->philo_id, DIE);
	if (check_death(philo->p_info) == 0)
		return (pthread_mutex_unlock(&philo->p_info->print_mutex), 1);
	if (ft_strcmp(msg, "sleep"))
		printf("%llu %llu %s\n", time, philo->philo_id, SLEEP);
	if (ft_strcmp(msg, "eat"))
		printf("%llu %llu %s\n", time, philo->philo_id, EAT);
	if (ft_strcmp(msg, "think"))
		printf("%llu %llu %s\n", time, philo->philo_id, THINK);
	if (ft_strcmp(msg, "fork"))
		printf("%llu %llu %s\n", time, philo->philo_id, FORK);
	pthread_mutex_unlock(&philo->p_info->print_mutex);
	return (0);
}
