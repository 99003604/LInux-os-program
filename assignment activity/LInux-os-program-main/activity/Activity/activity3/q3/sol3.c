#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 4
#define Buffer_Size 4

int inn = 0;
int outt = 0;
int buffer[Buffer_Size];
pthread_mutex_t mutex;
void *producer(void *pno)
{
    int itms;
    for(int k = 0; k < MaxItems; k++) 
    {
        itms = rand();
        pthread_mutex_lock(&mutex);
         while (((inn + 1) % Buffer_Size) == outt)
        {
           buffer[inn] = itm;
           // producer
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inn],inn);
           inn = (inn + 1) % Buffer_Size;
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{
    int itms=0;
    for(int k = 0; k < MaxItems; k++) 
    {
        pthread_mutex_lock(&mutex);
        while (inn == outt)
        {
           itm = buffer[outt];
           //consumer
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),itms, outt);
           outt = (outt + 1) % Buffer_Size;
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t pro[4],con[4];
    pthread_mutex_init(&mutex, NULL);
    int a[4] = {1,2,3,4}; 
    for(int k = 0; k < 4; k++) 
    {
        pthread_create(&pro[k], NULL, (void *)producer, (void *)&a[k]);
    }
    for(int k = 0; k < 4; k++) 
    {
        pthread_create(&con[k], NULL, (void *)consumer, (void *)&a[k]);
    }
    for(int k = 0; k < 4; k++)
     {
        pthread_join(pro[k], NULL);
    }
    for(int k = 0; k < 4; k++) {
        pthread_join(con[k], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
