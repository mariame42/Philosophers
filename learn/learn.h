/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:57:25 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 11:46:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEARN_H
# define LEARN_H

#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free
#include <string.h>     // memset
#include <unistd.h>     // write, usleep
#include <sys/time.h>   // gettimeofday
#include <pthread.h>    // pthread_create, pthread_detach, pthread_join, 
// pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

// #ifndef THREAD_NUM
// # define THREAD_NUM 23
// #endif

# include <semaphore.h> // sem_open, sem_close, sem_post, sem_wait, sem_unlink,
	// sem_init
# include <signal.h>    // kill
# include <sys/types.h> // fork, waitpid
# include <sys/wait.h>  // waitpid

typedef struct s_info{
	sem_t semaphore;
	int			i;
}				t_info;

#endif