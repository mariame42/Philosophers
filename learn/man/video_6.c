/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:42:55 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:06:01 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../learn.h"

// https://youtu.be/Adtrk3PREQI?si=1ykY0IQDnBPq8o0e
// why the allocation in the main function
// Each thread gets its own copy of i instead of all threads sharing
// the same memory location.
// Allocated memory is freed inside the thread function to avoid memory leaks.

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    // sleep(1);
    int index = *(int*)arg;
    printf("%d ", primes[index]);
    free(arg);
    return (NULL);
}
int main(int ac, char **av)
{
    pthread_t th[10];
    for (int i = 0; i < 10; i++)
    {
        int *index = malloc(sizeof(int));
        if (!index)
        {
            perror("malloc failed");
            return 1;
        }
        *index = i;
        if (pthread_create(&th[i], NULL, &routine, index) != 0){
            perror("Failed to create thread\n");
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("Faild to join\n");
    }
}