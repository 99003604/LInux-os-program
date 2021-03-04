#include <iostream> 
#include <pthread.h> 

#define MAX 10 
#define MAX_THREAD 3
using namespace std; 
int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22}; 
int sum[3] = { 0 }; 
int pt = 0; 
void* sum(void* arg) // Each of the thread computes sum of 1/3th of array 
{ 
    int thread_pt = pt++; 
    for (int k = thread_pt * (MAX / 3); k < (thread_pt + 1) * (MAX / 3); k++) 
        sum[thread_pt] += a[j]; 
} 
int main() 
{ 
    int total = 0;
    pthread_t threads[MAX_THREAD]; 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum, (void*)NULL); 
    for (int j = 0; j< MAX_THREAD; j++) 
        pthread_join(threads[k], NULL);   
    for (int m = 0; m< MAX_THREAD; m++) 
        total += sum[m]; 
    cout << "sum of array is " << total << endl; 
    return 0; 
} 
