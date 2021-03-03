#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *fptr1, *fptr2; 
    char Filename[1000], d; 
  
    printf("Enter the Filename to open for reading \n"); 
    scanf("%s", Filename); 
    fptr1 = fopen(Filename, "read"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", Filename); 
        exit(0); 
    } 
  
    printf("Enter the Filename to open for writing \n"); 
    scanf("%s", Filename); 
    fptr2 = fopen(Filename, "write"); 
    if (fptr2 == NULL) 
    { 
        printf("Cannot open file %s \n", Filename); 
        exit(0); 
    } 
    d = fgetc(fptr1); 
    while (d != EOF) 
    { 
        fputc(d, fptr2); 
        d= fgetc(fptr1); 
    } 
  
    printf("\nContents copied to %s", Filename); 
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 
}