#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#define MaxItms 5 
#define Buffer_Size 5 

sem_t empty;
sem_t full;
int w = 0;
int r = 0;
int itm=0;
int buffer[Buffer_Size];
void *prod(void *po)
{   
    if(w==Buffer_Size-1)
    {
        //stack producer
        
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
        w = (w + 1) % Buffer_Size;     
        sem_post(&full);
     }
    }
}
void *cons(void *co)
{   
    if(r==Buffer_Size-1)
    {
        // stack consumer
        printf("Stack of consumer contains nothing, can't read from it now\n");
    }
    else
    {
     int itms=0;
     for(int k = 0; k < MaxItems; k++) 
     {
        sem_wait(&full);
        itm = buffer[r]; // remove the consumer item
        printf("Remove Item %d from Consumer %d from %d: ", itm, *((int *)co), r); 
        r = (r + 1) % Buffer_Size;     
        sem_post(&empty);
     }
    }
}

int main()
{   
    pthread_t producer[5],consumer[5];
    sem_init(&empty,0,Buffer_Size);
    sem_init(&full,0,0);
    int c[5] = {1,2,3,4,5};
    for(int l = 0; l < 5; l++) 
    {
 // pthread ctreated in producer
        pthread_create(&producer[l], NULL, (void *)prod, (void *)&c[l]);
    }
    for(int l = 0; l < 5; l++) 
    { // pthread creatred in conusmer
        pthread_create(&consumer[l], NULL, (void *)cons, (void *)&c[l]);
    }
    // initilization of the part
    for(int l = 0; l < 5; l++) 
    {
        pthread_join(producer[l], NULL);
    }
    for(int l = 0; l < 5; l++) 
    {
        pthread_join(consumer[l], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
