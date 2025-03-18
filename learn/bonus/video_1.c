#include "../learn.h"

#define THREAD_NUM 4
    sem_t *semaphore;

void *routine(void *args)
{
    sem_wait(semaphore);
    sleep(1);
    printf("Hallo from thread %d\n", *(int *)args);
    free(args);
    return (NULL);
}

int main(void)
{
    semaphore = sem_open("/mysemaphore", O_CREAT, 0644, 1);
    // sem_t *semaphore = sem_open("/mysemaphore", O_CREAT, 0644, 1);
    pthread_t th[THREAD_NUM];
    int i = 0;
    while (i < THREAD_NUM)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("Faild to create thread");
        }
        i++;
    }
    i = 0;
    while (i < THREAD_NUM)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Faild to join thread");
        }
        i++;
    }
    // sem_destroy(&semaphore);  
}