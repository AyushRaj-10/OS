#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char ch;

    f1 = fopen("a.txt", "r");
    f2 = fopen("b.txt", "w");

    if(f1 == NULL)
    {
        printf("Source file not found\n");
        return 1;
    }

    while((ch = fgetc(f1)) != EOF)
    {
        fputc(ch, f2);
    }

    printf("File copied successfully\n");

    fclose(f1);
    fclose(f2);

    return 0;
}