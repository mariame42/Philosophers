/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:02:39 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:05:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../learn.h"

// https://youtu.be/oq29KUy29iQ?si=ZH-ELQ8op-s1o7uj

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
    for(int i = 0; i < 100000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t p1;
    pthread_t p2;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&p1, NULL, &routine, NULL) != 0)
        return (1);
    if (pthread_create(&p2, NULL, &routine, NULL) != 0)
        return (2);
    if (pthread_join(p1, NULL) != 0)
        return (3);
    if (pthread_join(p2, NULL) != 0)
        return (4);
    pthread_mutex_destroy(&mutex);
    printf("mails: %d\n", mails);
}