// C program to demonstrate working of Semaphores
#include "semaphore.h"

sem_t mutex;
int id = 0;

void* thread(void* arg)
{
    int n = id;
    sem_wait(&mutex);
    printf("\nEntered Thread :%d \n", n);

    //critical section
    sleep(4);
	
    printf("\nJust Exiting Thread :%d\n", n);
    sem_post(&mutex);
}

void semaphore()
{
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
	
    {
        pthread_create(&t1, NULL, thread, NULL);
        id = 1;
    }
    sleep(2);
    {
        pthread_create(&t2, NULL, thread, NULL);
        id = 2;
    }
	
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
	
    sem_destroy(&mutex);
}

int main()
{
    semaphore();
    return 0;
}

