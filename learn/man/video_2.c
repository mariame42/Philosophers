/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:58:40 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:05:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../learn.h"

// https://youtu.be/It0OFCbbTJE?si=8UE4QMsuDL-Dbb3F

void *myturn()
{
    int *j = (int *)malloc(sizeof(int));
    *j = 5;
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My Turn!: %d, our int: %d\n", i, *j);
        (*j)++;
    }
    return (j);
}

void yourturn()
{
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf("Your Turn!: %d\n", i);
    }
}

int main(void)
{
    pthread_t newthread;
    int *result;

    pthread_create(&newthread, NULL,  myturn, NULL);// to creat a thread
    yourturn();
    pthread_join(newthread, (void *)&result); // wait for the thread to finish before exting the program
    // and can take the return value of a function
    printf("the intger after: %d\n", *result);
}