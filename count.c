#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int chara, w, l;
    printf("Enter source file path: ");
    scanf("%s", path);
    file = fopen(path, "read");
  
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    /*
     * Logic to count characters, words and lines.
     */
    chara = w = l = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        chara++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            l++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            w++;
    }
    if (chara > 0)
    {
        w++;
        l++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total chara= %d\n", chara);
    printf("Total w   = %d\n", w);
    printf("Total l   = %d\n", l);
    fclose(file);

    return 0;
}
