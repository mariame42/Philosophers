/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:19:31 by meid              #+#    #+#             */
/*   Updated: 2025/02/15 12:38:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learn.h"

// https://youtu.be/xoXzp4B8aQk?si=3Rcaq0cl_9Jh44cO
// Without pthread_mutex_init, using pthread_mutex_lock may result in undefined behavior.
// Similarly, failing to call pthread_mutex_destroy can lead to resource leaks.
int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for(int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0)
            return (1);
        printf("Thread %d has started\n", i);
    }
    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            return (2);
        printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("mails: %d\n", mails);
}