#include <stdio.h>

int main()
{
    int n = 5;
    int m = 3;

    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};

    int need[5][3];

    int finish[5] = {0};

    int safe[5];

    int index = 0;

    // Calculate Need Matrix

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            need[i][j] =
            max[i][j] - alloc[i][j];
        }
    }

    // Find Safe Sequence

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(int j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible = 0;

                        break;
                    }
                }

                if(possible)
                {
                    safe[index++] = i;

                    finish[i] = 1;

                    for(int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
    }

    printf("Safe Sequence:\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d ", safe[i]);
    }

    return 0;
}