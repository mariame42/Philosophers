/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:28:49 by meid              #+#    #+#             */
/*   Updated: 2025/03/18 10:05:51 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../learn.h"

// https://youtu.be/9axu8CUvOKY?si=xzqgNygwHVRkfxtU

// a Race condition : Without proper synchronization (like mutexes), the updates can overlap, leading to lost increments.
// i++ : is three steps process
// reads i -> compute i + 1 -> store the new value
// When two threads execute this operation concurrently, one thread may read i before the other stores the updated value.
// This can lead to lost increments, causing incorrect results and inconsistencies in counting.

/*
#define BIG 1000000000UL
 
uint32_t counter = 0;
void *count_to_big(void *arg){
    for (uint32_t i = 0; i < BIG; i++){
        counter++;
    }
    return (NULL);
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, count_to_big, NULL);
    count_to_big(NULL);
    pthread_join(t, NULL);
    printf("Done, Counter = %u\n", counter);
}
*/

// A mutex lock (short for mutual exclusion lock) is a synchronization mechanism used in multithreading to prevent
// race conditions by ensuring that only one thread can access a shared resource at a time. A thread must lock 
// the mutex before accessing the resource and unlock it after finishing, allowing other threads to proceed safely.
// the problem now is the speed now our progrm is so slow

/*
#define BIG 1000000000UL
 
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg){
    for (uint32_t i = 0; i < BIG; i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return (NULL);
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, count_to_big, NULL);
    count_to_big(NULL);
    pthread_join(t, NULL);
    printf("Done, Counter = %u\n", counter);
}
*/

// gcc -S -masm=intel video_3.c -o video_3.s  <make assembly>