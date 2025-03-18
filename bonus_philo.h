/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:35:41 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:16:31 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILO_H
# define BONUS_PHILO_H

# include <pthread.h>   // pthread_create, pthread_detach, pthread_join
# include <semaphore.h> // sem_open, sem_close, sem_post, sem_wait, sem_unlink,
	// sem_init
# include <signal.h>    // kill
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <string.h>    // memset
# include <sys/time.h>  // gettimeofday
# include <sys/types.h> // fork, waitpid
# include <sys/wait.h>  // waitpid
# include <unistd.h>    // write, fork, usleep


#endif