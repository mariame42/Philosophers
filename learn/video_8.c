/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:05:45 by meid              #+#    #+#             */
/*   Updated: 2025/02/15 15:21:24 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learn.h"

// https://youtu.be/cunJcNgtxMk?si=DrIjLrVqwvZblc3I

// gettimeofday
// sunction that gets the current time expressed in elapsed seconds and
// microseconds since january-1-1970
// int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
// argument : first is timeval struct
// typedef struct timeval {
//   long tv_sec;
//   long tv_usec;
// } TIMEVAL, *PTIMEVAL, *LPTIMEVAL;
// tv_sec: Time interval, in seconds.
// tv_usec: Time interval, in microseconds. This value is used in combination with
// the tv_sec member to represent time interval values that are not a multiple of seconds.
// second arg is the timezone normally it will be set to NULL

int main(void)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    printf("%ld.%06d\n",
        current_time.tv_sec, current_time.tv_usec);
}



