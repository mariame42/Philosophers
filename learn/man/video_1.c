/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:58:40 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:05:41 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../learn.h"

// https://youtu.be/uA8X5zNOGw8?si=fVMY897RoxdUuqvt

void *myturn(void *arg)
{
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My Turn!: %d\n", i);
    }
    return (NULL);
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

    pthread_create(&newthread, NULL,  myturn, NULL);// to creat a thread
    yourturn();
    pthread_join(newthread, NULL); // wait for the thread to finish before exting the program
}