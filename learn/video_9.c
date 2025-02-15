/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:22:24 by meid              #+#    #+#             */
/*   Updated: 2025/02/15 15:37:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learn.h"

//Use pthread_join when:
// You need to wait for a thread to finish before continuing.
// You want to retrieve the thread's return value.
// Use pthread_detach when:

// You do not need to wait for the thread.
// The thread should clean itself up after finishing.

#define THREAD_NUM 2

void *function_call()
{
    sleep(1); 
    printf("something\n");
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t th[THREAD_NUM];

    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&th[i], NULL, function_call, NULL))
        {
            printf("the error in the creating process\n");
            return (1);
        }
        pthread_detach(th[i]);
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL))
        {
            printf("the error in the joining process\n");
            return (1); 
        }
    }
}