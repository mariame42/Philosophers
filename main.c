/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:09:21 by meid              #+#    #+#             */
/*   Updated: 2025/03/16 12:51:52 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_info info;
    
    if (args_check(ac, av, 0, 1))
        return (1);
    if (fill_some_info(&info, ac, av))
        return (1);
    if (philo_life_circle(&info, 0))
        return (1);
}