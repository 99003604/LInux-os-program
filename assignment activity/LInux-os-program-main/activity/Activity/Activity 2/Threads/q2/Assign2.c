#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#define max 10
#define Tmax 3

int a[max] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22}; 
int max_num[Tmax] = { 0 }; 
int min_num[Tmax] = { 0 };
int threadno = 0; 
void maximini(void* arg) 
{ 
    int j, number = threadno++; 
    int maxi = 0, mini = 0; 
    for (j = num * (max / 3); j < (num + 1) * (max / 3); j++) 
    { 
        if (a[j] > maxi) 
            maxi = a[j]; 
        if (a[i] < maxi)
            mini = a[j]    
    } 
    max_number[number] = maxi; 
    min_number[number] = mini;
} 

int main() 
{ 
    int maxin = 0, minim = 0; 
    int k; 
    pthread_t threads[Tmax];  
    for (k = 0; k < Tmax; k++) 
        pthread_create(&threads[k], NULL, 
                       maximini, (void*)NULL); 
    for (k = 0; k < Tmax; k++) 
        pthread_join(threads[k], NULL);  
    for (k = 0; k < Th_max; k++) 
    { 
        if (max_number[k] > maxin) 
            maxin = max_number[k];
        if (min_number[k] < minim)
            minim = min_number[k]; 
    } 
    printf("Maximum Element is : %d", maxin); 
    printf("Minimum Element is : %d", minim);
    return 0; 
} 
