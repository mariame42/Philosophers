/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:40:28 by meid              #+#    #+#             */
/*   Updated: 2025/03/15 18:27:03 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_order(t_philo *philo, int *first, int *next)
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

bool is_forks_available(t_philo *philo, int *first, int *next)
{
    int first_id;
    int next_id;

    check_order(philo, first, next);
	pthread_mutex_lock(&philo->p_info->fork_mutex[*first]);
	first_id = philo->p_info->forks[*first];
	pthread_mutex_unlock(&philo->p_info->fork_mutex[*first]);
	pthread_mutex_lock(&philo->p_info->fork_mutex[*next]);
	next_id = philo->p_info->forks[*next];
	pthread_mutex_unlock(&philo->p_info->fork_mutex[*next]);
	return (first_id != philo->philo_id && next_id != philo->philo_id);
}

void *philofunction(void *data)
{
    int first;
    int next;
    t_philo *current = (t_philo *)data;
    while (check_death(current->p_info))
    {
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
        // // printf("lol1");
        // pthread_mutex_lock(&current->p_info->fork_mutex[current->philo_id]);
        // // printf("lol2");
        // if (current->p_info->forks[current->right_fork] != current->philo_id && current->p_info->forks[current->left_fork] != current->philo_id)
        // {
        // // printf("lol3");
        //     current->p_info->forks[current->right_fork] = current->philo_id;
        //     current->p_info->forks[current->left_fork] = current->philo_id;
        //     pthread_mutex_unlock(&current->p_info->fork_mutex[current->philo_id]);
        // // printf("lol4");
        
        //     pthread_mutex_lock(&current->p_info->eat_mutex);
        // // printf("lol5");
        //     print_which_fork_did_he_use(current->p_info->first_time, current);
        //     print_philo_status(current, current->p_info->first_time , current->philo_id, "eat");
        //     accurate_usleep(current->p_info->time_to_eat, current);
        // // printf("lol6");
        //     current->last_eat = current_time() -  current->p_info->first_time;
        //     pthread_mutex_unlock(&current->p_info->eat_mutex);
        // // printf("lol7");


        // print_philo_status(current, current->p_info->first_time , current->philo_id, "sleep");
        // accurate_usleep(current->p_info->time_to_sleep, current);
        // print_philo_status(current,current->p_info->first_time , current->philo_id, "think");
        
        // if (current_time() - current->p_info->first_time - current->last_eat > (unsigned long long)current->p_info->time_to_die)
        // {
        //     printf("%llu %llu  %llu %llu %llu\n", current_time(), current->p_info->first_time, current->last_eat, current_time() - current->last_eat, (unsigned long long)current->p_info->time_to_die);
        //     current->is_it_dead = 1;
        // }
    // print_philo_status(current->p_info->first_time , current->philo_id, "die");


// void *philofunction(void *data)

void *death_checker(void *info)
{
    t_info *current = (t_info *)info;
    int i = 0;
    while (current->not_dead)
    {
        i = 0;
        while (i < current->number_of_philosophers)
		{
			pthread_mutex_lock(&current->eat_mutex);
			if (current->number_of_times_each_philosopher_must_eat > 0 && check_eats(current))
				return (printf("ko"), philo_died(info, i, 1), NULL);
            // printf("%llu ")
			if (current_time() > current->philos[i].last_eat + current->time_to_die)
            {
				return (printf("ko"), philo_died(info, i, 2), NULL);
            }
			pthread_mutex_unlock(&current->eat_mutex);
			i++;
		}
    }
    return (NULL);
}

int philo(t_info *info, int i)
{
    (void)info;
    (void)i;
    if (info->number_of_philosophers == 1)
        return (usleep(info->time_to_die), print_philo_status(&info->philos[0], "die"), clean_up(info, 0), 0);
    info->th = malloc(sizeof(pthread_t) * info->number_of_philosophers);
    if (!info->th)
        return (1);

    while( i < info->number_of_philosophers)
    {
        if (pthread_create(info->th + i, NULL, &philofunction, &info->philos[i]) != 0)
            return (1);
        printf("Thread %d has started\n", i);
        i++;
    }
    if (pthread_create(&info->checker, NULL, &death_checker, &info) != 0)
        return (1);
	if (pthread_join(info->checker, NULL))
		return (printf("Error: pthread_create failed\n"), 1);
    i = 0;
    while( i < info->number_of_philosophers)
    {
        if (pthread_join(info->th[i], NULL) != 0)
            return (2);
        i++;
    }
    clean_up(info, 1);
    return (0);
}