#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define BufferSize 10

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[Buffer_Size];
int MaxItems;

void *producer(void *pno)
{   
    int itms;
    for(int k = 0; k < MaxItems; k++)
     {
        itms = rand(); 
        sem_wait(&empty);
        while (((in + 1) % Buffer_Size) == out)
        {
           buffer[in] = itms;
           //producer
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
           in = (in + 1) % Buffer_Size;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cno)
{
    int itmss=0;
    for(int k = 0; k < MaxItems; k++) 
    {
        sem_wait(&full);
        while (in == out) 
        {
           itm = buffer[out];
           // consumer
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),itm, out); 
           out = (out + 1) % Buffer_Size; 
        }
        sem_post(&empty);
    }
}

int main()
{

    pthread_t pro[5],con[5];
    sem_init(&empty,0,Buffer_Size);
    sem_init(&full,0,0);

    int a[4] = {1,2,3,4}; 

    for(int k = 0; k < 4; k++) 
    {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[k]);
    }
    for(int k = 0; k < 4; k++)
     {
        pthread_create(&con[k], NULL, (void *)consumer, (void *)&a[k]);
    }

    for(int k = 0; k < 4; k++) {
        pthread_join(pro[k], NULL);
    }
    for(int k = 0; k < 4; k++) {
        pthread_join(con[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
