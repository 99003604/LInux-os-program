#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#define MaxItms 5 
#define BufferSize 5 

sem_t emty;
sem_t full;
int w = 0;
int r = 0;
int itm=0;
int buffer[BufferSize];
void *prod(void *po)
{   
    if(w==BufferSize-1)
    {
        printf("Stack of producer is full, can't write to it now \n");
    }
    else
    {
     for(int k = 0; k < MaxItms; k++) 
     {
        itms = rand();
        sem_wait(&empty);
        buffer[w] = item;
        printf(" Insert Item %d in Producer %d at %d: ", buffer[w], *((int *)po), w);
        w = (w + 1) % BufferSize;     
        sem_post(&full);
     }
    }
}
void *cons(void *co)
{   
    if(r==BufferSize-1)
    {
        printf("Stack of consumer contains nothing, can't read from it now\n");
    }
    else
    {
     int itms=0;
     for(int k = 0; k < MaxItems; k++) 
     {
        sem_wait(&full);
        itm = buffer[r];
        printf("Remove Item %d from Consumer %d from %d: ", itm, *((int *)co), r); 
        r = (r + 1) % BufferSize;     
        sem_post(&empty);
     }
    }
}

int main()
{   
    pthread_t producer[5],consumer[5];
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    int a[5] = {1,2,3,4,5};
    for(int l = 0; l < 10; l++) 
    {
 // thread ctreated in nproducer//
        pthread_create(&producer[l], NULL, (void *)prod, (void *)&a[l]);
    }
    for(int l = 0; l < 10; l++) 
    { // pthread creatred in conusmer
        pthread_create(&consumer[l], NULL, (void *)cons, (void *)&a[l]);
    }
    for(int l = 0; l < 10; l++) 
    {
        pthread_join(producer[l], NULL);
    }
    for(int l = 0; l < 10; l++) 
    {
        pthread_join(consumer[l], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
