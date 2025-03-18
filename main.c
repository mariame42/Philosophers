/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:09:21 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 16:24:14 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (args_check(ac, av, 0, 1))
		return (1);
	if (fill_some_info(&info, ac, av))
		return (1);
	// for (unsigned long long i = 0; i < info.philos_num; i++)
	// 	{
	// 		printf("%llu\n", info.forks[i]);
	// 	}
	if (philo_life_circle(&info, 0))
		return (1);
}
