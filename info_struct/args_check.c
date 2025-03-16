/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:28:10 by meid              #+#    #+#             */
/*   Updated: 2025/03/16 12:07:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	args_check(int ac, char **av, int i, int j)
{
	if (ac < 5)
		return (printf("%sthe program should have 4 to 5 arguments%s\n", RED,
				RESET), 1);
    while (av[j])
    {
        i = 0;
        while (av[j][i] && av[j][i] == ' ')
            i++;
        if (av[j][i] == '\0')
		    return (printf("%sempty arg%s\n", RED, RESET), 1);
        while (av[j][i] && ((av[j][i] >= '0' && av[j][i] <= '9') || (av[j][0] == '+')))
            i++;
        while (av[j][i] && av[j][i] == ' ')
            i++;
        if (av[j][i] != '\0')
            return (printf("%sinvaled char%s\n", RED, RESET), 1);    
        j++;       
    }
    return (0);
}
