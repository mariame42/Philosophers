/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:42:55 by meid              #+#    #+#             */
/*   Updated: 2025/02/15 14:05:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learn.h"

//https://youtu.be/Adtrk3PREQI?si=EuYZ0vlHIe5Sk29p

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    // sleep(1);
    int index = *(int*)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += primes[index + i];
    }
    *(int*)arg = sum;
    return (arg);
}

int main(int ac, char **av)
{
    pthread_t th[10];
    int i;
    for (i = 0; i < 2; i++)
    {
        int *index = malloc(sizeof(int));
        if (!index)
        {
            perror("malloc failed");
            return 1;
        }
        *index = i * 5;
        if (pthread_create(&th[i], NULL, &routine, index) != 0){
            perror("Failed to create thread\n");
        }
    }
    int globalsum = 0;
    for (i = 0; i < 2; i++)
    {
        void *result;
        if (pthread_join(th[i], &result) != 0)
            perror("Faild to join\n");
        globalsum += *(int *)result;
        free(result);
    }
    printf("sum: %d\n", globalsum);
} 