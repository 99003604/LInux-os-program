#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char loc[100];

    char cha;
    int l,w,ch;
    /* Input path  file to merge to  the third file */
    printf("Enter source file location: ");
    scanf("%s", location);

    /* Open the source file in read mode from location loc */
    
    file = fopen(location, "read");

    /* Check if the file is opened successfully */
    
    if (file == NULL)
    {
        printf("\nUnable to open the file.\n");
        printf("Please check if the file exists and you have the right privilege.\n");

        exit(EXIT_FAILURE);
    }
    // Logic to count the characters, words and lines in a file.
    l = w = ch = 0; 
// Initialise all with 0
    while ((cha = fgetc(file)) != EOF)
    {
        ch++;

        // Check and count the number of new line 
        if (cha == '\0' || cha == '\n')
            l++;

        // Check and count the number of words 
        if (cha == ' ' || cha == '\t' || cha == '\n' || cha == '\0')
            w++;
    }
    // Need to increment w and l for the last word 
    if (ch > 0)
    {
        w++;
        l++;
    }
    
// Print the count of  the cha, l and w in the file
 
    printf("\n");
    printf("Total ch = %d\n", ch);
    printf("Total w = %d\n", w);
    printf("Total l = %d\n", l);
    // Close the file
    fclose(file);
    return 0;
}
