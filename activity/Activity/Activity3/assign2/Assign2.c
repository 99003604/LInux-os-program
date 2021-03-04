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
    { //stack operation can be used to buffer operation//
        printf("Stack of producer is full,  using circular buffer operations \n");
        for(int k = 0; k < MaxItms; k++) 
        {
          itm = rand();
          sem_wait(&empty);
          buffer[w] = item;
          printf(" Insert Item %d in Producer %d at %d: ", buffer[w], *((int *)po), w);
          w = (w + 1) % BufferSize;     
          sem_post(&full);
        }
    }
    else
    {
     for(int k = 0; k < MaxItms; k++) 
     {
        itm = rand();
        sem_wait(&empty);
        buffer[w] = item;
        printf(" Insert Item %d in Producer %d at %d: ", buffer[w], *((int *)po), w);
        w = (write + 1) % BufferSize;     
        sem_post(&full);
     }
    }
}
void *cons(void *co)
{   
    if(r==BufferSize-1)
    { 
//consumer cant open the file
        printf("Stack of consumer contains nothing, can't read from it now\n");
    }
    else
    {
     int itm=0;
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
    int b[5] = {1,2,3,4,5};
    for(int m= 0; m< 10; m++) 
    {
        pthread_create(&producer[m], NULL, (void *)prod, (void *)&b[m]);
    }
    for(int m = 0; m < 10; m++) 
    {
        pthread_create(&consumer[m], NULL, (void *)cons, (void *)&b[m]);
    }
    for(int m = 0; m < 10; m++) 
    {
        pthread_join(producer[m], NULL);
    }
    for(int m = 0; m < 10; m++) 
    {
        pthread_join(consumer[m], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
