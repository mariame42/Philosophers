#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    // Open the semaphore
    sem_t *semaphore = sem_open("/mysemaphore", O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Wait (decrement semaphore)
    sem_wait(semaphore);
    printf("Semaphore acquired!\n");

    // Do something with the semaphore held...

    // Post (increment semaphore)
    sem_post(semaphore);
    printf("Semaphore released!\n");

    // Close the semaphore
    sem_close(semaphore);

    // Unlink the semaphore
    sem_unlink("/mysemaphore");

    return 0;
}
