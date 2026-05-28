#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[100];

    fp = fopen("test.txt", "r");

    if(fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, "hello"))
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}