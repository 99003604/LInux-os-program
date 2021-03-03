#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *fptr1, *fptr2; 
    char filename[100], d; 
  
    printf("Enter the filename to open for reading \n"); 
    scanf("%s", filename); 
    fptr1 = fopen(filename, "read"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
  
    printf("Enter the filename to open for writing \n"); 
    scanf("%s", filename); 
    fptr2 = fopen(filename, "write"); 
    if (fptr2 == NULL) 
    { 
        printf("Cannot open file %s \n", filename); 
        exit(0); 
    } 
    d = fgetc(fptr1); 
    while (d != EOF) 
    { 
        fputc(d, fptr2); 
        d= fgetc(fptr1); 
    } 
  
    printf("\nContents copied to %s", filename); 
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 
}