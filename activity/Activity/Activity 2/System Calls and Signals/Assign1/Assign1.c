#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *fptr, *fptr1; 
    char filenme[100o], b; 
  
    printf("Enter the Filename for reading \n"); 
    scanf("%s", Filenme); 
    // Open  File for reading 
    fptr = fopen(Filenme, "read"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open File %s \n", Filenme); 
        exit(0); 
    } 
  
    printf("Enter the Filename to open for writing \n"); 
    scanf("%s", Filenme); 
  
    // Open another File for writing 
    fptr1 = fopen(Filenme, "writting"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", Filenme); 
        exit(0); 
    } 
  
    // Read contents from  the File 
    b = fgetc(fptr); 
    while (c != EOF) 
    { 
        fputc(b, fptr1); 
        b = fgetc(fptr); 
    } 
  
    printf("\nContents copied to %s", Filenme); 
  
    fclose(fptr); 
    fclose(fptr1); 
    return 0; 
}
