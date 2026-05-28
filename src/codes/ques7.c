#include <stdio.h>

int main()
{
    int b[10], p[10];
    int nb, np;

    printf("Enter number of blocks and processes: ");
    scanf("%d %d", &nb, &np);

    printf("Enter block sizes:\n");

    for(int i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Enter process sizes:\n");

    for(int i = 0; i < np; i++)
    {
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < np; i++)
    {
        int allocated = 0;

        for(int j = 0; j < nb; j++)
        {
            if(b[j] >= p[i])
            {
                printf("Process %d allocated to block %d\n",
                i+1, j+1);

                b[j] -= p[i];

                allocated = 1;

                break;
            }
        }

        if(allocated == 0)
        {
            printf("Process %d cannot be allocated\n", i+1);
        }
    }

    return 0;
}