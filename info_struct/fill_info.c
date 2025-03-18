/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:13:26 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 09:56:25 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	threads_and_mutix(t_info *i)
{
	i->philos = philo_struct_array(i, i->philos_num, 0);
	i->th = NULL;
	i->checker = NULL;
	i->fork_mutex = make_mutex_array(i->philos_num, 0);
	pthread_mutex_init(&i->eat_mutex, NULL);
	pthread_mutex_init(&i->print_mutex, NULL);
	pthread_mutex_init(&i->death_mutex, NULL);
	if (!i->philos || !i->fork_mutex || !i->forks)
		return (clean_up(i, 0), 1);
	return (0);
}

int	fill_some_info(t_info *i, int ac, char **av)
{
	i->not_dead = true;
	i->philos_num = ascii_to_ull(av[1]);
	i->time_to_die = ascii_to_ull(av[2]);
	i->time_to_eat = ascii_to_ull(av[3]);
	i->time_to_sleep = ascii_to_ull(av[4]);
	if (i->philos_num == 0 || i->time_to_die == 0 || i->time_to_eat == 0
		|| i->time_to_sleep == 0)
		return (1);
	if (ac == 6)
		i->minimum_eat = ascii_to_ull(av[5]);
	else
		i->minimum_eat = -1;
	i->forks = make_pihlo_array(i->philos_num, 0);
	i->begin_time = current_time_ms();
	if (threads_and_mutix(i))
		return (1);
	return (0);
}
