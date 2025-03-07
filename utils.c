/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:47:12 by meid              #+#    #+#             */
/*   Updated: 2025/03/07 16:48:15 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) != 0)
        return 0;
    return (time.tv_sec * 1000ULL + time.tv_usec / 1000ULL);
}
