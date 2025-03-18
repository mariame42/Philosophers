/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:33:42 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 16:36:24 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

bool	is_forks_available(t_philo *philo, int *first, int *next)
{
	unsigned long long	first_id;
	unsigned long long	next_id;

	check_order(philo, first, next);
	pthread_mutex_lock(&philo->p_info->fork_mutex[*first]);
	// printf("id: %llu\n", philo->philo_id);
	first_id = philo->p_info->forks[*first];
	pthread_mutex_unlock(&philo->p_info->fork_mutex[*first]);
	pthread_mutex_lock(&philo->p_info->fork_mutex[*next]);
	next_id = philo->p_info->forks[*next];
	// printf("id : %llu , f: %llu n: %llu \n", philo->philo_id, first_id, next_id);
	pthread_mutex_unlock(&philo->p_info->fork_mutex[*next]);
	return (first_id != philo->philo_id && next_id != philo->philo_id);
}

void	*philofunction(void *data)
{
	int		first;
	int		next;
	t_philo	*current;

	current = (t_philo *)data;
	while (1)
	{
		// printf("iddddd : %llu\n", current->philo_id);
		pthread_mutex_lock(&current->p_info->death_mutex);
		if (!current->p_info->not_dead)
		{
			// printf("Philosopher %llu stopping: detected death\n",
			// 	current->philo_id);
			pthread_mutex_unlock(&current->p_info->death_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&current->p_info->death_mutex);
		// printf("iddddd : %llu\n", current->philo_id);
		if (is_forks_available(current, &first, &next))
		{
			if (eating(current, first, next))
				return (NULL);
			if (sleeping(current))
				return (NULL);
			if (thinking(current))
				return (NULL);
		}
	}
	return (NULL);
}

int	check_eats(t_info *data)
{
	unsigned long long	i;

	i = 0;
	while (i < data->philos_num)
	{
		if (data->philos[i].eat_times < (unsigned long long)data->minimum_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*death_checker(void *info)
{
	t_info				*current;
	unsigned long long	i;

	current = (t_info *)info;
	while (1)
	{
		i = 0;
		while (i < current->philos_num)
		{
			pthread_mutex_lock(&current->eat_mutex);
			if (current->minimum_eat > 0 && check_eats(current))
			{
				philo_died(current, i, 1);
				pthread_mutex_unlock(&current->eat_mutex);
				printf("Death detected: Exiting death_checker\n");
				return (NULL);
			}
			if (current_time_ms() > current->philos[i].last_eat
				+ current->time_to_die + 10)
			{
				// printf("--------c_t-%llu----l_e- %llu -----t_d- %llu ----s- %llu\n", current_time_ms(), current->philos[i].last_eat, current->time_to_die, current->philos[i].last_eat + current->time_to_die);
				philo_died(current, i, 2);
				pthread_mutex_unlock(&current->eat_mutex);
				// printf("Death detected: Exiting death_checker\n");
				return (NULL);
			}
			pthread_mutex_unlock(&current->eat_mutex);
			i++;
		}
	}
	return (NULL);
}
// printf("%llu %llu %llu %llu\n",
// current_time_ms() ,current->philos[i].last_eat, current->time_to_die,
// current->philos[i].last_eat + current->time_to_die);
// printf("%llu %llu %llu %llu\n",
// current_time_ms() ,current->philos[i].last_eat, current->time_to_die,
// current->philos[i].last_eat + current->time_to_die);

int	philo_life_circle(t_info *info, unsigned long long i)
{
	if (info->philos_num == 1)
		return (accurate_usleep(info->time_to_die, &info->philos[0]),
			philo_status(&info->philos[0], "die"), clean_up(info, 0), 0);
	info->th = malloc(sizeof(pthread_t) * info->philos_num);
	if (!info->th)
		return (1);
	info->checker = malloc(sizeof(pthread_t));
	if (!info->checker)
		return (1);
	while (i < info->philos_num)
	{
		if (pthread_create(info->th + i, NULL, &philofunction,
				&info->philos[i]) != 0)
			return (1);
		printf("Thread %llu has started\n", i);
		i++;
	}
	if (pthread_create(&info->checker, NULL, &death_checker, info) != 0)
		return (1);
	if (pthread_join(info->checker, NULL))
		return (printf("Error: pthread_create failed\n"), 1);
	i = 0;
	while (i < info->philos_num)
	{
		if (pthread_join(info->th[i], NULL) != 0)
			return (2);
		i++;
	}
	return (clean_up(info, 1), 0);
}
